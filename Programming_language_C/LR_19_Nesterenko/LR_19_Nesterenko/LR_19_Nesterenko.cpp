#define _CRT_SECURE_NO_WARNINGS // вимикає попередження про використання небезпечних функцій у Visual Studio
#include<stdio.h> // підключення бібліотеки
#include<stdlib.h> // підключення бібліотеки
#include<string.h> // підключення бібліотеки

struct employee // оголошення структури
{
	char surname[20]; // оголошення змінної типу char
	char position[20]; // оголошення змінної типу char
	int age; // оголошення змінної типу int
	float salary; // оголошення змінної типу float
};

int main() // головна функція програми
{
	int N, lich = 0; // оголошення змінних типу int
	char shspiv[20]; // оголошення змінної типу char
	FILE* p1; // оголошення покажчика типу FILE
	p1 = fopen("data.txt", "wb+"); // відкриття файлу для читання та запису
	if (p1 == 0) // якщо файл не відкрито
	{
		puts("Fayl data.txt ne vidkryto"); // виведення відповідного повідомлення
		exit(0); // завершення програми з помилкою
	}
	printf("Enter the number of employees: "); // виведення тексту
	scanf_s("%d", &N); // введення кількості робітників
	struct employee* x; // оголошення структури типу struct employee
	x = (struct employee*)malloc(N * sizeof(struct employee)); // виділення пам'яті для структури x

	for (int i = 0; i < N; i++) // цикл для введення структури 
	{
		printf("\n%d spivrobitnyk:\n", i + 1); // виведення тексту
		printf("Vvedit prizvyshche: "); // виведення тексту
		fflush(stdin); // очищення буферу
		scanf_s("%s", x[i].surname, 20); // введення прізвища
		printf("Vvedit posadu: "); // виведення тексту
		fflush(stdin); // очищення буферу
		scanf_s("%s", x[i].position, 20); // введення посади
		printf("Vvedit vik: "); // виведення тексту
		fflush(stdin); // очищення буферу
		scanf_s("%d", &x[i].age); // введення віку
		printf("Vvedit zarplatu: "); // виведення тексту
		fflush(stdin); // очищення буферу
		scanf_s("%f", &x[i].salary); // введення зарплати
		fwrite(&x[i], sizeof(struct employee), 1, p1); // запис інформації до файлу data.txt
	}
	rewind(p1); // для переміщення курсору на початок файлу

	puts("\nDanni shcho vy vvely:"); // виведення тексту
	for (int i = 0; i < N; i++) // цикл для виведення в консоль записаних даних
	{
		fread(&x[i], sizeof(struct employee), 1, p1); // зчитування даних з файлу data.txt
		printf("\n%d spivrobitnyk:\n", i + 1); // виведення тексту
		printf("Prizvyshche: %s\n Posada: %s\n Vik: %d\n Zarplata: %.2f\n", x[i].surname, x[i].position, x[i].age, x[i].salary); // виведення зчитаних даних

	}
	rewind(p1); // для переміщення курсору на початок файлу

	printf("\nVvedit prizvyshche shukanoho spivrobitnyka: "); // виведення тексту
	scanf_s("%s", shspiv, 20); // введення прізвища шуканого співробітника

	for (int i = 0; i < N; i++) // цикл для призначення нової зарплати шуканому співробітнику
	{
		fread(&x[i], sizeof(struct employee), 1, p1); // зчитування даних з файлу
		if (strcmp(shspiv, x[i].surname) == 0) // пошук шуканого співробітника
		{
			printf("Vvedit novu zarplatu: "); // виведення тексту
			scanf_s("%f", &x[i].salary); // введення нової зарплати
			fseek(p1, -(long)sizeof(struct employee), 1); // для установки індикатора позиції файлу в необхідному місці
			fwrite(&x[i], sizeof(struct employee), 1, p1); // запис оновлених даних
			lich = 1; // лічильник збільшуємо
			break; // вихід з циклу
		}
	}
	rewind(p1); // для переміщення курсору на початок файлу

	if (lich == 0) // якщо шуканих співробітників не знайдено
	{
		puts("\nSpivrobitnyka z takym prizvyshchem ne znaydeno"); // виведення тексту
		return 1; // завершення програми з помилкою
	}

	puts("\nOnovlenyy fayl:"); // виведення тексту
	for (int i = 0; i < N; i++) // цикл для виведення оновленого файлу
	{
		fread(&x[i], sizeof(struct employee), 1, p1); // зчитування даних з файлу
		printf("\n%d spivrobitnyk:\n", i + 1); // виведення тексту
		printf("Prizvyshche: %s\n Posada: %s\n Vik: %d\n Zarplata: %.2f\n", x[i].surname, x[i].position, x[i].age, x[i].salary); // виведення оновлених даних

	}
	fclose(p1); // закриття файлу
	return 0; // завершення програми
}