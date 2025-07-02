/*
Сдать решение задачи C9-Факториал
Факториал
Составить функцию вычисления N!. Использовать ее при вычислении факториала int factorial(int n)

Формат входных данных
Целое положительное число не больше 20
Формат результата
Целое положительное число
*/

#include <stdio.h>  // подключаем заголовочный файл stdio.h
#include <stdint.h> // полключение заголовочного файла типы переменных.

int factorial(int n)
{
    int i = 1;
    int res = 1;
    while (i++ < n)
    {
        res *= i;
    }
    return res;
}

int main(void) // определяем функцию main
{
    int Temp = 0;
    scanf("%d", &Temp);
    printf("%lu", factorial(Temp));

    /*if ((Temp > -1) && (Temp <= 20))
    {
        printf("%lu", F_Fact(Temp));
    }
    else
    {
        printf("Error input\n");
    };
*/
    return 0; // выходим из функции
} // конец функции
