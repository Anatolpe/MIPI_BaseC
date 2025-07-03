/*
Сдать решение задачи E6-Среднее арифметическое 2
Среднее арифметическое массива
Считать массив из 12 элементов и посчитать среднее арифметическое элементов массива.

Формат входных данных
12 целых чисел через пробел
Формат результата
Среднее арифметическое в формате "%.2f"
*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.
#define SIZE 12
float F_simple(int arra[], int Size_1)
{
    float temp = 0;
    for (int i = 0; i < Size_1; i++)
    {
            temp += arra[i];
    }
    return (float)temp/Size_1;
}

int main(void) // определяем функцию main
{
    int arr[SIZE];
    for (uint8_t I = 0; I < SIZE; I++)
    {
        scanf("%d", &arr[I]);
    }

    printf("%.2f\n", F_simple(arr, SIZE));
    return 0; // выходим из функции
} // конец функции
