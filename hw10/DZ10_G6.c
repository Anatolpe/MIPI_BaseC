/*
Сдать решение задачи G6-Проверка на палиндром
Проверка на палиндром
В файле input.txt символьная строка не более 1000 символов.
Необходимо проверить, является ли она палиндромом
(палиндром читается одинаково в обоих направлениях).
Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.

Формат входных данных
Строка из заглавных английских букв
Формат результата
YES или NO
*/

#include <stdio.h>   // подключаем заголовочный файл stdio.h
#include <stdint.h>  // полключение заголовочного файла типы переменных.
#include <string.h>  // полключение заголовочного файла работа со строками

// Функция для проверки, является ли строка палиндромом
int is_palindrom(const char *str) {
    int len = strlen(str);
   // printf("%s %d\n",str,len);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
    //        printf("NO\n");
            return 0; // Не палиндром
        }
    }
 //    printf("YES\n");
    return 1; // Палиндром
}

int main()
{
    FILE *file_in, *file_out;           // Указатели на файлы для чтения и записи
    char *file_n_in = "input.txt";   // Имя входного файла
    char *file_n_out = "output.txt"; // Имя выходного файла
    char tmp_string[1001] = "";         // Буфер для хранения строки первого слова из файла
    // char temp_c = 0;
    //  int count = 0;
    //  Читаем файл.
    file_in = fopen(file_n_in, "r");
    if (file_in == NULL) // проверяем открылся ли файл. Если нет то выдаем ошибку.
    {
        printf("File input error \n");
        return -1;
    };
    fscanf(file_in, "%[^\n]s", tmp_string); // открываем файл и всю сторочку в буфер.

    fclose(file_in);
    // printf("%s \n", tmp_string);
    file_out = fopen(file_n_out, "w"); // открываем
    if (file_out == NULL)
    {
        printf("File output error \n");
        return 1;
    }
    // Проверяем что получили.
    if (is_palindrom(tmp_string) == 1)
    {
        fprintf(file_out, "YES\n");
    }
    else
    {
        fprintf(file_out, "NO\n");
    }

    fclose(file_out);

    return 0;
}
