using System;

namespace practical_work_5
{
    class FloatingMeans                 // клас для опису плаваючих засобів
    {
        int numberMembers, attribute;   // змінні для кількості членів екіпажу та ознаки відповідності
        string name, material;          // змінні для назви плаваючого засобу та матеріалу корпусу
        double waterTonnage, speed;     // змінні для водотоннажності та швидкості

        double inputDouble()                                               // функція для безпечного введення дійсного числа
        {
            while (true)                                                   // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                      // вводиться рядок

                if (double.TryParse(inputStr, out double val) && val > 0) // якщо вдалося перетворити текст на double та число більше за 0
                {
                    return val;                                            // повертаємо перетворене значення
                }

                Console.Write("  Помилка! Потрібно ввести дійсне число більше за 0\n  Спробуйте ще раз: ");
            }
        }

        int inputInt()                                                     // функція для безпечного введення цілого числа
        {
            while (true)                                                   // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                      // вводиться рядок

                if (int.TryParse(inputStr, out int val) && val > 0)        // якщо вдалося перетворити текст на int та число більше за 0
                {
                    return val;                                            // повертаємо перетворене значення
                }

                Console.Write("  Помилка! Потрібно ввести ціле число більше за 0\n  Спробуйте ще раз: ");
            }
        }

        public void inputData(int n)                                       // функція для заповнення полів об'єкта даними з клавіатури
        {
            Console.WriteLine("\nВведіть інформацію для {0}-го плаваючого засобу:", n + 1);

            // введення назви
            Console.Write("  Назва - ");
            name = Console.ReadLine();

            // введення водотоннажності
            Console.Write("  Водотоннажність (у тоннах) = ");
            waterTonnage = inputDouble();

            // введення матеріалу корпусу
            Console.Write("  Матеріал, з якого виготовлений корпус - ");
            material = Console.ReadLine();

            // введення кількості членів екіпажу
            Console.Write("  Кількість членів екіпажа = ");
            numberMembers = inputInt();

            // введення швидкості руху
            Console.Write("  Швидкість руху (у вузлах) = ");
            speed = inputDouble();
        }

        public void analysis(ref string desireMaterial, ref double desireSpeed) // функція для аналізу на відповідність вимогам покупця
        {
            if (material == desireMaterial && speed >= desireSpeed) // якщо матеріал збігається і швидкість не менша за бажану
            {
                attribute = 1;                                      // встановлюємо ознаку, що засіб підходить
            }
            else                                                    // в іншому випадку
            {
                attribute = 0;                                      // встановлюємо ознаку, що засіб не підходить
            }
        }

        public void output(int n)    // функція для виведення даних
        {
            if (attribute == 1)      // якщо засіб підходить
            {
                Console.WriteLine("\nПлаваючий засіб номер {0} підходить Вам!", n + 1);
                Console.WriteLine("  Назва - {0}", name);
                Console.WriteLine("  Водотоннажність (у тоннах) = {0:F2}", waterTonnage);
                Console.WriteLine("  Матеріал, з якого виготовлений корпус - {0}", material);
                Console.WriteLine("  Кількість членів екіпажа = {0}", numberMembers);
                Console.WriteLine("  Швидкість руху (у вузлах) = {0:F2}", speed);
            }
            else                     // якщо засіб не підходить
            {
                Console.WriteLine("\nПлаваючий засіб номер {0} не підходить Вам", n + 1);
            }
        }
    }

    class Program                                               // головний клас програми, що містить точку входу Main
    {
        static void Main(string[] args)                         // головна функція програми
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі
            int numberFloatMeans;                               // змінна для збереження кількості засобів

            Console.Write("Введіть кількість плаваючих засобів: ");

            while (true)                                        // цикл для безпечного введення кількості засобів
            {
                string inputStr = Console.ReadLine();           // вводиться рядок

                if (int.TryParse(inputStr, out numberFloatMeans) && numberFloatMeans > 0) // якщо вдалося перетворити текст на int та число більше за 0
                {
                    break;                                      // вихід із циклу
                }

                Console.Write("\nПомилка! Потрібно ввести ціле число більше за 0\nСпробуйте ще раз: ");
            }

            FloatingMeans[] floatMeans = new FloatingMeans[numberFloatMeans]; // створення масиву об'єктів для плаваючих засобів

            // цикл для створення об'єктів та заповнення масиву даними
            for (int i = 0; i < floatMeans.Length; i++)
            {
                floatMeans[i] = new FloatingMeans();            // виділення пам'яті під конкретний об'єкт
                floatMeans[i].inputData(i);                     // виклик методу для введення даних об'єкта
            }

            string desireMaterial;                              // змінна для зберігання бажаного матеріалу
            double desireSpeed;                                 // змінна для зберігання бажаної швидкості

            // введення бажаного матераілу корпусу
            Console.Write("\nВведіть бажаний матеріал, з якого виготовлений корпус плаваючого засобу: ");
            desireMaterial = Console.ReadLine();

            // введення бажаної швидкості плаваючого засобу
            Console.Write("\nВведіть бажану швидкість плаваючого засобу: ");
            while (true)                                        // цикл для безпечного введення бажаної швидкості
            {
                string inputStr = Console.ReadLine();           // вводиться рядок

                if (double.TryParse(inputStr, out desireSpeed) && desireSpeed > 0) // якщо вдалося перетворити текст на double та число більше за 0
                {
                    break;                                      // вихід із циклу
                }

                Console.Write("\nПомилка! Потрібно ввести дійсне число більше за 0\nСпробуйте ще раз: ");
            }

            Console.WriteLine("\nРЕЗУЛЬТАТ ПОШУКУ ЗА ВВЕДЕНИМИ ДАНИМИ:");

            // перевірка та виведення підходящих об'єктів
            for (int i = 0; i < floatMeans.Length; i++)
            {
                floatMeans[i].analysis(ref desireMaterial, ref desireSpeed); // аналіз конкретного об'єкта масиву
                floatMeans[i].output(i);                                     // виведення результату перевірки для цього об'єкта
            }
        }
    }
}
