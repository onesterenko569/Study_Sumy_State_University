using System;

namespace practical_work_17
{
    internal class Program
    {
        delegate double MathFunc(double x);                                          // оголошення делегата

        int inputSize(string arrName)                                                // функція для введення розміру масиву
        {
            Console.Write("\nВведіть розмір для масиву {0}: ", arrName);

            while (true)                                                             // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                                // вводиться рядок

                if (int.TryParse(inputStr, out int size) && size > 0)                // якщо вдалося перетворити текст на int та число більше за 0
                {
                    return size;                                                     // повертаємо перетворене значення
                }

                Console.Write("Помилка! Розмір масиву має бути цілим числом більшим за 0\nСпробуйте ще раз: ");
            }
        }

        void inputArray(double[] arr, string arrName)                                // функція для введення масиву
        {
            Console.WriteLine("\nВведіть елементи масиву {0}: ", arrName);

            for (int i = 0; i < arr.Length; i++)                                     // цикл для введення
            {
                Console.Write("  {0}[{1}] = ", arrName, i);

                while (true)                                                         // цикл, який триватиме поки не спрацює break
                {
                    string inputStr = Console.ReadLine();                            // вводиться рядок

                    if (double.TryParse(inputStr, out double val))                   // якщо вдалося перетворити текст на double
                    {
                        if (Math.Abs(Math.Cos(val)) < 1e-9)                          // перевірка чи не є значення критичним для тангенсу
                        {
                            Console.Write("  Помилка! Значення призведе до ділення на нуль при обчисленні тангенсу\n  Спробуйте ще раз: ");
                            continue;                                                // перехід до наступної ітерації циклу введення
                        }

                        arr[i] = val;                                                // додаємо перетворене значення в масив
                        break;                                                       // завершуємо цикл
                    }

                    Console.Write("  Помилка! Значення {0}[{1}] повинно бути дійсним числом\n  Спробуйте ще раз: ", arrName, i);
                }
            }
        }

        // функція для обробки одного масиву з метою отримання трьох результатів
        void calculation(double[] arr, MathFunc f1, MathFunc f2, MathFunc f3, out double res1, out double res2, out double res3, out double s, out double p)
        {
            res1 = 0; res2 = 0; res3 = 0; s = 0; p = 1;                              // встановлення початкових значень 

            for (int i = 0; i < arr.Length; i++)                                     // цикл по елементах масиву
            {
                s += arr[i];                                                         // обчислення суми елементів
                p *= arr[i];                                                         // обчислення добутку елементів

                res1 += arr[i] * f1(arr[i]);                                         // застосування першої переданої математичної функції
                res2 += arr[i] * f2(arr[i]);                                         // застосування другої переданої математичної функції
                res3 += arr[i] * f3(arr[i]);                                         // застосування третьої переданої математичної функції
            }
        }

        static void Main(string[] args)                                              // головна функція програми
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;                      // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            Program ob = new Program();                                              // створення екземпляру класу Program, щоб викликати його нестатичні методи

            int xSize = ob.inputSize("x");                                           // введення розміру для масиву x
            double[] x = new double[xSize];                                          // виділення пам'яті під масив x

            int ySize = ob.inputSize("y");                                           // введення розміру для масиву y
            double[] y = new double[ySize];                                          // виділення пам'яті під масив y

            ob.inputArray(x, "x");                                                   // введення елементів масиву x
            ob.inputArray(y, "y");                                                   // введення елементів масиву y

            double sumX1, sumX2, sumX3, sx, px;                                      // змінні для проміжних результатів масиву x
            ob.calculation(x, Math.Sin, Math.Cos, Math.Tan, out sumX1, out sumX2, out sumX3, out sx, out px); // виклик функції з делегатами

            double A = px * sumX1;                                                   // обчислення A
            double B = sx * sumX2;                                                   // обчислення B
            double C = (px + sx) * sumX3;                                            // обчислення C

            double D, E, F, sy, py;                                                  // змінні для результатів масиву y

            ob.calculation(y, Math.Tan, Math.Exp, Math.Cos, out D, out E, out F, out sy, out py); // виклик функції з делегатами

            double denominator = D + E * Math.Sin(F);                                // обчислення знаменника

            if (Math.Abs(denominator) < 1e-9)                                        // перевірка чи знаменник не є нулем
            {
                Console.WriteLine("\nПомилка! Ділення на нуль. Обчислити значення виразу неможливо."); // виведення повідомлення про помилку
            }
            else                                                                     // якщо знаменник коректний
            {
                double psi = (A * Math.Sin(B) + B * Math.Cos(C)) / denominator;      // обчислення кінцевого результату

                // виведення результатів
                Console.WriteLine("\nРезультати обчислень:");
                Console.WriteLine("  A = {0:F3}\n  B = {1:F3}\n  C = {2:F3}", A, B, C);
                Console.WriteLine("  D = {0:F3}\n  E = {1:F3}\n  F = {2:F3}", D, E, F);
                Console.WriteLine("\n  Значення psi = {0:F3}", psi);
            }
        }
    }
}
