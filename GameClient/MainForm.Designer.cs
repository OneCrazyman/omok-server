namespace GameClient
{
    partial class MainForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            groupBox1 = new GroupBox();
            label1 = new Label();
            textBoxIP = new TextBox();
            label2 = new Label();
            textBoxPort = new TextBox();
            checkBoxLocalHostIP = new CheckBox();
            btnConnect = new Button();
            btnDisConnect = new Button();
            textBoxSendText = new TextBox();
            btnEcho = new Button();
            listBoxLog = new ListBox();
            groupBox1.SuspendLayout();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(checkBoxLocalHostIP);
            groupBox1.Controls.Add(label2);
            groupBox1.Controls.Add(textBoxPort);
            groupBox1.Controls.Add(textBoxIP);
            groupBox1.Controls.Add(label1);
            groupBox1.Location = new Point(12, 12);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(614, 97);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            groupBox1.Text = "소켓 더미 클라이언트 생성";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(20, 53);
            label1.Name = "label1";
            label1.Size = new Size(77, 20);
            label1.TabIndex = 1;
            label1.Text = "서버 주소:";
            // 
            // textBoxIP
            // 
            textBoxIP.Location = new Point(103, 46);
            textBoxIP.Name = "textBoxIP";
            textBoxIP.Size = new Size(125, 27);
            textBoxIP.TabIndex = 2;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(244, 53);
            label2.Name = "label2";
            label2.Size = new Size(77, 20);
            label2.TabIndex = 3;
            label2.Text = "포트 번호:";
            // 
            // textBoxPort
            // 
            textBoxPort.Location = new Point(327, 46);
            textBoxPort.Name = "textBoxPort";
            textBoxPort.Size = new Size(125, 27);
            textBoxPort.TabIndex = 2;
            // 
            // checkBoxLocalHostIP
            // 
            checkBoxLocalHostIP.AutoSize = true;
            checkBoxLocalHostIP.Location = new Point(467, 48);
            checkBoxLocalHostIP.Name = "checkBoxLocalHostIP";
            checkBoxLocalHostIP.Size = new Size(127, 24);
            checkBoxLocalHostIP.TabIndex = 1;
            checkBoxLocalHostIP.Text = "localhost 사용";
            checkBoxLocalHostIP.UseVisualStyleBackColor = true;
            // 
            // btnConnect
            // 
            btnConnect.Location = new Point(632, 30);
            btnConnect.Name = "btnConnect";
            btnConnect.Size = new Size(94, 29);
            btnConnect.TabIndex = 1;
            btnConnect.Text = "접속";
            btnConnect.UseVisualStyleBackColor = true;
            btnConnect.Click += btnConnect_Click;
            // 
            // btnDisConnect
            // 
            btnDisConnect.Location = new Point(632, 65);
            btnDisConnect.Name = "btnDisConnect";
            btnDisConnect.Size = new Size(94, 29);
            btnDisConnect.TabIndex = 2;
            btnDisConnect.Text = "접속끊기";
            btnDisConnect.UseVisualStyleBackColor = true;
            // 
            // textBoxSendText
            // 
            textBoxSendText.Location = new Point(32, 128);
            textBoxSendText.Name = "textBoxSendText";
            textBoxSendText.Size = new Size(125, 27);
            textBoxSendText.TabIndex = 2;
            // 
            // btnEcho
            // 
            btnEcho.Location = new Point(174, 126);
            btnEcho.Name = "btnEcho";
            btnEcho.Size = new Size(109, 29);
            btnEcho.TabIndex = 1;
            btnEcho.Text = "echo 보내기";
            btnEcho.UseVisualStyleBackColor = true;
            // 
            // listBoxLog
            // 
            listBoxLog.FormattingEnabled = true;
            listBoxLog.ItemHeight = 20;
            listBoxLog.Location = new Point(23, 300);
            listBoxLog.Name = "listBoxLog";
            listBoxLog.Size = new Size(453, 104);
            listBoxLog.TabIndex = 3;
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(9F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 449);
            Controls.Add(listBoxLog);
            Controls.Add(btnDisConnect);
            Controls.Add(btnEcho);
            Controls.Add(btnConnect);
            Controls.Add(groupBox1);
            Controls.Add(textBoxSendText);
            Name = "MainForm";
            Text = "네트워크 테스트 클라이언트";
            Load += MainForm_Load;
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private GroupBox groupBox1;
        private Label label2;
        private TextBox textBoxIP;
        private Label label1;
        private CheckBox checkBoxLocalHostIP;
        private TextBox textBoxPort;
        private Button btnConnect;
        private Button btnDisConnect;
        private TextBox textBoxSendText;
        private Button btnEcho;
        private ListBox listBoxLog;
    }
}
