#define _CRT_SECURE_NO_WARNINGS // вимикає попередження про використання небезпечних функцій у Visual Studio
#include<stdio.h> // підключення бібліотеки
#include<stdlib.h> // підключення бібліотеки
#include<string.h> // підключення бібліотеки
#define N 8 // задання розміру масиву структур

int main() // головна функція програми
{
	struct wine // оголошення структури
	{
		char marka[15]; // оголошення структурних даних
		char rozlyv[15]; // оголошення структурних даних
		float mitsnist; // оголошення структурних даних
		float yemnist; // оголошення структурних даних
		char kolir[15]; // оголошення структурних даних
	}x[N]; // створення масиву структур 

	int lich = 0; // оголошення змінної типу int
	FILE* p1, * p2; // оголошення змінних типу FILE
	char vvedenna_marka[15]; // оголошення змінної типу char

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

	for (int i = 0; i < N; i++) // цикл для друку зчитаних даних
	{
		printf("\n----------_%d_vyno_----------\n", i + 1); // виведення тексту
		printf("Marka vyna: %s\n", x[i].marka); // виведення даних
		printf("Mistse rozlyvu: %s\n", x[i].rozlyv); // виведення даних
		printf("Mitsnist: %.1f\n", x[i].mitsnist); // виведення даних
		printf("Yemnist plyashky: %.1f\n", x[i].yemnist); // виведення даних
		printf("Kolir: %s\n", x[i].kolir); // виведення даних
	}

	printf("\nVvedit shukanu marku vyna: "); // виведення тексту
	scanf_s("%s", &vvedenna_marka, 15); // введення шуканої марки вина

	p2 = fopen("vihid.txt", "w"); // відкриття файлу для запису
	for (int i = 0; i < N; i++) // цикл для пошуку шуканої марки вина та її запису
	{
		if (strcmp(x[i].marka, vvedenna_marka) == 0) // умова пошуку 
		{
			fprintf(p2, "\n----------_%d_vyno_----------\n", i + 1); // виведення тексту у файл vihid.txt
			fprintf(p2, "Marka vyna: %s\n", x[i].marka); // виведення даних у файл vihid.txt
			fprintf(p2, "Mistse rozlyvu: %s\n", x[i].rozlyv); // виведення даних у файл vihid.txt
			fprintf(p2, "Mitsnist: %.1f\n", x[i].mitsnist); // виведення даних у файл vihid.txt
			fprintf(p2, "Yemnist plyashky: %.1f\n", x[i].yemnist); // виведення даних у файл vihid.txt
			fprintf(p2, "Kolir: %s\n", x[i].kolir); // виведення даних у файл vihid.txt

			printf("\n----------_%d_vyno_----------\n", i + 1); // виведення тексту у консоль
			printf("Marka vyna: %s\n", x[i].marka); // виведення даних у консоль
			printf("Mistse rozlyvu: %s\n", x[i].rozlyv); // виведення даних у консоль
			printf("Mitsnist: %.1f\n", x[i].mitsnist); // виведення даних у консоль
			printf("Yemnist plyashky: %.1f\n", x[i].yemnist); // виведення даних у консоль
			printf("Kolir: %s\n", x[i].kolir); // виведення даних у консоль
			lich = 1; // збільшуємо лічильник
		}
	}
	if (lich != 1) // якщо шуканої марки вина не знайдено
	{
		fprintf(p2, "Vyno z danoyu markoy ne znaydeno\n"); // виведення відповідного повідомлення
		printf("Vyno z danoyu markoy ne znaydeno\n"); // виведення відповідного повідомлення
	}
	fclose(p2); // закриття файлу
	return 0; // завершення програми
}