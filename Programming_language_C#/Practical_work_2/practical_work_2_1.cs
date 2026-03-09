using System;

namespace practical_work_2_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            // ініціалізація змінних
            string variant;
            double x, z;

            // введення х
            Console.Write("Введіть x: ");
            x = Convert.ToDouble(Console.ReadLine());

            // введення варіанту
            Console.Write("Введіть варіант (1, first, First, FIRST / 2, Second, second, SECOND / 3, Third, third, THIRD): ");
            variant = Console.ReadLine();

            switch (variant)  // початок оператора множинного вибору switch, який аналізує значення змінної variant
            {
                case "1":                              // якщо введенно 1
                case "first":                          // якщо введенно first
                case "First":                          // якщо введенно First
                case "FIRST":                          // якщо введенно FIRST
                    z = Math.Pow(Math.Sin(x), 2);      // обрахування виразу
                    Console.WriteLine("\nz = {0}", z); // виведення результатів
                    break;                             // завершення виконання поточної гілки

                case "2":                                   // якщо введенно 2
                case "Second":                              // якщо введенно Second
                case "second":                              // якщо введенно second
                case "SECOND":                              // якщо введенно SECOND
                    if (x > 0)                              // якщо значення х коректне
                    {
                        z = Math.Log(x, 2);                 // обрахування виразу
                        Console.WriteLine("\nz = {0}", z);  // виведення результатів
                    }
                    else                                    // якщо значення х некоректне
                    {
                        Console.WriteLine("\nПомилка! Неможливо знайти log2({0})", x);
                    }
                    break;                                  // завершення виконання поточної гілки

                case "3":                                   // якщо введенно 3
                case "Third":                               // якщо введенно Third
                case "third":                               // якщо введенно third
                case "THIRD":                               // якщо введенно THIRD
                    double denominator;                     // ініціалізація змінної
                    denominator = Math.Cos(Math.Pow(x, 3)); // обраховуємо знаменник дробу

                    if (denominator == 0)                   // якщо знаменник = 0
                    { 
                        Console.WriteLine("\nПомилка! Ділення на нуль");
                    }
                    else                                    // якщо знаенник != 0
                    {
                        z = 1.0 / denominator;              // обрахування виразу
                        Console.WriteLine("\nz = {0}", z);  // виведення результатів
                    }
                    break;                                  // завершення виконання поточної гілки

                default:                                    // якщо введене значення не збіглося з жодним із варіантів case вище
                    Console.WriteLine("\nВи ввели не правильний варіант!");
                    break;
            }
        }
    }
}
