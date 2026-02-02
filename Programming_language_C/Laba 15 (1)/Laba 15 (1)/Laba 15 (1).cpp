#include <stdio.h> // підключення бібліотеки
#define N 2 // визначення константи, що задає розмір масиву
int main() { // головна функція
    int array[N]; // введення розміру масиву  
    printf("Vvedit dva chysla:\n"); // текст для подальшого введення елементів масиву
    for (int i = 0; i < N; i++) { // цикл для введення масиву
        scanf_s("%d", &array[i]);
    }
    if (array[0] > array[1]) // якщо перше число більше другого
    {
        printf("Pershe chyslo bilshe druhoho i = %d\n", array[0]); // виведення значення першого числа
    }
    else // якщо перша умова не задовільняє
    {
        printf("Pershe chyslo: %d\nDruhe chyslo: %d", array[0], array[1]); // виведення першого та другого числа
    }
    return 0;
}

