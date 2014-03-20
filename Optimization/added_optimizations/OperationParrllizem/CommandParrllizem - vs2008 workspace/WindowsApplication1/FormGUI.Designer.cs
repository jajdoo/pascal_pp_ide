namespace CompilersLab
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.openFileDialog_IR = new System.Windows.Forms.OpenFileDialog();
            this.button_openIR = new System.Windows.Forms.Button();
            this.button_ParseFiles = new System.Windows.Forms.Button();
            this.listBox_sourceIR = new System.Windows.Forms.ListBox();
            this.listBox_para = new System.Windows.Forms.ListBox();
            this.listBox_Depn = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // openFileDialog_IR
            // 
            this.openFileDialog_IR.FileName = "please Select a file";
            this.openFileDialog_IR.InitialDirectory = "c:\\";
            this.openFileDialog_IR.FileOk += new System.ComponentModel.CancelEventHandler(this.openFileDialog_IR_FileOk);
            // 
            // button_openIR
            // 
            this.button_openIR.Location = new System.Drawing.Point(12, 422);
            this.button_openIR.Name = "button_openIR";
            this.button_openIR.Size = new System.Drawing.Size(80, 26);
            this.button_openIR.TabIndex = 0;
            this.button_openIR.Text = "Open IR file";
            this.button_openIR.UseVisualStyleBackColor = true;
            this.button_openIR.Click += new System.EventHandler(this.button_openIR_Click);
            // 
            // button_ParseFiles
            // 
            this.button_ParseFiles.Location = new System.Drawing.Point(445, 422);
            this.button_ParseFiles.Name = "button_ParseFiles";
            this.button_ParseFiles.Size = new System.Drawing.Size(82, 26);
            this.button_ParseFiles.TabIndex = 1;
            this.button_ParseFiles.Text = "Build Parallel";
            this.button_ParseFiles.UseVisualStyleBackColor = true;
            this.button_ParseFiles.Click += new System.EventHandler(this.button_ParseFiles_Click);
            // 
            // listBox_sourceIR
            // 
            this.listBox_sourceIR.FormattingEnabled = true;
            this.listBox_sourceIR.Location = new System.Drawing.Point(12, 22);
            this.listBox_sourceIR.Name = "listBox_sourceIR";
            this.listBox_sourceIR.Size = new System.Drawing.Size(185, 394);
            this.listBox_sourceIR.TabIndex = 2;
            // 
            // listBox_para
            // 
            this.listBox_para.FormattingEnabled = true;
            this.listBox_para.HorizontalScrollbar = true;
            this.listBox_para.Location = new System.Drawing.Point(213, 22);
            this.listBox_para.Name = "listBox_para";
            this.listBox_para.Size = new System.Drawing.Size(314, 394);
            this.listBox_para.TabIndex = 3;
            // 
            // listBox_Depn
            // 
            this.listBox_Depn.FormattingEnabled = true;
            this.listBox_Depn.HorizontalScrollbar = true;
            this.listBox_Depn.Location = new System.Drawing.Point(551, 22);
            this.listBox_Depn.Name = "listBox_Depn";
            this.listBox_Depn.Size = new System.Drawing.Size(272, 394);
            this.listBox_Depn.TabIndex = 4;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 6);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(146, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Register Optimization Source ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(210, 6);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "Parallel IR";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(548, 6);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(79, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Dependencies ";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(835, 453);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.listBox_Depn);
            this.Controls.Add(this.listBox_para);
            this.Controls.Add(this.listBox_sourceIR);
            this.Controls.Add(this.button_ParseFiles);
            this.Controls.Add(this.button_openIR);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Parallel Code Builder";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.OpenFileDialog openFileDialog_IR;
        private System.Windows.Forms.Button button_openIR;
        private System.Windows.Forms.Button button_ParseFiles;
        private System.Windows.Forms.ListBox listBox_sourceIR;
        private System.Windows.Forms.ListBox listBox_para;
        private System.Windows.Forms.ListBox listBox_Depn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
    }
}

