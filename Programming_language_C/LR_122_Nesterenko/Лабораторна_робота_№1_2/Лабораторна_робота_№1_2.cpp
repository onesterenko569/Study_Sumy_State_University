#include <stdio.h> // підключення бібліотеки
#include <conio.h> // підключення бібліотеки
#include <Windows.h> // підключення бібліотеки
#include <math.h> // підключення бібліотеки
#define n 10 // задання розміру масива
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int mas[n], x = 2, s = 0, d = 0, max=-100, max_id, sum = 0, dob = 1; // задання змінних типу int
	float g = 0, sa; // задання змінних типу float
	for (int i = 0; i < n; i++) // цикл для заповнення масиву
	{
		puts("Vvedit element masyvu"); // виведення тексту
		scanf_s("%i", &mas[i]); // заповнення масиву
	}
	for (int i = 0; i < n; i++) // цикл для парних чисел
	{
		if (mas[i] % x == 0) // умова парності
		{
			sum += mas[i]; // сума парних чисел
			s++; // кількість парних чисел
		}
	}
	sa = sum / s; // середнє арифметичне
	for (int i = 0; i < n; i++) // цикл для непарних чисел
		{
		if (mas[i] % x != 0) // умова непарності
		{
			dob *= mas[i]; // добуток непарних чисел
			d++; // кількість непарних чисел
			g = pow((float)dob, 1.0 / d); // середнє геометричне
		}
		}
	for (int i = 0; i < n; i++) // цикл для визначення максимального елемента та його порядку
	{
		if (max < mas[i]) // умова для максимального елемента
		{
			max = mas[i]; // максимальний елемент
			max_id = i; // порядок максимального елемента
		}

	}
	printf("Suma parnykh chysel = %d\n", sum); // виведення результату
	printf("Serednye aryfmetychne parnykh chysel = %f\n", sa); // виведення результату
	printf("Dobutok neparnykh chysel = %d\n", dob); // виведення результату
	printf("Serednye heometrychne neparnykh chysel = %f\n", g); // виведення результату
	printf("Maksymalne znachennya = %d\n", max); // виведення результату
	printf("Nomer maksymalnoho znachennya = %d\n", max_id); // виведення результату
	return 0; // завершення програми
}


