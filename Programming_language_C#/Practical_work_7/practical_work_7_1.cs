using System;
using System.Collections.Generic;

namespace practical_work_7_1
{
    class Ship                           // базовий клас для всіх типів кораблів
    {
        protected string name;           // поле для збереження назви корабля
        protected string appointment;    // поле для призначення
        protected double waterTonnage;   // поле для водотоннажності
        protected double enginePower;    // поле для потужності двигуна
        protected string fuelType;       // поле для виду палива

        double inputDouble(double minVal, double maxVal)         // функція для безпечного введення дійсного числа у заданому діапазоні
        {
            while (true)                                         // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();            // вводиться рядок

                // якщо вдалося перетворити текст на double та число в межах діапазону
                if (double.TryParse(inputStr, out double val) && val >= minVal && val <= maxVal)
                {
                    return val;
                }

                Console.Write("  Помилка! Потрібно ввести дійсне число в межах від {0} до {1} включно\n  Спробуйте знову: ", minVal, maxVal);
            }
        }

        protected int inputInt(int minVal, int maxVal)            // функція для безпечного введення цілого числа
        {
            while (true)                                          // нескінченний цикл для перевірки вводу
            {
                string inputStr = Console.ReadLine();             // зчитування рядка з консолі

                // якщо конвертація успішна і число відповідає умовам
                if (int.TryParse(inputStr, out int val) && val >= minVal && val <= maxVal)
                {
                    return val;
                }

                Console.Write("  Помилка! Потрібно ввести ціле число в межах від {0} до {1} включно\n  Спробуйте знову: ", minVal, maxVal);
            }
        }

        protected void inputData()                    // метод для введення загальних характеристик будь-якого корабля
        {
            // введення назви корабля
            Console.Write("  Введіть назву корабля: ");
            name = Console.ReadLine();

            // введення призначення
            Console.Write("  Введіть його призначення: ");
            appointment = Console.ReadLine();

            // введення водотонажності
            Console.Write("  Введіть водотоннажність (у тоннах): ");
            waterTonnage = inputDouble(1, 1000000);

            // введення потужності двигуна
            Console.Write("  Введіть потужність двигуна (у кінських силах): ");
            enginePower = inputDouble(1, 500000);

            // введення виду палива
            Console.Write("  Введіть вид палива: ");
            fuelType = Console.ReadLine();
        }

