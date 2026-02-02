#include <stdio.h> // підключення бібліотеки
#define N 3 // визначення константи, що задає розмір масиву
int main() { // головна функція
    int array[N]; // введення розміру масиву  
    printf("Vvedit try chysla:\n"); // текст для подальшого введення елементів масиву
    for (int i = 0; i < N; i++) { // цикл для введення масиву
        scanf_s("%d", &array[i]);
    }
    int* ptr = array; // покажчик на початок масиву
    int* min_ptr = ptr; // Покажчик на мінімальний елемент
    for (int i = 0; i < N; i++, ptr++) { // цикл для пошуку мінімального та максимального значень
        if (*ptr < *min_ptr) { // пошук мінімального значення
            min_ptr = ptr; // оновлення покажчика min_ptr
        }
    }
    if (array[0] == array[1] && array[1] == array[2]) // якщо елементи масиву рівні 
    {
        printf("Chysla rivni i = %d\n", array[0]); // вивід значення
    }
    else
    {
        printf("Naymenshe chyslo = %d\n", *min_ptr);  // вивід мінімального значення
    }
    return 0;
}
