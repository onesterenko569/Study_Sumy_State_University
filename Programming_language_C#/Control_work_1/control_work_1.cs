using System;

namespace control_work_1
{
    class Jacket                               // клас для опису куртки
    {
        int attribute;                         // змінна для ознаки відповідності вимогам покупця
        string brand, gender, color;           // змінні для бренду, статі та кольору куртки
        double price;                          // змінна для ціни куртки

        public void inputData(int n)                               // функція для заповнення полів об'єкта даними з клавіатури
        {
            Console.WriteLine("\nВведіть інформацію для {0}-ї куртки:", n + 1);

            // введення бренду
            Console.Write("  Бренд: ");
            brand = Console.ReadLine();

            // введення статі
            Console.Write("  Стать (чоловіча/жіноча): ");
            while (true)                                           // цикл для перевірки правильного введення статі
            {
                gender = Console.ReadLine().ToLower();             // зчитуємо рядок і відразу переводимо в нижній регістр

                if (gender == "чоловіча" || gender == "жіноча")    // якщо введено один із правильних варіантів
                {
                    break;                                         // зупиняємо цикл
                }

                // якщо введено щось інше, виводимо помилку
                Console.Write("  Помилка! Потрібно ввести 'чоловіча' або 'жіноча'\n  Спробуйте ще раз: ");
            }

            // введення кольору
            Console.Write("  Колір: ");
            color = Console.ReadLine();

            // введення ціни
            Console.Write("  Ціна у гривнях: ");
            while (true)                                           // цикл, який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();              // вводиться рядок

                if (double.TryParse(inputStr, out price) && price > 0) // якщо вдалося перетворити текст на double та число більше за 0
                {
                    break;                                         // зупиняємо цикл
                }

                Console.Write("  Помилка! Ціна повинна бути дійсним числом більшим за 0\n  Спробуйте ще раз: ");
            }
        }

        public void analysis(string desireGender, string desireColor, double maxPrice) // функція для аналізу на відповідність вимогам покупця
        {
            // якщо стать і колір збігаються (незалежно від регістру), а ціна не перевищує максимальну
            if (gender == desireGender && color.ToLower() == desireColor.ToLower() && price <= maxPrice)
            {
                attribute = 1;                                     // встановлюємо ознаку, що куртка підходить
            }
            else                                                   // в іншому випадку
            {
                attribute = 0;                                     // встановлюємо ознаку, що куртка не підходить
            }
        }

        public void output(int n)                                  // функція для виведення даних
        {
            if (attribute == 1)                                    // якщо куртка підходить
            {
                Console.WriteLine("\nКуртка номер {0} підходить Вам!", n + 1);
                Console.WriteLine("  Бренд: {0}", brand);
                Console.WriteLine("  Стать: {0}", gender);
                Console.WriteLine("  Колір: {0}", color);
                Console.WriteLine("  Ціна: {0:F2} грн", price);
            }
            else                                                   // якщо куртка не підходить
            {
                Console.WriteLine("\nКуртка номер {0} не підходить Вам", n + 1);
            }
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;    // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі
            Console.InputEncoding = System.Text.Encoding.UTF8;     // встановлення кодування UTF-8 для коректного зчитування кирилиці з консолі

            int numberJackets;                                     // змінна для збереження кількості курток

            // введення кількості курток
            Console.Write("Введіть кількість курток: ");
            while (true)                                           // цикл для безпечного введення кількості курток
            {
                string inputStr = Console.ReadLine();              // вводиться рядок

                if (int.TryParse(inputStr, out numberJackets) && numberJackets > 0 && numberJackets <= 100) // якщо вдалося перетворити текст на int та число більше за 0 і менше за 101
                {
                    break;                                         // вихід із циклу
                }

                Console.Write("\nПомилка! Кількість курток повинна бути цілим числом від 1 до 100 включно\nСпробуйте ще раз: ");
            }

            Jacket[] jackets = new Jacket[numberJackets];          // створення масиву об'єктів для курток

            // цикл для створення об'єктів та заповнення масиву даними
            for (int i = 0; i < jackets.Length; i++)
            {
                jackets[i] = new Jacket();                         // виділення пам'яті під конкретний об'єкт
                jackets[i].inputData(i);                           // виклик методу для введення даних об'єкта
            }

            string desireGender;                                   // змінна для зберігання бажаної статі
            string desireColor;                                    // змінна для зберігання бажаного кольору
            double maxPrice;                                       // змінна для зберігання максимальної ціни

            // введення бажаної статі
            Console.Write("\nВведіть бажану стать куртки (чоловіча/жіноча): ");
            while (true)                                           // цикл для безпечного введення бажаної статі
            {
                desireGender = Console.ReadLine().ToLower();       // зчитуємо рядок і відразу переводимо в нижній регістр

                if (desireGender == "чоловіча" || desireGender == "жіноча") // якщо введено правильний варіант
                {
                    break;                                         // вихід із циклу
                }

                // повідомлення про помилку
                Console.Write("Помилка! Потрібно ввести 'чоловіча' або 'жіноча'\nСпробуйте ще раз: ");
            }

            // введення бажаного кольору
            Console.Write("Введіть бажаний колір куртки: ");
            desireColor = Console.ReadLine();

            // введення максимальної ціни
            Console.Write("Введіть максимальну ціну, яку готові заплатити (у грн): ");
            while (true)                                           // цикл для безпечного введення ціни
            {
                string inputStr = Console.ReadLine();              // вводиться рядок

                if (double.TryParse(inputStr, out maxPrice) && maxPrice > 0) // якщо вдалося перетворити текст на double та число більше за 0
                {
                    break;                                         // вихід із циклу
                }

                Console.Write("Помилка! Ціна повинна бути дійсним числом більшим за 0\nСпробуйте ще раз: ");
            }

            Console.WriteLine("\nРЕЗУЛЬТАТ ПОШУКУ ЗА ВВЕДЕНИМИ ДАНИМИ:");

            // перевірка та виведення підходящих об'єктів
            for (int i = 0; i < jackets.Length; i++)
            {
                jackets[i].analysis(desireGender, desireColor, maxPrice); // аналіз конкретного об'єкта масиву
                jackets[i].output(i);                                     // виведення результату перевірки для цього об'єкта
            }
        }
    }
}
