/*
Сдать решение задачи D1-От 1 до N
От 1 до N
Составить рекурсивную функцию, печать всех чисел от 1 до N

Формат входных данных
Одно натуральное число
Формат результата
Последовательность чисел от 1 до введенного числа
*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.

void print_simple(int n)
{
    if (n < 1)
    {
        return;
    };
    print_simple(n - 1);
    printf("%d ", n);
}

int main(void) // определяем функцию main
{
    int Temp = 0;
    scanf("%d", &Temp);
    if (Temp > 0)
    {
        print_simple(Temp);
    }
    else
    {
        printf("Error input!\n");
    };
    return 0; // выходим из функции
} // конец функции
