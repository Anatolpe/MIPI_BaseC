/*
Сдать решение задачи F5-Максимум в массиве
Максимум в массиве
Написать только одну функцию, которая находит максимальный элемент в массиве. Всю программу загружать не надо.
Прототип функции: int find_max_array(int size, int a[])

Формат входных данных
Массив состоящий из целых чисел. Первый аргумент, размер массива, второй аргумент адрес нулевого элемента.
Формат результата
Одно целое число
*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.
#include <string.h>

#define SIZE 100

int find_max_array(int size, int a[])
{
    int max = a[0];                // Примем за максимум 0
    for (int i = 0; i < size; i++) // пробежимся по всему массиву
    {
        if (max < a[i]) // Если текущий элемент больше чем предыдущий найденный Максимальный
        {
            max = a[i]; // Присваеваем его
        }
    }
    return max; // Возвращаем найденое максимальное число.
}
/*
int main()
{
    int TEMP[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &TEMP[i]);
    }
    printf("%d", find_max_array(SIZE, TEMP));
    return 0;
}
*/
