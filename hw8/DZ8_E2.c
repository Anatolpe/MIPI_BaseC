/*
Сдать решение задачи E2-Найти минимум
Найти минимум
Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.

Формат входных данных
5 целых чисел через пробел
Формат результата
Одно единственное целое число

*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.
#define SIZE 5

int F_simple(int arra[], int Size_1)
{
    int min = arra[0];
    for(int i=1; i<Size_1; ++i){
        if(arra[i] < min)
            min = arra[i];
    }
    return min;

}

int main(void) // определяем функцию main
{
    int arr[SIZE];
    for (uint8_t I = 0; I < SIZE; I++)
    {
        scanf("%d", &arr[I]);
    }
    printf("%d\n", F_simple(arr, SIZE));
    return 0; // выходим из функции
} // конец функции
