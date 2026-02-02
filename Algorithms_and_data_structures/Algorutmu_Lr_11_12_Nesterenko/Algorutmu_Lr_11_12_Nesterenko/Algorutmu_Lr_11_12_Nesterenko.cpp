#include <stdio.h>    // підключаємо стандартну бібліотеку вводу/виводу
#include <stdlib.h>   // підключаємо стандартну бібліотеку загального призначення (для malloc, free)
#include <limits.h>   // містить визначення граничних значень типів, потрібна для INT_MAX (нескінченність)
#include <time.h>     // підключаємо бібліотеку для роботи з часом (щоб виміряти швидкість алгоритмів)

#define MAX_V 100     // максимальна кількість вершин (щоб виділити пам'ять із запасом)
#define MAX_E 1000    // максимальна можлива кількість ребер

int V; // глобальна змінна, що зберігатиме реальну кількість вершин, яку введе користувач

// Глобальні лічильники операцій
long long opCountPrim = 0;    // лічильник операцій для алгоритму Прима
long long opCountKruskal = 0; // лічильник операцій для алгоритму Крускала

// --- ЧАСТИНА 1: СТРУКТУРИ ТА ФУНКЦІЇ ДЛЯ АЛГОРИТМУ ПРИМА ---

// оголошуємо структуру для вершини (елемент списку суміжності)
typedef struct Node
{
    int dest;            // індекс вершини, куди веде ребро
    int weight;          // вага цього ребра
    struct Node* next;   // вказівник на наступний вузол у списку (наступного сусіда)
} Node;

Node* adj[MAX_V] = { NULL }; // глобальний масив списків суміжності (спочатку всі пусті - NULL)

// функція додає зв'язок між двома вершинам (додає ребро u -> v та v -> u вагою w)
void addEdge(int u, int v, int w)
{
    // Додаємо пряме ребро u -> v
    Node* newNode = (Node*)malloc(sizeof(Node));    // виділяємо пам'ять під новий вузол
    newNode->dest = v;                              // записуємо, що сусід — це вершина v
    newNode->weight = w;                            // записуємо вагу ребра
    newNode->next = adj[u];                         // старий початок списку стає наступним елементом
    adj[u] = newNode;                               // новий вузол стає початком списку для вершини u

    // Додаємо зворотне ребро v -> u (граф неорієнтований)
    newNode = (Node*)malloc(sizeof(Node));          // знову виділяємо пам'ять
    newNode->dest = u;                              // тепер сусід — це вершина u
    newNode->weight = w;                            // вага та сама
    newNode->next = adj[v];                         // приєднуємо до існуючого списку вершини v
    adj[v] = newNode;                               // оновлюємо початок списку вершини v
}

// структура для вузла мін-купи (зберігає вершину та її поточну "вартість" приєднання)
typedef struct
{
    int vertex;          // номер вершини
    int key;             // мінімальна вага ребра до цієї вершини (ключ)
} HeapNode;

// структура для керування самою купою
typedef struct
{
    int size;            // поточна кількість елементів у купі
    int capacity;        // максимальна місткість купи
    int* pos;            // масив для відстеження позиції вершини всередині купи (щоб швидко знайти її)
    HeapNode** array;    // масив вказівників на вузли купи
} MinHeap;

// створює новий вузол для купи
HeapNode* newHeapNode(int v, int key)
{
    HeapNode* node = (HeapNode*)malloc(sizeof(HeapNode)); // виділяємо пам'ять
    node->vertex = v;                                     // записуємо номер вершини
    node->key = key;                                      // записуємо ключ (вагу)
    return node;                                          // повертаємо створений вузол
}

// створює та ініціалізує мін-купу
MinHeap* createMinHeap(int capacity)
{
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));              // виділяємо пам'ять під структуру купи
    heap->pos = (int*)malloc(capacity * sizeof(int));               // виділяємо пам'ять під масив позицій
    heap->size = 0;                                                 // спочатку купа порожня
    heap->capacity = capacity;                                      // встановлюємо обмеження
    heap->array = (HeapNode**)malloc(capacity * sizeof(HeapNode*)); // виділяємо пам'ять під масив елементів
    return heap;                                                    // повертаємо вказівник на купу
}

