#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

// структура вузла для ланцюжка
typedef struct NODE
{
    int data; // інформаційне поле
    struct NODE* next; // вказівник на наступний елемент
} NODE;

int hash_fun(int key, int size); // функція для обчислення індексу в масиві
void insert(NODE** hash_table, int size, int key); // функція вставки елемента в геш-таблицю
void delete_key(NODE** hash_table, int size, int key); // функція видалення елемента з геш-таблиці
NODE* search_key(NODE** hash_table, int size, int key); // функція пошуку елементів у геш-таблиці
void print_hash(NODE** hash_table, int size); // виведення геш-таблиці

int main()
{
    srand(time(NULL)); // ініціалізація функції rand значеннями функції time

    // введення номера варіанту
    int variant;
    printf("Vvedit nomer vashoho variantu: ");
    scanf_s("%d", &variant);

    // обчислення кількості елементів та розміру геш-таблиці
    int N = variant * 5 + 50;
    int S = (int)(N * 0.75);

    // виведення результату обчислень
    printf("\nKilkist elementiv N = %d\n", N);
    printf("Rozmir hesh-tablytsi S = %d\n\n", S);

    // динамічне створення геш-таблиці 
    NODE** hash_table = (NODE**)malloc(S * sizeof(NODE*));
    for (int i = 0; i < S; i++) // ініціалізуємо геш-таблицю
    {
        hash_table[i] = NULL;
    }

    // заповнення таблиці випадковими числами
    for (int i = 0; i < N; i++)
    {
        int num = rand() % 1000; // числа від 0 до 99
        insert(hash_table, S, num); // вставка елементів у геш-таблицю
    }

    // виведення сформованої геш-таблиці
    printf("Pochatkova hesh-tablytsya:\n");
    print_hash(hash_table, S);

    // видалення парних чисел з геш-таблиці
    for (int i = 0; i < S; i++)
    {
        NODE* hash_temp = hash_table[i];
        while (hash_temp != NULL) // поки ланцюжок не закінчиться 
        {
            int value = hash_temp->data;
            hash_temp = hash_temp->next; // переходимо далі по ланцюжку
            if (value % 2 == 0) // якщо елемент парний
            {
                NODE* found = search_key(hash_table, S, value);
                if (found != NULL)
                {
                    delete_key(hash_table, S, value);
                }
            }
        }
    }

    // виведення геш-таблиці після видалення парних елементів
    printf("\nHesh-tablytsya pislya vydalennya parnykh chysel:\n");
    print_hash(hash_table, S);

    // звільнення пам’яті
    for (int i = 0; i < S; i++)
    {
        NODE* hash_temp = hash_table[i];
        while (hash_temp != NULL)
        {
            NODE* hash_delete = hash_temp;
            hash_temp = hash_temp->next;
            free(hash_delete);
        }
    }
    free(hash_table);

    return 0;
}

// функція для обчислення індексу в масиві
int hash_fun(int key, int size)
{
    return key % size; // повертає індекс
}

// функція вставки елемента в геш-таблицю
void insert(NODE** hash_table, int size, int key)
{
    int index = hash_fun(key, size); // обчислюємо індекс
    NODE* hash_temp = (NODE*)malloc(sizeof(NODE));
    hash_temp->data = key;
    hash_temp->next = hash_table[index];
    hash_table[index] = hash_temp;
}

// функція видалення елемента з геш-таблиці
void delete_key(NODE** hash_table, int size, int key)
{
    int index = hash_fun(key, size); // обчислюємо індекс
    NODE* hash_temp = hash_table[index]; // тимчасова змінна
    NODE* hash_prev = NULL; // попередня змінна

    while (hash_temp != NULL) // поки лянцюжок не закінчиться
    {
        if (hash_temp->data == key) // якщо шуканий елемент знайдено
        {
            if (hash_prev == NULL) // якщо це перший елемент
            {
                hash_table[index] = hash_temp->next;
            }
            else // якщо це не перший елемент
            {
                hash_prev->next = hash_temp->next;
            }
            free(hash_temp); // звільняємо пам'ять
            return; // завершуємо цикл
        }
        // збільшуємо на 1
        hash_prev = hash_temp;
        hash_temp = hash_temp->next;
    }
}

// функція пошуку елементів у геш-таблиці
NODE* search_key(NODE** hash_table, int size, int key)
{
    int index = hash_fun(key, size); // обчислюємо індекс
    NODE* hash_temp = hash_table[index];
    while (hash_temp != NULL) // поки ланжюжок не закінчиться
    {
        if (hash_temp->data == key) // якщо елемент знайдено
        {
            return hash_temp; // повертаємо знайдений елемент
        }
        hash_temp = hash_temp->next; // переходимо далі по ланжюжку
    }
    return NULL; // якщо елемент не знайдено
}

// виведення геш-таблиці
void print_hash(NODE** hash_table, int size)
{
    for (int i = 0; i < size; i++) // проходимо по всіх елементах геш-таблиці
    {
        printf("%2d element: ", i);
        NODE* hash_temp = hash_table[i];
        while (hash_temp != NULL) // поки ланцюжок не закінчиться
        {
            printf("%d, ", hash_temp->data); // друкуємо елемнт таблиці
            hash_temp = hash_temp->next; // переходимо до наступного ланцюжкового елемента
        }
        printf("- ;\n");
    }
}
