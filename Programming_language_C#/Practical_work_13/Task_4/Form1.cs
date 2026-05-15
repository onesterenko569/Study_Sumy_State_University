using System;
using System.Windows.Forms;

namespace practical_work_13_4
{
    public partial class Form1 : Form
    {
        public Form1()                                                  // конструктор класу форми
        {
            InitializeComponent();                                      // ініціалізація компонентів форми

            // налаштування назв groupBox
            groupBox1.Text = "Номер букету";
            groupBox2.Text = "Склад букету";

            // налаштування назв варіантів букетів
            radioButton1.Text = "1 букет";
            radioButton2.Text = "2 букет";
            radioButton3.Text = "3 букет";

            // налаштування назв квітів
            checkBox1.Text = "Червоні троянди";
            checkBox2.Text = "Білі лілії";
            checkBox3.Text = "Рожеві півонії";
            checkBox4.Text = "Жовті хризантеми";
            checkBox5.Text = "Блакитні гортензії";
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e) // обробник вибору першого букету
        {
            // вибір квітів, що входять до першого букету
            checkBox1.Checked = true;
            checkBox2.Checked = false;
            checkBox3.Checked = false;
            checkBox4.Checked = true;
            checkBox5.Checked = false;

            textBox1.Text = "Ціна даного букету 550 грн";   // виведення вартості першого букету
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e) // обробник вибору другого букету
        {
            // вибір квітів, що входять до другого букету
            checkBox1.Checked = false;
            checkBox2.Checked = true;
            checkBox3.Checked = true;
            checkBox4.Checked = true;
            checkBox5.Checked = false;

            textBox1.Text = "Ціна даного букету 900 грн";   // виведення вартості другого букету
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e) // обробник вибору третього букету
        {
            // вибір квітів, що входять до третього букету
            checkBox1.Checked = true;
            checkBox2.Checked = true;
            checkBox3.Checked = false;
            checkBox4.Checked = false;
            checkBox5.Checked = true;

            textBox1.Text = "Ціна даного букету 800 грн";   // виведення вартості третього букету
        }
    }
}
