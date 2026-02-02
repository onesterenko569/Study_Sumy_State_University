#include<stdio.h> // підключення бібліотеки

float result(float x, float y) // використовуємо функцію
{
	float z; // введення змінної
	if (x <= y) // умова
	{
		z = x * x; // обчислення Z
		return z; // повернення Z
	}
	else // якщо перша умова хибна
	{
		z = y; // обчислення Z
		return z; // повернення Z
	}
}
int main()
{
	int n; // введення змінної типу int
	float a[20], b[20], c[20], * ptr; //  введення змінних типу float
	printf("Vvedit kilkist elementiv masyviv (n < 20)\nn = "); // виведення тексту
	scanf_s("%d", &n); // введення кількості елементів масивів
	puts("Vvedit masyv A:"); // виведення тексту
	for (ptr = a; ptr < a + n; ptr++) // введення масиву a
	{
		printf("A[%d] = ", ptr - a + 1); // виведення тексту
		scanf_s("%f", ptr); // введення елемента масиву
	}
	puts("Vvedit masyv B:"); // виведення тексту
	for (ptr = b; ptr < b + n; ptr++) // введення масиву b
	{
		printf("B[%d] = ", ptr - b + 1); // виведення тексту
		scanf_s("%f", ptr); // введення елемента масиву
	}
	for (int i = 0; i < n; i++) // обрахунок масиву c через функцію
	{
		c[i] = result(a[i], b[i]); // обрахунок масиву
	}
	puts("Sformovanyy masyv C:"); // виведення тексту
	for (ptr = c; ptr < c + n; ptr++) // виведення масиву c
	{
		printf("C[%d] = %.2f\n", ptr - c + 1, *ptr); // виведення масиву c
	}
	return(0); // завершення програми
}