// обмінює місцями два вузли купи
void swapHeapNode(HeapNode** a, HeapNode** b)
{
    HeapNode* t = *a;     // тимчасово зберігаємо a
    *a = *b;              // записуємо b в a
    *b = t;               // відновлюємо a в b
    opCountPrim++;        // рахуємо операцію обміну як дію алгоритму
}

// "просіювання вниз" — відновлює властивість мін-купи (батько менший за дітей)
void minHeapify(MinHeap* heap, int idx)
{
    int smallest = idx;             // припускаємо, що поточний елемент найменший
    int left = 2 * idx + 1;         // індекс лівої дитини
    int right = 2 * idx + 2;        // індекс правої дитини

    opCountPrim++; // рахуємо перевірку умови (порівняння)
    if (left < heap->size && heap->array[left]->key < heap->array[smallest]->key)
    {
        smallest = left;            // якщо ліва дитина менша, запам'ятовуємо її індекс
    }

    opCountPrim++; // рахуємо перевірку умови (порівняння)
    if (right < heap->size && heap->array[right]->key < heap->array[smallest]->key)
    {
        smallest = right;           // якщо права дитина ще менша, запам'ятовуємо її
    }

    if (smallest != idx)            // якщо порядок порушено (хтось із дітей менший)
    {
        // оновлюємо позиції вершин у масиві pos
        heap->pos[heap->array[smallest]->vertex] = idx;
        heap->pos[heap->array[idx]->vertex] = smallest;

        // фізично міняємо місцями вузли в купі
        swapHeapNode(&heap->array[smallest], &heap->array[idx]);

        // рекурсивно викликаємо функцію для піддерева, куди ми опустили елемент
        minHeapify(heap, smallest);
    }
}

// витягує елемент з найменшим ключем (корінь купи)
HeapNode* extractMin(MinHeap* heap)
{
    if (heap->size == 0) return NULL; // якщо купа порожня, повертаємо нічого

    HeapNode* root = heap->array[0];                  // зберігаємо корінь (мінімальний елемент)
    HeapNode* lastNode = heap->array[heap->size - 1]; // беремо останній елемент купи

    heap->array[0] = lastNode;                        // ставимо останній елемент на місце кореня
    heap->pos[root->vertex] = heap->size - 1;         // оновлюємо позицію видаленого елемента (формальність)
    heap->pos[lastNode->vertex] = 0;                  // оновлюємо позицію нового кореня

    heap->size--;                                     // зменшуємо розмір купи
    minHeapify(heap, 0);                              // викликаємо просіювання, щоб відновити порядок

    return root;                                      // повертаємо збережений мінімальний вузол
}

// зменшує значення ключа вершини v і піднімає її вгору по купі
void decreaseKey(MinHeap* heap, int v, int key)
{
    int i = heap->pos[v];      // знаходимо поточний індекс вершини v в купі
    heap->array[i]->key = key; // оновлюємо її ключ (вагу)

    // Поки елемент не корінь і він менший за свого батька
    while (i && heap->array[i]->key < heap->array[(i - 1) / 2]->key)
    {
        opCountPrim++; // рахуємо кожну ітерацію циклу (порівняння)

        // оновлюємо позиції в масиві pos
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i;

        // міняємо місцями елемент з батьком
        swapHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);

        // переходимо до батьківського індексу
        i = (i - 1) / 2;
    }
}

// перевіряє, чи знаходиться вершина v в купі (чи вона ще не додана до MST)
int isInMinHeap(MinHeap* heap, int v)
{
    if (heap->pos[v] < heap->size) return 1; // якщо позиція в межах розміру — так
    return 0;                                // інакше — ні
}

