/*
Сдать решение задачи G4-Совпадения букв
По одному разу
В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом.
Найдите только те символы слов, которые встречаются в обоих словах только один раз.
Напечатайте их через пробел в файл output.txt в лексикографическом порядке.

Формат входных данных
Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов.
Формат результата
Маленькие английские буквы через пробел.

*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.
#include <string.h> // полключение заголовочного файла работа со строками

int main()
{
    FILE *file_in, *file_out;           // Указатели на файлы для чтения и записи
    char *file_n_in = "input.txt";   // Имя входного файла
    char *file_n_out = "output.txt"; // Имя выходного файла
    char tmp1_string[101] = "";         // Буфер для хранения строки первого слова из файла
    char tmp2_string[101] = "";         // Буфер для хранения строки второго слова из файла
    int freq1[26] = {0};                // Массивы для подсчета частоты символов
    int freq2[26] = {0};                // Массивы для подсчета частоты символов
    int in_word1 = 0, in_word2 = 0;     // Флаги 
    // Читаем файл.
    file_in = fopen(file_n_in, "r");
    if (file_in == NULL) // проверяем открылся ли файл. Если нет то выдаем ошибку.
    {
        printf("File input error \n");
        return -1;
    };

    if (fscanf(file_in, "%s%s", tmp1_string, tmp2_string) != 2)
    {
        fputs("Error read file.\n", stderr);
        return -1;
    }
    // Подсчет частот для первого слова
    for (int i = 0; tmp1_string[i] != '\0'; i++)
    {
        if (tmp1_string[i] >= 'a' && tmp1_string[i] <= 'z')
        {
            freq1[tmp1_string[i] - 'a']++;
        }
    }

    // посмотрим что в первом массиве
    /*printf("%s \n", tmp1_string);
    for (int t1 = 0; t1 <= 25; t1++)
    {
        printf("%d ", freq1[t1]);
    };
    printf("\n "); //
    */
    // Подсчет частот для второго слова
    for (int i = 0; tmp2_string[i] != '\0'; i++)
    {
        if (tmp2_string[i] >= 'a' && tmp2_string[i] <= 'z')
        {
            freq2[tmp2_string[i] - 'a']++;
        }
    }
    // посмотрим что в втором массиве
    /*printf("%s \n", tmp2_string);
    for (int t2 = 0; t2 <= 25; t2++)
    {
        printf("%d ", freq2[t2]);
    };
    printf("\n "); //
    */

    // выводим в файл
    file_out = fopen(file_n_out, "w"); // открываем
    if (file_out == NULL)
    {
        printf("File output error \n");
        return 1;
    }
    // Для каждого символа проверяем условия
    for (int c = 0; c < 26; c++)
    {
        if (freq1[c] == 1 && freq2[c] == 1)
        {
            // Проверяем, есть ли этот символ в обоих словах ровно один раз
            // и он встречается в обоих словах
            char ch = 'a' + c;
            // Проверка наличия символа в каждом слове

            for (int i = 0; tmp1_string[i] != '\0'; i++)
            {
                if (tmp1_string[i] == ch)
                {
                    in_word1 = 1;
                    break;
                }
            }
            for (int i = 0; tmp2_string[i] != '\0'; i++)
            {
                if (tmp2_string[i] == ch)
                {
                    in_word2 = 1;
                    break;
                }
            }
            if (in_word1 && in_word2)
            {
                fprintf(file_out, "%c ", ch);
            }
        }
    }

    fclose(file_out);

    return 0;
}
