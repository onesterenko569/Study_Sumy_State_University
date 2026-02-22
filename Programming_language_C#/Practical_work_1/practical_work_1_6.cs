using System;

namespace practical_work_1_6
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n, steps = 0; // оголошення змінних

            // введення числа
            Console.Write("Vvedit bud-yake tsile dodatne chyslo: ");
            n = Convert.ToInt32(Console.ReadLine());

            if (n <= 0) // перевірка введення
            {
                Console.WriteLine("Pomylka! Potribno vvesty tsile dodatnye chyslo!"); // повідомлення про помилку
                return;                                                           // завершення програми
            }

            Console.Write("{0}", n); // виведення початкового числа

            // цикл працює, поки n не досягне 1
            while (n > 1)
            {
                if (n % 2 == 0)      // якщо парне
                {
                    n /= 2;          // ділимо на 2
                }
                else                 // якщо непарне
                {
                    n = (n * 3) + 1; // множимо на 3 та додаємо 1
                }

                Console.Write(" -> {0}", n); // виведення проміжних результатів
                steps++;                     // збільшення лічильника кількості ітерацій
            } 

            Console.WriteLine("\n\nKilʹkist krokiv do odynytsi: {0}", steps); // виведення результатів
        }
    }
}