// Основна функція алгоритму Прима
void primMST()
{
    int parent[MAX_V]; // масив для зберігання предків (дерева)
    int key[MAX_V];    // масив мінімальних ваг для з'єднання

    MinHeap* heap = createMinHeap(V); // створюємо купу

    // Ініціалізація
    for (int v = 0; v < V; v++)
    {
        parent[v] = -1;                          // спочатку батьків немає
        key[v] = INT_MAX;                        // вага нескінченна
        heap->array[v] = newHeapNode(v, key[v]); // додаємо в купу
        heap->pos[v] = v;                        // записуємо позицію
        opCountPrim++;                           // рахуємо операцію ініціалізації
    }

    key[0] = 0;                  // починаємо з 0-ї вершини
    heap->array[0]->key = 0;     // оновлюємо ключ в купі
    decreaseKey(heap, 0, 0);     // піднімаємо 0-у вершину наверх (хоча вона і так там)

    heap->size = V;              // встановлюємо розмір купи

    // Поки в купі є вершини
    while (heap->size > 0)
    {
        opCountPrim++; // рахуємо ітерацію циклу

        HeapNode* minNode = extractMin(heap); // витягуємо вершину з найменшою вагою
        int u = minNode->vertex;              // отримуємо її номер

        Node* temp = adj[u];                  // беремо список сусідів

        // Проходимо по всіх сусідах
        while (temp != NULL)
        {
            opCountPrim++; // рахуємо операцію перегляду сусіда

            int v = temp->dest; // номер сусіда

            // Якщо сусід ще в купі І знайдено коротший шлях
            if (isInMinHeap(heap, v) && temp->weight < key[v])
            {
                key[v] = temp->weight;        // оновлюємо вагу
                parent[v] = u;                // записуємо батька
                decreaseKey(heap, v, key[v]); // оновлюємо пріоритет в купі
            }
            temp = temp->next; // йдемо до наступного сусіда
        }
    }

    // Виведення результатів Прима
    printf("\n--- Rezultaty PRIMA ---\n");
    int sum = 0;
    for (int i = 1; i < V; i++)
    {
        // Виводимо ребро (додаємо +1 для "людської" нумерації)
        printf("%d - %d (vaha %d)\n", parent[i] + 1, i + 1, key[i]);
        sum += key[i]; // додаємо вагу до загальної суми
    }
    printf("Sumarna vaha (PRIM) = %d\n", sum);
}

// --- ЧАСТИНА 2: АЛГОРИТМ КРУСКАЛА ---

// Структура для зберігання ребра (простий формат для сортування)
typedef struct Edge {
    int src;    // звідки
    int dest;   // куди
    int weight; // вага
} Edge;

Edge allEdges[MAX_E]; // масив всіх ребер графа
int edgeCount = 0;    // кількість введених ребер

// Структура для підмножини (для Disjoint Set Union)
typedef struct Subset {
    int parent; // представник множини
    int rank;   // ранг (висота дерева)
} Subset;

// Функція пошуку представника множини (з компресією шляху)
int find(Subset subsets[], int i) {
    opCountKruskal++; // рахуємо операцію пошуку
    if (subsets[i].parent != i) {
        // рекурсивно шукаємо батька і перепідпорядковуємо вершину напряму йому
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent; // повертаємо корінь множини
}

// Функція об'єднання двох множин
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x); // шукаємо корінь першої множини
    int yroot = find(subsets, y); // шукаємо корінь другої множини

    opCountKruskal++; // рахуємо операцію об'єднання

    // Приєднуємо менше дерево до більшого за рангом
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    }
    else { // якщо ранги рівні
        subsets[yroot].parent = xroot; // робимо x батьком
        subsets[xroot].rank++;         // збільшуємо ранг x
    }
}

// Функція порівняння для qsort (потрібна для сортування ребер)
int myComp(const void* a, const void* b) {
    opCountKruskal++; // рахуємо кожне порівняння як операцію
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight > b1->weight; // повертає результат порівняння
}

