#include <stdio.h> // підключення бібліотеки
#define N 9 // визначення константи, що задає розмір масиву
int main() { // головна функція
    int array[N]; // введення розміру масиву  
    printf("Enter the elements of the array:\n"); // текст для подальшого введення елементів масиву
    for (int i = 0; i < N; i++) { // цикл для введення масиву
        scanf_s("%d", &array[i]);
    }
    int* ptr = array; // покажчик на початок масиву
    int sum = 0; // введення змінної
    for (int i = 0; i < N; i++) { // цикл для обчислення суми масиву
        sum += *ptr; // формула для обчислення суми масиву
        ptr++; // збільшення на 1
    }
    double average; // введення змінної
    average = (double)sum / N; // формула для середнього арифметичного
    printf("The average value of the given array: %lf\n", average); // виведення результату
    return 0; // завершення програми
}


