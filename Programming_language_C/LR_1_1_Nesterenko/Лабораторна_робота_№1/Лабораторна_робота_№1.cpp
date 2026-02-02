#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define n 10

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int mas[n], i, k, s;  //оголошуємо масив із 10 цілих чисел
    float sa;
    puts("Vvedit elementy masyvu \n"); // запрошення 
    for (i = 0; i < n; i++)
        scanf_s("%i", &mas[i]); // вводимо mas[i]
    k = 0; s = 0; // обнуляємо суму та лічильник 
    for (i = 0; i < n; i++) // у циклі обчислюємо суму та кількість елементів < 0  
        if (mas[i] < 0)
        {
            s += mas[i];
            k++;
        }
    // кінець циклу
        sa = (float)s / k;
        // виводимо результат на екран
        printf("Serednye aryfmetychne vidyemnykh elementiv masyvu % f  \n", sa); 
        printf("Kilkist elementiv < 0 = %i \n", k);
    _getch();
}
