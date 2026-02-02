#include<stdio.h> // підключення стандартних бібліотек
#include<math.h>
int main() // головна функція програми
{
	double c, x, S; // задання змінних
	printf("The value of c \n"); // вивід тексту на екран
	scanf_s("%lf", &c); // надання можливості вписати значення c
	printf("The value of x \n"); // вивід тексту на екран
	scanf_s("%lf", &x); // надання можливості вписати значення x
	S = log(c), ((c * exp(-2.5 * c + x) + pow(atan(fabs(c - x)), 2)) / fabs(pow(-1, -2.5 * c) + sqrt(fabs(log(fabs(x)) + log10(fabs(c)))))); // формула  
	printf("The value of S %lf\n", S); // виведення на екран відповіді
	return 0;
}