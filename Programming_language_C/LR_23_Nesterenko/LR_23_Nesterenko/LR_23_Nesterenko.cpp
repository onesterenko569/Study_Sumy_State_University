#include<stdio.h> // підключення бібліотеки
#include<stdlib.h> // підключення бібліотеки

typedef struct st // оголошення структури
{
	int info; // поле для інформації
	struct st* next; // поле для вказування на наступний елемент
}QUEUE; // перейменування struct st на QUEUE

QUEUE* add(QUEUE* tail, int item) // функція для додавання елементів до черги
{
	QUEUE* new_item; // оголошення змінної типу QUEUE
	new_item = (QUEUE*)malloc(sizeof(QUEUE)); // виділення пам'яті
	new_item->info = item; // надаємо значення
	new_item->next = NULL; // наступний елемент порожній
	if (tail != NULL) // якщо tail не пустий
	{
		tail->next = new_item; // для tail наступним елементом буде new_item
	}
	return new_item; // повернення new_item
}

int shift(QUEUE** tail, QUEUE** head) // функція для видалення елементів із черги 
{
	QUEUE* element = *head; // оголошення структури та надання їй значення голови структури 
	int value = element->info; // оголошення змінної та надання їй значення яке будемо видаляти 
	*head = (**head).next; // перехід до наступного елемента черги 
	free(element); // звільняємо пам'ять 
	if (*head == NULL) // якщо дійшли до кінця черги 
	{
		*tail = NULL; // звільняємо пам'ять
	}
	return value; // повертаємо потрібне нам значення 
}

void output_Q(QUEUE* head) // виведення черги
{
	while (head) // поки не дішли до кінця черги
	{
		printf("%d\t", head->info); // виводимо значення 
		head = head->next; // переходимо до наступного елемента черги 
	}
}

int main() // головна функція програми
{
	int N, value, diff, k = 1; // оголошення змінних типу int
	QUEUE* beg_1Q = NULL, * end_1Q = NULL; // оголошення змінних типу QUEUE*
	QUEUE* beg_2Q = NULL, * end_2Q = NULL; // оголошення змінних типу QUEUE*
	QUEUE* beg_3Q = NULL, * end_3Q = NULL; // голошення змінних типу QUEUE*

	printf("Vvedit rozmir dlya dvokh odnakovykh cherh: "); // виведення тексту
	scanf_s("%d", &N); // введення розміру черги 
	if (N < 1) // перевірка на правильність введення розміру черги 
	{
		printf("\nKilkist elementiv cherhy povynna buty bilsha 1\n"); // виведення відповідного повідомлення 
		exit(1); // завершення програми
	}
	
	printf("\nVvedit %d elementiv dlya pershoyi cherhy:\n", N); // виведення тексту
	for (int i = 0; i < N; i++) // цикл для введення першої черги 
	{
		printf("Vvedit %d element cherhy: ", i + 1); // виведення тексту
		scanf_s("%d", &value); // введення елементів черги
		end_1Q = add(end_1Q, value); // додавання введених елементів до черги 
		if (beg_1Q == NULL) // якщо beg_1Q порожній
		{
			beg_1Q = end_1Q; // запам'ятовуємо початок черги
		}
	}

	printf("\nVvedit %d elementiv dlya druhoyi cherhy:\n", N); // виведення тексту
	for (int i = 0; i < N; i++) // цикл для введення другої черги 
	{
		printf("Vvedit %d element cherhy: ", i + 1); // виведення тексту
		scanf_s("%d", &value); // введення елементів черги
		end_2Q = add(end_2Q, value); // додавання введених елементів до черги 
		if (beg_2Q == NULL) // якщо beg_2Q порожній
		{
			beg_2Q = end_2Q; // запам'ятовуємо початок черги
		}
	}

	printf("\nVy mayete pershu cherhu:\n"); // виведення тексту
	output_Q(beg_1Q); // виведення першої черги 
	puts(""); // для початку з нового рядка

	printf("\nVy mayete druhu cherhu:\n"); // виведення тексту
	output_Q(beg_2Q); // виведення другої черги 
	puts(""); // для початку з нового рядка

	while (beg_1Q != NULL && beg_2Q != NULL) // цикл, який відбуватиметься поки ми не дійдемо до кінця першої та другої черги
	{
		diff = shift(&end_1Q, &beg_1Q) - shift(&end_2Q, &beg_2Q); // обчислюємо елемент третьої черги
		end_3Q = add(end_3Q, diff); // додаємо елемент до третьої черги
		if (beg_3Q == NULL) // якщо beg_3Q порожній
		{
			beg_3Q = end_3Q; // запам'ятовуємо початок черги
		}
	}

	printf("\nTretya cherha:\n"); // виведення тексту
	while (beg_3Q) // цикл відбуватиметься поки не дійдемо до кінця третьої черги
	{
		printf("%d element = %d\n", k++, shift(&end_3Q, &beg_3Q)); // виведення третьої черги
	}
	return 0; // завершення програми
}

