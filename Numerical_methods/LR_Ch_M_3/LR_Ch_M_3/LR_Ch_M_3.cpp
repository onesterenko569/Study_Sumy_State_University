#include <stdio.h>
#include<math.h>

#define MAX_ITER 1000000
#define MAX_SOLUTIONS 100

double grad_Ux(double x, double y, double z) // знаходження градієнта (х)
{
    double f1 = 4 * x - 5 * y * y + z - 3.75;
    double f2 = 3 * x * x + 2 * y - 2 * z - 3;
    double f3 = x + y + 2 * z * z - 3.5;
    return 2 * (f1 * 4 + f2 * 6 * x + f3 * 1);
}

double grad_Uy(double x, double y, double z) // знаходження градієнта (у)
{
    double f1 = 4 * x - 5 * y * y + z - 3.75;
    double f2 = 3 * x * x + 2 * y - 2 * z - 3;
    double f3 = x + y + 2 * z * z - 3.5;
    return 2 * (f1 * (-10 * y) + f2 * 2 + f3 * 1);
}

double grad_Uz(double x, double y, double z) // знаходження градієнта (z)
{
    double f1 = 4 * x - 5 * y * y + z - 3.75;
    double f2 = 3 * x * x + 2 * y - 2 * z - 3;
    double f3 = x + y + 2 * z * z - 3.5;
    return 2 * (f1 * 1 + f2 * (-2) + f3 * (4 * z));
}

int main()
{
    // оголошення змінних
    int iter = 0, decision = 1, decision2 = 1;
    double e, x, y, z, lambda = 0.00001, g_x, g_y, g_z, g_max;

    // масиви для збереження розв’язків
    double solutions_x[MAX_SOLUTIONS];
    double solutions_y[MAX_SOLUTIONS];
    double solutions_z[MAX_SOLUTIONS];
    double solutions_grad[MAX_SOLUTIONS];
    int solutions_iter[MAX_SOLUTIONS];
    int solution_count = 0; // лічильник знайдених розв’язків

    // вивід інформації
    printf("Dano systemu rivnyan:\n");
    printf("\n / 4x - 5y^2 + z = 3.75\n |\n<  3x^2 + 2y - 2z = 3\n |\n \\ x + y + 2z^2 = 3.5");
    printf("\n\nRozv'yazhemo metodom hradiyentnoho spusku\n");

    // поки користувач бажає знаходити розв'язки
    while (decision2 == 1)
    {
        printf("\nVvedit tochnist obchyslen\ne = ");
        while (1) // введення та перевірка введення точності обчислень
        {
            if (scanf_s("%lf", &e) != 1) // введенно не число
            {
                printf("\nDyvys uvazhnishe!\ne = ");
                while (getchar() != '\n');
                continue;
            }

            if (e <= 0.0 || e >= 0.1) // число введенно не вірно
            {
                printf("\nVy znayomi z slovom matematyka?\ne = ");
                continue;
            }
            break;
        }

        // введення початкового наближення та перевірка коректності введень
        printf("\nPryvlasnit x, y, z pochatkovi znachennya vid yakykh budemo provodyty rozrakhunky\nx = ");
        while (scanf_s("%lf", &x) != 1) // введенно не число
        {
            printf("Pomylka! Vvedit chislo dlya x: ");
            while (getchar() != '\n');
        }
        printf("y = ");
        while (scanf_s("%lf", &y) != 1) // введенно не число
        {
            printf("Pomylka! Vvedit chislo dlya y: ");
            while (getchar() != '\n');
        }
        printf("z = ");
        while (scanf_s("%lf", &z) != 1) // введенно не число
        {
            printf("Pomylka! Vvedit chislo dlya z: ");
            while (getchar() != '\n');
        }

        // обнуляємо змінні
        iter = 0;
        decision = 1;

        do // виконуємо поки не досягнемо певного обмеження
        {
            // обчислення градієнту
            g_x = grad_Ux(x, y, z);
            g_y = grad_Uy(x, y, z);
            g_z = grad_Uz(x, y, z);

            // обчислення x, y, z
            x -= lambda * g_x;
            y -= lambda * g_y;
            z -= lambda * g_z;

            // перевірка на переповнення або некоректні значення
            if (isnan(x) || isnan(y) || isnan(z))
            {
                printf("\n\nVynyklalo chyslove perepovnennya abo pomylka obchyslen!\n");
                decision = 2; // щоб зупинити подальші обчислення
                break;
            }

            // обчислення max(|grad_U|)
            g_max = fmax(fmax(fabs(g_x), fabs(g_y)), fabs(g_z));

            // збільшуємо ітерації
            iter++;

            // виводимо кожну тисячну ітерацію
            if (iter % 1000 == 0)
            {
                printf("\nIteratsiya %d: x = %.4lf, y = %.4lf, z = %.4lf, max(|grad_U|) = %.6lf\n", iter, x, y, z, g_max);
            }

            // переірка на потужність
            if (iter == 10000)
            {
                printf("\nDosyahnuto 10000 iteratsiy\nVy vpevneni v potuzhnosti vashoho prystroyu?\n\n");
                printf("1 - tak, ya vpevnenyy v potuzhnosti\n");
                printf("2 - ni, ya ne vpevnenyy\n\n");
                scanf_s("%d", &decision);

                if (decision == 2)
                {
                    break;
                }
            }

        } while (g_max > e && iter < MAX_ITER); // цикл виконується поки здійснюються дані умови

        // виведення повідомлень взалежності від ситуації
        if (g_max < e)
        {
            printf("\nDosyahnuto zadany tochnosti e = %.8lf", e);
        }
        else if (iter >= MAX_ITER)
        {
            printf("\nPerevyshcheno maksymalnu kilkist iteratsiy (%d)\n", MAX_ITER);
            break;
        }

        // якщо користувачем прийнято рішення продовжити розрахунки
        if (decision == 1)
        {
            printf("\n\nRezultat obchyslen:\nIteratsiya: %d\nx = %.3lf\ty = %.3lf\tz = %.3lf\nmax(|grad_U|) = %.8lf\n\n",
                iter, x, y, z, g_max);

            // зберігаємо розв’язок у масив
            if (solution_count < MAX_SOLUTIONS)
            {
                solutions_x[solution_count] = x;
                solutions_y[solution_count] = y;
                solutions_z[solution_count] = z;
                solutions_grad[solution_count] = g_max;
                solutions_iter[solution_count] = iter;
                solution_count++;
            }
        }
        else // прийнято рішення завершти розрахунки
        {
            printf("\nNastupnoho razu poveze\n");
            break;
        }
        // чи бажає користувач знайти ще один розв'язок
        printf("Vy bazhayete znayty shche odyn rozv'yazok?\n\n1 - tak\n2 - ni\n\n");
        scanf_s("%d", &decision2);
    }

    if (solution_count > 0) // після завершення циклу виводимо всі знайдені розв’язки
    {
        printf("\n======================================================================\n");
        printf("                      USI ZNAYDENI ROZV'YAZKY\n");
        printf("======================================================================\n");
        printf("   |      x      |      y     |      z       | max(|grad_U|) | iter\n");
        printf("----------------------------------------------------------------------\n");

        for (int i = 0; i < solution_count; i++)
        {
            printf("%2d | %8.3lf    |  %7.3lf   | %8.3lf     | %13.8lf | %5d\n",
                i + 1, solutions_x[i], solutions_y[i], solutions_z[i],
                solutions_grad[i], solutions_iter[i]);
        }

        printf("======================================================================\n");
    }

    printf("\nDyakuyu za vykorystannya programu!\n");

    return 0;
}
