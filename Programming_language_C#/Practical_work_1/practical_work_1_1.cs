using System;

namespace practical_work_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double x, a, c, root_expression, root, denominator, y; // оголошення змінних

            // введення х
            Console.Write("Vvedit x: ");
            x = Convert.ToDouble(Console.ReadLine());

            if (x <= 0) // перевірка на коректність введення
            {
                Console.WriteLine("\nPomylka! Nemozhlyvo znayty ln({0})", x); // виведення повідомлення про помилку
                return;                                                       // завершення програми
            }

            // введення a
            Console.Write("Vvedit a: ");
            a = Convert.ToDouble(Console.ReadLine());

            // введення c
            Console.Write("Vvedit c: ");
            c = Convert.ToDouble(Console.ReadLine());

            root_expression = c * x - a; // обчислення підкореневого виразу

            if (root_expression < 0)     // якщо підкореневий вираз не коректний
            {
                Console.WriteLine("\nPomylka! Pidkorenevyy vyraz vid'yemnyy"); // виведення повідомлення про помилку
                return;                                                        // завершення програми
            }
            else // якщо підкореневий вираз коректний
            {
                root = Math.Pow(root_expression, 1.0 / 3.0); // обчислення значення кореня
            }

            denominator = 2 * Math.Sin(Math.PI / 3 + x); // обчислення знаменника

            if (denominator == 0) // якщо знаменник дорівнює нулю
            {
                Console.WriteLine("\nPomylka! Dilennya na nul"); // виведення повідомлення про помилку
                return;                                          // завершення програми
            }

            y = root + Math.Log(x) / denominator;                 // обчислення у
            Console.WriteLine("\nRezultat obchyslen: {0:F3}", y); // виведення результатів
        }
    }
}
