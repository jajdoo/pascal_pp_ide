namespace CompilationLoopIdentifications
{
    partial class LoopIdentificationForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(LoopIdentificationForm));
            this.textBoxInputFilePath = new System.Windows.Forms.TextBox();
            this.buttonBrowse = new System.Windows.Forms.Button();
            this.richTextBoxBasicBlock = new System.Windows.Forms.RichTextBox();
            this.richTextBoxBackEdgesInCfg = new System.Windows.Forms.RichTextBox();
            this.labelIntermidiateCodeTextBoxTitle = new System.Windows.Forms.Label();
            this.labelBackEdges = new System.Windows.Forms.Label();
            this.richTextBoxLoopInformation = new System.Windows.Forms.RichTextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonShowGraph = new System.Windows.Forms.Button();
            this.labelInputFile = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // textBoxInputFilePath
            // 
            this.textBoxInputFilePath.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.textBoxInputFilePath.Location = new System.Drawing.Point(269, 14);
            this.textBoxInputFilePath.Name = "textBoxInputFilePath";
            this.textBoxInputFilePath.ReadOnly = true;
            this.textBoxInputFilePath.Size = new System.Drawing.Size(407, 21);
            this.textBoxInputFilePath.TabIndex = 1;
            this.textBoxInputFilePath.TextChanged += new System.EventHandler(this.textBoxInputFilePath_TextChanged);
            // 
            // buttonBrowse
            // 
            this.buttonBrowse.Image = global::CompilationLoopIdentifications.Properties.Resources.Network_search;
            this.buttonBrowse.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.buttonBrowse.Location = new System.Drawing.Point(16, 5);
            this.buttonBrowse.Name = "buttonBrowse";
            this.buttonBrowse.Size = new System.Drawing.Size(247, 41);
            this.buttonBrowse.TabIndex = 2;
            this.buttonBrowse.Text = "Browse and Process";
            this.buttonBrowse.UseVisualStyleBackColor = true;
            this.buttonBrowse.Click += new System.EventHandler(this.buttonBrowse_Click);
            // 
            // richTextBoxBasicBlock
            // 
            this.richTextBoxBasicBlock.Location = new System.Drawing.Point(12, 69);
            this.richTextBoxBasicBlock.Name = "richTextBoxBasicBlock";
            this.richTextBoxBasicBlock.ReadOnly = true;
            this.richTextBoxBasicBlock.Size = new System.Drawing.Size(359, 380);
            this.richTextBoxBasicBlock.TabIndex = 3;
            this.richTextBoxBasicBlock.Text = "";
            // 
            // richTextBoxBackEdgesInCfg
            // 
            this.richTextBoxBackEdgesInCfg.Location = new System.Drawing.Point(378, 68);
            this.richTextBoxBackEdgesInCfg.Name = "richTextBoxBackEdgesInCfg";
            this.richTextBoxBackEdgesInCfg.ReadOnly = true;
            this.richTextBoxBackEdgesInCfg.Size = new System.Drawing.Size(281, 380);
            this.richTextBoxBackEdgesInCfg.TabIndex = 4;
            this.richTextBoxBackEdgesInCfg.Text = "";
            // 
            // labelIntermidiateCodeTextBoxTitle
            // 
            this.labelIntermidiateCodeTextBoxTitle.AutoSize = true;
            this.labelIntermidiateCodeTextBoxTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.labelIntermidiateCodeTextBoxTitle.Location = new System.Drawing.Point(13, 49);
            this.labelIntermidiateCodeTextBoxTitle.Name = "labelIntermidiateCodeTextBoxTitle";
            this.labelIntermidiateCodeTextBoxTitle.Size = new System.Drawing.Size(138, 17);
            this.labelIntermidiateCodeTextBoxTitle.TabIndex = 5;
            this.labelIntermidiateCodeTextBoxTitle.Text = "Intermidiate code ";
            // 
            // labelBackEdges
            // 
            this.labelBackEdges.AutoSize = true;
            this.labelBackEdges.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.labelBackEdges.Location = new System.Drawing.Point(375, 52);
            this.labelBackEdges.Name = "labelBackEdges";
            this.labelBackEdges.Size = new System.Drawing.Size(146, 17);
            this.labelBackEdges.TabIndex = 6;
            this.labelBackEdges.Text = "Back edges in CFG";
            // 
            // richTextBoxLoopInformation
            // 
            this.richTextBoxLoopInformation.Location = new System.Drawing.Point(665, 68);
            this.richTextBoxLoopInformation.Name = "richTextBoxLoopInformation";
            this.richTextBoxLoopInformation.ReadOnly = true;
            this.richTextBoxLoopInformation.Size = new System.Drawing.Size(281, 380);
            this.richTextBoxLoopInformation.TabIndex = 7;
            this.richTextBoxLoopInformation.Text = "";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.label1.Location = new System.Drawing.Point(662, 52);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(130, 17);
            this.label1.TabIndex = 8;
            this.label1.Text = "Loop Information";
            // 
            // buttonShowGraph
            // 
            this.buttonShowGraph.Location = new System.Drawing.Point(378, 454);
            this.buttonShowGraph.Name = "buttonShowGraph";
            this.buttonShowGraph.Size = new System.Drawing.Size(144, 43);
            this.buttonShowGraph.TabIndex = 9;
            this.buttonShowGraph.Text = "Show CFG";
            this.buttonShowGraph.UseVisualStyleBackColor = true;
            this.buttonShowGraph.Click += new System.EventHandler(this.buttonShowGraph_Click);
            // 
            // labelInputFile
            // 
            this.labelInputFile.AutoSize = true;
            this.labelInputFile.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(177)));
            this.labelInputFile.Location = new System.Drawing.Point(682, 14);
            this.labelInputFile.Name = "labelInputFile";
            this.labelInputFile.Size = new System.Drawing.Size(153, 15);
            this.labelInputFile.TabIndex = 10;
            this.labelInputFile.Text = "Choose a *.vcg file as input";
            // 
            // LoopIdentificationForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(958, 509);
            this.Controls.Add(this.labelInputFile);
            this.Controls.Add(this.buttonShowGraph);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.richTextBoxLoopInformation);
            this.Controls.Add(this.labelBackEdges);
            this.Controls.Add(this.labelIntermidiateCodeTextBoxTitle);
            this.Controls.Add(this.richTextBoxBackEdgesInCfg);
            this.Controls.Add(this.richTextBoxBasicBlock);
            this.Controls.Add(this.buttonBrowse);
            this.Controls.Add(this.textBoxInputFilePath);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "LoopIdentificationForm";
            this.Text = "Loop identification";
            this.Load += new System.EventHandler(this.LoopIdentificationForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxInputFilePath;
        private System.Windows.Forms.Button buttonBrowse;
        private System.Windows.Forms.RichTextBox richTextBoxBasicBlock;
        private System.Windows.Forms.RichTextBox richTextBoxBackEdgesInCfg;
        private System.Windows.Forms.Label labelIntermidiateCodeTextBoxTitle;
        private System.Windows.Forms.Label labelBackEdges;
        private System.Windows.Forms.RichTextBox richTextBoxLoopInformation;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonShowGraph;
        private System.Windows.Forms.Label labelInputFile;
    }
}

