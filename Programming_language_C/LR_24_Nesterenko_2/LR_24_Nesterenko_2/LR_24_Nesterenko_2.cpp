#include<stdio.h> // підключення бібліотеки
#include<stdlib.h> // підключення бібліотеки

typedef struct st // оголошення структури
{
	int info; // оголошення інформативного поля
	struct st* next; // покажчик на наступний елемент
} list; // переіменовуємо

void input(list** beg, int item) // функція для введення списку
{
	list* p; // оголошення покажчика
	p = (list*)malloc(sizeof(list)); // виділення пам'яті
	p->info = item; // надаємо значення
	p->next = *beg; // робимо головою
	*beg = p; // переміщуємо попередню голову
}

void output(list* beg) // функція для виведення списку
{
	while (beg) // поки список не закінчився
	{
		printf("%d\t", beg->info); // виведення елементів списку
		beg = beg->next; // перехід до наступного елемента списку
	}
	puts(""); // для початку з нового рядка
}

list* find(list* beg, int item) // пошук шуканого елемента
{
	while (beg) // поки не дійшли до кінця списку
	{
		if (beg->info == item) // якщо шуканий елемент знайдено
		{
			return beg; // повертаємо список
		}
		beg = beg->next; // переміщення далі по списку
	}
	return NULL; // якщо шуканий елемент не знайдено
}

void add_in(list* p, int item) // додавання елемента в середину списка
{
	list* new_item; // оголошення змінної типу list*
	new_item = (list*)malloc(sizeof(list)); // виділення пам'яті
	new_item->info = item; // надання елементу значення item
	new_item->next = p->next; // вставлення елемента в список
	p->next = new_item; // вставлення елемента в список
}

void clear(list** beg) // очищення пам'яті
{
	list* element; // оголошення змінної типу list*
	while (*beg) // поки не дійшли до кінця списку
	{
		element = *beg; // додавання значення списку
		*beg = (*beg)->next; // перехід по списку далі
		free(element); // видалення елементів списку
	}
}

int main() // головна функція програми
{
	int N, A, lich = 0, value, sum = 0, average; // оголошення змінних типу int
	list* head = NULL; // оголошення змінної типу list*

	printf("Vvedit kilkist elementiv u spysku: "); // виведення тексту
	scanf_s("%d", &N); // введення кількості елементів списку
	if (N < 1) // перевірка на правильність введення розміру списку 
	{
		printf("\nKilkist elementiv spusky povynna buty bilsha 1\n"); // виведення відповідного повідомлення 
		return 1; // завершення програми
	}

	printf("\nVvedit spysok iz %d elementiv:\n", N); // виведення тексту
	for (int i = 0; i < N; i++) // введення списку
	{
		printf("Vvedit %d element: ", i + 1); // виведення тексту
		scanf_s("%d", &value); // введення списку
		input(&head, value); // додавання елеменів до списку
	}

	printf("\nVy mayete spysok iz %d elementiv:\n", N); // виведення тексту
	output(head); // виведення введеного списку

	printf("Vvedit znachennya A: "); // виведення тексту
	scanf_s("%d", &A); // введення А

	list* p = head; // оголошення змінної типу list*
	while (p) // поки список не закінчився
	{
		if (p->info % 3 == 0) // якщо націло ділиться на 3
		{
			sum += p->info; // рахуємо суму
			lich++; // рахуємо кількість елементів
		}
		p = p->next; // переходимо до наступного елемента списку
	}

	if (lich == 0) // якщо лічильник = 0
	{
		printf("\nElementiv shcho dilyatsya na 3 nemaye\n"); // виведення відповідного повідомлення
		return 1; // завершення програми
	}

	average = sum / lich; // підрахунок середнього арифметичного
	printf("\nSerednye arefmytychne = %d\n", average); // виведення середнього арифметичного

	p = find(head, A); // пошук елемента А у списку
	if (p == NULL) // перевірка чи знайдено шукане значення
	{
		printf("\nElement shcho = %d ne znaydeno\n", A); // виведення відповідного повідомлення
		return 1; // завершення програми
	}
	add_in(p, average); // додавання елемента в список
	output(head); // виведення оновленого списку

	clear(&head); // очищення пам'яті
	return 0; // завершення програми
}