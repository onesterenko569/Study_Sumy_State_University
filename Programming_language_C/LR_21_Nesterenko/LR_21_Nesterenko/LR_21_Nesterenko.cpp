#include<stdio.h> // підключення бібліотеки
#include<stdlib.h> // підключення бібліотеки

void input(float** array, int size, char c) // функція для введення матриці
{ 
	printf("\nVvedit matrytsyu %c\n", c); // виведення тексту
	for (int i = 0; i < size; i++) // цикл по рядкам
	{
		for (int j = 0; j < size; j++) // цикл по стовпцям
		{
			printf("A[%d][%d] = ", i + 1, j + 1); // виведення тексту
			scanf_s("%f", &array[i][j]); // введення матриці
		}
	}
}

void output(float** array, int size, char c) // функція для виведення матриці
{
	printf("\nVy mayete matrytsyu %c[%d][%d]:\n", c, size, size); // виведення тексту
	for (int i = 0; i < size; i++) // цикл по рядкам
	{
		for (int j = 0; j < size; j++) //  цикл стовпцям
		{
			printf("%.2f\t", array[i][j]); // виведення матриці
		}
		printf("\n"); // для початку з нового рядка
	}
}
	
int main() // головна функція програми
{
	int n, k = 0, lich = 0; // оголошення змінних типу int
	float** A, *B; // оголошення масивів типу float

	printf("Vvedit rozmir kvadratnoyi matrytsi: "); // виведення тексту
	scanf_s("%d", &n); // введення розміру матриці

	A = (float**)malloc(n * sizeof(float*)); // виділення пам’яті для масиву вказівників
	if (A == NULL) // перевірка чи пам'ять була виділена
	{
		printf("\nPomylka pry vydilenni pamyati\n"); // якщо не виділена
		return 1; // завершення програми з помилкою
	}

	for (int i = 0; i < n; i++) // цикл для виділення пам'яті кожному елементу матриці
	{
		A[i] = (float*)malloc(n * sizeof(float)); // виділення пам'яті кожному елементу матриці
		if (A[i] == NULL) // перевірка чи пам'ять була виділена
		{
			printf("\nPomylka pry vydilenni pamyati\n"); // якщо не виділена
			return 1; // завершення програми з помилкою
		}
	}

	input(A, n, 'A'); // введення матриці A
	output(A, n, 'A'); // виведення матриці A

	for (int i = 0; i < n; i++) // цикл для обчислення кількості від'ємних елементів у матриці A
	{
		for (int j = 0; j < n; j++) // цикл по стовпцям
		{
			if (A[i][j] < 0) // якщо елемент матриці від'ємний
			{
				lich++; // збільшуємо лічильник
			}
		}
	}

	B = (float*)calloc(lich, sizeof(float)); // виділення пам'яті для масиву B
	if (B == NULL) // перевірка чи пам'ять була виділена
	{
		printf("\nPomylka pry vydilenni pamyati dlya vektora B\n"); // якщо не виділена
		return 1; // завершення програми з помилкою
	}

	for (int i = 0; i < n; i++) // цикл для формування вектору B з від'ємних елементів матриці A
	{
		for (int j = 0; j < n; j++) // цикл по стовпцям
		{
			if (A[i][j] < 0) // якщо елемент матриці A від'ємний
			{
				B[k++] = A[i][j]; // формуємо вектор B
			}
		}
	}

	printf("\nRozmir vektora B: %d\n", lich); // виведення розміру вектора B

	printf("\nVektor B:\n"); // виведення тексту
	for (int i = 0; i < lich; i++) // виведення сформованого вектора B
	{
		printf("%.2f\t", B[i]); // виведення вектора B
	}

	for (int i = 0; i < n; i++) // цикл для звільнення пам'яті
	{
		free(A[i]);	// звільнення пам'яті
	}
	free(A); // звільнення пам'яті двовимірного масиву 
	free(B); // звільнення пам'яті вектора
	return 0; // завершення програми
}