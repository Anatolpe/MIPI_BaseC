/*
Сдать решение задачи E8-Инверсия каждой трети
Инверсия каждой трети
Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.

Формат входных данных
12 целых чисел через пробел
Формат результата
12 целых чисел через пробел
*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.
#define SIZE 12
int F_simple(int arra[], int Size_1)
{
    for (int t = 0; t < 3; ++t)
    {
        int start = t * (Size_1 / 3);
        int end = start + (Size_1 / 3) - 1;
        for (int i = end; i >= start; --i)
        {
            printf("%d ", arra[i]);
        }
    }
}

int main(void) // определяем функцию main
{
    int arr[SIZE];
    for (uint8_t I = 0; I < SIZE; I++)
    {
        scanf("%d", &arr[I]);
    }
    F_simple(arr, SIZE);
    printf("\n");
    return 0; // выходим из функции
} // конец функции
