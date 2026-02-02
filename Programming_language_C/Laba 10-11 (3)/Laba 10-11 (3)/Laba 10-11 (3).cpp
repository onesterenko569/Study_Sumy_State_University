#include<stdio.h> // підключення бібліотек
#include<math.h>
int main() // головна функція програми
{
	double a, b, c, f, v, F; // задання змінних
	printf("The value of a:\n"); // виведення тексту на екран
	scanf_s("%lf", &a); // надання можливості вписати значення a
	printf("The value of b:\n"); // виведення тексту на екран
	scanf_s("%lf", &b); // надання можливості вписати значення b
	printf("The value of c:\n"); // виведення тексту на екран
	scanf_s("%lf", &c); // надання можливості вписати значення c
	printf("The value of f:\n"); //виведення тексту на екран
	scanf_s("%lf", &f); // надання можливості вписати значення f
	printf("The value of v:\n"); // виведення тексту на екран
	scanf_s("%lf", &v); // надання можливості вписати значення v
	F = exp((log(a) + cos(b)) / (a * c + b)) + 8 * f * v; // вираз для F
	printf("The value of F: %lf\n", F); // вивід значення F
	if (a * c + b == 0) // якщо знаменник = 0 то програма попередить про помилку
	{
		printf("The denominator must not be zero\n", F);
	}
	return 0; // закінчення коду
}