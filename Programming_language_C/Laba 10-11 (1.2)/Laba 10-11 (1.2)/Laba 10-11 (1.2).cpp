#include<stdio.h> // підключення стандартних бібліотек
#include<math.h>
int main() // головна функція програми
{
	double y, m, k; // задання змінних
	printf("The value of y \n"); // виведення тексту на екран
	scanf_s("%lf", &y); // надання можливості вписати значення y
	printf("The value of m \n"); // виведення тексту на екран
	scanf_s("%lf", &m); // надання можливості вписати значення m
	k = sqrt((pow(sin(m*y), 2) + pow(cos(y/ m), 2) + 0.64) / (log10(fabs(m * y)) + log(fabs(pow(m, 2) - pow(y, 3))) + exp(y - m))); // формула 
	printf("The value of k %lf\n", k); // виведення на екран відповіді
	return 0; // закінчення коду
}
