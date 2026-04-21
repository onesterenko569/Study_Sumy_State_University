using System;

namespace practical_work_6
{
    internal class Program                                      // головний клас програми
    {
        void printMenu()                                        // функція для виведення меню на екран
        {
            Console.WriteLine("\nОберіть дію:");
            Console.WriteLine("1 - об’єднання рядків");
            Console.WriteLine("2 - вставлення рядків");
            Console.WriteLine("3 - заміна рядків");
            Console.WriteLine("4 - вилучення рядків");
            Console.WriteLine("5 - порівняння двох рядків");
            Console.WriteLine("6 - порівняння символів із двох рядків, які знаходяться на певних місцях");
            Console.WriteLine("7 - визначення індексу першого входження заданого рядка в інший");
            Console.WriteLine("8 - ввести нові речення");
            Console.WriteLine("0 - вихід з програми");
            Console.Write("\nВаш вибір: ");
        }

        int inputProcessing(int minNum, int maxNum)             // функція для безпечного введення цілого числа у заданому діапазоні
        {
            while (true)                                        // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();           // вводиться рядок

                if ((int.TryParse(inputStr, out int num)) && (num >= minNum) && (num <= maxNum)) // якщо вдалося перетворити текст на int та число в межах діапазону
                {
                    return num;                                 // повертаємо перетворене значення
                }

                if (num < minNum)                               // якщо введене число менше за мінімально допустиме
                {
                    Console.WriteLine("\nПомилка! Мінімальне допустиме значення це {0}", minNum);
                }
                else if (num > maxNum)                          // якщо введене число більше за максимально допустиме
                {
                    Console.WriteLine("\nПомилка! Максимальне допустиме значення це {0}", maxNum);
                }
                else                                            // якщо введено некоректні символи
                {
                    Console.Write("\nПомилка! Потрібно ввести ціле додатнє число\nСпробуйте ще раз: ");
                }
            }
        }

        string replacingLines(string line)                      // функція для заміни частини тексту у вибраному рядку
        {
            while (true)                                        // цикл для безпечного пошуку тексту
            {
                Console.Write("\nВведіть частину тексту, яку потрібно замінити у рядку {0}: ", line);
                string oldText = Console.ReadLine();            // введення тексту, який шукаємо

                if (line.Contains(oldText))                     // якщо рядок містить текст для заміни
                {
                    Console.Write("\nВведіть текст, на який хочете замінити: ");
                    string newText = Console.ReadLine();        // введення нового тексту

                    string replacedLine = line.Replace(oldText, newText); // виконання заміни

                    return replacedLine;                        // повертаємо змінений рядок
                }

                // якщо тексту не знайдено, виводимо помилку і цикл повторюється
                Console.WriteLine("\nПомилка! Текст {0} не знайдено у рядку {1}", oldText, line);
                Console.WriteLine("Спробуйте ще раз: ");
            }
        }

        string extractingRows(string line)                      // функція для вилучення символів із рядка
        {
            Console.Write("\nВведіть індекс елемента, з якого видалятимемо елементи: ");
            int startIndex = inputProcessing(0, line.Length - 1); // безпечне введення початкового індексу

            int maxCount = line.Length - startIndex;            // обчислення максимально можливої кількості символів для видалення

            Console.Write("\nВведіть кількість символів для видалення: ");
            int count = inputProcessing(1, maxCount);           // безпечне введення кількості символів

            string removedResult = line.Remove(startIndex, count); // вилучення символів із рядка

            return removedResult;                               // повертаємо обрізаний рядок
        }

        int comparingParts(string firstLine, string secondLine) // функція для порівняння частин двох рядків
        {
            Console.Write("\nВведіть індекс початкового символу для першого рядка: ");
            int indexA = inputProcessing(0, firstLine.Length - 1); // безпечне введення індексу для першого рядка

            Console.Write("\nВведіть індекс початкового символу для другого рядка: ");
            int indexB = inputProcessing(0, secondLine.Length - 1); // безпечне введення індексу для другого рядка

            int maxLenA = firstLine.Length - indexA;            // максимальна довжина для першого рядка
            int maxLenB = secondLine.Length - indexB;           // максимальна довжина для другого рядка

            int maxLength = Math.Min(maxLenA, maxLenB);         // вибір найменшого значення, щоб не вийти за межі рядків

            Console.Write("\nВведіть кількість символів для порівняння (максимум {0}): ", maxLength);
            int length = inputProcessing(1, maxLength);         // безпечне введення кількості символів для порівняння

            return string.Compare(firstLine, indexA, secondLine, indexB, length); // повертаємо результат порівняння (0, -1 або 1)
        }

        int findingIndex(string line)                           // функція для пошуку індексу входження тексту
        {
            Console.Write("\nВведіть текст або символ, індекс якого потрібно знайти: ");
            string searchText = Console.ReadLine();             // введення тексту для пошуку

            return line.IndexOf(searchText);                    // повертаємо індекс першого входження (або -1)
        }

        static void Main(string[] args)                         // головна функція програми
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            bool running = true;                                // змінна для керування нескінченним циклом меню
            string firstLine, secondLine;                       // змінні для збереження двох речень

            Program ob = new Program();                         // створення об'єкта класу для доступу до методів

            Console.Write("Введіть перше речення: ");
            firstLine = Console.ReadLine();                     // введення першого рядка

            Console.Write("Введіть друге речення: ");
            secondLine = Console.ReadLine();                    // введення другого рядка

