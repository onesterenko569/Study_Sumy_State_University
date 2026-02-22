using System;

namespace practical_work_1_2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double x, xmin, xmax, dx, c, y;               // оголошення змінних

            Console.Write("Vvedit nyzhnyu mezhu xmin: ");
            xmin = Convert.ToDouble(Console.ReadLine());  // введення xmin

            Console.Write("Vvedit verkhnyu mezhu xmax: ");
            xmax = Convert.ToDouble(Console.ReadLine());  // введення xmax

            Console.Write("Vvedit krok dx: ");
            dx = Convert.ToDouble(Console.ReadLine());    // введення dx

            Console.Write("Vvedit c: ");
            c = Convert.ToDouble(Console.ReadLine());     // введення c
             
            Console.WriteLine();                          // для початку з нового рядка

            for (x = xmin; x <= xmax; x += dx)            // цикл для обрахунку виразу
            {
                y = Math.Pow((c * c * x * x + 2), 1.0 / 3.0) + (Math.Log(x * x + 1)) / (2 * Math.PI); // обрахунок виразу
                Console.WriteLine("Pry x = {0:F2}\ty = {1:F3}", x, y);                                // виведення результатів 
            }
        }
    }
}
