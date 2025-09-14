#include "Temp_function.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>

/**
 * НАЗВАНИЯ МЕСЯЦЕВ НА АНГЛИЙСКОМ
 */
const char month_name[12][10] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};

/**
 * @brief Сортирует данные по температуре (возрастание)
 * @param dt - указатель на структуру данных месяца
 *
 * Использует пузырьковую сортировку для упорядочивания измерений
 * по температуре от минимальной к максимальной
 */
void sortByTemp(data_month *dt)
{
  for (uint32_t i = 0; i < dt->meas_month; ++i)
    for (uint32_t j = i; j < dt->meas_month; ++j)
      if (dt->measure_month[i].temp >= dt->measure_month[j].temp)
      {
        // Обмен местами двух записей
        record temp = dt->measure_month[i];
        dt->measure_month[i] = dt->measure_month[j];
        dt->measure_month[j] = temp;
      }
}

/**
 * @brief Добавляет запись в массив измерений
 * @param dt - указатель на массив записей
 * @param num_meas - индекс для добавления
 * @param year, month, day, hour, min, temp - данные измерения
 */
void add_record(record *dt, uint32_t num_meas, uint16_t year, uint8_t month,
                uint8_t day, uint8_t hour, uint8_t min, int8_t temp)
{
  dt[num_meas].year = year;
  dt[num_meas].month = month;
  dt[num_meas].day = day;
  dt[num_meas].hour = hour;
  dt[num_meas].min = min;
  dt[num_meas].temp = temp;
}

/**
 * @brief Очищает данные месяца
 * @param dt - указатель на структуру данных месяца
 *
 * Сбрасывает счетчик измерений, сами данные не очищаются явно,
 * так как будут перезаписаны при следующем использовании
 */
void clear_month_data(data_month *dt)
{
  dt->meas_month = 0;
}

/**
 * @brief Извлекает данные для конкретного месяца
 * @param dt_source - источник данных (все измерения)
 * @param dt_dest - приемник данных (только указанный месяц)
 * @param month_number - номер месяца (1-12)
 */
void get_month_data(data *dt_source, data_month *dt_dest,
                    uint8_t month_number)
{
  uint32_t num_records = 0;
  for (uint32_t i = 0; i < dt_source->meas_amount; i++)
  {
    if (month_number == dt_source->measure[i].month)
    {
      dt_dest->measure_month[num_records] = dt_source->measure[i];
      num_records++;
    }
  }
  dt_dest->meas_month = num_records;
}

/**
 * @brief Вычисляет среднюю температуру за месяц
 * @param dt - указатель на данные месяца
 * @return средняя температура (float)
 */
float month_average_temp(data_month *dt)
{
  int32_t result = 0; // Используем int32_t для избежания переполнения
  for (uint16_t i = 0; i < dt->meas_month; i++)
  {
    result += dt->measure_month[i].temp;
  }
  return (float)result / dt->meas_month;
}

/**
 * @brief Выводит данные по месяцу
 * @param dt_dest - данные месяца
 * @param num_month - номер месяца
 * @param average - средняя температура
 */
void print_month_data(data_month *dt_dest, uint8_t num_month, float average)
{
  printf("%-8d %-15s %0.1f%-14s %d%-10s %d%s\n",
         dt_dest->measure_month[0].year,
         month_name[num_month - 1],
         average, "°C",
         dt_dest->measure_month[0].temp, "°C",
         dt_dest->measure_month[dt_dest->meas_month - 1].temp, "°C");
}

/**
 * @brief Выводит данные за год
 * @param avg - среднегодовая температура
 * @param max - максимальная температура года
 * @param min - минимальная температура года
 */
void print_year_data(float avg, int8_t max, int8_t min)
{
  printf("%-15s %-10s %s\n", "average_temp", "min_temp", "max_temp");
  printf("-------------  ---------  --------\n");
  printf("%s %0.1f%s%s %d%s%s %d%s\n\n",
         "   ", avg, "°C", "       ", min, "°C", "      ", max, "°C");
}

/**
 * @brief Выводит статистику для конкретного месяца
 * @param dt_source - исходные данные
 * @param dt_dest - буфер для данных месяца
 * @param num_month - номер месяца (1-12)
 */
