/*
Сдать решение задачи D4-В прямом порядке
В прямом порядке
Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками. Необходимо реализовать рекурсивную функцию.
void print_num(int num)

Формат входных данных
Одно целое неотрицательное число
Формат результата
Все цифры числа через пробел в прямом порядке.
*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.

void print_num(int num)
{
    if(num < 10){
        printf("%d ", num);
        return;
    }
    print_num(num / 10);
    printf("%d ", num % 10);
}

int main(void) // определяем функцию main
{
    int Temp = 0;
    scanf("%d", &Temp);
    if (Temp >= 0)
    {
        print_num(Temp);
    }
    else
    {
        printf("Error input!\n");
    };
    return 0; // выходим из функции
} // конец функции
