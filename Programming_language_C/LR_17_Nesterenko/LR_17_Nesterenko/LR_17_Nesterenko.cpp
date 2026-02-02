#define _CRT_SECURE_NO_WARNINGS // вимикає попередження про використання небезпечних функцій у Visual Studio
#include<stdio.h> // підключення бібліотеки
#include<stdlib.h> // підключення бібліотеки

#define row 3 // задання кількості рядків
#define column 4 // задання кількості стовпців

void open_file(float arr[row][column], int size_row, int size_column) // функція для відкриття файлу vhid.txt та зчитуванню з нього елементів матриці
{
	FILE* p1; // оголшення покажчика типу FILE
	p1 = fopen("vhid.txt", "r"); // відкриття файлу для читання
	if (p1 == 0) // перевірка чи файл був відкритий
	{
		puts("Fayl vhid.txt ne vidkryvsya"); // виведення повідомлення про помилку
		exit(1); // завершення програми
	}
	for (int i = 0; i < size_row; i++) // цикл для зчитування елементів матриці (по рядкам)
	{
		for (int j = 0; j < size_column; j++) // цикл по стовпцям
		{
			fscanf_s(p1, "%f", &arr[i][j]); // зчитування даних
		}
	}
	fclose(p1); // закриття файлу
}

void calculation(float arr[row][column], float result[column][row], float numeric, int size_row, int size_column) // функція для обчислення матриці та її транспонування 
{
	for (int i = 0; i < size_row; i++) // цикл по рядкам
	{
		for (int j = 0; j < size_column; j++) // цикл по стовпцям
		{
			result[j][i] = arr[i][j] - numeric; // обчислення матриці
		}
	}
}

void output_results(float result[column][row], int size_row, int size_column) // функція для виведення результатів
{
	FILE* p2; // оголшення покажчика типу FILE
	p2 = fopen("exit.txt", "w"); // відкриття файлу для запису даних
	if (p2 == 0) // перевірка чи файл був відкритий
	{
		puts("Fayl exit.txt ne vidkryvsya"); // виведення повідомлення про помилку
		exit(1); // завершення програми
	}
	for (int i = 0; i < size_column; i++) // цикл по рядкам
	{
		for (int j = 0; j < size_row; j++) // цикл по стовпцям
		{
			fprintf(p2, "%.1f\t", result[i][j]); // виведення обчисленої матриці в файл exit.txt
		}
		fprintf(p2, "\n"); // для початку з нового рядка
	}
	fclose(p2); // закриття файлу
	printf("Rezultat zapysano u fayl exit.txt\n"); // виведення повідомлення в консоль
}

int main() // головна функція програми
{
	float n, arr[row][column], result[column][row]; // оголошення змінних типу float
	printf("Vvedit bud-yake chyslo: "); // виведення тексту
	scanf_s("%f", &n); // введення числа n
	open_file(arr, row, column); // відкриття файлу vhid.txt та зчитування з нього елементів матриці
	calculation(arr, result, n, row, column); // обчислення матриці та її транспонування 
	output_results(result, row, column); // виведення результатів
	return 0; // завершення програми
}
