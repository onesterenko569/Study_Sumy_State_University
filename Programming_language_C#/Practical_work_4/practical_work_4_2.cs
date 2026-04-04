using System;

namespace practical_work_4_2
{
    internal class Program
    {
        int inputNumber()                                                 // функція для введення кількості студентів
        {
            Console.Write("Введіть кількість студентів: ");

            while (true)                                                  // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                     // вводиться рядок

                if (int.TryParse(inputStr, out int number) && number > 0) // якщо вдалося перетворити текст на int та число більше за 0
                {
                    return number;                                        // повертаємо перетворене значення
                }

                Console.Write("\nПомилка! Кількість студентів має бути цілим числом більшим за 0\nСпробуйте ще раз: ");
            }
        }

        void inputSurname(string[] surname)                               // функція для заповнення масиву прізвищ з клавіатури
        {
            Console.WriteLine();

            for (int i = 0; i < surname.Length; i++)                      // цикл для проходження по всіх елементах масиву
            {
                Console.Write("Введіть прізвище {0} студента: ", i + 1);
                surname[i] = Console.ReadLine();                          // записуємо введене прізвище у масив
            }
        }

        void printData(string[] surname, double[] rating)                 // функція для виведення даних у формі таблиці
        {
            // виведення заголовку таблиці
            Console.WriteLine(new string('-', 33));
            Console.WriteLine("|  №  |    Прізвище    | Оцінка |");
            Console.WriteLine(new string('-', 33));

            // виведення рядків таблиці
            for (int i = 0; i < surname.Length; i++)
            {
                Console.WriteLine("|{0,3}  |  {1,12}  |{2,7:F3} |", i + 1, surname[i], rating[i]);
            }

            // виведення нижньої межі таблиці
            Console.WriteLine(new string('-', 33));
        }

        void printMenu()                                                  // функція для виведення пунктів меню
        {
            Console.WriteLine("\nОберіть дію:");
            Console.WriteLine("1. Сортувати за прізвищами");
            Console.WriteLine("2. Сортувати за оцінками");
            Console.WriteLine("3. Вихід з програми");
            Console.Write("\nВаш вибір: ");
        }

        static void Main(string[] args)                         // головна функція програми
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            Program ob = new Program();                         // створення посилання на об'єкт класу Program для виклику методів
            Random rand = new Random();                         // створення посилання на об'єкт класу Random для генерації випадкових чисел

            int studentNumber = ob.inputNumber();               // введення кількості студентів

            string[] surname = new string[studentNumber];       // створення масиву для зберігання прізвищ
            double[] rating = new double[studentNumber];        // створення масиву для зберігання оцінок

            ob.inputSurname(surname);                           // виклик методу для заповнення масиву прізвищ

            double minRating = 0, maxRating = 100;              // діапазон значень для оцінок студентів

            // заповнення масиву оцінок за допомогою генерації чисел
            for (int i = 0; i < studentNumber; i++)
            {
                rating[i] = minRating + (maxRating - minRating) * rand.NextDouble();
            }

            // виведення початкових невідсортованих даних
            Console.WriteLine("\nПочатковий список студентів:");
            ob.printData(surname, rating);

            bool running = true;                                // змінна-прапорець для контролю роботи головного циклу

            while (running)                                     // безкінечний цикл меню, поки running не стане false
            {
                ob.printMenu();                                 // виведення меню на екран

                int choice;                                     // змінна для збереження вибору користувача

                while (true)                                    // цикл для перевірки правильності введеного пункту меню
                {
                    string inputStr = Console.ReadLine();       // вводиться рядок

                    if (int.TryParse(inputStr, out choice))     // якщо введено ціле число
                    {
                        break;                                  // вихід з циклу перевірки
                    }

                    Console.Write("\nПомилка! Потрібно ввести ціле число\nСпробуйте ще раз: ");
                }

                switch (choice)                                  // оператор вибору дій залежно від введеного пункту меню
                {
                    case 1:                                     // якщо обрано сортування за прізвищами
                        Array.Sort(surname, rating);            // сортування по прізвищах

                        // виведення результатів
                        Console.WriteLine("\nВідсортований список студентів по прізвищах:");
                        ob.printData(surname, rating);
                        break;

                    case 2:                                     // якщо обрано сортування за оцінками
                        Array.Sort(rating, surname);            // сортування по оцінках

                        // виведення результатів
                        Console.WriteLine("\nВідсортований список студентів по оцінках:");
                        ob.printData(surname, rating);
                        break;

                    case 3:                                     // якщо обрано вихід
                        Console.WriteLine("\nПрограму завершено!");
                        running = false;                        // зупиняємо головний цикл
                        break;

                    default:                                    // якщо введено число, якого немає в меню
                        Console.WriteLine("\nВи ввели не правильний варіант!");
                        break;
                }
            }
        }
    }
}
