using System;

namespace practical_work_3
{
    internal class Program
    {
        int inputSize(string arrName)                                // функція для введення розміру масиву
        {
            Console.Write("\nВведіть розмір для масиву {0}: ", arrName);

            while (true)                                              // цикл, який триватиме поки не спрацює return
            {
                string inputStr = Console.ReadLine();                 // вводиться рядок

                if (int.TryParse(inputStr, out int size) && size > 0) // якщо вдалося перетворити текст на int та число більше за 0
                {
                    return size;                                      // повертаємо перетворене значення
                }

                Console.Write("Помилка! Розмір масиву має бути цілим числом більшим за 0\nСпробуйте ще раз: ");
            }
        }

        void inputArray(ref double[] arr, string arrName)          // функція для введення масиву
        {
            Console.WriteLine("\nВведіть елементи масиву {0}: ", arrName);

            for (int i = 0; i < arr.Length; i++)                    // цикл для введення
            {
                Console.Write("{0}[{1}] = ", arrName, i);

                while (true)                                        // цикл, який триватиме поки не спрацює break
                {
                    string inputStr = Console.ReadLine();           // вводиться рядок

                    if (double.TryParse(inputStr, out double val))  // якщо вдалося перетворити текст на double
                    {
                        arr[i] = val;                               // додаємо перетворене значення в масив
                        break;                                      // завершуємо цикл
                    }

                    Console.Write("Помилка! Значення {0}[{1}] повинно бути дійсним числом\nСпробуйте ще раз: ", arrName, i);
                }
            }
        }

        void analysis(ref double[] arr, double num, out double sum, out double geomMean) // функція для обчислення суми та середнього геометричного
        {
            sum = 0;                                     // присвоєння початкового значення
            int number = 0;                              // змінна для зберігання кількості чисел під коренем
            double prod = 1;                             // змінна для зберігання підкореневого добутку чисел

            for (int i = 0; i < arr.Length; i++)         // цикл по елементах масиву
            {
                if (arr[i] > 0 && arr[i] < num)          // якщо елемент масиву більший за 0 та менший за задане користувачем число
                {
                    sum += arr[i];                       // обчислюємо суму елементів
                    prod *= arr[i];                      // обчислюємо підкореневий вираз
                    number++;                            // підраховуємо кількість елементів
                }
            }

            if (number > 0)                              // якщо знайдено елементи які підпадають під умову
            {
                geomMean = Math.Pow(prod, 1.0 / number); // обчислюємо середнє геометричне
            }
            else                                         // якщо не знайдено елементів які підпадають під умову
            {
                geomMean = -1;                           // присвоюємо значення -1
            }
        }

        static void Main(string[] args)                  // головна функція програми
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // встановлення кодування UTF-8 для коректного відображення кирилиці в консолі

            Program ob = new Program();                  // створюємо екземпляр класу Program, щоб викликати його нестатичні методи
            int arrSize;                                 // змінна для зберігання розміру масиву
            double sum, geomMean, num;                   // змінні для зберігання суми елементів, середнього геометричного та заданого користувачем числа відповідно

            arrSize = ob.inputSize("arr1");              // введення розміру для першого масиву
            double[] arr1 = new double[arrSize];         // виділення пам'яті під масив

            arrSize = ob.inputSize("arr2");              // введення розміру для другого масиву
            double[] arr2 = new double[arrSize];         // виділення пам'яті під масив

            arrSize = ob.inputSize("arr3");              // введення розміру для третього масиву
            double[] arr3 = new double[arrSize];         // виділення пам'яті під масив

            Console.Write("\nВведіть додатнє число для знаходження середнього геометричного: ");

            while (true)                                 // цикл який триватиме поки не спрацює break
            {
                string inputStr = Console.ReadLine();    // введення рядка

                if (double.TryParse(inputStr, out double val) && val > 0) // якщо вдалося перетворити текст на double та число більше за 0
                {
                    num = val;                           // присвоюємо значення
                    break;                               // зупиняємо цикл
                }

                Console.Write("Помилка! Введіть дійсне число більше за 0\nСпробуйте ще раз: ");
            }

            ob.inputArray(ref arr1, "arr1");             // введення першого масиву
            ob.analysis(ref arr1, num, out sum, out geomMean); // обчислення суми та середнього геометричного

            // виведення результатів
            Console.WriteLine("\nДля arr1:");
            Console.WriteLine("   Сума позитивних елементів менших за {0} = {1}", num, sum);
            if (geomMean != -1)                          // якщо середнє геометричне було обчислено
            {
                Console.WriteLine("   Cереднє геометричне позитивних елементів менших за {0} = {1:F3}", num, geomMean);
            }
            else                                         // якщо середнє геометричне не було обчислено
            {
                Console.WriteLine("   У даному масиві немає елементів, які б були позитивними та менші за {0}", num);
            }

            ob.inputArray(ref arr2, "arr2");             // введення другого масиву
            ob.analysis(ref arr2, num, out sum, out geomMean); // обчислення суми та середнього геометричного

            // виведення результатів
            Console.WriteLine("\nДля arr2:");
            Console.WriteLine("   Сума позитивних елементів менших за {0} = {1}", num, sum);
            if (geomMean != -1)                          // якщо середнє геометричне було обчислено
            {
                Console.WriteLine("   Cереднє геометричне позитивних елементів менших за {0} = {1:F3}", num, geomMean);
            }
            else                                         // якщо середнє геометричне не було обчислено
            {
                Console.WriteLine("   У даному масиві немає елементів, які б були позитивними та менші за {0}", num);
            }

            ob.inputArray(ref arr3, "arr3");             // введення третього масиву
            ob.analysis(ref arr3, num, out sum, out geomMean); // обчислення суми та середнього геометричного

            // виведення результатів
            Console.WriteLine("\nДля arr3:");
            Console.WriteLine("   Сума позитивних елементів менших за {0} = {1}", num, sum);
            if (geomMean != -1)                          // якщо середнє геометричне було обчислено
            {
                Console.WriteLine("   Cереднє геометричне позитивних елементів менших за {0} = {1:F3}", num, geomMean);
            }
            else                                         // якщо середнє геометричне не було обчислено
            {
                Console.WriteLine("   У даному масиві немає елементів, які б були позитивними та менші за {0}", num);
            }
        }
    }
}
