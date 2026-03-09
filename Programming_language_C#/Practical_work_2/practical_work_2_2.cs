using System;

namespace practical_work_2_2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            // ініціалізація змінних
            char variant;
            double x, z, tan_x;

            // введення х
            Console.Write("Введіть x: ");
            x = Convert.ToDouble(Console.ReadLine());

            // введення варіанту
            Console.Write("Введіть варіант (A, a / B, b / C, c): ");
            variant = Convert.ToChar(Console.ReadLine());

            if (Math.Cos(x) == 0)              // перевірка чи можливо обчислити тангенс
            {
                Console.WriteLine("\nПомилка! Неможливо знайти tg({0})", x);
                return;                        // завершення програми
            }
            
            tan_x = Math.Tan(x);               // обрахунок tg(x), оскільки багато де використовується

            switch (variant)                   // початок оператора множинного вибору switch, який аналізує значення змінної variant
            {
                case 'A':                      // якщо введенно A
                case 'a':                      // якщо введенно a

                    if (tan_x < 0)             // якщо обчислити корінь від х неможливо
                    {
                        Console.WriteLine("\nПомилка! Підкореневий вираз від'ємний");
                    }
                    else                       // якщо обчислити корінь від х можливо
                    {
                        z = Math.Sqrt(tan_x);               // обчислення виразу
                        Console.WriteLine("\nz = {0}", z);  // виведення результатів
                    }

                    break;                                  // завершення виконання поточної гілки

                case 'B':                                   // якщо введенно B
                case 'b':                                   // якщо введенно b

                    if (tan_x == 0)                         // якщо знаменник = 0
                    {
                        Console.WriteLine("\nПомилка! Ділення на нуль");
                    }
                    else                                    // якщо знаменник != 0
                    {
                        z = 1.0 / tan_x;                    // обчислення виразу
                        Console.WriteLine("\nz = {0}", z);  // виведення результатів
                    }

                    break;                                  // завершення виконання поточної гілки

                case 'C':                                   // якщо введенно C
                case 'c':                                   // якщо введенно c

                    if (tan_x <= 0)                         // якщо натуральний логарифм обчислити неможливо
                    {
                        Console.WriteLine("\nПомилка! Неможливо знайти ln({0})", tan_x);
                    }
                    else                                    // якщо натуральний логарифм обчислити можливо
                    {
                        z = Math.Log(tan_x);                // обрахування виразу
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
