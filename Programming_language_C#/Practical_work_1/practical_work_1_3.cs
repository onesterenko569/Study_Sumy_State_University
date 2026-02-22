using System;

namespace practical_work_1_3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double x, xmin, xmax, dx, a, k, y, ax, root_expression, root, denominator; // оголошення змінних

            Console.Write("Vvedit nyzhnyu mezhu xmin: ");
            xmin = Convert.ToDouble(Console.ReadLine());  // введення xmin

            Console.Write("Vvedit verkhnyu mezhu xmax: ");
            xmax = Convert.ToDouble(Console.ReadLine());  // введення xmax

            Console.Write("Vvedit krok dx: ");
            dx = Convert.ToDouble(Console.ReadLine());    // введення dx

            Console.Write("Vvedit a: ");
            a = Convert.ToDouble(Console.ReadLine());     // введення a

            Console.Write("Vvedit k: ");
            k = Convert.ToDouble(Console.ReadLine());     // введення k

            Console.WriteLine();                          // для початку з нового рядка

            for (x = xmin; x <= xmax; x += dx)            // цикл для обрахунку виразу
            {
                ax = a * x;                               // обрахунок ax, оскільки багато де використовується

                if (ax <= 0)                              // якщо значення є не допустимим для ln()
                {
                    Console.WriteLine("Pomylka! Nemozhlyvo znayty ln(a * x) pry x = {0:F2}, a = {1:F3}", x, a); // виведення повідомлення про помилку
                    continue;                                                                                   // перехід до наступної ітерації циклу
                }
                else                                      // якщо значення є допустимим для ln()
                {
                    denominator = Math.Log(ax);           // обраховуємо знаменник
                }

                if (denominator == 0)                     // перевірка чи знаменник є допустимим
                {
                    Console.WriteLine("Pomylka! Dilennya na nul pry x = {0:F2}, a = {1:F3}", x, a); // виведення повідомлення про помилку
                    continue;                                                                       // перехід до наступної ітерації циклу
                }

                root_expression = Math.Cos(ax);           // обчислення підкореневого виразу

                if (root_expression < 0)                  // якщо підкореневий вираз не є коректним
                {
                    Console.WriteLine("Pomylka! Pidkorenevyy vyraz vid'yemnyy pry x = {0:F2} a = {1:F3}", x, a); // виведення повідомлення про помилку
                    continue;                                                                                    // перехід до наступної ітерації циклу
                }
                else                                                   // якщо підкореневий вираз є коректним
                {
                    root = Math.Pow(root_expression, 1.0 / 3.0);       // обраховуємо значення кореня
                }

                y = root + (k * Math.Cos(ax)) / denominator;           // обраховуємо у
                Console.WriteLine("Pry x = {0:F2}\ty = {1:F3}", x, y); // виводимо результат обрахунку
            }
        }
    }
}
