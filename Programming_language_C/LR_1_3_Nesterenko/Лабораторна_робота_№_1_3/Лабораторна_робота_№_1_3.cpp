#include <stdio.h> // підключення бібліотеки
#include <conio.h> // підключення бібліотеки
#include <Windows.h> // підключення бібліотеки
#include <math.h> // підключення бібліотеки
#define n 10 // задання розміру масива
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int mas[n], min = 100, nul = 0, sum = 0;  // задання змінних типу int
	for (int i = 0; i < n; i++) // цикл для заповнення масиву
	{
		puts("Vvedit element masyvu"); // виведення тексту
		scanf_s("%i", &mas[i]); // заповнення масиву
	}
	for (int i = 0; i < n; i++) // цикл для визначення мінімального елемену масиву по модулю
	{
		if (min > abs(mas[i])) // умова знаходження мінімального елементу
		{
			min = abs(mas[i]); // мінімальний елемент по модулю
			
		}
	}
	for (int i = 0; i < n; i++) // цикл для знаходження елемента який дорівнює нулю
	{
		if (mas[i] == 0) // умова
		{
			nul = i; // порядок елемента який дорівнює нулю
		}
	}
	for (int i = nul + 1; i < n; i++) // цикл для обчислення суми після елемента який дорівнює нулю по модулю
	{
		sum += abs(mas[i]); // сума по модулю
	}
	printf("Minimalnyy za modulem element masyvu = %d\n", min); // виведення результату
	printf("Suma moduliv elementiv masyvu, rozmishchenykh pislya pershoho elementa, shcho dorivnyuye nulyu = %d\n", sum); // виведення результату
	return 0; // завершення програми
}

