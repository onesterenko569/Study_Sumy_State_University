using System;
using System.IO;

namespace practical_work_12_1
{
    internal class Program                                              // головний клас програми
    {
        static void Main(string[] args)                                 // головна функція програми
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;         // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі
            Console.InputEncoding = System.Text.Encoding.UTF8;          // встановлення кодування UTF-8 для коректного зчитування кирилиці з консолі

            double xmin, xmax, dx, k;                                   // змінні для зберігання вхідних даних

            try                                                         // блок обробки винятків при роботі з файлом
            {
                // створення об'єкта потоку для читання з файлу
                StreamReader sr = new StreamReader("C:\\Users\\final\\Desktop\\СумДу\\4 семестр\\Програмування під платформу. Net Framework\\C#\\practical_work_12_1\\practical_work_12_1\\f1.txt");

                xmin = Convert.ToDouble(sr.ReadLine());                 // зчитування xmin
                xmax = Convert.ToDouble(sr.ReadLine());                 // зчитування xmax
                dx = Convert.ToDouble(sr.ReadLine());                   // зчитування dx
                k = Convert.ToDouble(sr.ReadLine());                    // зчитування k

                sr.Close();                                             // закриття потоку читання
            }
            catch (FileNotFoundException)                               // якщо файл не знайдено
            {
                Console.WriteLine("\nПомилка! Файл для зчитування даних не існує");
                return;                                                 // зупинка програми
            }
            catch (Exception ex)                                        // якщо сталася інша помилка
            {
                Console.WriteLine("\nСталася помилка при відкритті файлу для зчитування: {0}", ex.Message);
                return;                                                 // зупинка програми
            }

            // створення об'єкта потоку для запису у файл
            StreamWriter sw = new StreamWriter("C:\\Users\\final\\Desktop\\СумДу\\4 семестр\\Програмування під платформу. Net Framework\\C#\\practical_work_12_1\\practical_work_12_1\\f2.txt");

            // виведення зчитаних даних у консоль
            Console.WriteLine("\nДані успішно зчитано:");
            Console.WriteLine("   xmin = {0}", xmin);
            Console.WriteLine("   xmax = {0}", xmax);
            Console.WriteLine("   dx = {0}", dx);
            Console.WriteLine("   k = {0}", k);

            // виведення зчитаних даних у файл
            sw.WriteLine("\nДані успішно зчитано:");
            sw.WriteLine("   xmin = {0}", xmin);
            sw.WriteLine("   xmax = {0}", xmax);
            sw.WriteLine("   dx = {0}", dx);
            sw.WriteLine("   k = {0}", k);

            const double EPS = 1e-9;                                    // константа для перевірки наближення до нуля
            double y, kx, tg_kx, root_exp, root, sin_kx, log_exp;       // проміжні змінні для обчислень

            Console.WriteLine("\nРезультат обчислень:");
            Console.WriteLine("\n   x        y");                       // шапка таблиці результатів в консолі
            sw.WriteLine("\n   x        y");                            // шапка таблиці результатів у файлі

            for (double x = xmin; x <= xmax; x += dx)                   // цикл для табулювання функції
            {
                kx = k * x;                                             // обчислення kx

                if (Math.Abs(Math.Cos(kx)) < EPS)                       // перевірка на нульовий косинус
                {
                    Console.WriteLine("{0,8:F2}    Неможливо розрахувати tg({0:F2})", x);
                    sw.WriteLine("{0,8:F2}    Неможливо розрахувати tg({0:F2})", x);

                    continue;                                           // перехід до наступного кроку циклу
                }

                tg_kx = Math.Tan(kx);                                   // обчислення тангенса

                if (Math.Abs(tg_kx) < EPS)                              // перевірка знаменника на нуль
                {
                    Console.WriteLine("{0,8:F2}    Ділення на нуль", x);
                    sw.WriteLine("{0,8:F2}    Ділення на нуль", x);

                    continue;                                           // перехід до наступного кроку циклу
                }

                root_exp = 1.0 / tg_kx;                                 // обчислення підкореневого виразу

                if (root_exp < 0)                                       // перевірка на від'ємний підкореневий вираз
                {
                    Console.WriteLine("{0,8:F2}    Від'ємний підкореневий вираз", x);
                    sw.WriteLine("{0,8:F2}    Від'ємний підкореневий вираз", x);

                    continue;                                           // перехід до наступного кроку циклу
                }

                root = Math.Pow(root_exp, 1.0 / 3.0);                   // обчислення кубічного кореня

                sin_kx = Math.Sin(kx);                                  // обчислення синуса

                if (sin_kx < 0 || Math.Abs(sin_kx) < EPS)               // перевірка підлогарифмічного виразу
                {
                    Console.WriteLine("{0,8:F2}    Підлогарифмічний вираз <= 0", x);
                    sw.WriteLine("{0,8:F2}    Підлогарифмічний вираз <= 0", x);

                    continue;                                           // перехід до наступного кроку циклу
                }

                log_exp = Math.Log(sin_kx);                             // обчислення натурального логарифма

                if (Math.Abs(log_exp) < EPS)                            // перевірка знаменника на нуль
                {
                    Console.WriteLine("{0,8:F2}    Ділення на нуль", x);
                    sw.WriteLine("{0,8:F2}    Ділення на нуль", x);

                    continue;                                           // перехід до наступного кроку циклу
                }

                y = root + Math.Cos(kx) / log_exp;                      // фінальне обчислення значення функції

                Console.WriteLine("{0,8:F2}    {1:F3}", x, y);          // виведення результату в консоль
                sw.WriteLine("{0,8:F2}    {1:F3}", x, y);               // запис результату у файл
            }

            sw.Close();                                                 // закриття потоку запису
        }
    }
}
