using System;
using System.Windows.Forms;

namespace coursework
{
    public partial class Form1 : Form
    {
        public Form1()                                                                  // конструктор класу форми
        {
            InitializeComponent();                                                      // ініціалізація компонентів форми
        }

        private void Form1_Load(object sender, EventArgs e)                             // метод-обробник завантаження форми
        {
            this.Width = 1143;                                                          // встановлення ширини вікна
            this.Height = 450;                                                          // встановлення висоти вікна
        }

        private void button1_Click(object sender, EventArgs e)                          // метод-обробник події натискання на кнопку
        {
            // очищення вікон
            listBox1.Items.Clear();
            listBox2.Items.Clear();

            if (!double.TryParse(textBox1.Text, out double xmin))                       // перевірка та зчитування значення xmin
            {
                MessageBox.Show("Значення xmin повинне бути дійсним числом!", "ПОМИЛКА ВВЕДЕННЯ", MessageBoxButtons.OK, MessageBoxIcon.Error);
                textBox1.Focus();
                textBox1.SelectAll();
                return;
            }

            if (!double.TryParse(textBox2.Text, out double xmax) || xmax <= xmin)       // перевірка та зчитування значення xmax
            {
                MessageBox.Show("Значення xmax повинне бути дійсним числом більшим за xmin!", "ПОМИЛКА ВВЕДЕННЯ", MessageBoxButtons.OK, MessageBoxIcon.Error);
                textBox2.Focus();
                textBox2.SelectAll();
                return;
            }

            if (!double.TryParse(textBox3.Text, out double dx))                         // перевірка та зчитування значення кроку dx
            {
                MessageBox.Show("Значення кроку dx повинне бути дійсним числом!", "ПОМИЛКА ВВЕДЕННЯ", MessageBoxButtons.OK, MessageBoxIcon.Error);
                textBox3.Focus();
                textBox3.SelectAll();
                return;
            }

            const double EPS = 1e-9;                                                    // константа для порівняння з нулем

            if (dx < EPS)                                                               // перевірка кроку на додатність і щоб не був нулем
            {
                MessageBox.Show("Значення кроку dx повинне бути додатнім числом більшим за 0!", "ПОМИЛКА ВВЕДЕННЯ", MessageBoxButtons.OK, MessageBoxIcon.Error);
                textBox3.Focus();
                textBox3.SelectAll();
                return;
            }

            if (dx > (xmax - xmin))                                                     // перевірка кроку на перевищення діапазону
            {
                MessageBox.Show("Крок dx занадто великий. Він не може бути більшим за різницю між xmax та xmin", "ПОМИЛКА ВВЕДЕННЯ", MessageBoxButtons.OK, MessageBoxIcon.Error);
                textBox3.Focus();
                textBox3.SelectAll();
                return;
            }

            if (!double.TryParse(textBox4.Text, out double a))                          // перевірка та зчитування значення константи a
            {
                MessageBox.Show("Значення константи a повинне бути дійсним числом", "ПОМИЛКА ВВЕДЕННЯ", MessageBoxButtons.OK, MessageBoxIcon.Error);
                textBox4.Focus();
                textBox4.SelectAll();
                return;
            }

            Random random = new Random();                                               // створення об'єкта для генерації випадкових чисел
            int countF1 = 0, countF2 = 0;                                               // ініціалізація лічильників для обох формул

            for (double x = xmin; x <= xmax; x += dx)                                   // цикл табуляції від xmin до xmax із кроком dx
            {
                double q = random.NextDouble();                                         // генерація випадкового числа q

                while (Math.Abs(q) < EPS)                                               // перевірка, щоб q не дорівнювало нулю
                {
                    q = random.NextDouble();                                            // повторна генерація випадкового числа q
                }

                if (q <= 0.35)                                                          // умова для першої формули
                {
                    double rootExpr = Math.Cos(q * x);                                  // обчислення підкореневого виразу

                    if (rootExpr < 0)                                                   // перевірка ОДЗ для кореня
                    {
                        listBox1.Items.Add($"При x = {x:F3} та q = {q:F3} -> під коренем < 0"); // виведення повідомлення про помилку ОДЗ
                    }
                    else
                    {
                        double y1 = Math.Sqrt(rootExpr);                                // обчислення y1
                        listBox1.Items.Add($"При x = {x:F3} та q = {q:F3} y = {y1:F4}"); // виведення результату
                        countF1++;                                                      // збільшення лічильни ка першої формули
                    }
                }
                else                                                                    // умова для другої формули
                {
                    double a_x = a - x;                                                 // обчислення аргументу логарифма

                    if (a_x <= 0)                                                       // перевірка ОДЗ для логарифма
                    {
                        listBox2.Items.Add($"При x = {x:F3} та q = {q:F3} -> логарифм від <= 0"); // виведення повідомлення про помилку ОДЗ
                        continue;                                                       // перехід до наступної ітерації циклу
                    }

                    double logVal = Math.Log(a_x);                                      // обчислення логарифма

                    if (Math.Abs(logVal) < EPS)                                         // перевірка щоб знаменник не дорівнював нулю
                    {
                        listBox2.Items.Add($"При x = {x:F3} та q = {q:F3} -> ділення на 0"); // виведення повідомлення про помилку ділення на нуль
                    }
                    else
                    {
                        double y2 = q / logVal;                                         // обчислення y2
                        listBox2.Items.Add($"При x = {x:F3} та q = {q:F3} y = {y2:F4}"); // виведення результату
                        countF2++;                                                      // збільшення лічильника другої формули
                    }
                }
            }

            label12.Text = $"{countF1}";                                                // виведення кількості обчислень першої формули
            label14.Text = $"{countF2}";                                                // виведення кількості обчислень другої формули
        }
    }
}
