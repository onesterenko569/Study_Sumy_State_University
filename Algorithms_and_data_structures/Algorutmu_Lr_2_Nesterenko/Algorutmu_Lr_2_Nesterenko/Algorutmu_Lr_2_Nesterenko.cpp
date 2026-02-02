#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>

#define SIZE 95 // розмір черги (9*5+50)

typedef struct st // оголошення структури
{
	int info; // поле для інформації
	struct st* next; // поле для вказування на наступний елемент
}QUEUE; // перейменування struct st на QUEUE

int count = 0; // оголошення лічильника

void enqueue(QUEUE** head, QUEUE** tail, int item); // додати (зберігати) елемент до черги
int dequeue(QUEUE** tail, QUEUE** head); // видалити (одержати доступ) до елемента з черги
int peek(QUEUE* head); // одержує елемент на початку черги, не видаляючи його
int isempty(QUEUE* head); // перевіряє, чи порожня черга
int isfull(); // перевіряє, чи заповнена черга
int isprime(int n); // знаходження простих чисел 
void output(QUEUE* head); // виведення черги без її видалення

int main() // головна функція програми
{
	srand(time(NULL)); // ініціалізація функції rand значеннями функції time

	QUEUE* head = NULL; // оголошення голови черги
	QUEUE* tail = NULL; // оголошення хвоста черги

	// заповнення черги випадковими числами від 1 до 1000
	while (!isfull())
	{
		int num = rand() % 1000 + 1; // генерування числа від 1 до 1000
		enqueue(&head, &tail, num); // додання елемента до черги
	}
	
	// виведення створеної черги
	printf("Pochatkova cherha:\n");
	output(head);

	// знаходження та виведення простих чисел 
	printf("\n\nElementy cherhy, shcho ye prostymy chyslamy:\n");
	while (!isempty(head))
	{
		int value = dequeue(&tail, &head); // витягуємо елемент черги
		
		if (isprime(value)) // чи є елемент простим 
		{
			printf("%d ", value); // друкуємо його
		}
	}

	return 0; 
}

// опис функцій
void enqueue(QUEUE** head, QUEUE** tail, int item) // додати (зберігати) елемент до черги
{
	if (isfull())
	{
		printf("Cherha zapovnena!\n");
		return;
	}
	QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
	q->info = item;
	q->next = NULL;
	if (*tail != NULL)
	{
		(*tail)->next = q;   
	}
	else
	{
		*head = q;           
	}
	*tail = q; 
	count++;
}


int dequeue(QUEUE** tail, QUEUE** head) // видалити (одержати доступ) до елемента з черги
{
	QUEUE* q = *head; 
	int value = q->info; 
	*head = (*head)->next;
	free(q);  
	if (isempty(*head)) 
	{
		*tail = NULL; 
	}
	count--;
	return value; 
}

int peek(QUEUE* head) // одержує елемент на початку черги, не видаляючи його
{
	if (isempty(head))
	{
		printf("Cherha porozhnya!\n");
		exit(1); 
	}
	return head->info;
}

int isempty(QUEUE* head) // перевіряє, чи порожня черга
{
	return (head == NULL);
}

int isfull() // перевіряє, чи заповнена черга
{
	return (count >= SIZE);
}

int isprime(int n) // знаходження простих чисел 
{
	if (n < 2)
	{
		return 0;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void output(QUEUE* head) // виведення черги без її видалення
{
	if (isempty(head))
	{
		printf("Cherha porozhnya!\n");
		return;
	}
	QUEUE* q = head; 
	while (q != NULL)
	{
		printf("%d ", q->info); 
		q = q->next; 
	}
}
