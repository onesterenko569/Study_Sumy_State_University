// підключення необхідних бібліотек 
#include <stdio.h>
#include <stdlib.h>

int main() // головна функція програми
{
    int N; // змінна, яка зберігає кількість точок

    // введення кількості точок
    printf("Vvedit kilkist tochok: ");
    scanf_s("%d", &N);
    while (N < 2) // якщо кількість точок введена невірно
    {
        printf("\nPomylka! K-ct tochok povynna buty >= 2. Sprobuyte znovu\nN = ");
        scanf_s("%d", &N); // повторне введення
    }

    // виділення пам'яті для масиву координат х
    double* arr_x = (double*)malloc(N * sizeof(double));
    if (arr_x == NULL) // якщо виникла помилка при виділенні пам'яті
    {
        printf("\nPomylka vydilennya pam'yati!\n");
        return 1;
    }

    // виділення пам'яті для масиву координат у
    double* arr_y = (double*)malloc(N * sizeof(double));
    if (arr_y == NULL) // якщо виникла помилка при виділенні пам'яті
    {
        printf("\nPomylka vydilennya pam'yati!\n");
        free(arr_x);
        return 1;
    }

    // введення координат точок (х, у)
    printf("\nVvedit koordynaty %d tochok:\n", N);
    for (int i = 0; i < N; i++)
    {
        printf("\n%d tochka:\nx = ", i + 1);
        scanf_s("%lf", &arr_x[i]); // вводимо х
        printf("y = ");
        scanf_s("%lf", &arr_y[i]); // вводимо у
    }

    // введення значення х для якого шукаємо у
    double x;
    printf("\nVvedit znachennya x dlya yakogo potribno znayty y: ");
    scanf_s("%lf", &x);

    double result = 0.0; // змінна, яка зберігатиме результат обчислень

    // обраховуємо у
    for (int i = 0; i < N; i++) // зовнішній цикл
    {
        double current = arr_y[i]; // змінна, яка зберігатиме значення дробу
        for (int j = 0; j < N; j++) // внутрішній цикл
        {
            if (j != i) // обраховуємо, коли i та j різні
            {
                current *= (x - arr_x[j]) / (arr_x[i] - arr_x[j]); // обраховуємо дріб окремо
            }
        }
        result += current; // результат (сума дробів)
    }

    printf("\nU tochci x = %.3lf znachenya funkciyi y = %.3lf\n", x, result); // виведення результатів

    // звільнення пам'яті
    free(arr_x);
    free(arr_y);

    return 0;
}
