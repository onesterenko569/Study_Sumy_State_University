#include <stdio.h>
#include <stdlib.h> // підключення бібліотек
#include <time.h>

// структура для зберігання даних про сортування
typedef struct
{
    long comp;                // кількість порівнянь
    long assig;               // кількість присвоєнь
    double time;              // тривалість виконання алгоритму в мілісекундах
} STATS;

// функція для обміну двох елементів
void swap(int* a, int* b, STATS* stats)
{
    int temp = *a; 
    *a = *b;                    // міняємо місцями два елемента
    *b = temp;
    stats->assig += 3;          // збільшуємо кількість присвоєнь
}

// функція розділення та перестановки масиву
int partition(int arr[], int low, int high, STATS* stats)
{
    int pivot_index = low + rand() % (high - low + 1);  // генеруємо випадковий опорний елемент (його індекс)
    swap(&arr[pivot_index], &arr[high], stats);         // ставимо згенерований опорний елемент в кінець масиву

    int pivot = arr[high];                              // вибираємо опорний елемент (останній елемент масиву)
    stats->assig++;                                     // збільшуємо кількість присвоєнь
    int i = (low - 1);                                  // показує останній елемент менший за опорний

    for (int j = low; j < high; j++)                    // цикл по елементах підмасиву
    {
        stats->comp++;                                  // збільшуємоо лічильник порівнянь

        if (arr[j] < pivot)                             // якщо елемент менший за опорний
        {
            i++;                                        // просуваємо межу лівих менших елементів.
            swap(&arr[i], &arr[j], stats);              // міняємо місцями arr[i] і arr[j]
        }
    }

    swap(&arr[i + 1], &arr[high], stats);               // переставляємо опорний елемент на правильну позицію

    return (i + 1);                                     // повертаємо індекс опорного елемента
}

// рекурсивна функція швидкого сортування
void quick_sort_recursive(int arr[], int low, int high, STATS* stats)
{
    if (low < high)                                        // перевіряємо чи масив існує
    {
        stats->comp++;                                     // збільшуємоо лічильник порівнянь

        int pi = partition(arr, low, high, stats);         // виконуємо розділення масиву (pi - нова позиція опорного елемента)
        quick_sort_recursive(arr, low, pi - 1, stats);     // рекурсивно сортуємо ліву частину від pi
        quick_sort_recursive(arr, pi + 1, high, stats);    // рекурсивно сортуємо праву частину від pi
    }
    else                                                   // коли low >= high
    {
        stats->comp++;                                     // збільшуємоо лічильник порівнянь
    }
}

// головна функція швидкого сортування
void quick_sort(int arr[], int n, STATS* stats)
{
    stats->comp = 0;                                                     // обнуляємо лічильник порівнянь
    stats->assig = 0;                                                    // обнуляємо лічильник присвоєнь

    clock_t start = clock();                                             // фіксуємо початок вимірювання часу

    quick_sort_recursive(arr, 0, n - 1, stats);                          // виклик основного рекурсивного алгоритму сортування

    clock_t end = clock();                                               // фіксуємо час завершення алгоритму
    stats->time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;    // обраховуємо час та переводимо в мікросекунди
}


// функція для генерації випадкового, зростаючого та спадаючого масиву
void generate_array(int arr[], int n, int type)
{
    if (type == 0)                     // якщо 0 створюємо випадковий масив
    {
        for (int i = 0; i < n; i++)    // цикл для генерації масиву
        {
            arr[i] = rand() % 10000;   // генеруємо випадковий масив від 0 до 9999
        }
    }
    else if (type == 1)                // якщо 1 створюємо зростаючий масив
    {
        for (int i = 0; i < n; i++)    // цикл для генерації масиву
        {
            arr[i] = i;                // генеруємо масив від 0 до n в порядку зростання
        }
    }
    else                               // якщо 2 створюємо спадний масив
    {
        for (int i = 0; i < n; i++)    // цикл для генерації масиву
        {
            arr[i] = n - i;            // генеруємо масив від n до 0 в порядку спадання
        }
    }
}

// функція перевірки правильності сортування масиву
int is_sorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)   // проходимо по елементах масива
    {
        if (arr[i] > arr[i + 1])      // якщо не відсортовано
        {
            return 0;                 // повертаємо 0 - масив не відсортований
        }
    }
    return 1;                         // повертаємо 1 - масив відсортований
}

// головна функція програми
int main()
{
    srand(time(NULL));                                                       // ініціалізація генератора випадкових чисел

    int sizes[] = { 10, 100, 1000, 5000, 10000 };                            // створюємо масив розмірів
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);                        // автоматично визначаємо кількість елементів у масиві sizes[] (20 / 4 = 5)

    const char* types[] = { "Vypadkove", "Zrostannya", "Spadannya" };        // масив назв типів послідовностей

    for (int s = 0; s < num_sizes; s++)                                      // зовнішній цикл по розмірах масиву
    {
        int n = sizes[s];                                                    // поточний розмір масиву для цього тесту
        for (int type = 0; type < 3; type++)                                 // внутрішній цикл по типах послідовності
        {
            int* arr = (int*)malloc(n * sizeof(int));                        // динамічно виділяємо пам’ять для масиву arr з n елементів
            if (!arr)                                                        // якщо пам'ять не виділено
            {
                printf("Pomylka vydilennya pam'yati!\n");                    // виведення відповідного повідомлення
                return 1;                                                    // завершуємо програму
            }

            generate_array(arr, n, type);                                    // генерація масиву потрібного типу
            STATS stats;                                                     // cтворення змінної для статистики
            quick_sort(arr, n, &stats);                                      // сортуємо згенерований масив

            if (!is_sorted(arr, n))                                          // якщо відсортовано не правильно
            {
                printf("Masiv ne vidsortovanui!\n");                         // виведення відповідного повідомлення
            }

            printf("N = %-6d %-10s:       Chas vykonannya - %.0f mks       ",
                n, types[type], stats.time);
            printf("Poryvnyannya - %-8ld       Prysvoyennya - %-8ld\n",      // виведення результатів
                stats.comp, stats.assig);

            free(arr);                                                       // звільняємо пам'ять
        }
        printf("\n");                                                        // відступ
    }

    return 0;                                                                // завершення програми
}
