using System;

namespace practical_work_2_4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            // ініціалізація змінних
            string variant;
            double x, a, z, expression;

            // введення х
            Console.Write("Введіть x: ");
            x = Convert.ToDouble(Console.ReadLine());

            // введення a
            Console.Write("Введіть a: ");
            a = Convert.ToDouble(Console.ReadLine());

            // введення варіанту
            Console.Write("Введіть варіант (1, alfa / 2, beta / 3, gamma): ");
            variant = Console.ReadLine();

            switch (variant)                                // початок оператора множинного вибору switch, який аналізує значення змінної variant
            {
                case "1":                                   // якщо введенно 1
                case "alfa":                                // якщо введенно alfa

                    expression = a + Math.Sin(x);           // обрахунок підкореневого виразу

                    if (expression < 0)                     // якщо обчислити корінь неможливо
                    {
                        Console.WriteLine("\nПомилка! Підкореневий вираз від'ємний");
                    }
                    else                                    // якщо обчислити корінь можливо
                    {
                        z = Math.Sqrt(expression);          // обчислення виразу
                        Console.WriteLine("\nz = {0}", z);  // виведення результатів
                    }

                    break;                                  // завершення виконання поточної гілки

                case "2":                                   // якщо введенно 2
                case "beta":                                // якщо введенно beta

                    expression = Math.Sin(a * x);           // обрахунок підкореневого виразу

                    if (expression < 0)                     // якщо обчислити корінь неможливо
                    {
                        Console.WriteLine("\nПомилка! Підкореневий вираз від'ємний");
                    }
                    else                                    // якщо обчислити корінь можливо
                    {
                        z = Math.Sqrt(expression);          // обчислення виразу
                        Console.WriteLine("\nz = {0}", z);  // виведення результатів
                    }

                    break;                                  // завершення виконання поточної гілки

                case "3":                                   // якщо введенно 3
                case "gamma":                               // якщо введенно gamma

                    expression = a - x;                     // обчислення логарифмічного виразу

                    if (expression <= 0)                    // якщо натуральний логарифм обчислити неможливо
                    {
                        Console.WriteLine("\nПомилка! Неможливо знайти ln({0})", expression);
                    }
                    else                                    // якщо натуральний логарифм обчислити можливо
                    {
                        z = Math.Log(expression);           // обрахування виразу
                        Console.WriteLine("\nz = {0}", z);  // виведення результатів
                    }

                    break;                                  // завершення виконання поточної гілки

                default:                                    // якщо введене значення не збіглося з жодним із варіантів case вище

                    Console.WriteLine("\nВи ввели не правильний варіант!");
                    break;                                  // завершення виконання поточної гілки
            }
        }
    }
}
