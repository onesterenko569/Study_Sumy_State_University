using System;

namespace practical_work_7_2
{
    class Goods                                                    // базовий клас товар
    {
        protected string name;                                     // назва товару
        protected double price;                                    // ціна товару
        protected string manufacturer;                             // виробник товару

        protected double inputDouble(double minVal, double maxVal) // функція для безпечного введення дійсного числа
        {
            while (true)                                           // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();              // зчитування рядка з консолі

                // якщо вдалося перетворити текст на double та число в межах діапазону
                if (double.TryParse(inputStr, out double val) && val >= minVal && val <= maxVal)
                {
                    return val;
                }

                Console.Write("  Помилка! Введіть дійсне число від {0} до {1}\n  Спробуйте знову: ", minVal, maxVal);
            }
        }

        protected int inputInt(int minVal, int maxVal)             // функція для безпечного введення цілого числа
        {
            while (true)                                           // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();              // зчитування рядка з консолі

                // якщо вдалося перетворити текст на int та число в межах діапазону
                if (int.TryParse(inputStr, out int val) && val >= minVal && val <= maxVal)
                {
                    return val;
                }

                Console.Write("  Помилка! Введіть ціле число від {0} до {1}\n  Спробуйте знову: ", minVal, maxVal);
            }
        }

        protected void inputBaseGoods()                            // метод введення загальних даних товару
        {
            // введення назви
            Console.Write("  Введіть назву товару: ");
            name = Console.ReadLine();

            // введення ціни
            Console.Write("  Введіть ціну (у грн): ");
            price = inputDouble(0.1, 1000000);

            // введення виробника
            Console.Write("  Введіть виробника: ");
            manufacturer = Console.ReadLine();
        }

        protected void printBaseGoods()                            // метод виведення загальних даних товару
        {
            Console.WriteLine("  Назва: {0}", name);
            Console.WriteLine("  Ціна: {0} грн", price);
            Console.WriteLine("  Виробник: {0}", manufacturer);
        }
    }

    class Toy : Goods                                           // похідний клас іграшка, який наслідує базовий клас Goods
    {
        protected int minimumAge;                               // мінімальний вік дитини
        protected string material;                              // матеріал іграшки

        public void inputToy()                                  // метод для заповнення даних про іграшку
        {
            inputBaseGoods();                                   // викликаємо метод базового класу

            // введення мінімального віку
            Console.Write("  Введіть мінімальний вік для іграшки (років): ");
            minimumAge = inputInt(0, 18);

            // введення матеріалу іграшки
            Console.Write("  Введіть матеріал іграшки: ");
            material = Console.ReadLine();
        }

        public void printToy()                                  // метод для виведення всієї інформації про іграшку
        {
            printBaseGoods();                                   // виводимо дані базового класу

            Console.WriteLine("  Мінімальний вік: від {0} років", minimumAge);
            Console.WriteLine("  Матеріал: {0}", material);
        }
    }

    class Product : Goods                                       // похідний клас продукт, який наслідує базовий клас Goods
    {
        protected int expirationDays;                           // термін придатності у днях
        protected double weight;                                // вага у грамах

        protected void inputProduct()                           // метод для заповнення даних
        {
            inputBaseGoods();                                   // викликаємо метод базового класу товар

            // введення терміну придатності
            Console.Write("  Введіть термін придатності (у днях): ");
            expirationDays = inputInt(1, 1000);

            // введення ваги
            Console.Write("  Введіть вагу (у грамах): ");
            weight = inputDouble(1, 50000);
        }

        protected void printProduct()                           // метод для виведення інформації
        {
            printBaseGoods();                                   // виводимо дані базового класу товар

            Console.WriteLine("  Термін придатності: {0} діб", expirationDays);
            Console.WriteLine("  Вага: {0} г", weight);
        }
    }

    class DairyProduct : Product                                // похідний клас молочний продукт, який наслідує клас Product
    {
        private double fatPercentage;                           // відсоток жирності

        public void inputDairy()                                // метод для заповнення даних про молочний продукт
        {
            inputProduct();                                     // викликаємо метод батьківського класу

            // введення відсотку жирності
            Console.Write("  Введіть відсоток жирності (%): ");
            fatPercentage = inputDouble(0, 100);
        }

        public void printDairy()                                // метод для виведення всієї інформації про молочний продукт
        {
            printProduct();                                     // виводимо дані батьківського класу

            Console.WriteLine("  Жирність: {0}%", fatPercentage);
        }
    }

    internal class Program                                      // головний клас програми
    {
        static void Main(string[] args)                         // головна функція програми
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            Console.WriteLine("Введіть інформацію про іграшку:");
            Toy myToy = new Toy();                              // створення об'єкта класу іграшка
            myToy.inputToy();                                   // виклик методу заповнення даних для іграшки

            Console.WriteLine("\nВведіть інформацію про молочний продукт:");
            DairyProduct myDairy = new DairyProduct();          // створення об'єкта класу молочний продукт
            myDairy.inputDairy();                               // виклик методу заповнення даних для молочного продукту

            Console.WriteLine("\nВиведення інформацію про іграшку:");
            myToy.printToy();                                   // виведення інформації про створену іграшку

            Console.WriteLine("\nВиведення інформацію про молочний продукт:");
            myDairy.printDairy();                               // виведення інформації про створений молочний продукт
        }
    }
}