// Основна функція алгоритму Крускала
void kruskalMST() {
    Edge result[MAX_V]; // масив для зберігання ребер результату
    int e = 0;          // лічильник доданих ребер
    int i = 0;          // лічильник перевірених ребер

    // Сортуємо всі ребра за вагою (від найменшого)
    qsort(allEdges, edgeCount, sizeof(allEdges[0]), myComp);

    // Виділяємо пам'ять під множини
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));

    // Ініціалізуємо множини: кожен сам собі батько
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
        opCountKruskal++; // рахуємо ініціалізацію
    }

    // Поки не знайдемо V-1 ребер або не переберемо всі
    while (e < V - 1 && i < edgeCount) {
        opCountKruskal++; // рахуємо ітерацію циклу

        Edge next_edge = allEdges[i++]; // беремо наступне найменше ребро

        int x = find(subsets, next_edge.src);  // шукаємо множину початку ребра
        int y = find(subsets, next_edge.dest); // шукаємо множину кінця ребра

        // Якщо вершини з різних множин (не утворюється цикл)
        if (x != y) {
            result[e++] = next_edge; // додаємо ребро в результат
            Union(subsets, x, y);    // об'єднуємо множини
        }
    }

    // Виведення результатів Крускала
    printf("\n--- Rezultaty KRUSKALA ---\n");
    int sum = 0;
    for (i = 0; i < e; ++i) {
        // Виводимо ребро (додаємо +1 для зручності)
        printf("%d - %d (vaha %d)\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
        sum += result[i].weight; // сумуємо вагу
    }
    printf("Sumarna vaha (KRUSKAL) = %d\n", sum);

    free(subsets); // звільняємо пам'ять
}

// --- ГОЛОВНА ФУНКЦІЯ ---

int main()
{
    printf("Vvedit kilkist vershyn u grafi: ");
    if (scanf_s("%d", &V) != 1) return 1; // зчитуємо кількість вершин, якщо помилка — виходимо

    int E_input; // змінна для кількості ребер
    printf("Vvedit kilkist reber: ");
    scanf_s("%d", &E_input); // зчитуємо кількість ребер

    printf("Vvedit rebra u formati: Zvidky Kudy Vaha (napr. 1 2 5)\n");

    // Цикл зчитування всіх ребер
    for (int i = 0; i < E_input; i++) {
        int u, v, w;
        scanf_s("%d %d %d", &u, &v, &w); // зчитуємо дані ребра

        u--; // зменшуємо на 1, щоб перетворити "людську" вершину (напр. 1) в "програмну" (0)
        v--; // зменшуємо на 1, щоб перетворити "людську" вершину (напр. 2) в "програмну" (1)

        addEdge(u, v, w); // додаємо ребро в список суміжності (для Прима)

        // Додаємо ребро в масив (для Крускала)
        allEdges[edgeCount].src = u;
        allEdges[edgeCount].dest = v;
        allEdges[edgeCount].weight = w;
        edgeCount++; // збільшуємо лічильник ребер
    }

    printf("\n--- Poryvnyannya vykonannya ---\n");

    // --- Запуск і заміри Прима ---
    clock_t start_prim = clock(); // засікаємо час початку
    opCountPrim = 0;              // обнуляємо лічильник операцій
    primMST();                    // запускаємо алгоритм
    clock_t end_prim = clock();   // засікаємо час кінця
    // розраховуємо час у секундах
    double time_prim = ((double)(end_prim - start_prim)) / CLOCKS_PER_SEC;

    // --- Запуск і заміри Крускала ---
    clock_t start_kruskal = clock(); // засікаємо час початку
    opCountKruskal = 0;              // обнуляємо лічильник операцій
    kruskalMST();                    // запускаємо алгоритм
    clock_t end_kruskal = clock();   // засікаємо час кінця
    // розраховуємо час у секундах
    double time_kruskal = ((double)(end_kruskal - start_kruskal)) / CLOCKS_PER_SEC;

    // Виведення статистики
    printf("\n--- Statystyka ---\n");
    printf("PRIMA:   Chas = %.6f sek,  Operatsiy = %lld\n", time_prim, opCountPrim);
    printf("KRUSKAL: Chas = %.6f sek,  Operatsiy = %lld\n", time_kruskal, opCountKruskal);

    // Додатковий аналіз ефективності
    if (opCountPrim < opCountKruskal)
        printf("\nVisnovok: Na comu grafi algorytm PRIMA vykonal menshe operatsiy.\n");
    else
        printf("\nVisnovok: Na comu grafi algorytm KRUSKALA vykonal menshe operatsiy.\n");

    return 0; // завершуємо роботу програми
}