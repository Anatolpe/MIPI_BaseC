/*
Сдать решение задачи E3-Максимум и минимум и их номера
Максимум и минимум
Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.
Формат входных данных
10 целых чисел через пробел
Формат результата
4 целых числа через пробел: номер максимума, максимум, номер минимума, минимум.

*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.
#define SIZE 10
int F_simple_max(int arra[], int Size_1)
{
    int max = arra[0], ind_max=1;
    for (int i = 1; i < Size_1; ++i)
    {
        if (arra[i] > max){
            max = arra[i];
            ind_max=i+1;
            }
    }
    printf("%d %d",ind_max, max);
}

int F_simple_min(int arra[], int Size_1)
{
    int min = arra[0], ind_min=1;
    for (int i = 1; i < Size_1; ++i)
    {
        if (arra[i] < min){
            min = arra[i];
            ind_min=i+1;
            }
    }
    printf("%d %d",ind_min, min);
}

int main(void) // определяем функцию main
{
    int arr[SIZE];
    for (uint8_t I = 0; I < SIZE; I++)
    {
        scanf("%d", &arr[I]);
    }
    F_simple_max(arr, SIZE);
    printf(" ");
    F_simple_min(arr, SIZE);
    printf("\n");
    return 0; // выходим из функции
} // конец функции
