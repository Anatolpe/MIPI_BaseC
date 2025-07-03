/*
Сдать решение задачи E4-Два максимума
Два максимума
Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.
Формат входных данных
10 целых чисел через пробел.
Формат результата
Сумма двух максимальных элементов.
*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.
#define SIZE 10
int F_simple_max(int arra[], int Size_1)
{
    int max1 = arra[0], max2 = arra[1];
    int temp = 0;
    for (int i = 0; i < Size_1; i++)
    {
        for (int j = 0; j < Size_1 - 1; j++)
        {
            if (arra[j] < arra[j + 1])
            {
                temp = arra[j];
                arra[j] = arra[j + 1];
                arra[j + 1] = temp;
            }
        }
    }
    return arra[0] + arra[1];
}

int main(void) // определяем функцию main
{
    int arr[SIZE];
    for (uint8_t I = 0; I < SIZE; I++)
    {
        scanf("%d", &arr[I]);
    }

    printf("%d\n", F_simple_max(arr, SIZE));
    return 0; // выходим из функции
} // конец функции
