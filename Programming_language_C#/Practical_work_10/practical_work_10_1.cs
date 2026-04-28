using System;

namespace practical_work_10_1
{
    abstract class Plane                                                // абстрактний базовий клас літак
    {
        protected string model;                                         // модель літака
        protected string countryManufacture;                            // країна-виробник літака
        protected double maxSpeed;                                      // максимальна швидкість (км/год)
        protected double flightRange;                                   // дальність польоту (км)
        protected int numberPilots;                                     // кількість пілотів екіпажу

        protected int inputInt(int minVal, int maxVal)                  // метод для безпечного введення цілого числа з перевіркою меж
        {
            while (true)                                                // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                   // зчитування рядка з консолі

                // перевірка на ціле число та входження в заданий діапазон
                if (int.TryParse(inputStr, out int val) && val >= minVal && val <= maxVal)
                {
                    return val;                                         // повернення коректного значення та вихід з методу
                }

                Console.WriteLine("  Помилка! Потрібно ввести ціле число в межах від {0} до {1} включно", minVal, maxVal);
                Console.Write("  Спробуйте ще раз: ");
            }
        }

        protected double inputDouble(double minVal, double maxVal)      // метод для безпечного введення дійсного числа з перевіркою меж
        {
            while (true)                                                // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                   // зчитування рядка з консолі

                // перевірка на дійсне число та входження в заданий діапазон
                if (double.TryParse(inputStr, out double val) && val >= minVal && val <= maxVal)
                {
                    return val;                                         // повернення коректного значення та вихід з методу
                }

                Console.WriteLine("  Помилка! Потрібно ввести дійсне число в межах від {0} до {1} включно", minVal, maxVal);
                Console.Write("  Спробуйте ще раз: ");
            }
        }

        public abstract void inputData();                               // абстрактний метод для введення даних
        public abstract void outputData();                              // абстрактний метод для виведення даних
    }

    class Destroyer : Plane                                             // похідний клас винищувач, який наслідує Plane
    {
        string typeMissile;                                             // тип ракет
        int numberMissiles;                                             // кількість ракет
        bool hasStealth;                                                // наявність стелс-технології

        public override void inputData()                                // перевизначений метод для заповнення даних
        {
            // введення моделі винищувача
            Console.Write("  Введіть модель винищувача: ");
            model = Console.ReadLine();

            // введення країни-виробника
            Console.Write("  Введіть країну-виробник винищувача: ");
            countryManufacture = Console.ReadLine();

            // введення максимальної швидкості
            Console.Write("  Введіть максимальну швидкість (км/год): ");
            maxSpeed = inputDouble(1200, 3500);                         // виклик методу для безпечного введення з лімітами

            // введення дальності польоту
            Console.Write("  Введіть дальність польоту (км): ");
            flightRange = inputDouble(500, 4000);                       // виклик методу для безпечного введення з лімітами

            // введення кількості пілотів
            Console.Write("  Введіть необхідну кількість пілотів: ");
            numberPilots = inputInt(1, 2);                              // виклик методу для безпечного введення з лімітами

            // введення типу ракет
            Console.Write("  Введіть тип ракет: ");
            typeMissile = Console.ReadLine();

            // введення кількості ракет
            Console.Write("  Введіть кількість ракет: ");
            numberMissiles = inputInt(0, 14);                           // виклик методу для безпечного введення з лімітами

            // вибір наявності стелс-технології
            Console.WriteLine("  Чи має винищувач стелс-технологію?\n    1 - так\n    2 - ні");
            Console.Write("\n  Ваш вибір: ");
            int userChoice = inputInt(1, 2);                            // виклик методу для безпечного введення з лімітами

            if (userChoice == 1)
            {
                hasStealth = true;                                      // присвоєння значення true, якщо вибрано 1
            }
            else
            {
                hasStealth = false;                                     // присвоєння значення false, якщо вибрано 2
            }
        }

        public override void outputData()                               // перевизначений метод для виведення інформації
        {
            Console.WriteLine("  Модель винищувача: {0}", model);
            Console.WriteLine("  Країна-виробник винищувача: {0}", countryManufacture);
            Console.WriteLine("  Максимальна швидкість (км/год): {0}", maxSpeed);
            Console.WriteLine("  Дальність польоту (км): {0}", flightRange);
            Console.WriteLine("  Кількість пілотів: {0}", numberPilots);
            Console.WriteLine("  Тип ракет: {0}", typeMissile);
            Console.WriteLine("  Кількість ракет: {0}", numberMissiles);

            // виведення інформації про стелс-технологію
            if (hasStealth)
            {
                Console.WriteLine("  Стелс-технологія присутня");
            }
            else
            {
                Console.WriteLine("  Стелс-технологія відсутня");
            }
        }
    }

    class PassengerLiner : Plane                                        // похідний клас пасажирський лайнер, який наслідує Plane
    {
        string airlineName;                                             // назва авіакомпанії
        int numberPassenger;                                            // кількість пасажирських місць

        public override void inputData()                                // перевизначений метод для заповнення даних
        {
            // введення назви авіакомпанії
            Console.Write("  Введіть назву авіакомпанії: ");
            airlineName = Console.ReadLine();

            // введення моделі лайнера
            Console.Write("  Введіть модель пасажирського лайнеру: ");
            model = Console.ReadLine();

            // введення країни-виробника
            Console.Write("  Введіть країну-виробник пасажирського лайнеру: ");
            countryManufacture = Console.ReadLine();

            // введення максимальної швидкості
            Console.Write("  Введіть максимальну швидкість (км/год): ");
            maxSpeed = inputDouble(400, 1100);                          // виклик методу для безпечного введення з лімітами

            // введення дальності польоту
            Console.Write("  Введіть дальність польоту (км): ");
            flightRange = inputDouble(1000, 17000);                     // виклик методу для безпечного введення з лімітами

            numberPilots = 2;                                           // задання кількості пілотів для лайнера

            // введення кількості пасажирів
            Console.Write("  Введіть кількість пасажирських місць: ");
            numberPassenger = inputInt(20, 853);                        // виклик методу для безпечного введення з лімітами
        }

        public override void outputData()                               // перевизначений метод для виведення інформації
        {
            Console.WriteLine("  Назва авіакомпанії: {0}", airlineName);
            Console.WriteLine("  Модель пасажирського лайнера: {0}", model);
            Console.WriteLine("  Країна-виробник: {0}", countryManufacture);
            Console.WriteLine("  Максимальна швидкість (км/год): {0}", maxSpeed);
            Console.WriteLine("  Дальність польоту (км): {0}", flightRange);
            Console.WriteLine("  Кількість пілотів: {0}", numberPilots);
            Console.WriteLine("  Кількість пасажирських місць: {0}", numberPassenger);
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;         // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            Console.WriteLine("Введіть інформацію про винищувач:");
            Destroyer destroyer = new Destroyer();                      // створення об'єкта класу Destroyer
            destroyer.inputData();                                      // виклик методу заповнення даних для винищувача

            Console.WriteLine("\nВведіть інформацію про пасажирський лайнер:");
            PassengerLiner passengerLiner = new PassengerLiner();       // створення об'єкта класу PassengerLiner
            passengerLiner.inputData();                                 // виклик методу заповнення даних для лайнера

            Console.WriteLine("\nВведена інформація про винищувач:");
            destroyer.outputData();                                     // виведення інформації про винищувач

            Console.WriteLine("\nВведена інформація про пасажирський лайнер:");
            passengerLiner.outputData();                                // виведення інформації про лайнер
        }
    }
}