void print_month_info(data *dt_source, data_month *dt_dest, uint8_t num_month)
{
  if (num_month > 12 || num_month < 1) // Надо выпилить, проверка идет и так в главной программе
  {
    printf("\nНекорректный номер месяца: (1-12)\n\n");
    return;
  }

  get_month_data(dt_source, dt_dest, num_month);

  if (dt_dest->meas_month == 0)
  {
    printf("\nОтсутсвуют данные по данному месяцу: %s\n\n", month_name[num_month - 1]);
    return;
  }

  float av = month_average_temp(dt_dest);
  sortByTemp(dt_dest);
  printf("\n====================Статистика за месяц====================\n\n");
  printf("%-8s %-12s %-16s %-8s %11s\n",
        "Year", "Month", "Average_temp", "Min_temp", "Max_temp");
  printf("-----   ----------    ------------    ----------  ----------\n");
  print_month_data(dt_dest, num_month, av);
  printf("\n");
}

/**
 * @brief Выводит статистику за весь год
 * @param dt_source - исходные данные
 * @param dt_dest - буфер для данных месяца
 *
 * Выводит статистику по каждому месяцу и общую статистику за год
 */
void print_yearstat_info(data *dt_source, data_month *dt_dest)
{
  if (dt_source->meas_amount == 0)
  {
    printf("Нет данных для отображения статистики\n");
    return;
  }

  int8_t year_max = INT8_MIN;
  int8_t year_min = INT8_MAX;
  float year_avg = 0.0;
  uint32_t total_measurements = 0;
  printf("\n=============СТАТИСТИКА ПО МЕСЯЦАМ ЗА ГОД===================\n\n");
  printf("%-8s %-12s %-16s %-8s %11s\n",
         "Year", "Month", "Average_temp", "Min_temp", "Max_temp");
  printf("-----   ----------    ------------    ----------  ----------\n");
  // Обрабатываем каждый месяц
  for (uint8_t j = 1; j <= 12; j++)
  {
    get_month_data(dt_source, dt_dest, j);

    if (dt_dest->meas_month == 0)
    {
      continue; // Пропускаем месяцы без данных
    }

    sortByTemp(dt_dest);
    float av = month_average_temp(dt_dest);

    // Обновляем годовые минимум и максимум
    if (dt_dest->measure_month[dt_dest->meas_month - 1].temp > year_max)
    {
      year_max = dt_dest->measure_month[dt_dest->meas_month - 1].temp;
    }
    if (dt_dest->measure_month[0].temp < year_min)
    {
      year_min = dt_dest->measure_month[0].temp;
    }

    // Суммируем для среднегодовой температуры
    year_avg += av * dt_dest->meas_month;
    total_measurements += dt_dest->meas_month;

    print_month_data(dt_dest, j, av);
    clear_month_data(dt_dest);
  }

  // Вычисляем среднегодовую температуру
  if (total_measurements > 0)
  {
    year_avg /= total_measurements;
  }

  printf("\n================СТАТИСТИКА ЗА ГОД=====================\n\n");
  print_year_data(year_avg, year_max, year_min);
}

/**
 * @brief Преобразует строку в число
 * @param p - указатель на строку
 * @param stop_symb - символ остановки
 * @return число или DATA_ERROR при ошибке
 *
 * Поддерживает отрицательные числа и пропускает пробелы
 */
int32_t char2num(char *p, char stop_symb)
{
  int32_t num = 0;
  uint8_t negative = 0;

  while (*p != stop_symb && *p != '\n' && *p != '\r' && *p != '\000')
  {
    if (*p == ' ')
    {
      p++;
      continue;
    }

    if (*p == '-')
    {
      negative = 1;
      p++;
    }
    else if (*p >= '0' && *p <= '9')
    {
      num = num * 10 + (*p - '0');
      p++;
    }
    else
    {
      return DATA_ERROR;
    }
  }

  return negative ? -num : num;
}

/**
 * @brief Читает данные из CSV файла
 * @param dt - структура для хранения данных
 * @param csv_name - имя CSV файла
 * @return SUCCESS при успехе, ERROR при ошибке
 *
 * Формат CSV: YEAR;MONTH;DAY;HOUR;MINUTE;TEMPERATURE
 * Выполняет проверку корректности данных и подсчет ошибок
 */
