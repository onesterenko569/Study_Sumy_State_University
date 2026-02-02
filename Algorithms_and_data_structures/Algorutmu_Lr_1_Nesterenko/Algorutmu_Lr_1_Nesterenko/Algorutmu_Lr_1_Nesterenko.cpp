#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define SIZE 95 // задання розміру стеку (9*5+50)

struct node // головна структура (прототип)
{
    int data; // оголошення змінної типу int
    struct node* next; // для наступної структури
};
typedef struct node STACK; // переіменовуємо struct node для зручності

// функції які зостосовувались 
int isFull(STACK* TOP); // перевіряє, чи заповнений стек
int isEmpty(STACK* TOP); // перевіряє, чи порожній стек
STACK* push(STACK* TOP, int value); // додає елемент у вершину стека
STACK* pop(STACK* TOP, int* value); // видаляє верхній елемент стека
int size(STACK* TOP); // повертає розмір стека

// функції які не застосовувалися, але наведені в коді, бо так вимагалося в завданні
STACK* top(STACK* TOP); // повертає посилання на самий верхній елемент стека
int peek(STACK* TOP); // одержить верхній елемент стека, не видаляючи його

int main() // головна функція програми
{
    int value; // оголошення змінної 
    STACK* main_stack = NULL; // початковий стек
    STACK* even_stack = NULL; // стек з парними числами
    STACK* odd_stack = NULL; // стек з непарними числами
    
    srand(time(NULL)); // ініціалізація функції rand значенням функції time

    while (!isFull(main_stack)) // заповнюємо початковий стек випадковими числами від 1 до 1000
    {
        int num = rand() % 1000 + 1; // число від 1 до 1000
        main_stack = push(main_stack, num);
    }

    printf("Rozmir pochatkovoho steku = %d", size(main_stack)); // виведення тексту
    printf("\n\nPochatkovyy stek:\n"); // виведення тексту
    while (!isEmpty(main_stack)) // перенесення парних елементів у even_stack, непарних у odd_stack
    {
        main_stack = pop(main_stack, &value); // витягуємо елементи з початкового стеку
        printf("%5d", value); // виведення початкового стеку
        if (value % 2 == 0) // якщо число парне
        {
            even_stack = push(even_stack, value);
        }
        else // число непарне 
        {
            odd_stack = push(odd_stack, value);
        }
    }

    // виводимо стек з парними елементами
    printf("\n\nStek z parnymy chyslamy:\n");
    while (!isEmpty(even_stack))
    {
        even_stack = pop(even_stack, &value);
        printf("%5d", value);
    }
   
    // виводимо стек з непарними елементами
    printf("\n\nStek z neparnymy chyslamy:\n");
    while (!isEmpty(odd_stack))
    {
        odd_stack = pop(odd_stack, &value);
        printf("%5d", value);
    }

    return 0;
}

// описуємо оголошені вище функції

STACK* push(STACK* TOP, int value) // функція для додавання елементів у стек
{
    STACK* p; 
    p = (STACK*)malloc(sizeof(STACK)); 
    if (p == NULL) 
    {
        printf("Problema pry vydilenni pamyati\n"); 
        exit(0); 
    }
    p->data = value; 
    p->next = TOP; 
    TOP = p; 
    return(TOP); 
}

STACK* pop(STACK* TOP, int* value) // функція для витягування даних зі стеку
{
    STACK* p; 
    if (TOP == NULL) 
    {
        printf("Stek pustyy\n"); 
        exit(0); 
    }
    *value = TOP->data; 
    p = TOP; 
    TOP = TOP->next; 
    free(p);
    return(TOP); 
}

int size(STACK* TOP) // функція для повернення розміру стека
{
    int count = 0;
    STACK* p = TOP;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

STACK* top(STACK* TOP) // функція для повернення посилання на верхній елемент стеку
{
    return TOP;
}

int peek(STACK* TOP) // функція для одержання верхнього елемент стека, не видаляючи його
{
    if (TOP == NULL)
    {
        printf("Stek pustyy\n");
        exit(0);
    }
    return TOP->data;
}

int isFull(STACK* TOP) // функція для перевірки чи заповнений стек
{
    return size(TOP) >= SIZE;
}


int isEmpty(STACK* TOP) // функція для перевірки чи порожній стек
{
    return (TOP == NULL);
}