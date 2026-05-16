namespace practical_work_15
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.btn9Clear = new System.Windows.Forms.Button();
            this.btn8AddLineArray = new System.Windows.Forms.Button();
            this.btn7CheckLineExists = new System.Windows.Forms.Button();
            this.btn6DeleteLineByIndex = new System.Windows.Forms.Button();
            this.btn5DeleteLineByText = new System.Windows.Forms.Button();
            this.btn4InsertRowByIndex = new System.Windows.Forms.Button();
            this.btn3FindRowIndex = new System.Windows.Forms.Button();
            this.btn2Type = new System.Windows.Forms.Button();
            this.btn1Number = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 20;
            this.listBox1.Items.AddRange(new object[] {
            "А на вулиці йде дощ",
            "Я сижу на кухні",
            "Їм борщ",
            "Дуже смачно",
            "З капустою",
            "Але чомусь трішки сумно"});
            this.listBox1.Location = new System.Drawing.Point(753, 12);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(516, 584);
            this.listBox1.TabIndex = 0;
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // panel1
            // 
            this.panel1.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.panel1.Controls.Add(this.btn9Clear);
            this.panel1.Controls.Add(this.btn8AddLineArray);
            this.panel1.Controls.Add(this.btn7CheckLineExists);
            this.panel1.Controls.Add(this.btn6DeleteLineByIndex);
            this.panel1.Controls.Add(this.btn5DeleteLineByText);
            this.panel1.Controls.Add(this.btn4InsertRowByIndex);
            this.panel1.Controls.Add(this.btn3FindRowIndex);
            this.panel1.Controls.Add(this.btn2Type);
            this.panel1.Controls.Add(this.btn1Number);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.textBox3);
            this.panel1.Controls.Add(this.textBox2);
            this.panel1.Controls.Add(this.textBox1);
            this.panel1.Location = new System.Drawing.Point(12, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(735, 584);
            this.panel1.TabIndex = 19;
            // 
            // btn9Clear
            // 
            this.btn9Clear.Location = new System.Drawing.Point(204, 541);
            this.btn9Clear.Name = "btn9Clear";
            this.btn9Clear.Size = new System.Drawing.Size(334, 39);
            this.btn9Clear.TabIndex = 33;
            this.btn9Clear.Text = "Очистити список";
            this.btn9Clear.UseVisualStyleBackColor = true;
            this.btn9Clear.Click += new System.EventHandler(this.btn9Clear_Click);
            // 
            // btn8AddLineArray
            // 
            this.btn8AddLineArray.Location = new System.Drawing.Point(392, 481);
            this.btn8AddLineArray.Name = "btn8AddLineArray";
            this.btn8AddLineArray.Size = new System.Drawing.Size(334, 39);
            this.btn8AddLineArray.TabIndex = 32;
            this.btn8AddLineArray.Text = "Додати масив рядків";
            this.btn8AddLineArray.UseVisualStyleBackColor = true;
            this.btn8AddLineArray.Click += new System.EventHandler(this.btn8AddLineArray_Click);
            // 
            // btn7CheckLineExists
            // 
            this.btn7CheckLineExists.Location = new System.Drawing.Point(392, 421);
            this.btn7CheckLineExists.Name = "btn7CheckLineExists";
            this.btn7CheckLineExists.Size = new System.Drawing.Size(334, 39);
            this.btn7CheckLineExists.TabIndex = 31;
            this.btn7CheckLineExists.Text = "Перевірити наявність рядка";
            this.btn7CheckLineExists.UseVisualStyleBackColor = true;
            this.btn7CheckLineExists.Click += new System.EventHandler(this.btn7CheckLineExists_Click);
            // 
            // btn6DeleteLineByIndex
            // 
            this.btn6DeleteLineByIndex.Location = new System.Drawing.Point(392, 361);
            this.btn6DeleteLineByIndex.Name = "btn6DeleteLineByIndex";
            this.btn6DeleteLineByIndex.Size = new System.Drawing.Size(334, 39);
            this.btn6DeleteLineByIndex.TabIndex = 30;
            this.btn6DeleteLineByIndex.Text = "Видалити рядок за індексом";
            this.btn6DeleteLineByIndex.UseVisualStyleBackColor = true;
            this.btn6DeleteLineByIndex.Click += new System.EventHandler(this.btn6DeleteLineByIndex_Click);
            // 
            // btn5DeleteLineByText
            // 
            this.btn5DeleteLineByText.Location = new System.Drawing.Point(392, 301);
            this.btn5DeleteLineByText.Name = "btn5DeleteLineByText";
            this.btn5DeleteLineByText.Size = new System.Drawing.Size(334, 39);
            this.btn5DeleteLineByText.TabIndex = 29;
            this.btn5DeleteLineByText.Text = "Видалити рядок за текстом";
            this.btn5DeleteLineByText.UseVisualStyleBackColor = true;
            this.btn5DeleteLineByText.Click += new System.EventHandler(this.btn5DeleteLineByText_Click);
            // 
            // btn4InsertRowByIndex
            // 
            this.btn4InsertRowByIndex.Location = new System.Drawing.Point(13, 481);
            this.btn4InsertRowByIndex.Name = "btn4InsertRowByIndex";
            this.btn4InsertRowByIndex.Size = new System.Drawing.Size(334, 39);
            this.btn4InsertRowByIndex.TabIndex = 28;
            this.btn4InsertRowByIndex.Text = "Вставити рядок за індексом";
            this.btn4InsertRowByIndex.UseVisualStyleBackColor = true;
            this.btn4InsertRowByIndex.Click += new System.EventHandler(this.btn4InsertRowByIndex_Click);
            // 
            // btn3FindRowIndex
            // 
            this.btn3FindRowIndex.Location = new System.Drawing.Point(13, 421);
            this.btn3FindRowIndex.Name = "btn3FindRowIndex";
            this.btn3FindRowIndex.Size = new System.Drawing.Size(334, 39);
            this.btn3FindRowIndex.TabIndex = 27;
            this.btn3FindRowIndex.Text = "Знайти індекс рядка";
            this.btn3FindRowIndex.UseVisualStyleBackColor = true;
            this.btn3FindRowIndex.Click += new System.EventHandler(this.btn3FindRowIndex_Click);
            // 
            // btn2Type
            // 
            this.btn2Type.Location = new System.Drawing.Point(13, 361);
            this.btn2Type.Name = "btn2Type";
            this.btn2Type.Size = new System.Drawing.Size(334, 39);
            this.btn2Type.TabIndex = 26;
            this.btn2Type.Text = "Тип елементу";
            this.btn2Type.UseVisualStyleBackColor = true;
            this.btn2Type.Click += new System.EventHandler(this.btn2Type_Click);
            // 
            // btn1Number
            // 
            this.btn1Number.Location = new System.Drawing.Point(13, 301);
            this.btn1Number.Name = "btn1Number";
            this.btn1Number.Size = new System.Drawing.Size(334, 39);
            this.btn1Number.TabIndex = 25;
            this.btn1Number.Text = "Кількість рядків";
            this.btn1Number.UseVisualStyleBackColor = true;
            this.btn1Number.Click += new System.EventHandler(this.btn1Number_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(8, 194);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(289, 26);
            this.label3.TabIndex = 24;
            this.label3.Text = "Поле 3 (введення чисел)";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(8, 103);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(295, 26);
            this.label2.TabIndex = 23;
            this.label2.Text = "Поле 2 (введення тексту)";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(8, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(257, 26);
            this.label1.TabIndex = 22;
            this.label1.Text = "Поле 1 (результат дії)";
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(13, 237);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(713, 26);
            this.textBox3.TabIndex = 21;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(13, 147);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(713, 26);
            this.textBox2.TabIndex = 20;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(13, 57);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(713, 26);
            this.textBox1.TabIndex = 19;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1413, 604);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.listBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button btn9Clear;
        private System.Windows.Forms.Button btn8AddLineArray;
        private System.Windows.Forms.Button btn7CheckLineExists;
        private System.Windows.Forms.Button btn6DeleteLineByIndex;
        private System.Windows.Forms.Button btn5DeleteLineByText;
        private System.Windows.Forms.Button btn4InsertRowByIndex;
        private System.Windows.Forms.Button btn3FindRowIndex;
        private System.Windows.Forms.Button btn2Type;
        private System.Windows.Forms.Button btn1Number;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox1;
    }
}

