/*
Сдать решение задачи A17-Время года
Ограничение времени:	1 с
Ограничение реального времени:	5 с
Ограничение памяти:	64M
Какое время года
Ввести номер месяца и вывести название времени года.

Формат входных данных
Целое число от 1 до 12 - номер месяца.
Формат результата
Время года на английском: winter, spring, summer, autumn
*/

#include <stdio.h>            			// подключаем заголовочный файл stdio.h
#include <stdint.h>						// полключение заголовочного файла типы переменных.
//#include <math.h>						// подключаем заголовочный файл математических функций
 
int main(void)                			// определяем функцию main
{                             			// начало функции
	int MES; 							// Обявляем переменные
	scanf("%d",&MES);		 			//Считаем число и запишем их по адресу переменной MES;
	
	if (MES == 1 || MES == 2 || MES == 12){					// Проеверям условия "Зимы"
		printf("winter \n"); 		 //Выводим на экран
	};
  
	if (MES == 3 || MES == 4 || MES == 5){					// Проеверям условия "Весны"
		printf("spring \n");		 //Выводим на экран
	};
	if (MES == 6 || MES == 7 || MES == 8){					// Проеверям условия "Лета"
		printf("summer \n"); 		 //Выводим на экран
	};
	if (MES >= 9 && MES <= 11){					// Проеверям условия "Осени"
		printf("autumn \n"); 		 //Выводим на экран
	};
  
  
    
    return 0;                       // выходим из функции
}                                   // конец функции
