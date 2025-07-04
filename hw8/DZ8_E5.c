/*
Сдать решение задачи E5-Сумма положительных элементов
Сумма положительных элементов
Считать массив из 10 элементов и посчитать сумму положительных элементов массива.

Формат входных данных
10 целых чисел через пробел
Формат результата
Одно целое число - сумма положительных элементов массива

*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.
#define SIZE 10
int F_simple_pol(int arra[], int Size_1)
{
    int temp = 0;
    for (int i = 0; i < Size_1; i++)
    {
        if (arra[i] >= 0)
        {
            temp += arra[i];
        }
    }
    return temp;
}

int main(void) // определяем функцию main
{
    int arr[SIZE];
    for (uint8_t I = 0; I < SIZE; I++)
    {
        scanf("%d", &arr[I]);
    }

    printf("%d\n", F_simple_pol(arr, SIZE));
    return 0; // выходим из функции
} // конец функции
