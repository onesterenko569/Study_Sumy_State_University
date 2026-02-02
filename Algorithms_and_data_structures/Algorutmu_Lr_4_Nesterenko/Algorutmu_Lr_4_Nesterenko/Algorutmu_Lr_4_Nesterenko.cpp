#include <stdio.h>
#include <stdlib.h> // підключення необхідних бібліотек
#include <string.h>

typedef struct Node // структура вузла дерева
{
    char key[50];         // ключ (ПІБ студента)
    char phone[20];       // номер телефону
    struct Node* left;    // дитина зліва
    struct Node* right;   // дитина справа
    struct Node* parent;  // батько
} Node;

Node* root = NULL;                     // створюємо корінь, якому надаємо значення NULL

Node* Tree_Search(Node* x, char* k);   // операція пошуку елемента в бінарному дереві       
void Tree_Insert(Node** T, Node* z);   // операція вставки елемента в бінарне дерево
Node* Tree_Min(Node* x);               // пошук мінімального елемента бінарного дерева       
Node* Delete(Node** T, Node* z);       // видалення вузла з бінарного дерева
void output(Node* x);                  // обхід та виведення всіх елементів дерева

int main()
{
    // оголошення необхідних змінних
    int choice;
    char name[50], phone[20];

    printf("\n----- Telefonnyy dovidnyk -----\n"); // виведення тексту

    while (1) // цикл працюватиме, поки користувач не вибере 0
    {
        // виводимо меню 
        printf("\nFunktsiyi korystuvacha:\n");
        printf("1 - dodaty studenta\n");
        printf("2 - znayty studenta\n");
        printf("3 - vydalyty studenta\n");
        printf("4 - vyvesty vsikh studentiv\n");
        printf("0 - vykhid\n");
        printf("Vash vybir: ");
        scanf_s("%d", &choice);
        getchar(); // очищаємо буфер

        if (choice == 1)                   // якщо користувач ввів 1
        {
            printf("Vvedit PIB: ");        // виведення тексту
            fgets(name, 50, stdin);        // введення ПІБ студента
            name[strcspn(name, "\n")] = 0; // видаляє кінцевий "\n"

            printf("Vvedit nomer telefonu: ");  // виведення тексту
            fgets(phone, 20, stdin);            // введення номера телефону студента
            phone[strcspn(phone, "\n")] = 0;    // видаляє кінцевий "\n"

            Node* z = (Node*)malloc(sizeof(Node));         // виділення пам'яті під вузол
            strcpy_s(z->key, sizeof(z->key), name);        // копіюємо ПІБ до вузла
            strcpy_s(z->phone, sizeof(z->phone), phone);   // копіюємо номер телефону до вузла
            z->left = z->right = z->parent = NULL;         // надаємо значень

            Tree_Insert(&root, z);          // вставляємо вузол у дерево            
            printf("Studenta dodano!\n");   // виведення відповідного повідомлення
        }

        else if (choice == 2)                      // якщо користувач ввів 2
        {
            printf("Vvedit PIB dlya poshuku: ");   // виведення тексту
            fgets(name, 50, stdin);                // вводимо шукане ПІБ
            name[strcspn(name, "\n")] = 0;         // видаляє кінцевий "\n"

            Node* r = Tree_Search(root, name);                   // шукаємо шуканого студента
            if (r != NULL)                                       // якщо шуканого студента знайдено
            {
                printf("Znaydeno: %s - %s\n", r->key, r->phone); // виведення відповідного поідомлення
            }
            else                                                 // якщо шуканого студента не знайдено
            {
                printf("Ne znaydeno\n");                         // виведення відповідного поідомлення
            }
        }

        else if (choice == 3)                          // якщо користувач ввів 3
        {
            printf("Vvedit PIB dlya vydalennya: ");    // виведення тексту
            fgets(name, 50, stdin);                    // введення ПІБ шуканого студента
            name[strcspn(name, "\n")] = 0;             // видаляє кінцевий "\n"

            Node* r = Tree_Search(root, name);         // шукаємо студента
            if (r != NULL)                             // якщо студента знайдено
            {
                Node* deleted = Delete(&root, r);      // видаляємо студента
                free(deleted);                         // звільняємо пам'ять
                printf("Vydaleno!\n");                 // виведення відповідного повідомлення
            }
            else                                       // якщо студента не знайдено
            {
                printf("Ne znaydeno\n");               // виведення відповідного повідомлення
            }
        }

        else if (choice == 4)                          // якщо користувач ввів 4
        {
            printf("\n--- Vsi studenty ---\n");        // виведення тексту
            output(root);                              // виведення дерева
        }

        else if (choice == 0)                          // якщо користувач ввів 0
        {
            printf("Do pobachennya!\n");               // виведення тексту        
            break;                                     // завершуємо цикл
        }
    }
    return 0;                                          // завершення програми
}

