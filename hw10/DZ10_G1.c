/*
Сдать решение задачи G1-Три раза
Три раза
В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.
Формат входных данных
Строка из английских букв и пробелов. Не более 100 символов. В конце могут быть незначащие переносы строк.
Формат результата
Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней.
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
    char temp_c = 0;
    int count = 0;
    // Читаем файл.
    file = fopen(file_in, "r");
    if (file_in == NULL) // проверяем открылся ли файл. Если нет то выдаем ошибку.
    {
        printf("File input error \n");
        return -1;
    };
    while ((temp_c = getc(file)) != EOF && temp_c != '\n') // считываем посимвольно пока не увидем конец строки или перевод строки
    {
        tmp_string[count] = temp_c; // Если не нашли перевод- то во временный массив добавляем символ  и увеличиваем счетчик символов на 1
        count++;
    }
    fclose(file);
    // выводим в файл
    file = fopen(file_out, "w");  // открываем 
    fprintf(file, "%s, %s, %s %d", tmp_string, tmp_string, tmp_string, count); // добавляем временный буфер
    fclose(file);

    return 0;
}
