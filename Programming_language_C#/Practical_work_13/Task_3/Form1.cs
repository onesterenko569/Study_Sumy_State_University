using System;
using System.Windows.Forms;

namespace practical_work_13_3
{
    public partial class Form1 : Form
    {
        public Form1()                                                  // конструктор класу форми
        {
            InitializeComponent();                                      // ініціалізація компонентів форми

            // налаштування назв groupBox
            groupBox1.Text = "Номер обіду";
            groupBox2.Text = "Склад обіду";

            // налаштування назв варіантів комплексних обідів
            radioButton1.Text = "1 обід";
            radioButton2.Text = "2 обід";
            radioButton3.Text = "3 обід";

            // налаштування назв страв
            checkBox1.Text = "Борщ";
            checkBox2.Text = "Окрошка";
            checkBox3.Text = "Картопляне пюре з котлетою";
            checkBox4.Text = "Салат \"Шериф\"";
            checkBox5.Text = "Ананасовий сік";
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e) // обробник вибору першого варіанту обіду
        {
            // вибір страв, що входять до першого комплексного обіду
            checkBox1.Checked = true;
            checkBox2.Checked = false;
            checkBox3.Checked = true;
            checkBox4.Checked = true;
            checkBox5.Checked = true;

            textBox1.Text = "Ціна даного комплексного обіду 220 грн";   // виведення вартості першого обіду
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e) // обробник вибору другого варіанту обіду
        {
            // вибір страв, що входять до другого комплексного обіду
            checkBox1.Checked = false;
            checkBox2.Checked = true;
            checkBox3.Checked = true;
            checkBox4.Checked = true;
            checkBox5.Checked = true;

            textBox1.Text = "Ціна даного комплексного обіду 200 грн";   // виведення вартості другого обіду
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e) // обробник вибору третього варіанту обіду
        {
            // вибір страв, що входять до третього комплексного обіду
            checkBox1.Checked = false;
            checkBox2.Checked = false;
            checkBox3.Checked = true;
            checkBox4.Checked = true;
            checkBox5.Checked = true;

            textBox1.Text = "Ціна даного комплексного обіду 150 грн";   // виведення вартості третього обіду
        }
    }
}
