#include<stdio.h> // підключення бібліотеки
#include<stdlib.h>// підключення бібліотеки

int* memory_allocation(int size) // функція для виділення пам'яті масивам
{
	int* K; // оголошення покажчика типу int
	K = (int*)calloc(size, sizeof(int)); // виділення пам'яті
	if (!K) // перевірка чи пам'ять була виділена
	{
		puts("ERROR"); // виведення повідомлення про помилку
		exit(1); // завершення програми з помилкою
	}
	return K; // повернення K
}

void input(int* arr, int size, char c) // функція для введення масивів
{
	printf("\nVvedit elementy dlya masyvu %c[%d]:\n", c, size); // виведення тексту
	for (int i = 0; i < size; i++) // цикл для введення масивів
	{
		printf("%c[%d] = ", c, i + 1); // виведення тексту
		scanf_s("%d", arr + i); // введення елементів масивів
	}
}

void output(int* arr, int size, char c) // функція для виведення масивів
{
	printf("\nMasyv %c:\n", c); // виведення тексту
	for (int i = 0; i < size; i++) // цикл для виведення масивів
	{
		printf("%d\t", *(arr + i)); // виведення масивів
	}
	printf("\n"); // для початку з нового рядка
}

int finding_multiples(int* arr, int size, char c) // функція для підрахування в масивах кількості елементів, кратних двом 
{
	int lich = 0; // оголошення змінної типу int
	for (int i = 0; i < size; i++) // цикл для пошуку елементів кратних двом
	{
		if (*(arr + i) % 2 == 0) // умова пошуку
		{
			lich++; // збільшуємо лічильник
		}
	}
	if (lich == 0) // якщо елементів кратних двом не знайдено
	{
		printf("\nU masyvi %c nemaye elementiv kratnykh 2\n", c); // виведення відповідного повідомлення
		return 0; // повернення 0
	}
	else // якщо елементи кратні двом знайдені
	{
		return lich; // повертаємо кількість елементів кратних двом
	}
}

int main() // головна функція програми
{
	int* A, * B, N, lA, lB; // оголошення змінних типу int

	printf("Vvedit kilkist elementiv masyviv A[N], B[N]: "); // виведення тексту
	scanf_s("%d", &N); // введення кількості елементів для масивів

	A = memory_allocation(N); // виділення пам'яті для масиву A
	B = memory_allocation(N); // виділення пам'яті для масиву B

	input(A, N, 'A'); // введення масиву A
	input(B, N, 'B'); // введення масиву B

	output(A, N, 'A'); // виведення масиву A
	output(B, N, 'B'); // виведення масиву B

	lA = finding_multiples(A, N, 'A'); // підрахування кількості елементів кратних двом у масиві A
	lB = finding_multiples(B, N, 'B'); // підрахування кількості елементів кратних двом у масиві B

	printf("\nKilkist elementiv kratnykh dvom:\n"); // виведення тексту
	printf("A: %d\n", lA); // виведення кількості кратних елементів двом у масиві A
	printf("B: %d\n", lB); // виведення кількості кратних елементів двом у масиві B

	printf("\nPershym vyvodytsia masyv z bilshoyu kilkistiu kratnykh elementiv dvom:\n"); // виведення тексту

	if (lA > lB) // якщо у масиві A більше елементів кратних двом
	{
		output(A, N, 'A'); // виведення масиву A
		output(B, N, 'B'); // виведення масиву B
	}
	else if (lB > lA) // якщо у масиві B більше елементів кратних двом
	{
		output(B, N, 'B'); // виведення масиву B
		output(A, N, 'A'); // виведення масиву A
	}
	else // якщо кількість елементів кратних двом однакова
	{
		printf("\nU masyvi A[%d] i B[%d] kilkist elementiv kratnykh dvom odnakova = %d\n", N, N, lA); // виведення відповідного повідомлення
		output(A, N, 'A'); // виведення масиву A
		output(B, N, 'B'); // виведення масиву B
	}

	free(A); // звільняє пам'ять для масиву A
	free(B); // звільняє пам'ять для масиву B

	return 0; // завершення програми
}