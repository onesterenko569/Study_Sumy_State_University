#include<stdio.h> // підключення бібліотек
#include<math.h>
int main() // головна функція програми
{
	double a, b, c, x, F; // задання змінних
	puts("The value of x"); // виведення тексту на екран
	scanf_s("%lf", &x); // надання можливості вписати значення x
	a = 1.5;
	b = 8;
	c = 0.5; 
	if ((x * a) > 0) // перевірка на ОДЗ
	{
		F = ((log(x * a) - 3 * x * tan(b)) / (pow(b, a))) * log(5 * c) + 6; // якщо ОДЗ вірне то вираз обчислиться
		printf("F = %lf\n", F); // виведення значення F
	}
	else { // якщо ОДЗ не задовільняє
		printf("It is impossible to calculate F at:\n"); // виведення тексту на екран про помилку
		printf("x=%lf\n", x); // виведення значення x
	}
	return 0;
}
