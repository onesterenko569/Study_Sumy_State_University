using System;

namespace practical_work_1_5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double score; // оголошення змінної

            // користувач вводить кількість балів
            Console.Write("Vvedit vashu kilkist baliv (0-100): ");
            score = Convert.ToDouble(Console.ReadLine());
            
            if (score < 0 || score > 100) // перевірка чи користувач правильно ввів кількість балів
            {
                Console.WriteLine("Pomylka! Kilkist baliv maye buty vid 0 do 100");
            }
            else if (score >= 90) // якщо 90-100 балів
            {
                Console.WriteLine("Vasha otsinka: A (vidminno)\nVy pretenduyete na pidvyshchenu stypendiyu!");
            }
            else if (score >= 82) // якщо 82-89 балів
            {
                Console.WriteLine("Vasha otsinka: B (dobre)\nVy pretenduyete na zvychaynu stypendiyu");
            }
            else if (score >= 75) // якщо 75-81 балів
            {
                Console.WriteLine("Vasha otsinka: C (dobre)\nShansy na stypendiyu zalezhat vid reytynhu");
            }
            else if (score >= 64) // якщо 64-74 балів
            {
                Console.WriteLine("Vasha otsinka: D (zadovilno)\nStypendiya ne narakhovuyetsya");
            }
            else if (score >= 60) // якщо 60-63 балів
            {
                Console.WriteLine("Vasha otsinka: E (zadovilno)\nZa stypendiyu mozhete zabuty");
            }
            else if (score >= 35) // якщо 35-59 балів
            {
                Console.WriteLine("Vasha otsinka: FX (nezadovilno)\nPotribne pereskladannya");
            }
            else // якщо 1-34 балів
            {
                Console.WriteLine("Vasha otsinka: F (nezadovilno)\nVitayemo, vy vyhraly VIP-kvytok na povtorne vyvchennya tsiyeyi dystsypliny!");
            }
        }
    }
}