        protected void printBaseInfo()                // метод для виведення загальних характеристик корабля
        {
            Console.WriteLine("  Назва корабля: {0}", name);
            Console.WriteLine("  Призначення: {0}", appointment);
            Console.WriteLine("  Водотоннажність (у тоннах): {0}", waterTonnage);
            Console.WriteLine("  Потужність двигуна (у кінських силах): {0}", enginePower);
            Console.WriteLine("  Вид палива: {0}", fuelType);
        }
    }

    class Carrier : Ship                               // похідний клас авіаносець, який наслідує базовий клас Ship
    {
        // словник для зберігання типів літаків (ключ) та їх кількості (значення)
        Dictionary<string, int> aircraft = new Dictionary<string, int>();

        public void inputInfo()                       // метод для заповнення даних про авіаносець
        {
            inputData();                              // виклик методу базового класу для введення загальних даних

            while (true)                              // цикл для додавання літаків у словник
            {
                // введення типу літака
                Console.Write("  Введіть тип літаків, які має авіаносець або 0 для завершення введення: ");
                string type = Console.ReadLine();

                if (type == "0")                      // умова виходу з циклу додавання
                {
                    break;
                }

                if (aircraft.ContainsKey(type))       // якщо такий тип літака вже існує у словнику
                {
                    Console.WriteLine("  Літаки типу {0} вже є на авіаносці!", type);
                    continue;                         // пропускаємо поточну ітерацію і починаємо цикл спочатку
                }

                // введення кількості літаків
                Console.Write("  Введіть кількість літаків типу {0}: ", type);
                int count = inputInt(1, 100);

                aircraft.Add(type, count);            // додавання нового запису до словника
            }
        }

        public void printInfo()                       // метод для виведення всієї інформації про авіаносець
        {
            printBaseInfo();                          // виклик методу базового класу для виводу загальних даних

            Console.WriteLine("  Літаки на борту:");

            if (aircraft.Count == 0)                  // перевірка чи словник порожній
            {
                Console.WriteLine("    На борту немає жодного літака!");
            }
            else                                      // якщо літаки є на борту
            {
                // перебір всіх елементів словника та їх виведення
                foreach (KeyValuePair<string, int> val in aircraft)
                {
                    Console.WriteLine("    - тип: {0}, кількість: {1} шт.", val.Key, val.Value);
                }
            }
        }
    }

    class RocketCarrier : Ship                         // похідний клас ракетоносець, який наслідує базовий клас Ship
    {
        // словник для зберігання типів ракет (ключ) та їх кількості (значення)
        Dictionary<string, int> rocket = new Dictionary<string, int>();

        public void inputInfo()                       // метод для заповнення даних про ракетоносець
        {
            inputData();                              // виклик методу базового класу для введення загальних даних

            while (true)                              // цикл для додавання ракет у словник
            {
                // введення типу ракети
                Console.Write("  Введіть тип ракет, які має ракетоносець або 0 для завершення введення: ");
                string type = Console.ReadLine();

                if (type == "0")                      // умова виходу з циклу додавання
                {
                    break;
                }

                if (rocket.ContainsKey(type))         // перевірка наявності такого типу ракети у словнику      
                {
                    Console.WriteLine("  Ракети типу {0} вже є на ракетоносці!", type);
                    continue;                         // перехід до наступної ітерації
                }

                // введення кількості ракет
                Console.Write("  Введіть кількість ракет типу {0}: ", type);
                int count = inputInt(1, 1000);

                rocket.Add(type, count);              // збереження даних у словник
            }
        }

        public void printInfo()                       // метод для виведення інформації про ракетоносець
        {
            printBaseInfo();                          // виведення загальної інформації про корабель

            Console.WriteLine("  Наявні ракети:");

            if (rocket.Count == 0)                    // якщо словник ракет порожній
            {
                Console.WriteLine("    На борту немає жодної ракети!");
            }
            else                                      // якщо ракети додано
            {
                // перебір всіх ракет у словнику та їх виведення
                foreach (KeyValuePair<string, int> val in rocket)
                {
                    Console.WriteLine("    - тип: {0}, кількість: {1} шт.", val.Key, val.Value);
                }
            }
        }
    }

    internal class Program    // головний клас програми
    {
        void printMenu()      // функція для виведення меню на екран
        {
            Console.WriteLine("\nОберіть дію:");
            Console.WriteLine("1 - ввести дані про авіаносці");
            Console.WriteLine("2 - ввести дані про ракетоносці");
            Console.WriteLine("3 - вивести інформацію про авіаносці");
            Console.WriteLine("4 - вивести інформацію про ракетоносці");
            Console.WriteLine("0 - вихід з програми");
            Console.Write("\nВаш вибір: ");
        }

        int inputInt(int minVal, int maxVal)    // функція для безпечного введення цілого числа
        {
            while (true)                       // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine(); // зчитування вводу користувача

                if (int.TryParse(inputStr, out int val) && val >= minVal && val <= maxVal) // перевірка на валідність вводу
                {
                    return val;
                }

                Console.Write("\nПомилка! Потрібно ввести ціле число в межах від {0} до {1} включно\nСпробуйте знову: ", minVal, maxVal);
            }
        }

        static void Main(string[] args)                         // головна функція програми                 
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            Program ob = new Program();                         // створення об'єкта класу для доступу до методів меню

            bool running = true;                                // змінна для керування нескінченним циклом меню

            Carrier[] carriers = null;                          // масив для зберігання об'єктів авіаносців
            RocketCarrier[] rocketCarriers = null;              // масив для зберігання об'єктів ракетоносців

            while (running)                                     // головний цикл роботи програми
            {
                ob.printMenu();                                 // виклик методу для виведення меню

                int userChoice = ob.inputInt(0, 4);             // безпечне зчитування вибору користувача від 0 до 4

                switch (userChoice)                             // оператор вибору дій залежно від введеного числа
                {
                    case 1:                                     // якщо обрано пункт меню ввести дані про авіаносці
                        // введення кількості авіаносців
                        Console.Write("\nВведіть кількість авіаносців: ");
                        int countCarrier = ob.inputInt(1, 10);

                        carriers = new Carrier[countCarrier];   // ініціалізація масиву потрібного розміру
                        for (int i = 0; i < countCarrier; i++)  // цикл заповнення масиву
                        {
                            carriers[i] = new Carrier();        // створення нового екземпляра авіаносця

                            Console.WriteLine("\nВведіть інформацію про {0} авіаносець:", i + 1);
                            carriers[i].inputInfo();            // виклик методу заповнення даних конкретного корабля
                        }

                        break;

                    case 2:                                     // якщо обрано пункт меню ввести дані про ракетоносці
                        // введення кількості ракетоносців
                        Console.Write("\nВведіть кількість ракетоносців: ");
                        int countRocketCarrier = ob.inputInt(1, 10);

                        rocketCarriers = new RocketCarrier[countRocketCarrier]; // ініціалізація масиву потрібного розміру
                        for (int i = 0; i < countRocketCarrier; i++)            // цикл заповнення масиву
                        {
                            rocketCarriers[i] = new RocketCarrier();            // створення нового екземпляра ракетоносця

                            Console.WriteLine("\nВведіть інформацію про {0} ракетоносець:", i + 1);
                            rocketCarriers[i].inputInfo();                      // виклик методу заповнення даних
                        }

                        break;

                    case 3:                                             // якщо обрано пункт меню вивести дані про авіаносці
                        if (carriers == null || carriers.Length == 0)   // перевірка чи масив авіаносців існує і не порожній
                        {
                            Console.WriteLine("\nПомилка! Спочатку додайте авіаносці в пункті 1");
                        }
                        else                                            // якщо масив заповнено
                        {
                            // перебір усіх збережених авіаносців та виведення інформації
                            for (int i = 0; i < carriers.Length; i++)
                            {
                                Console.WriteLine("\nІнформація про {0} авіаносець:", i + 1);
                                carriers[i].printInfo();                // виклик методу виведення інформації
                            }
                        }

                        break;

                    case 4:                                                       // якщо обрано пункт меню вивести дані про ракетоносці
                        if (rocketCarriers == null || rocketCarriers.Length == 0) // перевірка чи масив ракетоносців існує
                        {
                            Console.WriteLine("\nПомилка! Спочатку додайте ракетоносці в пункті 2");
                        }
                        else                                                      // якщо масив заповнено
                        {
                            // перебір усіх збережених ракетоносців та виведення інофрмації
                            for (int i = 0; i < rocketCarriers.Length; i++)
                            {
                                Console.WriteLine("\nІнформація про {0} ракетоносець:", i + 1);
                                rocketCarriers[i].printInfo();                    // виклик методу виведення інформації
                            }
                        }

                        break;

                    default:                                               // якщо обрано пункт меню виходу з програми
                        Console.WriteLine("\nУдачі!");
                        running = false;                                   // зупинка циклу для завершення роботи програми
                        break;
                }
            }
        }
    }
}
