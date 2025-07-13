/*
Сдать решение задачи G5-Заменить a на b
Заменить a на b
В файле input.txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.

Формат входных данных
Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Формат результата
Строка из маленьких и больших английских букв, знаков препинания и пробелов.

*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.
#include <string.h> // полключение заголовочного файла работа со строками

int main()
{
    FILE *file_in, *file_out;           // Указатели на файлы для чтения и записи
    char *file_n_in = "input.txt";   // Имя входного файла
    char *file_n_out = "output.txt"; // Имя выходного файла
    char tmp_string[1001] = "";         // Буфер для хранения строки первого слова из файла
    char temp_c = 0;
    int count = 0;
    // Читаем файл.
    file_in = fopen(file_n_in, "r");
    if (file_in == NULL) // проверяем открылся ли файл. Если нет то выдаем ошибку.
    {
        printf("File input error \n");
        return -1;
    };
    file_out = fopen(file_n_out, "w"); // открываем
    if (file_out == NULL)
    {
        printf("File output error \n");
        return 1;
    }

    while ((temp_c = getc(file_in)) != EOF && temp_c != '\n') // считываем посимвольно пока не увидем конец строки или перевод строки
    {
       // printf("%c ", temp_c);
        switch (temp_c)     //Находим символ который подподает под критерии замены и меняем..
        {
        case 'A':
            temp_c = 'B';
            break;
        case 'B':
            temp_c = 'A';
            break;
        case 'a':
            temp_c = 'b';
            break;
        case 'b':
            temp_c = 'a';
            break;
        }
       // printf("%c \n", temp_c);
        fputc(temp_c, file_out);  // Выводим символ в файл.
    }
    fclose(file_in);
    fclose(file_out);

    return 0;
}
