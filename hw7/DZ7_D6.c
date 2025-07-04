/*
Сдать решение задачи D6-Строка наоборот
Строка наоборот
Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот. Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.
void reverse_string()

Формат входных данных
Строка из английских букв и знаков препинания. В конце строки символ точка.
Формат результата
Исходная строка задом наперед.
*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.

void reverse_string()
{
    char c = getchar();
    if(c == '.') {return;};
    reverse_string();
    printf("%c", c);
}

int main(void) // определяем функцию main
{
    reverse_string();
    printf("\n");
    return 0; // выходим из функции
} // конец функции
