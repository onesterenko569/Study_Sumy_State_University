#include <stdio.h> // підключення бібліотеки
#define N 8 // визначення константи, що задає розмір масиву
int main() // головна функція
{
    int array[N]; // введення розміру масиву  
    printf("Vvedit chysla:\n"); // текст для подальшого введення елементів масиву
    for (int i = 0; i < N; i++) // цикл для введення масиву
    {
        scanf_s("%d", &array[i]);
    }
    printf("Elementy masyvu v zvorotnomu poryadku:\n"); // виведення тексту
    for (int i = N - 1; i >= 0; i--) // умова циклу
    {
        printf("%d, ", array[i]); // виведення оберненого масиву
    }
    return 0;
}


