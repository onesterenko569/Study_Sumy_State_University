using System;
using System.Windows.Forms;

namespace practical_work_20
{
    public partial class Form1 : Form
    {
        public Form1()                                                                      // конструктор класу форми
        {
            InitializeComponent();                                                          // ініціалізація компонентів форми
        }

        private void Form1_Load(object sender, EventArgs e)                                 // обробник події завантаження форми
        {
            this.Text = "My Browser";                                                       // задання заголовка вікна програми
        }

        private void button1_Click(object sender, EventArgs e)                              // обробник події натискання на кнопку "Пошук"
        {
            webBrowser1.Navigate(textBox1.Text);                                            // перехід за URL-адресою, введеною у текстове поле
        }

        private void button2_Click(object sender, EventArgs e)                              // обробник події натискання на кнопку "Forward"
        {
            webBrowser1.GoForward();                                                        // перехід на сторінку вперед в історії браузера
        }

        private void button3_Click(object sender, EventArgs e)                              // обробник події натискання на кнопку "Back"
        {
            webBrowser1.GoBack();                                                           // перехід на сторінку назад в історії браузера
        }

        private void button4_Click(object sender, EventArgs e)                              // обробник події натискання на кнопку "Home"
        {
            webBrowser1.Navigate("youtube.com");                                            // перехід на сторінку youtube
        }

        private void button5_Click(object sender, EventArgs e)                              // обробник події натискання на кнопку "Save as..."
        {
            webBrowser1.Print();                                                            // виклик вікна збереження поточної веб-сторінки
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)             // обробник події зміни вибраного елемента у випадному списку
        {
            switch (comboBox1.SelectedIndex)                                                // перевірка індексу вибраного елемента
            {
                case 0: webBrowser1.Navigate("youtube.com"); break;                         // якщо вибрано перший пункт - перехід на YouTube
                case 1: webBrowser1.Navigate("google.com"); break;                          // якщо вибрано другий пункт - перехід на Google
                case 2: webBrowser1.Navigate("Gmail.com"); break;                           // якщо вибрано третій пункт - перехід на Gmail
            }
        }
    }
}