            while (running)                                     // головний цикл роботи програми
            {
                ob.printMenu();                                 // виклик методу для виведення меню

                int userChoice = ob.inputProcessing(0, 8);      // безпечне зчитування вибору користувача (від 0 до 8)

                switch (userChoice)                              // оператор вибору дій залежно від введеного числа
                {
                    case 0:
                        Console.WriteLine("\nУдачі!");
                        running = false;                        // зупинка циклу
                        break;

                    case 1:
                        string mergedLines = firstLine + " " + secondLine; // об'єднання рядків через пробіл
                        Console.WriteLine("\nРезультат об'єднання рядків {0} та {1}:", firstLine, secondLine);
                        Console.WriteLine(mergedLines);
                        break;

                    case 2:
                        Console.Write("\nВведіть індекс елемента, з якого зробити вставку другого рядка в перший: ");
                        int index = ob.inputProcessing(0, firstLine.Length); // введення індексу для вставки

                        string insertingRows = firstLine.Insert(index, secondLine); // вставлення другого рядка в перший

                        Console.WriteLine("\nРезультат вставлення другого рядка в перший з {0} позиції:", index);
                        Console.WriteLine(insertingRows);
                        break;

                    case 3:
                        Console.WriteLine("\nОберіть рядок у якому будемо робити заміну: ");
                        Console.WriteLine("1 - {0}", firstLine);
                        Console.WriteLine("2 - {0}", secondLine);
                        int lineNumber = ob.inputProcessing(1, 2); // вибір рядка для редагування

                        if (lineNumber == 1)                    // якщо обрано перший рядок
                        {
                            string replacedFirstLine = ob.replacingLines(firstLine);

                            Console.Write("\nРезультат заміни: ");
                            Console.WriteLine(replacedFirstLine);
                        }
                        else                                    // якщо обрано другий рядок
                        {
                            string replacedSecondLine = ob.replacingLines(secondLine);

                            Console.Write("\nРезультат заміни: ");
                            Console.WriteLine(replacedSecondLine);
                        }
                        break;

                    case 4:
                        Console.WriteLine("\nОберіть рядок у якому будемо вилучати символи: ");
                        Console.WriteLine("1 - {0}", firstLine);
                        Console.WriteLine("2 - {0}", secondLine);
                        int linNumber = ob.inputProcessing(1, 2); // вибір рядка для редагування

                        if (linNumber == 1)                     // якщо обрано перший рядок
                        {
                            string result = ob.extractingRows(firstLine);

                            Console.Write("\nРезультат видалення: ");
                            Console.WriteLine(result);
                        }
                        else                                    // якщо обрано другий рядок
                        {
                            string result = ob.extractingRows(secondLine);

                            Console.Write("\nРезультат видалення: ");
                            Console.WriteLine(result);
                        }
                        break;

                    case 5:
                        if (Equals(firstLine, secondLine))      // перевірка рядків на повну ідентичність
                        {
                            Console.WriteLine("\nРядки однакові!");
                        }
                        else                                    // якщо рядки відрізняються
                        {
                            Console.WriteLine("\nРядки різні!");
                        }

                        break;

                    case 6:
                        int compareResult = ob.comparingParts(firstLine, secondLine); // виклик функції порівняння частин

                        Console.WriteLine("\nРезультат порівняння:");
                        if (compareResult == 0)                 // якщо частини ідентичні
                        {
                            Console.WriteLine("Обрані частини рядків абсолютно однакові!");
                        }
                        else if (compareResult < 0)             // якщо перша частина за алфавітом раніше
                        {
                            Console.WriteLine("Частина першого рядка стоїть за алфавітом раніше за частину другого");
                        }
                        else                                    // якщо перша частина за алфавітом пізніше
                        {
                            Console.WriteLine("Частина першого рядка стоїть за алфавітом пізніше за частину другого");
                        }
                        break;

                    case 7:
                        Console.WriteLine("\nОберіть рядок, у якому будемо шукати текст:");
                        Console.WriteLine("1 - {0}", firstLine);
                        Console.WriteLine("2 - {0}", secondLine);
                        int searchLineNumber = ob.inputProcessing(1, 2); // вибір рядка для пошуку

                        int foundIndex;                         // змінна для збереження знайденого індексу

                        if (searchLineNumber == 1)              // якщо обрано перший рядок
                        {
                            foundIndex = ob.findingIndex(firstLine);
                        }
                        else                                    // якщо обрано другий рядок
                        {
                            foundIndex = ob.findingIndex(secondLine);
                        }

                        if (foundIndex != -1)                   // якщо текст успішно знайдено
                        {
                            Console.WriteLine("\nУспіх! Індекс першого входження: {0}", foundIndex);
                        }
                        else                                    // якщо тексту немає в рядку
                        {
                            Console.WriteLine("\nЗбігів не знайдено! Такого тексту немає у вибраному рядку");
                        }
                        break;

                    case 8:
                        Console.Write("\nВведіть нове перше речення: ");
                        firstLine = Console.ReadLine();         // перезапис першого рядка

                        Console.Write("Введіть нове друге речення: ");
                        secondLine = Console.ReadLine();        // перезапис другого рядка

                        Console.WriteLine("\nРядки успішно оновлено! Тепер усі операції в меню будуть застосовуватися до нового тексту");
                        break;

                    default:                                    // обробка непередбачених варіантів вводу
                        Console.WriteLine("\nПомилка! Число повинно бути від 0 до 8");
                        break;
                }
            }
        }
    }
}
