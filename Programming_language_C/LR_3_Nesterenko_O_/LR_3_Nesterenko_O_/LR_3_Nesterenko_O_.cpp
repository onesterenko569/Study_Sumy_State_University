#include <stdio.h> // підключення бібліотеки
#include <conio.h> // підключення бібліотеки
#define N 15 // задання розміру масиву
int main() // головна функція
{
	float X[N] = { 9, 4, 15, 1, 3, 8, 2, 12, 5, 6, 14, 11, 7, 13, 10 }, min, tmp; // задання змінних типу float
	int A = 0, flag, min_index; // задання змінних типу int
	puts("\nMasyv do sortuvannya:"); // виведення тексту
	for (int i = 0; i < N; i++) // цикл для виведення масиву
	{
		printf("%.1f  ", X[i]); // виведення масиву
	}
	puts("\nVvedit znachennya A:"); // виведення тексту
	scanf_s("%d", &A); // введення A
	flag = 0; // присвоєння значення
	for (int i = 0; i < N; i++) // цикл для знаходження елемента масива рівного A
	{
		if (X[i] == A) // умова
		{
			printf("Indeks = %d ", i); // виведення індекса елемента 
			flag = 1; //  присвоєння значення
		}
	}
	if (!flag) // якщо елемент який дорівнює A не знайдено
	{
		puts("U masyvi X nemaye elementiv, shcho dorivnyuyut elementu A"); // виведення тексту
	}
	for (int i = 0; i < N - 1; i++) // цикл для сортування масиву
	{
		min_index = i; // присвоєння значення
		min = X[i]; // присвоєння значення
		for (int j = i; j < N; j++) // цикл для пошуку найменшого елемента
		{
			if (X[j] <= min) // якщо черговий елемент < min
			{
				min_index = j; // запам'ятовуємо його індекс
				min = X[j]; // змінюємо значення min
			}
		}
		tmp = X[i]; // допоміжна змінна для перестановки
		X[i] = X[min_index]; // міняємо місцями елементи
		X[min_index] = tmp; // A[i] та A[min_index]
	}
	puts("\nMasyv X pislya sortuvannya:"); // виведення тексту
	for (int i = 0; i < N; i++)	// виведення відсортованого масиву
	{
		printf("%.1f  ", X[i]); // виведення 
	}
	int left = 0, right = N - 1, middle; // задання змінних типу int
	flag = 0; // обнуляємо
	while (left <= right) // цикл для бінарного пошуку
	{
		middle = (int)((left + right) / 2); // рахуємо середній індекс
		if (X[middle] == A) // якщо середній елемент масиву дорівнює A
		{
			flag = 1; // присвоєння значення
			break; // завершення 
		}
		if (A > X[middle]) // якщо середній елемент масиву менший за A
		{
			left = middle + 1; // рахуємо лівий елемент (лівий край масиву)
		}
		else
		{
			right = middle - 1; // рахуємо правий елемент (правий край масиву)
		}
	}
	if (flag) // якщо елемент який дорівнює A знайдено
	{
		printf("\nIndeks = %d", middle); // виведення його індексу
	}
	else 
	{
		printf("\nU masyvi X nemaye elementiv, shcho dorivnyuyut elementu A"); // якщо елемент який дорівнює A не знайдено
	}
	return(0); // завершення програми
}
