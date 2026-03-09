using System;

namespace practical_work_2_3
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
            Console.Write("Введіть варіант (100, A / 200, B / 250, C): ");
            variant = Console.ReadLine();

            switch (variant)                   // початок оператора множинного вибору switch, який аналізує значення змінної variant
            {
                case "100":                    // якщо введенно 100
                case "A":                      // якщо введенно A

                    double sin_x = Math.Sin(x);// обрахунок sin(x)

                    if (sin_x < 0)             // якщо обчислити корінь від sin(х) неможливо
                    {
                        Console.WriteLine("\nПомилка! Підкореневий вираз від'ємний");
                    }
                    else                       // якщо обчислити корінь від sin(х) можливо
                    {
                        z = Math.Sqrt(sin_x);               // обчислення виразу
                        Console.WriteLine("\nz = {0}", z);  // виведення результатів
                    }

                    break;                                  // завершення виконання поточної гілки

                case "200":                                 // якщо введенно 200
                case "B":                                   // якщо введенно B

                    double cos_x = Math.Cos(x);             // обрахунок cos(x)

                    if (cos_x == 0)                         // якщо знаменник = 0
                    {
                        Console.WriteLine("\nПомилка! Ділення на нуль");
                    }
                    else                                    // якщо знаменник != 0
                    {
                        z = 1.0 / cos_x;                    // обчислення виразу
                        Console.WriteLine("\nz = {0}", z);  // виведення результатів
                    }

                    break;                                  // завершення виконання поточної гілки

                case "250":                                 // якщо введенно 250
                case "C":                                   // якщо введенно C

                    if (Math.Cos(x) == 0)                   // перевірка чи можливо обчислити тангенс
                    {
                        Console.WriteLine("\nПомилка! Неможливо знайти tg({0})", x);
                        return;                             // завершення програми
                    }

                    double abs_tan_x = Math.Abs(Math.Tan(x)); // обрахунок |tg(x)|

                    if (abs_tan_x == 0)                     // якщо натуральний логарифм обчислити неможливо
                    {
                        Console.WriteLine("\nПомилка! Неможливо знайти ln({0})", abs_tan_x);
                    }
                    else                                    // якщо натуральний логарифм обчислити можливо
                    {
                        z = Math.Log(abs_tan_x);            // обрахування виразу
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
