#include<stdio.h> // підключення бібліотеки
int main() // головна функція програми
{
	int x = 1, y = 1, kratne; // задання змінних
	printf("Enter the starting value of the range\n"); // виведення тексту
	scanf_s("%d", &x); // надання можливості вписати x
	printf("Enter the end value of the range\n"); // виведення тексту
	scanf_s("%d", &y); // надання можливості вписати y
	printf("Multiples of 3 from %d to %d:\n", x, y); // виведення тексту
		for (int kratne = x; kratne <= y; kratne++) // введення циклу
		{
			if (kratne % 3 == 0) // ввдення умови
			{
				printf("%d ", kratne); // виведення тексту
			}
		}
		return 0; // завершення програми
}