uint8_t read_data(data *dt, char *csv_name)
{
  uint32_t meas_cntr = 0;
  char str[STRING_LENTH] = "";
  FILE *rd = fopen(csv_name, "r");

  if (rd == NULL)
  {
    printf("\nОшибка открытия файла %s!\n\n", csv_name);
    return ERROR;
  }

  uint32_t line_number = 0;
  uint32_t error_count = 0;

  while (fgets(str, STRING_LENTH, rd))
  {
    line_number++;

    // Пропускаем пустые строки и заголовок
    if (str[0] == '\n' || str[0] == '\r' || str[0] == '\0')
      continue;
    if (strstr(str, "YEAR") != NULL)
      continue;

    // Убираем символы новой строки
    str[strcspn(str, "\r\n")] = '\0';

    // Разбираем CSV строку на токены
    char *token = strtok(str, ";");
    if (token == NULL)
    {
      printf("Ошибка в строке %d: пустая строка или неверный формат\n", line_number);
      error_count++;
      continue;
    }

    // Парсим все поля CSV (ЭТА ЧАСТЬ БЫЛА ПРОПУЩЕНА!)
    int32_t year = char2num(token, '\0');

    token = strtok(NULL, ";");
    if (token == NULL)
    {
      printf("Ошибка в строке %d: отсутствует месяц\n", line_number);
      error_count++;
      continue;
    }
    int32_t month = char2num(token, '\0');

    token = strtok(NULL, ";");
    if (token == NULL)
    {
      printf("Ошибка в строке %d: отсутствует день\n", line_number);
      error_count++;
      continue;
    }
    int32_t day = char2num(token, '\0');

    token = strtok(NULL, ";");
    if (token == NULL)
    {
      printf("Ошибка в строке %d: отсутствует час\n", line_number);
      error_count++;
      continue;
    }
    int32_t hour = char2num(token, '\0');

    token = strtok(NULL, ";");
    if (token == NULL)
    {
      printf("Ошибка в строке %d: отсутствуют минуты\n", line_number);
      error_count++;
      continue;
    }
    int32_t min = char2num(token, '\0');

    token = strtok(NULL, ";");
    if (token == NULL)
    {
      printf("Ошибка в строке %d: отсутствует температура\n", line_number);
      error_count++;
      continue;
    }
    int32_t temp = char2num(token, '\0');

    // Проверяем корректность данных
    if (year == DATA_ERROR || year < 1000 || year > 9999)
    {
      printf("Ошибка в строке %d: некорректный год (%d)\n", line_number, year);
      error_count++;
      continue;
    }

    if (month == DATA_ERROR || month < 1 || month > 12)
    {
      printf("Ошибка в строке %d: некорректный месяц (%d)\n", line_number, month);
      error_count++;
      continue;
    }

    if (day == DATA_ERROR || day < 1 || day > 31)
    {
      printf("Ошибка в строке %d: некорректный день (%d)\n", line_number, day);
      error_count++;
      continue;
    }

    if (hour == DATA_ERROR || hour > 23)
    {
      printf("Ошибка в строке %d: некорректный час (%d)\n", line_number, hour);
      error_count++;
      continue;
    }

    if (min == DATA_ERROR || min > 59)
    {
      printf("Ошибка в строке %d: некорректные минуты (%d)\n", line_number, min);
      error_count++;
      continue;
    }

    if (temp == DATA_ERROR || temp < -99 || temp > 99)
    {
      printf("Ошибка в строке %d: некорректная температура (%d)\n", line_number, temp);
      error_count++;
      continue;
    }

    // Проверяем дублирование записи
    uint8_t duplicate = 0;
    for (uint32_t i = 0; i < meas_cntr; i++)
    {
      if (dt->measure[i].year == year && dt->measure[i].month == month &&
          dt->measure[i].day == day && dt->measure[i].hour == hour &&
          dt->measure[i].min == min)
      {
        printf("Ошибка в строке %d: повторная запись\n", line_number);
        error_count++;
        duplicate = 1;
        break;
      }
    }
    if (duplicate)
      continue;

    // Добавляем корректную запись
    add_record(dt->measure, meas_cntr, year, month, day, hour, min, temp);
    dt->meas_amount = ++meas_cntr;
  }

  fclose(rd);

  printf("\nОбработка завершена. Строк обработано: %d, ошибок: %d, корректных записей: %d\n",
         line_number, error_count, meas_cntr);

  if (meas_cntr == 0)
  {
    printf("Файл пуст или все данные некорректны\n");
    return ERROR;
  }

  return SUCCESS;
}
