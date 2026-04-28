using System;

namespace practical_work_9_2
{
    class InvestmentAsset                                       // базовий клас інвестиційний актив
    {
        protected string ticker;                                // тікер (назва) активу, наприклад VOO
        protected double currentPrice;                          // поточна ціна за одиницю
        protected double investedAmount;                        // загальна вкладена сума

        public virtual void inputData()                         // віртуальний метод для введення даних
        {
            // введення назви активу
            Console.Write("  Введіть назву (тікер) активу: ");
            ticker = Console.ReadLine();

            // введення поточної ціни активу
            Console.Write("  Введіть поточну ціну активу у доларах: ");
            while (true)                                        // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();           // зчитування рядка з консолі

                // перевірка на дійсне число більше нуля
                if (double.TryParse(inputStr, out currentPrice) && currentPrice > 0)
                {
                    break;
                }

                Console.Write("  Помилка! Потрібно ввести додатне число\n  Спробуйте ще раз: ");
            }

            // введення вкладеної суми
            Console.Write("  Введіть загальну вкладену суму у доларах: ");
            while (true)                                        // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();           // зчитування рядка з консолі

                // перевірка на дійсне число більше нуля
                if (double.TryParse(inputStr, out investedAmount) && investedAmount > 0)
                {
                    break;
                }

                Console.Write("  Помилка! Потрібно ввести додатне число\n  Спробуйте ще раз: ");
            }
        }

        public virtual void outputData()                        // віртуальний метод для виведення даних
        {
            Console.WriteLine("  Тікер активу: {0}", ticker);
            Console.WriteLine("  Поточна ціна: {0} $", currentPrice);
            Console.WriteLine("  Вкладена сума: {0} $", investedAmount);
        }
    }

    class ETF : InvestmentAsset                                 // похідний клас індексний фонд, який наслідує InvestmentAsset
    {
        double managementFee;                                   // комісія фонду за управління
        double dividendYield;                                   // дивідендна дохідність

        public override void inputData()                        // перевизначений метод для заповнення даних
        {
            base.inputData();                                   // виклик методу базового класу

            // введення комісії фонду
            Console.Write("  Введіть комісію фонду за управління у відсотках: ");
            while (true)                                        // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();           // зчитування рядка з консолі

                // перевірка на дійсне число в межах від 0 до 10%
                if (double.TryParse(inputStr, out managementFee) && managementFee >= 0 && managementFee <= 10)
                {
                    break;
                }

                Console.Write("  Помилка! Потрібно ввести число від 0 до 10\n  Спробуйте ще раз: ");
            }

            // введення дивідентної дохідності
            Console.Write("  Введіть річну дивідендну дохідність у відсотках: ");
            while (true)                                        // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();           // зчитування рядка з консолі

                // перевірка на дійсне число в межах від 0 до 100%
                if (double.TryParse(inputStr, out dividendYield) && dividendYield >= 0 && dividendYield <= 100)
                {
                    break;
                }

                Console.Write("  Помилка! Потрібно ввести число від 0 до 100\n  Спробуйте ще раз: ");
            }
        }

        public override void outputData()                       // перевизначений метод для виведення інформації
        {
            base.outputData();                                  // виклик методу базового класу

            Console.WriteLine("  Комісія фонду: {0}%", managementFee);
            Console.WriteLine("  Дивідендна дохідність: {0}%", dividendYield);

            // розрахунок чистого річного прибутку з урахуванням комісії
            double netReturn = investedAmount * ((dividendYield - managementFee) / 100);
            Console.WriteLine("  Очікуваний річний прибуток: {0} $", netReturn);
        }
    }

    class Bond : InvestmentAsset                                // похідний клас державна облігація, який наслідує InvestmentAsset
    {
        double interestRate;                                    // річна відсоткова ставка
        int maturityYears;                                      // термін погашення (у роках)

        public override void inputData()                        // перевизначений метод для заповнення даних
        {
            base.inputData();                                   // виклик методу базового класу

            // введення відсоткової ставки
            Console.Write("  Введіть річну відсоткову ставку у відсотках: ");
            while (true)                                        // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();           // зчитування рядка з консолі

                // перевірка на дійсне число в межах від 0 до 100%
                if (double.TryParse(inputStr, out interestRate) && interestRate >= 0 && interestRate <= 100)
                {
                    break;
                }

                Console.Write("  Помилка! Потрібно ввести число від 0 до 100\n  Спробуйте ще раз: ");
            }

            // введення терміну погашення
            Console.Write("  Введіть термін погашення (у роках): ");
            while (true)                                        // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();           // зчитування рядка з консолі

                // перевірка на ціле число в межах від 1 до 50 років
                if (int.TryParse(inputStr, out maturityYears) && maturityYears >= 1 && maturityYears <= 50)
                {
                    break;
                }

                Console.Write("  Помилка! Потрібно ввести ціле число від 1 до 50\n  Спробуйте ще раз: ");
            }
        }

        public override void outputData()                       // перевизначений метод для виведення інформації
        {
            base.outputData();                                  // виклик методу базового класу

            Console.WriteLine("  Річна ставка: {0}%", interestRate);
            Console.WriteLine("  Термін погашення: {0} років", maturityYears);

            // розрахунок прибутку за весь період дії облігації
            double totalReturn = investedAmount * (interestRate / 100) * maturityYears;
            Console.WriteLine("  Очікуваний прибуток за весь період: {0} $", totalReturn);
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            Console.WriteLine("Введіть інформацію про акцію індексного фонду (ETF):");
            ETF myETF = new ETF();                              // створення об'єкта класу ETF
            myETF.inputData();                                  // виклик методу заповнення даних для ETF

            Console.WriteLine("\nВведіть інформацію про державну облігацію:");
            Bond myBond = new Bond();                           // створення об'єкта класу Bond
            myBond.inputData();                                 // виклик методу заповнення даних для облігації

            Console.WriteLine("\nВведена інформація про індексний фонд (ETF):");
            myETF.outputData();                                 // виведення інформації про ETF

            Console.WriteLine("\nВведена інформація про державну облігацію:");
            myBond.outputData();                                // виведення інформації про облігацію
        }
    }
}
