#include<stdio.h> // підключення бібліотеки
#define size 50 // задання розміру масиву
struct student // використання структури 
{
    char prizvyshche[size]; // поле для прізвища
    char hrupa[size]; // поле для групи
    float stypendiya; // поле для стипендії
    float seredniybal; // поле для середнього балу
};
int main()
{
    int n;
    printf("Vvedit kilkist studentiv\nKilkist studentiv = "); // виведення тексту для розуміння дій користувачу
    scanf_s("%d", &n); // введення кількості студентів
    struct student x[size], * p = x; // оголошення змінних
    for (p = x; p < x + n; p++) // цикл для введення даних у поля структури
    {
        printf("\n-------Zapovnit informatsiyu pro %d studenta-------", p - x + 1); // виведення тексту
        printf("\nVvedit prizvyshche studenta: "); // виведення тексту
        scanf_s(" %[^\n]", p->prizvyshche, size); // введення прізвища
        printf("Vvedit hrupu studenta: "); // виведення тексту
        scanf_s(" %[^\n]", p->hrupa, size); // введення групи
        printf("Vvedit seredniy bal studenta: "); // виведення тексту
        scanf_s(" %f", &p->seredniybal); // введення середнього балу
    }
    for (p = x; p < x + n; p++) // цикл для обрахунку стипендії
    {
        if (p->seredniybal < 3) // якщо середній бал менше 3
        {
            p->stypendiya = 0; // стипендія = 0
        }
        else if (p->seredniybal < 4) // якщо середній бал менше 4
        {
            p->stypendiya = 400; // стипендія = 400
        }
        else if (p->seredniybal < 5) // якщо середній бал менше 5
        {
            p->stypendiya = 500; // стипендія = 500
        }
        else // якщо середній бал = 5
        { 
            p->stypendiya = 600; // стипендія = 600
        }
    }
    for (p = x; p < x + n; p++) // цикл для виведення результатів обчислень
    {
        printf("\n-------Informatsiya pro %d studenta-------\n", p - x + 1); // виведення тексту
        printf("Prizvyshche: %s\nHrupa: %s\nStypendiya: %.2f\n", p->prizvyshche, p->hrupa, p->stypendiya); // виведення результату
    }
    return(0); // завершення програми
}