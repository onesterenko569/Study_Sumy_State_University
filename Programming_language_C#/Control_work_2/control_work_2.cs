using System;

namespace control_work_2
{
    internal class Program
    {
        delegate double MathFunc(double x);

        int inputSize(string arrName)
        {
            Console.Write("\nВведіть розмір для масиву {0}: ", arrName);

            while (true)
            {
                string inputStr = Console.ReadLine();

                if (int.TryParse(inputStr, out int size) && size > 0)
                {
                    return size;
                }

                Console.Write("Помилка! Розмір масиву має бути цілим числом більшим за 0\nСпробуйте ще раз: ");
            }
        }

        void inputArray(double[] arr, string arrName)
        {
            Console.WriteLine("\nВведіть елементи масиву {0}: ", arrName);

            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write("  {0}[{1}] = ", arrName, i);

                while (true)
                {
                    string inputStr = Console.ReadLine();

                    if (double.TryParse(inputStr, out double val))
                    {
                        if (Math.Abs(Math.Cos(val)) < 1e-9)
                        {
                            Console.Write("  Помилка! Значення призведе до ділення на нуль при обчисленні тангенсу\n  Спробуйте ще раз: ");
                            continue;
                        }

                        arr[i] = val;
                        break;
                    }

                    Console.Write("  Помилка! Значення {0}[{1}] повинно бути дійсним числом\n  Спробуйте ще раз: ", arrName, i);
                }
            }
        }

        void calculation(double[] arr, MathFunc f1, MathFunc f2, out double res1, out double res2)
        {
            res1 = 0; res2 = 0;

            for (int i = 0; i < arr.Length; i++)
            {
                res1 += arr[i] * f1(arr[i]);
                res2 += arr[i] * f2(arr[i]);
            }

            res2 *= res1;
        }

        double absSinFunc(double x)
        {
            return Math.Abs(Math.Sin(x));
        }

        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;

            Program ob = new Program();

            int xSize = ob.inputSize("x");
            double[] x = new double[xSize];

            int ySize = ob.inputSize("y");
            double[] y = new double[ySize];

            ob.inputArray(x, "x");
            ob.inputArray(y, "y");

            double A, B;
            ob.calculation(x, Math.Sin, Math.Cos, out A, out B);

            double D, C;

            ob.calculation(y, Math.Tan, ob.absSinFunc, out D, out C);

            double denominator = Math.Sin(D) + Math.Abs(Math.Cos(D));

            if (Math.Abs(denominator) < 1e-9)
            {
                Console.WriteLine("\nПомилка! Ділення на нуль. Обчислити значення виразу неможливо");
            }
            else
            {
                double theta = (A * Math.Tan(D) + B * Math.Cos(C)) / denominator;

                Console.WriteLine("\nРезультати обчислень:");
                Console.WriteLine("  A = {0:F3}\n  B = {1:F3}\n  C = {2:F3}\n  D = {3:F3}", A, B, C, D);
                Console.WriteLine("\n  theta = {0:F4}", theta);
            }
        }
    }
}
