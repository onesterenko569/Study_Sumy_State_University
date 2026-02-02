#include <stdio.h> // підключення бібліотеки
#include <limits.h> // бібліотека для INT_MAX та INT_MIN
#define P 9 // визначення константи, що задає розмір масиву
int main() { // головна функція
    int array[P]; // введення розміру масиву  
    printf("Enter the elements of the array:\n"); // текст для подальшого введення елементів масиву
    for (int i = 0; i < P; i++) { // цикл для введення масиву
        scanf_s("%d", &array[i]);
    }
    int *ptr = array; // покажчик на початок масиву
    int *min_ptr = ptr; // Покажчик на мінімальний елемент
    int *max_ptr = ptr; // Покажчик на максимальний елемент
    for (int i = 0; i < P; i++, ptr++) { // цикл для пошуку мінімального та максимального значень
        if (*ptr < *min_ptr) { // пошук мінімального значення
            min_ptr = ptr; // оновлення покажчика min_ptr
        }
        if (*ptr > *max_ptr) { // пошук максимального значення
            max_ptr = ptr; // оновлення покажчика max_ptr
        }
    }
    int distance = max_ptr > min_ptr ? (max_ptr - min_ptr) : (min_ptr - max_ptr); // відстань між мінімальним і максимальним
    printf("Minimum value: %d\n", *min_ptr);  // вивід результату
    printf("Maximum value: %d\n", *max_ptr); // вивід результату
    printf("The distance between the minimum and maximum elements: %d\n", distance); // вивід результату
    return 0;
}

