/*
Сдать решение задачи G8-Числа в массив
Числа в массив
В файле input.txt дана строка, не более 1000 символов, содержащая буквы,
целые числа и иные символы. Требуется все числа, которые встречаются в строке,
поместить в отдельный целочисленный массив. Например, если дана строка
"data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести массив по возрастанию в файл output.txt.

Формат входных данных
Строка из английских букв, цифр и знаков препинания
Формат результата
Последовательность целых чисел отсортированная по возрастанию
*/
#define MAX_CHAR 1001 // Максимальный размер строки
#include <stdio.h>    // подключаем заголовочный файл stdio.h
#include <stdint.h>   // полключение заголовочного файла типы переменных.
#include <string.h>   // полключение заголовочного файла работа со строками

// ###############################################################
// Функция поиска чисел в строке.
// str - входная строка. out - массив для хранения найденных чисел.
// Возвращает количество найденных чисел.
uint32_t finder(char *str, int32_t *out)
{
    uint8_t temp[10] = {0}; // Временный массив для хранения цифр числа (максимум 10 цифр)
    uint8_t temp_cntr = 0;  // Счётчик цифр текущего числа
    uint8_t out_cntr = 0;   // Счётчик найденных чисел
    uint32_t num = 0;       // Текущее число

    uint16_t stringsize = strlen(str); // Размер строки

    for (uint16_t i = 0; i < stringsize; i++)
    {
        // Проверяем, является ли текущий символ цифрой ('0'..'9')
        if (str[i] >= '0' && str[i] <= '9')
        {
            // Начинаем сбор числа
            num = 0; // Обнуляем число перед сбором нового
            while (i < stringsize && str[i] >= '0' && str[i] <= '9')
            {
                // Преобразуем символ в цифру и добавляем к текущему числу
                num = num * 10 + (str[i] - '0');
                i++; // Переходим к следующему символ строки
            }
            // После выхода из цикла, i указывает на первый нецифровой символ после числа,
            // поэтому уменьшаем i на один, чтобы внешний цикл продолжил с правильной позиции.
            i--;

            // Записываем найденное число в массив
            out[out_cntr] = num;
            out_cntr++;
        }
        // Если символ не цифра, просто продолжаем цикл
    }
    return out_cntr; // Возвращаем количество найденных чисел
}

// ###############################################################
// Функция сортировки массива по возрастанию методом пузырька.
void sort(int32_t *num, uint32_t mas_size)
{
    for (uint8_t i = 0; i < mas_size; i++)
    {
        for (uint8_t j = 0; j < mas_size - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                int32_t temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
}

// ###############################################################
int main()
{
    FILE *file_in, *file_out;           // Указатели на файлы для чтения и записи
    char *file_n_in = "input.txt";   // Имя входного файла
    char *file_n_out = "output.txt"; // Имя выходного файла
    char temp_c = 0;                    // Временная переменная
    char tmp_string[MAX_CHAR] = "";     // Буфер для хранения строки из файла
    int out_buf[MAX_CHAR] = {0};        // Буфер хранения цифр на выход.
    int out_size = 0;                   //

    //  Читаем файл.
    file_in = fopen(file_n_in, "r");
    if (file_in == NULL) // проверяем открылся ли файл. Если нет то выдаем ошибку.
    {
        printf("File input error \n");
        return -1;
    };
    // Читаем строку из файла (до символа новой строки)

    fscanf(file_in, "%[^\n]s", tmp_string);
    // Находим все числа в строке и сохраняем их в out_buf, возвращая их количество
    out_size = finder(tmp_string, out_buf);
    // ##Смотрим что в массиве#############################################################
    /*    for (uint32_t u = 0; u < out_size; u++)
        {
            printf("%d ", *(out_buf + u));
        }
             printf("\n");
    */
    // ###############################################################
    // Сортируем полученные числа по возрастанию пузырьковым методом.
    sort(out_buf, out_size);
    // Выводим все в файл.
    file_out = fopen(file_n_out, "w"); // открываем
    if (file_out == NULL)              // проверяем открылся ли файл. Если нет то выдаем ошибку.
    {
        printf("File input error \n");
        return -1;
    };
    // Записываем отсортированные числа в файл вывода через пробел
    for (uint32_t u = 0; u < out_size; u++)
    {
        //     printf("%d ", *(out_buf + u));
        fprintf(file_out, "%d ", *(out_buf + u));
    }

    fclose(file_in);
    fclose(file_out);

    return 0;
}
