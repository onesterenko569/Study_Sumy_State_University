#define _CRT_SECURE_NO_WARNINGS // вимикає попередження про використання небезпечних функцій у Visual Studio
#include<stdio.h> // підключення бібліотеки
#include<stdlib.h> // підключення бібліотеки
#include<string.h> // підключення бібліотеки
#define N 5 // задання розміру масиву структур

struct wine // оголошення структури
{
	char marka[15]; // оголошення структурних даних
	char rozlyv[15]; // оголошення структурних даних
	float mitsnist; // оголошення структурних даних
	float yemnist; // оголошення структурних даних
	char kolir[15]; // оголошення структурних даних
}x[N]; // створення масиву структур 

int main() // головна функція програми
{
	int lich = 0; // оголошення змінної типу int
	char shokwine[15]; // оголошення змінної типу char
	FILE* p1, * p2; // оголошення змінних типу FILE
	

	p1 = fopen("data.txt", "r"); // відкриття файлу data.txt для читання
	if (p1 == 0) // перевірка чи файл відкрито
	{
		puts("Fayl data.txt ne vidkryvsya"); // виведення повідомлення про помилку
		exit(1); // завершення програми з помилкою
	}
	for (int i = 0; i < N; i++) // цикл для зчитування даних з файлу data.txt
	{
		fscanf_s(p1, "%s", &x[i].marka, 15); // зчитування даних
		fscanf_s(p1, "%s", &x[i].rozlyv, 15); // зчитування даних
		fscanf_s(p1, "%f", &x[i].mitsnist); // зчитування даних
		fscanf_s(p1, "%f", &x[i].yemnist); // зчитування даних
		fscanf_s(p1, "%s", &x[i].kolir, 15); // зчитування даних
	}
	fclose(p1); // закриття файлу

	p2 = fopen("b_data.txt", "wb+"); // відкриття файлу b_data.txt для читання та запису
	if (p2 == 0) // перевірка чи файл відкрито
	{
		puts("Fayl b_data.txt ne vidkryvsya"); // виведення повідомлення про помилку
		exit(1); // завершення програми з помилкою
	}
	fwrite(x, sizeof(struct wine), N, p2); // записуємо в файл b_data.txt дані з файлу data.txt
	rewind(p2); // для переміщення курсору на початок файлу

	for (int i = 0; i < N; i++) // цикл для друку файлу b_data.txt
	{
		fread(&x[i], sizeof(struct wine), 1, p2); // читаємо файл
		printf("\n----------_%d_vyno_----------\n", i + 1); // виведення тексту
		printf("Marka vyna: %s\n", x[i].marka); // виведення даних
		printf("Mistse rozlyvu: %s\n", x[i].rozlyv); // виведення даних
		printf("Mitsnist: %.2f\n", x[i].mitsnist); // виведення даних
		printf("Yemnist plyashky: %.2f\n", x[i].yemnist); // виведення даних
		printf("Kolir: %s\n", x[i].kolir); // виведення даних
	}
	rewind(p2); // для переміщення курсору на початок файлу

	printf("\nVvedit shukanu marku vyna: "); // виведення тексту
	scanf_s("%s", shokwine, 15); // введення шуканої марки вина

	for (int i = 0; i < N; i++) // цикл для пошуку шуканої марки вина та змінення його міцності
	{
		fread(&x[i], sizeof(struct wine), 1, p2); // читаємо файл b_data.txt
		if (strcmp(shokwine, x[i].marka) == 0) // умова пошуку шуканої марки вина
		{
			printf("Zapyshit novu mitsnist (yakshcho stara mitsnist = %.2f): ", x[i].mitsnist); // виведення тексту
			scanf_s("%f", &x[i].mitsnist); // введення нової міцності вина
			fseek(p2, -(long)sizeof(struct wine), 1); // для установки індикатора позиції файлу в необхідному місці
			fwrite(&x[i], sizeof(struct wine), 1, p2); // запис оновлених даних
			lich = 1; // збільшуємо лічильник
			break; // виходимо з циклу
		}
	}
	rewind(p2); // для переміщення курсору на початок файлу

	if (lich == 0) // якщо шуканого вина не знайдено
	{
		puts("\nVyno z danoyu markoyu ne znaydeno"); // виведення тексту
		return 1; // завершення програми з помилкою
	}

	puts("\nOnovlenyy fayl:"); // виведення тексту
	for (int i = 0; i < N; i++) // цикл для виведення оновленого файлу b_data.txt
	{
		fread(&x[i], sizeof(struct wine), 1, p2); // читаємо файл b_data.txt
		printf("\n----------_%d_vyno_----------\n", i + 1); // виведення тексту
		printf("Marka vyna: %s\n", x[i].marka); // виведення даних
		printf("Mistse rozlyvu: %s\n", x[i].rozlyv); // виведення даних
		printf("Mitsnist: %.2f\n", x[i].mitsnist); // виведення даних
		printf("Yemnist plyashky: %.2f\n", x[i].yemnist); // виведення даних
		printf("Kolir: %s\n", x[i].kolir); // виведення даних
	}
	rewind(p2); // для переміщення курсору на початок файлу
	fclose(p2); // закриття файлу
	return 0; // завершення програми
}