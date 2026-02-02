#include <stdio.h>
#include <math.h>

// функція за заданим варіантом
double f(double x)
{
    return 4 - exp(-(pow(x, 2))); // повертає обчислене значення функції
}

// функція для обрахування дельти на першій ітерації
double d1(double x1, double x2, double x3, double f1, double f2, double f3)
{
    return (1.0 / 2.0) * (((x2 * x2 - x3 * x3) * f1 + (x3 * x3 - x1 * x1) * f2 + (x1 * x1 - x2 * x2) * f3) / ((x2 - x3) * f1 + (x3 - x1) * f2 + (x1 - x2) * f3));
}

// функція для обрахування дельти починаючи з другої ітерації
double d2(double x1, double x2, double x3, double f1, double f2, double f3)
{
    return (1.0 / 2.0) * (x1 + x2) + ((0.5 * (f1 - f2) * (x2 - x3) * (x3 - x1)) / ((x2 - x3) * f1 + (x3 - x1) * f2 + (x1 - x2) * f3));
}

// головна функція програми
int main()
{
    double a = 0.0;              // ліва межа заданого інтервалу
    double b = 1.0;              // права межа заданого інтервалу
    double e = 0.001;            // задана точність з якою необхідно обчислити
    double A = (b - a) / 4.0;    // визначаємо початкову точку на інтервалі від a до b
    double H = 0.1;              // визначаємо крок
    double x1, x2, x3;           // оголошуємо змінні, які зберігатимуть значення по х
    double f1, f2, f3;           // оголошуємо змінні, які зберігатимуть значення по у
    double delta;                // змінна для зберігання значення дельти
    double f_delta;              // змінна для зберігання значення функції від дельти
    int iter = 0;                // лічильник ітерацій

    x1 = A;                      // початкова точка
    x2 = A + H;                  // обраховуємо значення другої точки
    // знаходимо значення функції у знайдених точках
    f1 = f(x1);
    f2 = f(x2);

    if (f1 < f2)                 // якщо значення функції в першій точці менше за значення функції в другій
    {
        x3 = A - H;              // знаходимо значення точки х3 за правилом
    }
    else                         // якщо значення функції в другій точці менше за значення функції в першій
    {
        x3 = A + 2 * H;          // знаходимо значення точки х3 за правилом
    }

    f3 = f(x3);                  // знаходимо значення функції у знайденій точці

    // виведення обрахованих даних
    printf("Zadana funktsiya: y = 4 - e^(-(x^2))");
    printf("\nInterval funktsiyi: [%.0lf; %.0lf]\n", a, b);
    printf("\nA = %.3lf\nH = %.3lf\n", A, H);

    while (1) // цикл для обрахунку точки мінімуму з заданою точністю
    {
        iter++;                     // збільшуємо кількість ітерацій

        // обраховуємо значення дельти
        if (iter == 1) // якщо перша ітерація
        {
            delta = d1(x1, x2, x3, f1, f2, f3);
        }
        else // починаючи з другої ітерації
        {
            delta = d2(x1, x2, x3, f1, f2, f3);
        }

        f_delta = f(delta); // обраховуємо значення функції в знайденій дельті

        // виведення результатів
        printf("\nIteratsiya %d:\n\n", iter);
        printf("   x1 = %.4lf\n   f(%.4lf) = %.4lf\n", x1, x1, f1);
        printf("\n   x2 = %.4lf\n   f(%.4lf) = %.4lf\n", x2, x2, f2);
        printf("\n   x3 = %.4lf\n   f(%.4lf) = %.4lf\n", x3, x3, f3);
        printf("\n   delta = %.4lf\n   f(%.4lf) = %.4lf\n", delta, delta, f_delta);

        // визначення мінімального значення функції
        double fmin = f1;
        if (f2 < fmin)
        {
            fmin = f2;
        }
        if (f3 < fmin)
        {
            fmin = f3;
        }

        // визначення максимального значення функції
        double fmax = f1;
        if (f2 > fmax)
        {
            fmax = f2;
        }
        if (f3 > fmax)
        {
            fmax = f3;
        }
        if (f_delta > fmax)
        {
            fmax = f_delta;
        }

        if (fabs(fmin - f_delta) <= e) // умова зупинки циклу
        {
            break;                     // зупиняємо цикл
        }

        // відкидання гіршої точки та підготовка до наступної ітерації
        if (f1 == fmax)
        {
            printf("\n   Vidkydayemo tochku x1 = %.4lf\n", x1);
            x1 = delta;
            f1 = f_delta;
        }
        else if (f2 == fmax)
        {
            printf("\n   Vidkydayemo tochku x2 = %.4lf\n", x2);
            x2 = delta;
            f2 = f_delta;
        }
        else
        {
            printf("\n   Vidkydayemo tochku x3 = %.4lf\n", x3);
            x3 = delta;
            f3 = f_delta;
        }
    }

    // виведення остаточних результатів
    printf("\n_______Rezultat_______\n");
    printf("Tochka minimumu x = %.4lf\n", delta);
    printf("Minimalne znachennya f(%.4lf) = %.4lf\n", delta, f(delta));
    printf("Tochnist rozrakhunkiv: %.3lf\n", e);
    printf("Kilkist iteratsiy: %d\n", iter);

    return 0;
}
