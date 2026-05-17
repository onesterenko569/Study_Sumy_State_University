using System;
using System.Drawing;
using System.Windows.Forms;

namespace practical_work_16_1
{
    public partial class Form1 : Form
    {
        public Form1()                                                              // конструктор класу форми
        {
            InitializeComponent();                                                  // ініціалізація компонентів форми
        }

        Pen pen1 = new Pen(Color.Red, 4);                                           // створення червоного пензлика товщиною 4
        Bitmap bmp;                                                                 // оголошення змінної для зберігання зображення
        bool permit;                                                                // дозвіл на малювання
        Point startPoint;                                                           // координати початкової точки для малювання лінії

        string full_name_of_image;                                                  // змінна для зберігання шляху до файлу

        private void Form1_Load(object sender, EventArgs e)                         // обробник події завантаження форми
        {
            this.Text = "Редагування картинки";
            button1.Text = "Додати фото";
            button2.Text = "Зберегти";
            button3.Text = "Очистити";
        }

        private void button1_Click(object sender, EventArgs e)                      // обробник події натискання на кнопку "Огляд"
        {
            OpenFileDialog open_dialog = new OpenFileDialog();                      // створення діалогового вікна для відкриття файлу

            if (open_dialog.ShowDialog() == DialogResult.OK)                        // якщо користувач обрав файл і натиснув "ОК"
            {
                try                                                                 // блок перехоплення помилок
                {
                    full_name_of_image = open_dialog.FileName;                      // збереження шляху файлу
                    bmp = new Bitmap(open_dialog.FileName);                         // завантаження зображення
                    this.pictureBox1.SizeMode = PictureBoxSizeMode.AutoSize;        // налаштування розміру PictureBox під оригінальний розмір картинки
                    pictureBox1.Image = bmp;                                        // відображення картинки у компоненті PictureBox
                    pictureBox1.Invalidate();                                       // оновлення екрану
                }
                catch                                                               // якщо виникла помилка під час відкриття
                {
                    MessageBox.Show("Обраний файл неможливо відкрити", "Увага", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)                      // обробник події натискання на кнопку "Зберегти"
        {
            if (pictureBox1.Image != null)                                          // перевірка чи завантажено зображення на форму
            {
                SaveFileDialog savedialog = new SaveFileDialog();                   // створення діалогового вікна для збереження файлу

                savedialog.Title = "Зберегти як ...";
                savedialog.OverwritePrompt = true;
                savedialog.ShowHelp = true;

                savedialog.Filter = "Зображення JPEG (*.jpg)|*.jpg|Всі файли (*.*)|*.*"; // налаштування форматів для збереження
                savedialog.DefaultExt = "jpg";                                      // задання розширення файлу за замовчуванням

                if (savedialog.ShowDialog() == DialogResult.OK)                     // якщо користувач вказав шлях і натиснув "Зберегти"
                {
                    try                                                             // блок перехоплення помилок
                    {
                        bmp.Save(savedialog.FileName, System.Drawing.Imaging.ImageFormat.Jpeg); // збереження малюнка у форматі JPEG
                    }
                    catch                                                           // якщо виникла помилка під час збереження
                    {
                        MessageBox.Show("Неможливо зберегти файл", "Помилка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
            }

        }

        private void button3_Click(object sender, EventArgs e)                      // обробник події натискання на кнопку "Очистити"
        {
            Graphics g = pictureBox1.CreateGraphics();                              // створення об'єкта
            g.Clear(SystemColors.Window);                                           // зафарбовування
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)         // обробник події руху курсора миші по картинці
        {
            if (e.Button == MouseButtons.Left)                                      // перевірка чи затиснута саме ліва кнопка миші
            {
                using (Graphics g = Graphics.FromImage(pictureBox1.Image))          // створення об'єкта для малювання по картинці
                {
                    if (permit == true)                                             // якщо малювання дозволено 
                    {
                        // малюємо
                        g.DrawLine(pen1, startPoint, e.Location);
                        startPoint = e.Location;
                        pictureBox1.Invalidate();
                    }
                }
            }
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)         // обробник події натискання кнопки миші на картинці
        {
            if (e.Button == MouseButtons.Left)                                      // перевірка чи натиснута саме ліва кнопка
            {
                permit = true;                                                      // надання дозволу на малювання
                startPoint = e.Location;                                            // фіксація початкової координати курсору
            }

        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)           // обробник події відпускання кнопки миші
        {
            if (e.Button == MouseButtons.Left)                                      // перевірка чи була відпущена саме ліва кнопка
            {
                permit = false;                                                     // скасування дозволу на малювання
            }
        }
    }
}
