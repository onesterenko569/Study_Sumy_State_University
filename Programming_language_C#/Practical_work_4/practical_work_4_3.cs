using System;

namespace practical_work_4_3
{
    internal class Program
    {
        int inputNumber()                                                 // функція для введення кількості учасників змагань
        {
            Console.Write("Введіть кількість учасників змагань: ");

            while (true)                                                  // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                     // вводиться рядок

                if (int.TryParse(inputStr, out int number) && number > 0) // якщо вдалося перетворити текст на int та число більше за 0
                {
                    return number;                                        // повертаємо перетворене значення
                }

                Console.Write("\nПомилка! Кількість учасників має бути цілим числом більшим за 0\nСпробуйте ще раз: ");
            }
        }

        void inputSurname(string[] surname)                               // функція для заповнення масиву прізвищ з клавіатури
        {
            Console.WriteLine();

            for (int i = 0; i < surname.Length; i++)                      // цикл для проходження по всіх елементах масиву
            {
                Console.Write("Введіть прізвище {0} учасника: ", i + 1);
                surname[i] = Console.ReadLine();                          // записуємо введене прізвище у масив
            }
        }

        void printData(string[] surname, double[] jumpResult)                 // функція для виведення даних у формі таблиці
        {
            // виведення заголовку таблиці
            Console.WriteLine(new string('-', 40));
            Console.WriteLine("|  №  |    Прізвище    | Результат (м) |");
            Console.WriteLine(new string('-', 40));

            // виведення рядків таблиці
            for (int i = 0; i < surname.Length; i++)
            {
                Console.WriteLine("|{0,3}  |  {1,12}  |{2,10:F3}     |", i + 1, surname[i], jumpResult[i]);
            }

            // виведення нижньої межі таблиці
            Console.WriteLine(new string('-', 40));
        }

        static void Main(string[] args)                         // головна функція програми
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            Program ob = new Program();                         // створення посилання на об'єкт класу Program для виклику методів
            Random rand = new Random();                         // створення посилання на об'єкт класу Random для генерації випадкових чисел

            int memberNumber = ob.inputNumber();                // введення кількості учасників змагань

            string[] surname = new string[memberNumber];        // створення масиву для зберігання прізвищ
            double[] jumpResult = new double[memberNumber];     // створення масиву для зберігання довжин стрибків

            ob.inputSurname(surname);                           // виклик методу для заповнення масиву прізвищ

            double minJumpResult = 5, maxJumpResult = 9;        // діапазон значень для результатів стрибків

            // заповнення масиву стрибків за допомогою генерації чисел
            for (int i = 0; i < memberNumber; i++)
            {
                jumpResult[i] = minJumpResult + (maxJumpResult - minJumpResult) * rand.NextDouble();
            }

            // виведення початкових невідсортованих даних
            Console.WriteLine("\nПочатковий список учасників та їх результатів:");
            ob.printData(surname, jumpResult);

            Array.Sort(jumpResult, surname);                    // спочатку сортуємо за зростанням
            Array.Reverse(jumpResult);                          // перевертаємо масив довжин стрибків
            Array.Reverse(surname);                             // перевертаємо масив прізвищ

            // виведення відсортованого списку за спаданням по стрибках
            Console.WriteLine("\nВідсортований список учасників за результатами стрибків:");
            ob.printData(surname, jumpResult);

            Console.WriteLine("\nЗолоту медаль отримує {0} з результатом {1:F3}", surname[0], jumpResult[0]);
            Console.WriteLine("Вітаємо!");
        }
    }
}
