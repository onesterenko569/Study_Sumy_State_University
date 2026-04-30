using System;

namespace practical_work_11
{
    class Motorcycle                                                    // клас мотоцикл
    {
        string brand;                                                   // марка мотоцикла
        double maxSpeed;                                                // максимальна швидкість
        int numberWheels;                                               // кількість колес
        double price;                                                   // ціна мотоцикла

        public void input()                                             // метод для введення даних
        {
            // введення марки
            Console.Write("  Введіть марку мотоцикла: ");
            brand = Console.ReadLine();

            // введення максимальної швидкості
            Console.Write("  Введіть максимальну швидкість у км/год: ");
            while (true)                                                // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();                   // зчитування рядка з консолі

                // якщо вдалося перетворити текст на double та число в межах діапазону
                if (double.TryParse(inputStr, out maxSpeed) && maxSpeed >= 30 && maxSpeed <= 400)
                {
                    break;
                }

                Console.WriteLine("  Помилка! Швидкість повинна бути в діапазоні від 30 до 400 включно");
                Console.Write("  Спробуйте ще раз: ");
            }

            // введення кількості колес
            Console.Write("  Введіть кількість колес: ");
            while (true)                                                // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();                   // зчитування рядка з консолі

                // якщо вдалося перетворити текст на int та число відповідає умові
                if (int.TryParse(inputStr, out numberWheels) && (numberWheels == 2 || numberWheels == 3))
                {
                    break;
                }

                Console.WriteLine("  Помилка! Кількість колес повинна бути 2 або 3");
                Console.Write("  Спробуйте ще раз: ");
            }

            // введення ціни
            Console.Write("  Введіть ціну в гривнях: ");
            while (true)                                                // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();                   // зчитування рядка з консолі

                // якщо вдалося перетворити текст на double та число більше нуля
                if (double.TryParse(inputStr, out price) && price > 0)
                {
                    break;
                }

