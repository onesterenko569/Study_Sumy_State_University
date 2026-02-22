using System;

namespace practical_work_1_4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double diameter, price, radius, area, cost_one_square_centimeter; // оголошення змінних

            // введення діаметру піци
            Console.Write("Vvedit diametr pitsy (u sm): ");
            diameter = Convert.ToDouble(Console.ReadLine());

            // введення ціни піци
            Console.Write("Vvedit tsinu pitsy (u hrn): ");
            price = Convert.ToDouble(Console.ReadLine());

            radius = diameter / 2.0;                   // розрахунок радіусу піци
            area = Math.PI * Math.Pow(radius, 2);      // розрахунок площи піци
            cost_one_square_centimeter = price / area; // розрахунок вартості 1 квадратного см піци

            // виведення результатів
            Console.WriteLine("\nPloshcha pitsy: {0:F2} kv. sm", area);
            Console.WriteLine("Vartist 1 kv. sm: {0:F2} hrn", cost_one_square_centimeter);
        }
    }
}
