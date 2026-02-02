#include <stdio.h> // підключення бібліотеки
#define N 8 // визначення константи, що задає розмір масиву
int main() { // головна функція
    int array[N]; // введення розміру масиву  
    printf("Vvedit elementy masyvu:\n"); // текст для подальшого введення елементів масиву
    for (int i = 0; i < N; i++) // цикл для введення масиву
    { 
        scanf_s("%d", &array[i]);
    }
    int* ptr = array; // покажчик на початок масиву
    int* min_ptr = ptr; // Покажчик на мінімальний елемент
    int* max_ptr = ptr; // Покажчик на максимальний елемент
    for (int i = 0; i < N; i++, ptr++) { // цикл для пошуку мінімального та максимального значень
        if (*ptr < *min_ptr) { // пошук мінімального значення
            min_ptr = ptr; // оновлення покажчика min_ptr
        }
        if (*ptr > *max_ptr) { // пошук максимального значення
            max_ptr = ptr; // оновлення покажчика max_ptr
        }
    }
    printf("Minimalne znachennya: %d\n", *min_ptr);  // вивід результату
    printf("Maksymalne znachennya: %d\n", *max_ptr); // вивід результату
    return 0;
}


