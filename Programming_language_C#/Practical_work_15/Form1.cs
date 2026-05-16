using System;
using System.Windows.Forms;

namespace practical_work_15
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();                                              // ініціалізація компонентів форми
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedItem != null)                                  // перевірка наявності виділеного рядка
            {
                label1.Text = "Обрано наступний рядок:";
                textBox1.Text = listBox1.SelectedItem.ToString();               // виведення тексту виділеного рядка

                textBox2.Clear();
                textBox3.Clear();
            }
            else
            {
                textBox1.Clear();                                               // очищення поля при знятті виділення
                label1.Text = "Поле 1 (результат дії):";

                textBox2.Clear();
                textBox3.Clear();
            }
        }

        private void btn1Number_Click(object sender, EventArgs e)
        {
            label1.Text = "Кількість символьних рядків:";
            textBox1.Text = listBox1.Items.Count.ToString();                    // підрахунок кількості елементів у списку

            textBox2.Clear();
            textBox3.Clear();
        }

        private void btn2Type_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedItem != null)
            {
                label1.Text = "Тип виділеного рядка:";
                textBox1.Text = listBox1.Items.GetType().ToString();            // визначення типу

                textBox2.Clear();
                textBox3.Clear();
            }
            else
            {
                MessageBox.Show("Будь ласка, спочатку оберіть рядок у списку!", "Увага", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void btn3FindRowIndex_Click(object sender, EventArgs e)
        {
            string line = textBox2.Text;

            if (string.IsNullOrWhiteSpace(line))                                // перевірка на порожнє поле вводу
            {
                MessageBox.Show("Для пошуку необхідно ввести рядок в Поле 2!", "Увага", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                textBox2.Focus();

                return;
            }

            label1.Text = "Номер розшукуваного рядка:";

            int ind = listBox1.Items.IndexOf(line);                             // пошук індексу введеного рядка

            if (ind == -1)                                                      // якщо рядок не знайдено
            {
                textBox1.Text = "Даний рядок не знайдено!";

                textBox2.Focus();
                textBox2.SelectAll();
            }
            else
            {
                textBox1.Text = $"Індекс рядка \"{line}\" - {ind}";             // виведення знайденого індексу

                textBox2.Clear();
                textBox3.Clear();
            }

        }

        private void btn4InsertRowByIndex_Click(object sender, EventArgs e)
        {
            string line = textBox2.Text;
            string indS = textBox3.Text;

            if (string.IsNullOrWhiteSpace(line))
            {
                MessageBox.Show("Для вставлення необхідно ввести рядок в Поле 2!", "Увага", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                textBox2.Focus();

                return;
            }

            if (string.IsNullOrWhiteSpace(indS))
            {
                MessageBox.Show("Для вставлення необхідно ввести індекс (позицію вставлення) в Поле 3!", "Увага", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                textBox3.Focus();

                return;
            }

            if (!int.TryParse(indS, out int ind))                               // зчитування та перевірка індексу
            {
                MessageBox.Show("Індекс позиції повинен бути цілим числом!", "Помилка введення", MessageBoxButtons.OK, MessageBoxIcon.Error);

                textBox3.Focus();
                textBox3.SelectAll();

                return;
            }

            if (ind < 0 || ind > listBox1.Items.Count)                          // перевірка виходу індексу за межі списку
            {
                MessageBox.Show($"Індекс виходить за межі! Допустимий діапазон: від 0 до {listBox1.Items.Count}", "Помилка", MessageBoxButtons.OK, MessageBoxIcon.Error);

                textBox3.Focus();
                textBox3.SelectAll();

                return;
            }

            textBox1.Text = $"Рядок \"{line}\" під індексом {indS} успішно вставлено!";

            listBox1.Items.Insert(ind, line);                                   // вставлення рядка за вказаним індексом

            textBox2.Clear();
            textBox3.Clear();
        }

        private void btn5DeleteLineByText_Click(object sender, EventArgs e)
        {
            string line = textBox2.Text;

            if (string.IsNullOrWhiteSpace(line))
            {
                MessageBox.Show("Для видалення необхідно ввести рядок в Поле 2!", "Увага", MessageBoxButtons.OK, MessageBoxIcon.Warning);

                textBox2.Focus();

                return;
            }

            if (!listBox1.Items.Contains(line))                                 // перевірка наявності рядка перед видаленням
            {
                MessageBox.Show("Даний рядок не знайдено", "Увага", MessageBoxButtons.OK, MessageBoxIcon.Warning);

                textBox2.Focus();
                textBox2.SelectAll();

                return;
            }

            listBox1.Items.Remove(line);                                        // видалення рядка за текстом

            label1.Text = "Результат видалення:";
            textBox1.Text = $"Рядок \"{line}\" успішно видалено!";

            textBox2.Clear();
            textBox3.Clear();
        }

        private void btn6DeleteLineByIndex_Click(object sender, EventArgs e)
        {
            string indS = textBox3.Text;

            if (string.IsNullOrEmpty(indS))
            {
                MessageBox.Show("Для видалення необхідно ввести індекс рядка в Поле 3!", "Увага", MessageBoxButtons.OK, MessageBoxIcon.Warning);

                textBox3.Focus();

                return;
            }

            if (!int.TryParse(indS, out int ind))
            {
                MessageBox.Show("Індекс позиції повинен бути цілим числом!", "Помилка введення", MessageBoxButtons.OK, MessageBoxIcon.Error);

                textBox3.Focus();
                textBox3.SelectAll();

                return;
            }

            if (ind < 0 || ind >= listBox1.Items.Count)                         // перевірка допустимих меж для видалення
            {
                MessageBox.Show($"Індекс виходить за межі (індексація з 0)! Допустимий діапазон: від 0 до {listBox1.Items.Count - 1}", "Помилка", MessageBoxButtons.OK, MessageBoxIcon.Error);

                textBox3.Focus();
                textBox3.SelectAll();

                return;
            }

            listBox1.Items.RemoveAt(ind);                                       // видалення елемента за вказаним індексом

            label1.Text = "Результат видалення:";
            textBox1.Text = $"Рядок з індексом {ind} успішно видалено!";

            textBox2.Clear();
            textBox3.Clear();
        }

        private void btn7CheckLineExists_Click(object sender, EventArgs e)
        {
            string line = textBox2.Text;

            if (string.IsNullOrWhiteSpace(line))
            {
                MessageBox.Show("Для пошуку необхідно ввести рядок в Поле 2!", "Увага", MessageBoxButtons.OK, MessageBoxIcon.Warning);

                textBox2.Focus();

                return;
            }

            label1.Text = "Результат пошуку:";

            if (!listBox1.Items.Contains(line))                                 // перевірка, чи існує заданий рядок
            {
                textBox1.Text = $"Рядок \"{line}\" відсутній в списку";

                textBox2.Clear();
                textBox3.Clear();
            }
            else
            {
                textBox1.Text = $"Рядок \"{line}\" присутній в списку під {listBox1.Items.IndexOf(line)} індексом";

                textBox2.Clear();
                textBox3.Clear();
            }
        }

        private void btn8AddLineArray_Click(object sender, EventArgs e)
        {
            string line = textBox2.Text;

            if (string.IsNullOrWhiteSpace(line))
            {
                MessageBox.Show("Введіть елементи масиву через крапку з комою (;) в Поле 2!", "Увага", MessageBoxButtons.OK, MessageBoxIcon.Warning);

                textBox2.Focus();

                return;
            }

            string[] arr = line.Split(';');                                     // розбиття введеного тексту на масив рядків

            for (int i = 0; i < arr.Length; i++)                                // цикл для видалення зайвих пробілів по краях
            {
                arr[i] = arr[i].Trim();
            }

            listBox1.Items.AddRange(arr);                                       // додавання всього масиву в кінець списку

            label1.Text = "Результат додавання масиву:";
            textBox1.Text = $"Масив із {arr.Length} елементів успішно додано!";

            textBox2.Clear();
            textBox3.Clear();
        }

        private void btn9Clear_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();                                             // очищення списку ListBox

            label1.Text = "Результат дії:";
            textBox1.Text = "Список повністю очищено!";

            textBox2.Clear();
            textBox3.Clear();
        }
    }
}
