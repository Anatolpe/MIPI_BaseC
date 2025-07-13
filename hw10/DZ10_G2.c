/*
Сдать решение задачи G2-Строка и цифры
Строка и цифры
Считать число N из файла input.txt.
Сформировать строку из N символов.
N четное число, не превосходящее 26.
На четных позициях должны находится четные цифры в порядке возрастания, кроме 0,
на нечетных позициях - заглавные буквы в порядке следования в английском алфавите.
Результат записать в файл output.txt

Формат входных данных
Четное N ≤ 26
Формат результата
Строка из английских букв и цифр

*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.
#include <string.h> // полключение заголовочного файла работа со строками

int main()
{
    FILE *file;
    char *file_in = "input.txt";
    char *file_out = "output.txt";
    char tmp_string[100] = "";
    char temp_c = 0, letter = 'A';
    int count = 0, count1 = 2;
    // Читаем файл.
    file = fopen(file_in, "r");
    if (file_in == NULL) // проверяем открылся ли файл. Если нет то выдаем ошибку.
    {
        printf("File input error \n");
        return -1;
    };

    if (fscanf(file, "%d", &count) != 1 || count > 26 || count < 1) // Считываем число- и проверяем попадаем ли в диапазон
    {
        printf("Error file text \n");
        return 1;
    };
    printf("N= %d \n", count);
    fclose(file);
    // выводим в файл
    file = fopen(file_out, "w"); // открываем
    if (file == NULL)
    {
        printf("File output error \n");
        return 1;
    }

    for (int i = 0; i < count; i++)
    {
        if ((i + 1) % 2 == 1) // Если нечетная позиция: заглавная буква
        {
            tmp_string[i] = letter++;
        }
        else // Если Четная позиция: то пишем четную цифру
        {
            tmp_string[i] = count1 + '0';
            count1 = count1 + 2;
            if (count1 > 8)             // Если счетчик больше 8 то сбрасываем- 
            {
                count1 = 2;
            };
        }
    }
    tmp_string[count] = '\0'; // завершаем строку нуль-терминатор
    // Запись в файл output.txt
    fprintf(file, "%s\n", tmp_string);
    fclose(file);
    // printf("Строка успешно записана в output.txt\n");
    return 0;
}
