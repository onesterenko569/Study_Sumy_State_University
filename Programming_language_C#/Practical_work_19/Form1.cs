using System;
using System.IO;
using System.Windows.Forms;

namespace practical_work_19
{
    public partial class Form1 : Form
    {
        public Form1()                                                                      // конструктор класу форми
        {
            InitializeComponent();                                                          // ініціалізація компонентів форми
        }

        private void Form1_Load(object sender, EventArgs e)                                 // обробник події завантаження форми
        {
            this.Text = "Текстовий редактор";                                               // задання заголовка вікна програми
            saveFileDialog1.Filter = "Текстовi файли (*.txt)|*.txt|All files (*.*)|*.*";    // налаштування форматів файлів для відображення у діалогових вікнах
        }

        private void відкритиToolStripMenuItem_Click(object sender, EventArgs e)            // обробник події натискання на пункт меню "Відкрити"
        {
            openFileDialog1.ShowDialog();                                                   // відкриття діалогового вікна вибору файлу для читання

            if (openFileDialog1.FileName == null)                                           // перевірка чи файл був обраний
            {
                return;                                                                     // вихід з методу, якщо користувач не обрав файл
            }

            StreamReader MyReader = new StreamReader(openFileDialog1.FileName);             // створення об'єкта для зчитування даних з обраного файлу
            textBox1.Text = MyReader.ReadToEnd();                                           // зчитування всього тексту з файлу та запис його у текстове вікно
            MyReader.Close();                                                               // закриття файлового потоку
        }

        private void зберегтиЯкToolStripMenuItem_Click(object sender, EventArgs e)          // обробник події натискання на пункт меню "Зберегти як..."
        {
            saveFileDialog1.FileName = openFileDialog1.FileName;                            // автоматична підстановка поточного імені відкритого файлу

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)                            // виклик вікна збереження та перевірка, чи натиснув користувач "ОК"
            {
                Save();                                                                     // виклик допоміжного методу для збереження файлу
            }
        }

        void Save()                                                                         // допоміжний метод збереження
        {
            StreamWriter MyWriter = new StreamWriter(saveFileDialog1.FileName);             // створення об'єкта для запису тексту
            MyWriter.Write(textBox1.Text);                                                  // запис усього вмісту текстового вікна у файл
            MyWriter.Close();                                                               // закриття файлового потоку
            textBox1.Modified = false;                                                      // скидання прапорця про наявність незбережених змін у тексті
        }

        private void вихідToolStripMenuItem_Click(object sender, EventArgs e)               // обробник події натискання на пункт меню "Вийти"
        {
            this.Close();                                                                   // виклик методу закриття головного вікна програми
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)               // обробник події закриття форми
        {
            if (textBox1.Modified == false)                                                 // перевірка чи редагувався текст у вікні
            {
                return;                                                                     // якщо змін не було, дозволяємо вільне закриття форми
            }

            DialogResult result = MessageBox.Show("Текст був змінений. Зберегти зміни?", "Закрити вікно", MessageBoxButtons.YesNoCancel); // виклик вікна з питанням і трьома кнопками

            if (result == DialogResult.No)                                                  // якщо користувач обрав "Ні"
            {
                return;                                                                     // виходимо з обробника
            }

            if (result == DialogResult.Cancel)                                              // якщо користувач обрав "Відмінити"
            {
                e.Cancel = true;                                                            // форма залишається відкритою
            }

            if (result == DialogResult.Yes)                                                 // якщо користувач обрав "Так"
            {
                if (saveFileDialog1.ShowDialog() == DialogResult.OK)                        // відкриваємо вікно вибору шляху та перевіряємо чи підтвердив користувач збереження
                {
                    Save();                                                                 // записуємо файл
                    return;                                                                 // дозволяємо формі закритися
                }
                else                                                                        // якщо користувач скасував збереження на етапі вибору папки
                {
                    e.Cancel = true;                                                        // зупиняємо закриття форми
                }
            }
        }
    }
}
