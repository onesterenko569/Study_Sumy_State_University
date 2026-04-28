using System;

namespace practical_work_9_1
{
    class Transport                                             // базовий клас транспорт
    {
        protected double netProfit;                             // чистий прибуток транспорту

        public virtual void inputData()                         // віртуальний метод для введення даних
        {
            Console.Write("  Введіть чистий прибуток у гривнях: ");
            while (true)                                        // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();           // зчитування рядка з консолі

                // якщо вдалося перетворити текст на double
                if (double.TryParse(inputStr, out netProfit))
                {
                    break;
                }

                Console.Write("  Помилка! Потрібно ввести дійсне число\n  Спробуйте ще раз: ");
            }
        }

        public virtual void outputData()                        // віртуальний метод для виведення даних
        {
            Console.WriteLine("  Чистий прибуток: {0} грн", netProfit);
        }
    }

    class FreightTransport : Transport                          // похідний клас вантажний транспорт, який наслідує базовий клас Transport
    {
        string type;                                            // тип вантажного транспорту
        string model;                                           // модель вантажного транспорту
        double loadCapacity;                                    // вантажопідйомність

        public override void inputData()                        // перевизначений метод для заповнення даних
        {
            // введення типу транспорту
            Console.Write("  Введіть тип вантажного транспорту (автомобіль/поїзд/літак/корабель/інше): ");
            type = Console.ReadLine();

            // введення моделі транспорту
            Console.Write("  Введіть модель вантажного транспорту типу {0}: ", type);
            model = Console.ReadLine();

            // введення вантажопідйомності
            Console.Write("  Введіть вантажопідйомність у тоннах: ");
            while (true)                                        // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();           // зчитування рядка з консолі

                // якщо вдалося перетворити текст на double та число в межах діапазону
                if (double.TryParse(inputStr, out loadCapacity) && loadCapacity >= 1 && loadCapacity <= 1000000)
                {
                    break;
                }

                Console.Write("  Помилка! Потрібно ввести дійсне число в межах від 1 до 1000000\n  Спробуйте ще раз: ");
            }

            // виклик методу базового класу для введення чистого прибутку
            base.inputData();
        }

        public override void outputData()                       // перевизначений метод для виведення інформації
        {
            Console.WriteLine("  Тип вантажного транспорту: {0}", type);
            Console.WriteLine("  Модель вантажного транспорту: {0}", model);
            Console.WriteLine("  Вантажопідйомність: {0} т", loadCapacity);
            Console.WriteLine("  Чистий прибуток: {0} грн", netProfit);
        }
    }

    class PassengerTransport : Transport                        // похідний клас пасажирський транспорт, який наслідує базовий клас Transport
    {
        string type;                                            // тип пасажирського транспорту
        string model;                                           // модель пасажирського транспорту
        int numberSeats;                                        // кількість місць для пасажирів

        public override void inputData()                        // перевизначений метод для заповнення даних
        {
            // введення типу транспорту
            Console.Write("  Введіть тип пасажирського транспорту (автомобіль/поїзд/літак/корабель/інше): ");
            type = Console.ReadLine();

            // введення моделі транспорту
            Console.Write("  Введіть модель пасажирського транспорту типу {0}: ", type);
            model = Console.ReadLine();

            // введення кількості місць
            Console.Write("  Введіть кількість місць для пасажирів: ");
            while (true)                                        // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();           // зчитування рядка з консолі

                // якщо вдалося перетворити текст на int та число в межах діапазону
                if (int.TryParse(inputStr, out numberSeats) && numberSeats >= 1 && numberSeats <= 10000)
                {
                    break;
                }

                Console.Write("  Помилка! Потрібно ввести ціле число в межах від 1 до 10000\n  Спробуйте ще раз: ");
            }

            // виклик методу базового класу для введення чистого прибутку
            base.inputData();
        }

        public override void outputData()                       // перевизначений метод для виведення інформації
        {
            Console.WriteLine("  Тип пасажирського транспорту: {0}", type);
            Console.WriteLine("  Модель пасажирського транспорту: {0}", model);
            Console.WriteLine("  Кількість місць: {0}", numberSeats);
            Console.WriteLine("  Чистий прибуток: {0} грн", netProfit);
        }
    }

    internal class Program                                      // головний клас програми
    {
        static void Main(string[] args)                         // головна функція програми
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            Console.WriteLine("Введіть інформацію про вантажний транспортний засіб:");
            FreightTransport freightTransport = new FreightTransport(); // створення об'єкта класу вантажний транспорт
            freightTransport.inputData();                       // виклик методу заповнення даних для вантажного транспорту

            Console.WriteLine("\nВведіть інформацію про пасажирський транспортний засіб:");
            PassengerTransport passengerTransport = new PassengerTransport(); // створення об'єкта класу пасажирський транспорт
            passengerTransport.inputData();                     // виклик методу заповнення даних для пасажирського транспорту

            Console.WriteLine("\nВведена інформація про вантажний транспортний засіб:");
            freightTransport.outputData();                      // виведення інформації про створений вантажний транспорт

            Console.WriteLine("\nВведена інформація про пасажирський транспортний засіб:");
            passengerTransport.outputData();                    // виведення інформації про створений пасажирський транспорт
        }
    }
}
