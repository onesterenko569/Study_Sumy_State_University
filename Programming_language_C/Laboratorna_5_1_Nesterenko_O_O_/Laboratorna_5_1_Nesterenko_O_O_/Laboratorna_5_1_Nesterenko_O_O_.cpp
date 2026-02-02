#include<stdio.h> // підкючення бібліотеки
int main()
{
	int i, j, m, flag = 0; // введення змінних типу int
	float A[10][10], sum[10] = { 0 }, sum2 = 0; // введення змінних типу float
	puts("Vvedit kilkist ryadkiv ta kilkist stovptsiv kvadratnoyi matrytsi (<10)"); // виведення тексту для розуміння подальших дій користувачу
	scanf_s("%i", &m); // надання можливості користувачу ввести m
	puts("Vvedit matrytsyu"); // виведення тексту
	for (i = 0; i < m; i++) // цикл для введення матриці
	{
		for (j = 0; j < m; j++)
		{ 
			scanf_s("%f", &A[i][j]); // введення матриці
		}
	}
	puts("Zadana matrytsya:"); // виведення тексту
	for (i = 0; i < m; i++) // цикл для виведення матриці
	{
		for (j = 0; j < m; j++)
		{
			printf("%8.2f", A[i][j]); // виведення матриці
		}
		printf("\n"); // для початку з нового рядка
	}
	for (j = 0; j < m; j++) // цикл для знаходження суми елементів кожного стовпця
	{
		for (i = 0; i < m; i++)
		{
			sum[j] += A[i][j]; // знаходження суми 
		}
	}
	puts("Sumy elementiv v kozhnomu stovptsi:"); // виведення тексту
	for (i = 0; i < m; i++) // цикл для виведення суми елементів кожного стовпця
	{
		printf("%8.2f", sum[i]); // виведення масиву (суми елементів стовпців)
	}
	printf("\n"); // для початку з нового рядка
	for (i = 0; i < m; i++) // цикл для знаходження суми головної діагоналі матриці
	{
		for (j = 0; j < m; j++)
		{
			if (i == j) // умова для знаходження елеметів головної діагоналі
			{
				sum2 += A[i][j]; // знаходження суми
			}
		}
	}
	printf("Suma elementiv holovnoyi diahonali = %.2f\n", sum2);
	for (i = 0; i < m; i++) // перевірка на рівність сум елементів кожного стовпця з сумою елементів головної діагоналі
	{
		if (sum[i] != sum2) // умова перевірки
		{
			flag = 1; // позначаємо
		}
	}
	if (flag) // якщо суми різні
	{
		printf("Sumy elementiv v kozhnomu stovptsi ta suma elementiv holovnoyi diahonali rizni\n"); // виведення відповідного результату
	}
	else // якщо суми однакові
	{
		printf("Sumy elementiv v kozhnomu stovptsi dorivnyuyut sumi elementiv holovnoyi diahonali ta = %.2f\n", sum2); // виведення відповідного результату
	}
	return(0); // завершення програми
}