                Console.WriteLine("  Помилка! Ціна повинна бути додатнім дійсним числом");
                Console.Write("  Спробуйте ще раз: ");
            }
        }

        public void output()                                            // метод для виведення даних
        {
            Console.WriteLine("  Марка мотоцикла: {0}", brand);
            Console.WriteLine("  Максимальна швидкість: {0} км/год", maxSpeed);
            Console.WriteLine("  Кількість колес: {0}", numberWheels);
            Console.WriteLine("  Ціна в гривнях: {0} грн", price);
        }

        public static bool operator ==(Motorcycle a, Motorcycle b)      // перевантаження оператора порівняння на рівність
        {
            if (a.brand == b.brand && a.maxSpeed == b.maxSpeed && a.numberWheels == b.numberWheels && a.price == b.price)
            {
                return true;
            }

            return false;
        }

        public static bool operator !=(Motorcycle a, Motorcycle b)      // перевантаження оператора порівняння на нерівність
        {
            if (a.brand != b.brand || a.maxSpeed != b.maxSpeed || a.numberWheels != b.numberWheels || a.price != b.price)
            {
                return true;
            }

            return false;
        }

        public static bool operator <(Motorcycle a, Motorcycle b)       // перевантаження оператора менше
        {
            if (a.maxSpeed < b.maxSpeed)
            {
                return true;
            }

            return false;
        }

        public static bool operator >(Motorcycle a, Motorcycle b)       // перевантаження оператора більше
        {
            if (a.maxSpeed > b.maxSpeed)
            {
                return true;
            }

            return false;
        }

        public static Motorcycle operator +(Motorcycle a, Motorcycle b) // перевантаження оператора додавання
        {
            Motorcycle c = new Motorcycle();                            // створення нового об'єкта для результату
            if (a.brand == b.brand)                                     // якщо бренди однакові
            {
                c.brand = a.brand;
            }
            else
            {
                c.brand = "NoName";
            }

            c.maxSpeed = a.maxSpeed + b.maxSpeed;                       // сумування максимальної швидкості

            if (a.numberWheels > b.numberWheels)                        // якщо в першого кількість коліс більша
            {
                c.numberWheels = a.numberWheels;
            }
            else                                                        // якщо в другого кількість коліс більша
            {
                c.numberWheels = b.numberWheels;
            }

            c.price = a.price + b.price;                                // сумування цін на мотоцикли

            return c;                                                   // повернення нового об'єкта
        }
    }
    internal class Program                                              // головний клас програми
    {
        void printMenu()                                                // функція для виведення меню на екран
        {
            Console.WriteLine("\nМеню управління");
            Console.WriteLine("  1 - створити та заповнити масив мотоциклів");
            Console.WriteLine("  2 - вивести всі мотоцикли на екран");
            Console.WriteLine("  3 - порівняти мотоцикли в циклі");
            Console.WriteLine("  4 - демонстрація оператора '+' зовні циклу");
            Console.WriteLine("  0 - вихід з програми");
            Console.Write("\nВаш вибір: ");
        }

        int inputInt(int minVal, int maxVal)                            // метод для безпечного введення цілого числа
        {
            while (true)                                                // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                   // зчитування рядка з консолі

                // якщо вдалося перетворити текст на int та число в межах діапазону
                if (int.TryParse(inputStr, out int val) && val >= minVal && val <= maxVal)
                {
                    return val;
                }

                Console.Write("\nПомилка! Потрібно ввести ціле число в межах від {0} до {1} включно\nСпробуйте ще раз: ", minVal, maxVal);
            }
        }

        static void Main(string[] args)                                 // головна функція програми
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;         // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            bool running = true;                                        // змінна для керування нескінченним циклом меню
            Program ob = new Program();                                 // створення об'єкта головного класу
            Motorcycle[] motorcycles = null;                            // оголошення масиву об'єктів мотоциклів

            while (running)                                             // головний цикл роботи програми
            {
                ob.printMenu();                                         // виклик методу для виведення меню
                int userChoice = ob.inputInt(0, 4);                     // зчитування вибору користувача

                switch (userChoice)                                     // оператор вибору дій
                {
                    case 1:                                             // пункт створення та заповнення масиву
                        // введення кількості мотоциклів
                        Console.Write("\nВведіть кількість мотоциклів: ");
                        int motoNumber = ob.inputInt(1, 10);

                        motorcycles = new Motorcycle[motoNumber];       // ініціалізація масиву вказаного розміру
                        for (int i = 0; i < motoNumber; i++)            // цикл для заповнення масиву
                        {
                            motorcycles[i] = new Motorcycle();          // створення нового екземпляра мотоцикла

                            Console.WriteLine("\nВведіть дані про {0} мотоцикл:", i + 1);
                            motorcycles[i].input();                     // виклик методу заповнення даних
                        }

                        break;

                    case 2:                                             // пункт виведення масиву на екран
                        if (motorcycles == null)                        // якщо масив мотоциклів пустий
                        {
                            Console.WriteLine("\nПомилка! Спочатку заповніть масив мотоциклів у пункті 1");
                        }
                        else
                        {
                            for (int i = 0; i < motorcycles.Length; i++)
                            {
                                Console.WriteLine("\nІнформація про {0} мотоцикл:", i + 1);
                                motorcycles[i].output();                // виклик методу виведення інформації
                            }
                        }

                        break;

                    case 3:                                             // пункт порівняння мотоциклів
                        // якщо масив мотоциклів пустий або мотоциклів менше ніж 2
                        if (motorcycles == null || motorcycles.Length < 2)
                        {
                            Console.WriteLine("\nПомилка! Для порівняння потрібно створити масив хоча б з 2 мотоциклів");
                        }
                        else
                        {
                            for (int i = 1; i < motorcycles.Length; i++) // цикл порівняння сусідніх об'єктів
                            {
                                Console.WriteLine("\nПоріняння {0} мотоцикла з {1}:", i, i + 1);

                                if (motorcycles[i - 1] == motorcycles[i])
                                {
                                    Console.WriteLine("  - мотоцикли ідентичні");
                                }
                                else if (motorcycles[i - 1] != motorcycles[i])
                                {
                                    Console.WriteLine("  - мотоцикли відрізняються");
                                }

                                if (motorcycles[i - 1] < motorcycles[i])
                                {
                                    Console.WriteLine("  - попередній мотоцикл має меншу максимальну швидкість");
                                }
                                else if (motorcycles[i - 1] > motorcycles[i])
                                {
                                    Console.WriteLine("  - попередній мотоцикл має більшу максимальну швидкість");
                                }
                                else
                                {
                                    Console.WriteLine("  - максимальні швидкості рівні");
                                }
                            }
                        }

                        break;

                    case 4:                                             // пункт додавання мотоциклів
                        // якщо масив мотоциклів пустий або мотоциклів менше ніж 2
                        if (motorcycles == null || motorcycles.Length < 2)
                        {
                            Console.WriteLine("\nПомилка! Для додавання потрібно створити масив хоча б з 2 мотоциклів");
                        }
                        else
                        {
                            // введення номера першого мотоцикла
                            Console.Write("\nВведіть номер першого мотоцикла для додавання: ");
                            int firstMoto = ob.inputInt(1, motorcycles.Length);
                            firstMoto -= 1;

                            // введення номера другого мотоцикла
                            Console.Write("\nВведіть номер другого мотоцикла для додавання: ");
                            int secondMoto = ob.inputInt(1, motorcycles.Length);
                            secondMoto -= 1;

                            // створення нового об'єкта через перевантажений оператор додавання
                            Motorcycle sumMoto = motorcycles[firstMoto] + motorcycles[secondMoto];

                            Console.WriteLine("\nРезультат додавання:");
                            sumMoto.output();                           // виведення результату додавання
                        }

                        break;

                    default:                                            // пункт виходу з програми
                        Console.WriteLine("\nУдачі!");
                        running = false;                                // зупинка циклу
                        break;
                }
            }
        }
    }
}
