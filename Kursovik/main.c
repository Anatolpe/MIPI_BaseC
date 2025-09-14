#include "Temp_function.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <windows.h>
// Глобальная переменная хранения аргументов коммандной строки.
char argum[] = "";
// uint8_t u = 0;

// Глобальные структуры для хранения данных
// full_data - все данные из CSV файла
// m_data - данные для отдельного месяца
data full_data;
data_month m_data;

/**
 * @brief Функция извлекает имя файла из строки
 * @param source - исходная строка
 * @param dest_name - буфер для имени файла
 * @return длина имени файла
 */
uint8_t get_filename(char *source, char *dest_name)
{
  char *pp = source;
  uint8_t t = 0;
  while (*pp != '\0' && *pp != ' ' && *pp != '\n' && *pp != '\r')
  {
    *(dest_name + (t++)) = *(pp++);
  }
  dest_name[t] = '\0'; // Добавляем нуль-терминатор
  return t;
}
/**
 * @brief Выводит справку по использованию программы
 */
void print_help(void)
{
  // printf("\nThis is a simple temperature statistic program %s\n", version);
  printf("Поддерживаемые аргументы:\n");
  printf("-h                                 -- help\n");
  printf("-f <filename.csv> -m <month>       -- .csv имя загружаемого файла.\n");
  printf(" доп аргумент -m MM(1..12) покажет статистику по конкретному месяцу за год\n");
  printf("если аргумента -m нету, покажет статистику за один год. \n");
  printf("-v                                 -- покажет версию программы\n");
}
/**
 * @brief Выводит информацию о программе
 */
void print_about(void)
{
  printf("\n============================================================\n");
  printf("\nПрограмма обработки файлов и вывода статистики по температуре.\n");
  printf("\nКурсовой проект по дисциплине \"Базовый С\" Петькова Анатолия\n");
  printf(" Используйте аргумент -h для получения помощи.\n");
  printf("\n======================================================\n\n");
}

/**
 * @brief Обрабатывает аргументы командной строки
 * @param argc - количество аргументов
 * @param argv - массив аргументов
 *
 * Поддерживаемые аргументы:
 * -f <file.csv>   - указать CSV файл для обработки
 * -m <month>      - показать статистику для конкретного месяца (1-12)
 * -h              - показать справку
 * -v              - показать версию
 *
 * Если указан только -f, выводится статистика за весь год
 */
void args(int32_t argc, char *argv[])
{
  char filename[256] = "";
  uint8_t month = 0;
  uint8_t has_file = 0;
  uint8_t has_month = 0;

  for (uint8_t i = 1; i < argc; i++)
  {
    char *p = argv[i];

    // Все аргументы должны начинаться с '-'
    if (*p != '-')
    {
      printf("Неизвестный аргумент: %s (аргументы должны начинаться с '-')\n", argv[i]);
      return;
    }

    p++; // Пропускаем '-'

    switch (*p)
    {
    case 'f': // Обработка аргумента -f (файл)
      if (i + 1 >= argc)
      {
        printf("Отсутствует имя файла после -f\n");
        return;
      }
      strcpy(filename, argv[i + 1]);
      has_file = 1;
      i++; // Пропускаем следующий аргумент (имя файла)
      break;

    case 'm': // Обработка аргумента -m (месяц)
      if (i + 1 >= argc)
      {
        printf("Отсутствует номер месяца после -m\n");
        return;
      }
      month = char2num(argv[i + 1], '\0');
      if (month < 1 || month > 12)
      {
        printf("Некорректный номер месяца: %d. Должен быть от 1 до 12.\n", month);
        return;
      }
      has_month = 1;
      i++; // Пропускаем следующий аргумент (номер месяца)
      break;

    case 'h': // Показать справку
      print_help();
      return;

    case 'v': // Показать версию
      printf("Версия проекта =1 . \n");
      print_help();
      return;

    default: // Неизвестная опция
      printf("Неизвестная опция: -%s\n", p);
      return;
    }
  }

  // Проверяем, указан ли файл
  if (!has_file)
  {
    printf("Не указан файл для обработки (используйте -f <filename.csv>)\n");
    return;
  }

  // Загружаем данные и показываем статистику
  process_file_and_show_stats(filename, has_month ? month : 0);
}

/**
 * @brief Обрабатывает файл и показывает статистику
 * @param filename - имя CSV файла
 * @param month - номер месяца (0 = показать весь год)
 *
 * Функция загружает данные из файла и в зависимости от параметра month:
 * - Если month > 0: показывает статистику для указанного месяца
 * - Если month = 0: показывает статистику за весь год
 */

void process_file_and_show_stats(char *filename, uint8_t month)
{
  // Читаем данные из CSV файла
  if (read_data(&full_data, filename) != SUCCESS)
  {
    printf("Ошибка при чтении данных из файла %s!\n", filename);
    return;
  }

  if (month > 0)
  {
    // Показываем статистику для конкретного месяца
    if (month < 1 || month > 12)
    {
      printf("Некорректный номер месяца: %d. Должен быть от 1 до 12.\n", month);
      return;
    }
    print_month_info(&full_data, &m_data, month);
  }
  else
  {
    // Показываем статистику за весь год
    print_yearstat_info(&full_data, &m_data);
  }
}

/**
 * @brief Главная функция программы
 * @param argc - количество аргументов
 * @param argv - массив аргументов
 * @return код завершения (0 - успешно)
 *
 */
int main(int32_t argc, char *argv[])
{
  //* Устанавливает русскую кодировку для Windows и запускает обработку аргументов

  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
  // Если аргументов нет, показать информацию о программе
  if (argc < 2)
  {
    print_about();
    return 0;
  }
  // Обработать аргументы командной строки
  args(argc, argv);
  return 0;
}