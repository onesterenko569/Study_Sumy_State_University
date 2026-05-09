using System;
using System.IO;

namespace practical_work_12_2
{
    internal class Program                                              // головний клас програми
    {
        int inputSize()                                                 // метод для безпечного введення розміру матриці
        {
            string inputStr;                                            // змінна для зчитування рядка з консолі

            while (true)                                                // нескінченний цикл, який триватиме поки не спрацює return
            {
                inputStr = Console.ReadLine();                          // зчитування введеного тексту

                if (int.TryParse(inputStr, out int val) && val > 0)     // якщо вдалося перетворити текст на int та число більше нуля
                {
                    return val;                                         // повернення коректного значення
                }

                Console.Write("\nПомилка! Розмір повинен бути цілим числом більшим за 0\nСпробуйте ще раз: "); // виведення повідомлення про помилку
            }
        }

        static void Main(string[] args)                                 // головна функція програми
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;         // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі
            Console.InputEncoding = System.Text.Encoding.UTF8;          // встановлення кодування UTF-8 для коректного зчитування кирилиці з консолі

            Program ob = new Program();                                 // створення екземпляра класу для виклику методів

            int rowOne, colOne, rowTwo, colTwo;                         // змінні для зберігання розмірностей матриць

            while (true)                                                // цикл для безпечного введення розмірностей
            {
                Console.Write("Введіть кількість рядків для першої матриці: ");
                rowOne = ob.inputSize();                                // виклик методу для введення кількості рядків першої матриці

                Console.Write("\nВведіть кількість стовпців для першої матриці: ");
                colOne = ob.inputSize();                                // виклик методу для введення кількості стовпців першої матриці

                rowTwo = colOne;                                        // прирівнювання рядків другої матриці до стовпців першої
                Console.WriteLine("\nОскільки для множення матриць, кількість стовпців першої матриці повинна дорівнювати");
                Console.WriteLine("кількості рядків другої матриці то кількість рядків другої матриці = {0}", rowTwo);

                Console.Write("\nВведіть кількість стовпців для другої матриці: ");
                colTwo = ob.inputSize();                                // виклик методу для введення кількості стовпців другої матриці

                if ((rowOne * colOne + rowTwo * colTwo) > 100)          // перевірка чи не перевищує загальна кількість елементів 100
                {
                    Console.WriteLine("\nПомилка! Сумарна кількість елементів у двох матрицях не повинна перевищувати 100");
                    Console.WriteLine("Спробуйте ще раз:\n");
                }
                else
                {
                    Console.WriteLine("\nРозміри матриць успішно введено!");
                    break;                                              // зупинка циклу
                }
            }

            double[,] matrixOne = new double[rowOne, colOne];           // виділення пам'яті для першої матриці
            double[,] matrixTwo = new double[rowTwo, colTwo];           // виділення пам'яті для другої матриці

            try                                                         // блок обробки винятків при роботі з файлом
            {
                StreamReader sr = new StreamReader("C:\\Users\\final\\Desktop\\СумДу\\4 семестр\\Програмування під платформу. Net Framework\\C#\\practical_work_12_2\\f1.txt"); // створення об'єкта потоку для читання

                for (int i = 0; i < rowOne; i++)                        // цикл для проходу по рядках першої матриці
                {
                    for (int j = 0; j < colOne; j++)                    // цикл для проходу по стовпцях першої матриці
                    {
                        matrixOne[i, j] = Convert.ToDouble(sr.ReadLine()); // зчитування числа з файлу та запис у масив
                    }
                }

                for (int i = 0; i < rowTwo; i++)                        // цикл для проходу по рядках другої матриці
                {
                    for (int j = 0; j < colTwo; j++)                    // цикл для проходу по стовпцях другої матриці
                    {
                        matrixTwo[i, j] = Convert.ToDouble(sr.ReadLine()); // зчитування числа з файлу та запис у масив
                    }
                }

                sr.Close();                                             // закриття потоку читання
            }
            catch (FileNotFoundException)                               // перехоплення помилки якщо файл не знайдено
            {
                Console.WriteLine("\nПомилка! Файл для зчитування даних не існує");
                return;                                                 // зупинка програми
            }
            catch (Exception ex)                                        // перехоплення інших непередбачуваних помилок
            {
                Console.WriteLine("\nСталася помилка при відкритті файлу для зчитування: {0}", ex.Message);
                return;                                                 // зупинка програми
            }

            StreamWriter sw = new StreamWriter("C:\\Users\\final\\Desktop\\СумДу\\4 семестр\\Програмування під платформу. Net Framework\\C#\\practical_work_12_2\\f2.txt"); // створення об'єкта потоку для запису

            Console.Write("\nПерша зчитана матриця розмірності {0} на {1}:", rowOne, colOne); // виведення заголовка у консоль
            sw.Write("\nПерша зчитана матриця розмірності {0} на {1}:", rowOne, colOne);      // запис заголовка у файл

            for (int i = 0; i < rowOne; i++)                            // цикл для виведення першої матриці
            {
                Console.WriteLine("");                                  // перехід на новий рядок у консолі
                sw.WriteLine("");                                       // перехід на новий рядок у файлі

                for (int j = 0; j < colOne; j++)
                {
                    Console.Write("{0,4}  ", matrixOne[i, j]);          // виведення елемента першої матриці в консоль
                    sw.Write("{0,4}  ", matrixOne[i, j]);               // запис елемента першої матриці у файл
                }
            }

            Console.Write("\n\nДруга зчитана матриця розмірності {0} на {1}:", rowTwo, colTwo); // виведення заголовка у консоль
            sw.Write("\n\nДруга зчитана матриця розмірності {0} на {1}:", rowTwo, colTwo);      // запис заголовка у файл

            for (int i = 0; i < rowTwo; i++)                            // цикл для виведення другої матриці
            {
                Console.WriteLine("");                                  // перехід на новий рядок у консолі
                sw.WriteLine("");                                       // перехід на новий рядок у файлі

                for (int j = 0; j < colTwo; j++)
                {
                    Console.Write("{0,4}  ", matrixTwo[i, j]);          // виведення елемента другої матриці в консоль
                    sw.Write("{0,4}  ", matrixTwo[i, j]);               // запис елемента другої матриці у файл
                }
            }

            double[,] matrixResult = new double[rowOne, colTwo];        // виділення пам'яті для матриці результатів обчислення

            for (int i = 0; i < rowOne; i++)                            // цикл для проходу по рядках
            {
                for (int j = 0; j < colTwo; j++)                        // цикл для проходу по стовпцях
                {
                    matrixResult[i, j] = 0;                             // початкова ініціалізація нулем

                    for (int t = 0; t < rowTwo; t++)                    // внутрішній цикл для обчислення добутків
                    {
                        matrixResult[i, j] += matrixOne[i, t] * matrixTwo[t, j]; // формула множення матриць
                    }
                }
            }

            Console.Write("\n\nРезультат множення двох матриць:");      // виведення заголовка у консоль
            sw.Write("\n\nРезультат множення двох матриць:");           // запис заголовка у файл

            for (int i = 0; i < rowOne; i++)                            // цикл для виведення матриці результатів
            {
                Console.WriteLine("");                                  // перехід на новий рядок у консолі
                sw.WriteLine("");                                       // перехід на новий рядок у файлі

                for (int j = 0; j < colTwo; j++)
                {
                    Console.Write("{0,5}  ", matrixResult[i, j]);       // виведення результату в консоль
                    sw.Write("{0,5}  ", matrixResult[i, j]);            // запис результату у файл
                }
            }

            sw.Close();                                                 // закриття потоку запису
        }
    }
}
