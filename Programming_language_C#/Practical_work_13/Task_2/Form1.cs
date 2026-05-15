using System;
using System.Drawing;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace practical_work_13_2
{
    public partial class Form1 : Form
    {
        public Form1()                                                  // конструктор класу форми
        {
            InitializeComponent();                                      // ініціалізація компонентів форми

            button1.Text = "Малювати";                                  // зміна тексту на кнопці
        }

        private void button1_Click(object sender, EventArgs e)          // метод-обробник події натискання на кнопку
        {
            Graphics g = Graphics.FromHwnd(this.Handle);                // створення полотна

            // налаштування нешаблонного пера
            Pen rectPen = new Pen(Color.DeepPink, 4);
            rectPen.DashStyle = DashStyle.DashDotDot;

            g.DrawRectangle(rectPen, 10, 150, 300, 100);                // малювання прямокутника

            Font textFont = new Font("Arial Black", 14);                // налаштування шрифту
            Brush textBrush = Brushes.Black;                            // налаштування пензлика
            g.DrawString("Як справи?", textFont, textBrush, 100, 185);  // виведення тексту

            // створення пензлика зі штрихуванням та малювання еліпса цим пензликом
            HatchBrush ellipseBrush = new HatchBrush(HatchStyle.DiagonalCross, Color.BlueViolet, Color.White);
            g.FillEllipse(ellipseBrush, 10, 10, 300, 100);
        }
    }
}
