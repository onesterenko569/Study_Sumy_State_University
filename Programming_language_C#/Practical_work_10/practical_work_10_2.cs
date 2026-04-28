using System;

namespace practical_work_10_2
{
    abstract class CommercialMushroom                                           // абстрактний базовий клас комерційний гриб
    {
        protected string sortName;                                              // назва сорту гриба
        protected int growthCycleDays;                                          // цикл росту у днях
        protected double marketPricePerKg;                                      // ринкова ціна за 1 кг у гривнях

        protected int inputInt(int minVal, int maxVal)                          // метод для безпечного введення цілого числа
        {
            while (true)                                                        // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                           // зчитування рядка з консолі

                // перевірка на ціле число та входження в заданий діапазон
                if (int.TryParse(inputStr, out int val) && val >= minVal && val <= maxVal)
                {
                    return val;                                                 // повернення коректного значення
                }

                Console.WriteLine("  Помилка! Потрібно ввести ціле число в межах від {0} до {1} включно", minVal, maxVal);
                Console.Write("  Спробуйте ще раз: ");
            }
        }

        protected double inputDouble(double minVal, double maxVal)              // метод для безпечного введення дійсного числа
        {
            while (true)                                                        // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                           // зчитування рядка з консолі

                // перевірка на дійсне число та входження в заданий діапазон
                if (double.TryParse(inputStr, out double val) && val >= minVal && val <= maxVal)
                {
                    return val;                                                 // повернення коректного значення
                }

                Console.WriteLine("  Помилка! Потрібно ввести дійсне число в межах від {0} до {1} включно", minVal, maxVal);
                Console.Write("  Спробуйте ще раз: ");
            }
        }

        public abstract void inputData();                                       // абстрактний метод для введення даних
        public abstract void outputData();                                      // абстрактний метод для виведення даних
        public abstract void calculateMonthlyYield();                           // абстрактний метод розрахунку місячної врожайності
    }

    class Champignon : CommercialMushroom                                       // похідний клас печериця
    {
        double compostVolume;                                                   // об'єм компосту в тоннах
        bool requiresCasingSoil;                                                // чи потребує покривної землі для росту

        public override void inputData()                                        // перевизначений метод введення даних
        {
            // введення сорту печериць
            Console.Write("  Введіть назву сорту печериць: ");
            sortName = Console.ReadLine();

            // введення циклу росту
            Console.Write("  Введіть цикл росту у днях: ");
            growthCycleDays = inputInt(15, 60);

            // введення очікуваної ринкової ціни
            Console.Write("  Введіть очікувану ринкову ціну за 1 кг у гривнях: ");
            marketPricePerKg = inputDouble(1, 1000);

            // введення об'єму компосту
            Console.Write("  Введіть об'єм компосту у тоннах: ");
            compostVolume = inputDouble(0.1, 100);

            // введення чи потребує покривної землі
            Console.WriteLine("  Чи потребує покривної землі?\n    1 - так\n    2 - ні");
            Console.Write("\n  Ваш вибір: ");
            int userChoice = inputInt(1, 2);

            if (userChoice == 1)
            {
                requiresCasingSoil = true;
            }
            else
            {
                requiresCasingSoil = false;
            }
        }

        public override void outputData()                                       // перевизначений метод виведення даних
        {
            Console.WriteLine("  Сорт печериць: {0}", sortName);
            Console.WriteLine("  Цикл росту: {0} днів", growthCycleDays);
            Console.WriteLine("  Ринкова ціна: {0} грн/кг", marketPricePerKg);
            Console.WriteLine("  Об'єм компосту: {0} тонн", compostVolume);

            if (requiresCasingSoil)   // якщо покривна земля потрібна
            {
                Console.WriteLine("  Покривна земля необхідна");
            }
            else                      // якщо покривна земля не потрібна
            {
                Console.WriteLine("  Покривна земля не потрібна");
            }
        }

        public override void calculateMonthlyYield()                            // перевизначений метод розрахунку
        {
            // урожайність печериць становить близько 250 кг з однієї тонни компосту за цикл
            double yieldPerCycle = compostVolume * 250;                         // розрахунок врожайності за один цикл (250 кг з тонни)
            double cyclesPerMonth = 30.0 / growthCycleDays;                     // розрахунок кількості циклів за один місяць
            double monthlyYield = yieldPerCycle * cyclesPerMonth;               // розрахунок загальної врожайності за місяць
            double expectedIncome = monthlyYield * marketPricePerKg;            // розрахунок очікуваного доходу за місяць

            Console.WriteLine("  Орієнтовний врожай за місяць: {0:F2} кг", monthlyYield);
            Console.WriteLine("  Очікуваний дохід за місяць: {0:F2} грн", expectedIncome);
        }
    }

    class OysterMushroom : CommercialMushroom                                   // похідний клас глива
    {
        int substrateBlocksCount;                                               // кількість субстратних блоків
        double humidityRequirement;                                             // необхідний рівень вологості у відсотках

        public override void inputData()                                        // перевизначений метод введення даних
        {
            // введення назви сорту глив
            Console.Write("  Введіть назву сорту глив: ");
            sortName = Console.ReadLine();

            // введення циклу росту
            Console.Write("  Введіть цикл росту у днях: ");
            growthCycleDays = inputInt(10, 45);

            // введення очікуваної ринкової ціни
            Console.Write("  Введіть очікувану ринкову ціну за 1 кг у гривнях: ");
            marketPricePerKg = inputDouble(1, 1000);

            // введення кількості субстратних блоків
            Console.Write("  Введіть кількість субстратних блоків (шт): ");
            substrateBlocksCount = inputInt(1, 10000);

            // введення рівня вологості
            Console.Write("  Введіть необхідний рівень вологості (%): ");
            humidityRequirement = inputDouble(1, 100);
        }

        public override void outputData()                                       // перевизначений метод виведення даних
        {
            Console.WriteLine("  Сорт глив: {0}", sortName);
            Console.WriteLine("  Цикл росту: {0} днів", growthCycleDays);
            Console.WriteLine("  Ринкова ціна: {0} грн/кг", marketPricePerKg);
            Console.WriteLine("  Кількість блоків субстрату: {0} шт", substrateBlocksCount);
            Console.WriteLine("  Необхідна вологість: {0}%", humidityRequirement);
        }

        public override void calculateMonthlyYield()                            // перевизначений метод розрахунку
        {
            // урожайність глив становить близько 2.5 кг з одного субстратного блоку за цикл
            double yieldPerCycle = substrateBlocksCount * 2.5;                  // розрахунок врожайності за один цикл
            double cyclesPerMonth = 30.0 / growthCycleDays;                     // розрахунок кількості циклів за один місяць
            double monthlyYield = yieldPerCycle * cyclesPerMonth;               // розрахунок загальної врожайності за місяць
            double expectedIncome = monthlyYield * marketPricePerKg;            // розрахунок очікуваного доходу за місяць

            Console.WriteLine("  Орієнтовний врожай за місяць: {0:F2} кг", monthlyYield);
            Console.WriteLine("  Очікуваний дохід за місяць: {0:F2} грн", expectedIncome);
        }
    }

    internal class Program
    {
        void printMenu()                                                        // функція для виведення меню на екран
        {
            Console.WriteLine("\nМеню управління бізнесом");
            Console.WriteLine("1 - Ввести дані про печериці");
            Console.WriteLine("2 - Ввести дані про гливи");
            Console.WriteLine("3 - Вивести інформацію та розрахунок по печерицях");
            Console.WriteLine("4 - Вивести інформацію та розрахунок по гливах");
            Console.WriteLine("0 - Вихід з програми");
            Console.Write("\nВаш вибір: ");
        }

        int inputInt(int minVal, int maxVal)                                    // функція для безпечного введення цілого числа для меню
        {
            while (true)                                                        // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                           // зчитування вводу користувача

                if (int.TryParse(inputStr, out int val) && val >= minVal && val <= maxVal) // перевірка на валідність вводу
                {
                    return val;
                }

                Console.Write("\nПомилка! Потрібно ввести ціле число в межах від {0} до {1} включно\nСпробуйте знову: ", minVal, maxVal);
            }
        }

        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;                 // встановлення кодування UTF-8

            Program ob = new Program();                                         // створення об'єкта класу для доступу до методів меню
            bool running = true;                                                // змінна для керування нескінченним циклом меню

            Champignon champignon = null;                                       // змінна для зберігання об'єкта печериць
            OysterMushroom oysterMushroom = null;                               // змінна для зберігання об'єкта глив

            while (running)                                                     // головний цикл роботи програми
            {
                ob.printMenu();                                                 // виклик методу для виведення меню
                int userChoice = ob.inputInt(0, 4);                             // безпечне зчитування вибору користувача

                switch (userChoice)                                             // оператор вибору дій
                {
                    case 1:                                                     // пункт введення даних про печериці
                        Console.WriteLine("\nВведення даних для печериць:");
                        champignon = new Champignon();                          // створення нового екземпляра
                        champignon.inputData();                                 // виклик методу заповнення даних
                        break;

                    case 2:                                                     // пункт введення даних про гливи
                        Console.WriteLine("\nВведення даних для глив:");
                        oysterMushroom = new OysterMushroom();                  // створення нового екземпляра
                        oysterMushroom.inputData();                             // виклик методу заповнення даних
                        break;

                    case 3:                                                     // пункт виведення інформації про печериці
                        if (champignon == null)                                 // перевірка чи об'єкт створено
                        {
                            Console.WriteLine("\nПомилка! Спочатку введіть дані про печериці у пункті 1");
                        }
                        else                                                    // якщо об'єкт заповнено
                        {
                            Console.WriteLine("\nІнформація про печериці:");
                            champignon.outputData();                            // виклик методу виведення даних
                            champignon.calculateMonthlyYield();                 // виклик методу розрахунку
                        }
                        break;

                    case 4:                                                     // пункт виведення інформації про гливи
                        if (oysterMushroom == null)                             // перевірка чи об'єкт створено
                        {
                            Console.WriteLine("\nПомилка! Спочатку введіть дані про гливи у пункті 2");
                        }
                        else                                                    // якщо об'єкт заповнено
                        {
                            Console.WriteLine("\nІнформація про гливи:");
                            oysterMushroom.outputData();                        // виклик методу виведення даних
                            oysterMushroom.calculateMonthlyYield();             // виклик методу розрахунку
                        }
                        break;

                    default:                                                    // пункт виходу з програми
                        Console.WriteLine("\nУдачі!");
                        running = false;                                        // зупинка циклу
                        break;
                }
            }
        }
    }
}
