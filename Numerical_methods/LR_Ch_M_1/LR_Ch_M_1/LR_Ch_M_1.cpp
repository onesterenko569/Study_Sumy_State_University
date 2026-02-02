#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// функції 
float calculation_f_x(float x);
float calculation_f_egv(float x);
float calculation_f_prime(float x);

int main()
{
    int choice;

    // вибір метода обчислення
    printf("Vy mayete nastupnyy vyraz: e^(1/(x+2)) - 3x = 0");
    printf("\n\nOberit metod obchyslennya:\n\nVvedit 1, yakshcho obyrayete metod prostykh iteratsiyi\nVvedit 2, yakshcho obyrayete metod Nyutona\n");
    scanf_s("%d", &choice);



    // метод простих ітерацій
    if (choice == 1)
    {
        // оголошення змінних
        float beg, end, step, a, b;
        int size_1;


        // введення необхідних даних
        printf("\n1. Vyznachymo promizhky lokalizatsiyi:\n");
        printf("Vvedit kraynye live ta kraynye prave znachennya promizhku po osi x:\n");
        printf("x pochatkove = ");
        scanf_s("%f", &beg);
        printf("x kintseve = ");
        scanf_s("%f", &end);
        printf("Vvedit krok z yakym maye zminyuvatysya funktsiya: ");
        scanf_s("%f", &step);

        // перевірка вводу
        if (step <= 0)
        {
            printf("\nVy nepravylno vvely krok, sprobuyte znovu\n");
            exit(1);
        }

        size_1 = (int)((end - beg) / step) + 1; // обрахування кількості елементів для масиву f(x)

        // виділення пам'яті для масиву f(x)
        float* f_x = (float*)malloc(size_1 * sizeof(float));

        if (f_x == NULL)
        {
            printf("Pomylka vydilennya pamyati!\n");
            exit(1);
        }

        // обраховуємо f(x)
        printf("\nZnachenya funktsiyi:\n");
        for (int i = 0; i < size_1; i++)
        {
            float x = beg + i * step;

            if ((x + 2) == 0) // перевірка, щоб не було ділення на нуль
            {
                printf("Pry x = %.2f, f(x) ne isnue (dilennya na nul)\n", x);
                exit(1);
            }

            f_x[i] = calculation_f_x(x);
            printf("Pry x = %.2f, f(x) = %.3f\n", x, f_x[i]);
        }

        // знаходимо проміжок на якому функція змінює знак
        for (int i = 0; i < size_1 - 1; i++)
        {
            float t1, t2;

            t1 = f_x[i];
            t2 = f_x[i + 1];

            float x = beg + i * step;

            if ((t1 * t2) < 0)
            {
                a = x;
                b = x + step;
                printf("\nZ znachen funtsiyi f(x) mozhna pobachyty shcho korin rivnyannya lezhyt na promizhku vid %.2f do %.2f\n", x, x + step);
                printf("Todi a = %.2f\n     b = %.2f", a, b);
                break; 
            }
        }
        free(f_x); // звільняємо пам'ять

        // перевірка умови f(a) * f(b) < 0
        printf("\n\n2. Pereviremo umovu  f(a) * f(b) < 0\n\n");

        float audit = calculation_f_x(a) * calculation_f_x(b);

        if (audit < 0)
        {
            printf("f(a) * f(b) = %.3f\n\nPerevirka proydena", audit);
        }
        else
        {
            printf("Perevirka ne proydena, sprobuyte inshyy sposib vyrishennya zadachi");
            exit(1);
        }

        // записуємо еквівалентну функцію
        printf("\n\n3. Zapyshemo ekvivalentnu funktsiyu");
        printf("\n\nEkvivalentna funktsiya: f_egv(x) = e^(1/(x+2)) / 3");

        // перевіряємо достатню умову збіжності
        printf("\n\n4. Perevirymo dostatnyu umovu zbizhnosti |f_egv'(x)| < 1");
        printf("\n\nZnaydemo pokhidnu:\n");
        printf("f_egv'(x) = - (e^(1/(x+2))) / (3 * (x + 2)^2)");

        float tm1 = -(exp(1.0 / (a + 2))) / (3 * pow((a + 2), 2));
        float tm2 = -(exp(1.0 / (b + 2))) / (3 * pow((b + 2), 2));

        // перевірка на збіжність
        if (fabs(tm1) < 1 && fabs(tm2) < 1)
        {
            printf("\n\nf_egv'(a) = %.3f", tm1);
            printf("\nf_egv'(b) = %.3f", tm2);
            printf("\n\nProtses zbizhnyy");
        }
        else
        {
            printf("\nProtses rozbizhnyy");
            exit(1);
        }

        // шукаємо ітерації
        float e, x0 = 0, x1;

        printf("\n\n5. Shukayemo iteratsiyi\n");
        printf("\nVvedit tochnist:\ne = ");
        scanf_s("%f", &e);
        printf("Vvedit znachennya x0 (na vpromizhku vid a do b), z yakoho pochnemo provodyty iteratsiyi: ");
        scanf_s("%f", &x0);
        puts("");

        // проводимо ітерації
        if (x0 >= a && x0 <= b)
        {
            int i = 1;
            do {
                x1 = calculation_f_egv(x0);
                float delta = fabs(x1 - x0);

                printf("x%d = %.3f, delta%d = %.5f\n", i, x1, i, delta);

                if (delta < e)
                {
                    printf("\nVidpovid: x = %.3f z tochniistyu %.3f\nPokhybka = %.5f\nKilkist iteratsiy: %d\n", x1, e, delta, i);
                    break;
                }

                x0 = x1;
                i++;

            } while (1);
        }
        else
        {
            printf("\nVy nepravylno vvely x0");
            exit(1);
        }

        return 0;
    }
 


    // метод Ньютона
    else if (choice == 2)
    {
        // оголошення змінних
        float beg, end, step, a, b;
        int size_1;


        // введення необхідних даних
        printf("\n1. Vyznachymo promizhky lokalizatsiyi:\n");
        printf("Vvedit kraynye live ta kraynye prave znachennya promizhku po osi x:\n");
        printf("x pochatkove = ");
        scanf_s("%f", &beg);
        printf("x kintseve = ");
        scanf_s("%f", &end);
        printf("Vvedit krok z yakym maye zminyuvatysya funktsiya: ");
        scanf_s("%f", &step);

        // перевірка вводу
        if (step <= 0)
        {
            printf("\nVy nepravylno vvely krok, sprobuyte znovu\n");
            exit(1);
        }

        size_1 = (int)((end - beg) / step) + 1; // обрахування кількості елементів для масиву f(x)

        // виділення пам'яті для масиву f(x)
        float* f_x = (float*)malloc(size_1 * sizeof(float));

        if (f_x == NULL)
        {
            printf("Pomylka vydilennya pamyati!\n");
            exit(1);
        }

        // обраховуємо f(x)
        printf("\nZnachenya funktsiyi:\n");
        for (int i = 0; i < size_1; i++)
        {
            float x = beg + i * step;

            if ((x + 2) == 0) // перевірка, щоб не було ділення на нуль
            {
                printf("Pry x = %.2f, f(x) ne isnue (dilennya na nul)\n", x);
                exit(1);
            }

            f_x[i] = calculation_f_x(x);
            printf("Pry x = %.2f, f(x) = %.3f\n", x, f_x[i]);
        }

        // знаходимо проміжок на якому функція змінює знак
        for (int i = 0; i < size_1 - 1; i++)
        {
            float t1, t2;

            t1 = f_x[i];
            t2 = f_x[i + 1];

            float x = beg + i * step;

            if ((t1 * t2) < 0)
            {
                a = x;
                b = x + step;
                printf("\nZ znachen funtsiyi f(x) mozhna pobachyty shcho korin rivnyannya lezhyt na promizhku vid %.2f do %.2f\n", x, x + step);
                printf("Todi a = %.2f\n     b = %.2f", a, b);
                break; // вихід з циклу
            }
        }
        free(f_x); // звільняємо пам'ять

        // перевірка умови f(a) * f(b) < 0
        printf("\n\n2. Pereviremo umovu  f(a) * f(b) < 0\n\n");

        float audit = calculation_f_x(a) * calculation_f_x(b);

        if (audit < 0)
        {
            printf("f(a) * f(b) = %.3f\n\nPerevirka proydena", audit);
        }
        else
        {
            printf("Perevirka ne proydena, sprobuyte inshyy sposib vyrishennya zadachi");
            exit(1);
        }
        // перевіряємо чи перша похідна та друга похідна функції зберігає знак
        printf("\n\n3. Perevirymo chy f1(x) ta f2(x) zberihayut znak na [a; b]");
        printf("\n\nSpochatku znaydemo pershu pokhidnu:\n");
        printf("f'(x) = - e^(1/(x+2)) / (x + 2)^2 - 3");

        float f1_a = -exp(1.0 / (a + 2)) / pow((a + 2), 2) - 3;
        float f1_b = -exp(1.0 / (b + 2)) / pow((b + 2), 2) - 3;

        printf("\n\nf'(a) = %.3f", f1_a);
        printf("\nf'(b) = %.3f", f1_b);

        if ((f1_a > 0 && f1_b > 0) || (f1_a < 0 && f1_b < 0))
        {
            printf("\n\nFunktsiya f'(x) zberihaye znak na [a; b]");
        }
        else
        {
            printf("\n\nFunktsiya f'(x) ne zberihaye znak na [a; b]");
            exit(-1);
        }

        printf("\n\nZnaydemo druhu pokhidnu:\n");
        printf("f''(x) = (2 * e^(1/(x+2))) / (x + 2)^3 + (e^(1/(x+2))) / (x + 2)^4");

        float f2_a = (2 * exp(1.0 / (a + 2))) / pow((a + 2), 3) + (exp(1.0 / (a + 2))) / pow((a + 2), 4);
        float f2_b = (2 * exp(1.0 / (b + 2))) / pow((b + 2), 3) + (exp(1.0 / (b + 2))) / pow((b + 2), 4);

        printf("\n\nf''(a) = %.3f", f2_a);
        printf("\nf''(b) = %.3f", f2_b);

        if ((f2_a > 0 && f2_b > 0) || (f2_a < 0 && f2_b < 0))
        {
            printf("\n\nFunktsiya f''(x) zberihaye znak na [a; b]");
        }
        else
        {
            printf("\n\nFunktsiya f''(x) ne zberihaye znak na [a; b]");
            exit(-1);
        }

        // визначаємо m M
        printf("\n\n4. Vyznachymo m ta M");
        
        float m, M;

        if (fabs(f1_a) > fabs(f1_b))
        {
            m = fabs(f1_b);
        }
        else
        {
            m = fabs(f1_a);
        }

        if (fabs(f2_a) > fabs(f2_b))
        {
            M = fabs(f2_a);
        }
        else
        {
            M = fabs(f2_b);
        }

        printf("\n\nm = %.3f\nM = %.3f", m, M);

        // визначаємо точність обчислень
        printf("\n\n5. Vyznachymo tochnist obchyslen\n\n");

        float e, e0;

        printf("\nVvedit tochnist:\ne = ");
        scanf_s("%f", &e);

        e0 = sqrt(2 * m * e / M);

        printf("e0 = %.3f", e0);

        // визначаємо х0
        printf("\n\n6. Vyznachymo x0 shchob f(x0) * f2(x0) > 0");

        float x0, fx_0;

        printf("\n\nVvedit x0: ");
        scanf_s("%f", &x0);

        fx_0 = calculation_f_x(x0) * ((2 * exp(1.0 / (x0 + 2))) / pow((x0 + 2), 3) + (exp(1.0 / (x0 + 2))) / pow((x0 + 2), 4));

        printf("f(x0) * f2(x0) = %.3f", fx_0);

        if (fx_0 > 0)
        {
            printf("\n\nPerevirka proydena");
        }
        else
        {
            printf("\n\nPomylka, sprobuyte znovu");
            exit(1);
        }

        // обчислюємо ітерації
        printf("\n\n7. Obchyslymo iteratsiyi\n\n");

        float x1, delta;
        int i = 1;

        do 
        {
            x1 = x0 - calculation_f_x(x0) / calculation_f_prime(x0);

            delta = fabs(x1 - x0);

            printf("\nx%d = %.3f\t", i, x1);
            printf("delta%d = %.6f\t", i, delta);

            if ((delta < e0) && (delta < e)) 
            {
                printf("\n\nVidpovid: x = %.3f z tochnistyu e = %.3f ta tochnistyu e0 = %.3f\nPokhybka = %.6f\n", x1, e, e0, delta);
                break;
            }

            x0 = x1;
            i++;

        } while (1);
    }

   

    // якщо неправильний ввід
    else
    {
        printf("\nPomylka pry vvedeni, sprobuyte znovu\n");
        exit(1);
    }
}

// синтаксис функцій
float calculation_f_x(float x)
{
    return exp(1.0 / (x + 2)) - 3 * x;
}

float calculation_f_egv(float x)
{
    return exp(1.0 / (x + 2)) / 3.0;
}

float calculation_f_prime(float x)
{
    return -(exp(1.0 / (x + 2))) / pow((x + 2), 2) - 3;
}