// операція пошуку елемента в бінарному дереві 
Node* Tree_Search(Node* x, char* k)            // x - вузол (спочатку корінь), k - шуканий елемент
{
    if (x == NULL || strcmp(k, x->key) == 0)   // якщо кореня немає (дійшли до кінця дерева) або шуканий елемент знайдено
    {
        return x;                              // повертаємо вузол
    }

    if (strcmp(k, x->key) < 0)                 // якщо ключ пошуку шуканого елемента менший за поточний ключ
    {
        return Tree_Search(x->left, k);        // знову шукаємо але зі зміщенням ліворуч
    }
    else                                       // якщо ключ пошуку шуканого елемента більший за поточний ключ
    {
        return Tree_Search(x->right, k);       // знову шукаємо але зі зміщенням праворуч
    }
}

// операція вставки елемента в бінарне дерево
void Tree_Insert(Node** T, Node* z)            // T - адреса кореня (** щоб можна було змінювати), z - вузол, який необхідно вставити
{
    Node* y = NULL;                            // майбутній батько z
    Node* x = *T;                              // показує на поточний вузол, з якого починаємо (root дерева)

    while (x != NULL)                          // поки вузол існує, рухаємося нижче
    {
        y = x;                                 // зберігаємо батька
        if (strcmp(z->key, x->key) < 0)        // якщо новий ключ менший за ключ x
        {
            x = x->left;                       // ідемо в ліве піддерево
        }
        else                                   // якщо новий ключ більший за ключ x
        {
            x = x->right;                      // ідемо в праве піддерево
        }
    }

    z->parent = y;                             // встановлюємо батька для нового вузла

    if (y == NULL)                             // якщо дерево пусте
    {
        *T = z;                                // новий вузол z стає коренем дерева
    }
    else if (strcmp(z->key, y->key) < 0)       // якщо ключ менший за ключ батька
    {
        y->left = z;                           // додаємо зліва
    }
    else                                       // якщо ключ більший за ключ батька
    {
        y->right = z;                          // додаємо справа
    }
}

// пошук мінімального елемента бінарного дерева
Node* Tree_Min(Node* x)                        // x - вузол, від якого починається пошук 
{
    while (x->left != NULL)                    // поки існує лівий нащадок 
    {
        x = x->left;                           // рухаємося ліворуч
    }
    return x;                                  // повертаємо мінімальний вузол
}

// видалення вузла з бінарного дерева
Node* Delete(Node** T, Node* z)                // T - адреса кореня (** щоб можна було змінювати), z - вузол, який необхідно видалити
{
    Node* y;                                   // вузол, який буде видалено
    Node* x;                                   // дитина вузла y, яка займе його місце

    if (z->left == NULL || z->right == NULL)   // якщо в z 0 або 1 дитина 
    {
        y = z;                                 // видаляємо сам z
    }
    else                                       // якщо у z 2 нащадки
    {
        y = Tree_Min(z->right);                // шукаємо найменший елемент у правому піддереві
    }

    // визначаємо, хто замінить y
    if (y->left != NULL)                       // якщо у має дитину зліва                
    {
        x = y->left;                           // х буде дитиною зліва
    }
    else                                       // якщо у має дитину справа  
    {
        x = y->right;                          // х буде дитиною справа
    }

    if (x != NULL)                             // якщо x існує
    {
        x->parent = y->parent;                 // прив’язуємо дитину до нового батька  
    }

    if (y->parent == NULL)                     // якщо видаляємо корінь
    {
        *T = x;                                // коренем стає x
    }
    else if (y == y->parent->left)             // якщо y був лівим сином
    {
        y->parent->left = x;                   // підставляємо x на місце y
    }
    else                                       // якщо y був правим сином
    {
        y->parent->right = x;                  // підставляємо x на місце y
    }

    if (y != z)                                // якщо z має двох дітей
    {
        strcpy_s(z->key, sizeof(z->key), y->key);       // копіюємо в вузол z дані з вузла y
        strcpy_s(z->phone, sizeof(z->phone), y->phone); // копіюємо в вузол z дані з вузла y

    }

    return y;                                  // повертаємо видалений вузол
}

// обхід та виведення всіх елементів дерева
void output(Node* x)                           // х - корінь дерева              
{
    if (x != NULL)                             // поки вузол існує
    {
        output(x->left);                       // спочатку виводимо всі елементи, які менші за поточний ключ      
        printf("%s - %s\n", x->key, x->phone); // виведення 
        output(x->right);                      // обходимо праве піддерево
    }
}
