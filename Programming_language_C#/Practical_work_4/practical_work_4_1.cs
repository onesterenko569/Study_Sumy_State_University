using System;

namespace practical_work_4_1
{
    internal class Program
    {
        int inputSize()                                               // функція для введення кількості співробітників
        {
            Console.Write("Введіть кількість співробітників: ");

            while (true)                                              // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                 // вводиться рядок

                if (int.TryParse(inputStr, out int size) && size > 0) // якщо вдалося перетворити текст на int та число більше за 0
                {
                    return size;                                      // повертаємо перетворене значення
                }

                Console.Write("\nПомилка! Кількість співробітників має бути цілим числом більшим за 0\nСпробуйте ще раз: ");
            }
        }

        void printData(double[] height, double[] weight)              // функція для виведення даних у формі таблиці
        {
            // виведення заголовку таблиці
            Console.WriteLine(new string('-', 32));
            Console.WriteLine("|  №  | Зріст (см) | Вага (кг) |");
            Console.WriteLine(new string('-', 32));

            // виведення рядків таблиці
            for (int i = 0; i < height.Length; i++)
            {
                Console.WriteLine("|{0,3}  |   {1:F2}   |{2,8:F2}   |", i + 1, height[i], weight[i]);
            }

            // виведення нижньої межі таблиці
            Console.WriteLine(new string('-', 32));
        }

        static void Main(string[] args)                         // головна функція програми
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            Program ob = new Program();                         // створення посилання на об'єкт класу Program для виклику методів inputSize, printData
            Random rand = new Random();                         // створення посилання на об'єкт класу Random для генерації випадкових чисел

            int employNumber = ob.inputSize();                  // введення кількості співробітників

            double[] height = new double[employNumber];         // створення масиву для зберігання зросту співробітників 
            double[] weight = new double[employNumber];         // створення масиву для зберігання ваги співробітників 

            double minHeight = 150, maxHeight = 210;            // діапазон значень для зросту співробітників
            double minWeight = 40, maxWeight = 140;             // діапазон значень для ваги співробітників

            // заповнення масивів за добопогою генерації чисел
            for (int i = 0; i < employNumber; i++)
            {
                height[i] = minHeight + (maxHeight - minHeight) * rand.NextDouble();
                weight[i] = minWeight + (maxWeight - minWeight) * rand.NextDouble();
            }

            // виведення згенерованих даних
            Console.WriteLine("\nСписок співробітників:");
            ob.printData(height, weight);

            // сортування масиву за зростанням зросту співробітників
            Array.Sort(height, weight);

            // виведення відсортованих даних
            Console.WriteLine("\nВідсортований список співробітників в порядку зростання зросту:");
            ob.printData(height, weight);
        }
    }
}
