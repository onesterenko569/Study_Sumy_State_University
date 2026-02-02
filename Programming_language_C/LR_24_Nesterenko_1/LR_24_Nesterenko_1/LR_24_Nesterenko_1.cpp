#include <stdlib.h>
#include <stdio.h> 
#include <conio.h> 

typedef struct st // оголошення структури struct st
{	
    int info; // оголошення поля для інформації
    struct st* prev; // оголошення поля для наступного елемента
} ELEMENT;


void add(ELEMENT** head, int item); // додавання елементів на початок списку
void add_in(ELEMENT* p, int item); // додавання елемента в середину списка
ELEMENT* find(ELEMENT* head, int item); // пошук шуканого елемента
void print_list(ELEMENT* head); // виведення списку на екран
void lremove(ELEMENT** element, int item); // видалення потрібного елемента (100)
void clear(ELEMENT** head); // очищення пам'яті

int main() // головна функція програми
{
    ELEMENT* head = NULL, * p;
    int i, value, VAL;
    for (i = 0; i < 4; i++) // введення списку
    {
        printf("Vvedite element %d:", i);
        scanf_s("%d", &value);
        add(&head, value);
    }
    puts("*********   search *******");
    printf("input value for serch \n");
    scanf_s("%d", &VAL); // введення шуканого значення
    p = find(head, VAL); // пошук шуканого значення
    if (p == NULL) // перевірка чи знайдено шукане значення
    {
        printf("  is absent  \n");
        _getch();
        return 1;
    }
    else // якщо знайдено
        printf("value find \n");

    puts("***********list after add 100 *********** ");
    add_in(p, 100); // додавання елемента після шуканого значення
    print_list(head); // виведення списку
    puts("*********delete VAL=100 *********");
    lremove(&head, 100); // видалення вписаного елемента 
    print_list(head); // виведення списку
    _getch();
    clear(&head); // очищення пам'яті
    return 0;
}

void add(ELEMENT** head, int item) // додавання елементів на початок списку
{
    ELEMENT* new_item; // оголошення змінної типу ELEMENT*
    new_item = (ELEMENT*)malloc(sizeof(ELEMENT)); // виділення пам'яті
    new_item->info = item; // надання елементу значення item
    new_item->prev = *head; // для new_item->prev наступний елемент буде голова списку
    *head = new_item; // переміщуємо голову списку вище
}

void print_list(ELEMENT* head) // виведення списку на екран
{
    while (head) // поки не дійшли до кінця списку
    {
        printf("%d ", head->info); // виведення елемента списку
        head = head->prev; // переміщення далі по списку
    }
    puts(" "); // для початку з нового рядка
}

ELEMENT* find(ELEMENT* head, int item) // пошук шуканого елемента
{
    while (head) // поки не дійшли до кінця списку
    {
        if (head->info == item) // якщо шуканий елемент знайдено
        {
            return head; // повертаємо список
        }
        head = head->prev; // переміщення далі по списку
    }
    return NULL; // якщо шуканий елемент не знайдено
}

void add_in(ELEMENT* p, int item) // додавання елемента в середину списка
{ 
    ELEMENT* new_item; // оголошення змінної типу ELEMENT*
    new_item = (ELEMENT*)malloc(sizeof(ELEMENT)); // виділення пам'яті
    new_item->info = item; // надання елементу значення item
    new_item->prev = p->prev; // вставлення елемента в список
    p->prev = new_item; // вставлення елемента в список
}

void lremove(ELEMENT** head, int item) // видалення потрібного елемента (100)
{
    ELEMENT* tmp = *head, * element; // оголошення змінних типу ELEMENT*
    element = tmp->prev; // надання списку значення
    if (tmp->info == item) // якщо перший елемент шуканий
    {
        *head = tmp->prev; // прибираємо перший елемент
        free(tmp); // видаляємо перший елемент
        return; // повертаємо оновлений список
    }
    element = tmp->prev; // надання списку значення
    while (element) // поки список не закінчився
    {
        if (element->info == item) // якщо шуканий елемент знайдено
        {
            tmp->prev = element->prev; // видалення шуканого елемента
            free(element); // видалення шуканого елемента
            return; // повернення оновленого списку
        }
        tmp = element; // перехід по списку далі
        element = element->prev; // перехід по списку далі
    }
}

void clear(ELEMENT** head) // очищення пам'яті
{
    ELEMENT* element; // оголошення змінної типу ELEMENT*
    while (*head) // поки не дійшли до кінця списку
    {
        element = *head; // додавання значення списку
        *head = (*head)->prev; // перехід по списку далі
        free(element); // видалення елементів списку
    }
}
