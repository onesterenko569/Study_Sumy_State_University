using System;
using System.Windows.Forms;

namespace practical_work_14_1
{
    public partial class Form1 : Form
    {
        public Form1()                                                          // конструктор класу форми
        {
            InitializeComponent();                                              // ініціалізація компонентів форми
        }

        private void button1_Click_1(object sender, EventArgs e)                // метод-обробник події натискання на кнопку
        {
            listBox1.Items.Clear();                                             // очищення списку від попередніх результатів

            if (!double.TryParse(textBox1.Text, out double x_min))              // перевірка та зчитування значення x_min
            {
                MessageBox.Show("Значення x_min повинне бути дійсним числом!", "Помилка вводу", MessageBoxButtons.OK, MessageBoxIcon.Error); // виведення повідомлення про помилку
                textBox1.Clear();                                               // очищення поля вводу
                textBox1.Focus();                                               // встановлення курсора в поле

                return;                                                         // переривання виконання методу
            }

            if (!double.TryParse(textBox2.Text, out double x_max))              // перевірка та зчитування значення x_max
            {
                MessageBox.Show("Значення x_max повинне бути дійсним числом!", "Помилка вводу", MessageBoxButtons.OK, MessageBoxIcon.Error); // виведення повідомлення про помилку
                textBox2.Clear();                                               // очищення поля вводу
                textBox2.Focus();                                               // встановлення курсора в поле

                return;                                                         // переривання виконання методу
            }

            if (!double.TryParse(textBox3.Text, out double dx))                 // перевірка та зчитування значення кроку dx
            {
                MessageBox.Show("Значення dx повинне бути дійсним числом!", "Помилка вводу", MessageBoxButtons.OK, MessageBoxIcon.Error); // виведення повідомлення про помилку
                textBox3.Clear();                                               // очищення поля вводу
                textBox3.Focus();                                               // встановлення курсора в поле

                return;                                                         // переривання виконання методу
            }

            if (!double.TryParse(textBox4.Text, out double c))                  // перевірка та зчитування значення параметра c
            {
                MessageBox.Show("Значення c повинне бути дійсним числом!", "Помилка вводу", MessageBoxButtons.OK, MessageBoxIcon.Error); // виведення повідомлення про помилку
                textBox4.Clear();                                               // очищення поля вводу
                textBox4.Focus();                                               // встановлення курсора в поле

                return;                                                         // переривання виконання методу
            }

            const double EPS = 1e-9;                                            // константа для порівняння з нулем

            for (double x = x_min; x <= x_max + EPS; x += dx)                   // цикл табуляції від x_min до x_max із кроком dx
            {
                double cx = c * x;                                              // обчислення c * x

                if (cx < 0)                                                     // перевірка для підкореневого виразу
                {
                    listBox1.Items.Add($"При x = {x:F3} та c = {c:F3} підкореневий вираз менший за 0");
                    continue;
                }

                if (Math.Abs(Math.Cos(cx)) < EPS)                               // перевірка для тангенса
                {
                    listBox1.Items.Add($"При x = {x:F3} та c = {c:F3} неможливо обрахувати tg(cx)");
                    continue;
                }

                double c_x = c - x;                                             // обчислення c - x

                if (c_x < EPS)                                                  // перевірка для логарифма
                {
                    listBox1.Items.Add($"При x = {x:F3} та c = {c:F3} неможливо обрахувати ln(c - x)");
                    continue;
                }

                double ln_c_x = Math.Log(c_x);                                  // обчислення логарифма

                if (Math.Abs(ln_c_x) < EPS)                                     // перевірка щоб знаменник не дорівнював нулю
                {
                    listBox1.Items.Add($"При x = {x:F3} та c = {c:F3} відбувається ділення на нуль");
                    continue;
                }

                double root_exp = ln_c_x + Math.Sin(x);                         // обчислення підкореневого виразу

                double root = Math.Sign(root_exp) * Math.Pow(Math.Abs(root_exp), 1.0 / 5.0); // обчислення кореня 5 степеня

                double y = root + (Math.Tan(cx) + Math.Sqrt(cx)) / ln_c_x;      // обчислення y

                listBox1.Items.Add($"При x = {x:F3} та c = {c:F3} y = {y:F4}");
            }
        }
    }
}
