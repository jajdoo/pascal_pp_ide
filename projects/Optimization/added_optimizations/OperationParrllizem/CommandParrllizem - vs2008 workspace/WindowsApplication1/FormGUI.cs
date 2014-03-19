using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace CompilersLab
{
    public partial class Form1 : Form
    {
        private LogicManager logicmanager;

        public Form1()
        {
            logicmanager = new LogicManager() ;
            InitializeComponent();
        }

        private void button_openIR_Click(object sender, EventArgs e)
        {
            openFileDialog_IR.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
            openFileDialog_IR.ShowDialog();
        }

        private void button_ParseFiles_Click(object sender, EventArgs e)
        {
            logicmanager.buildParallelBasicBlocks();
            for (int i = 0; i < logicmanager.BasicBlocks.Count; i++)
            {
                listBox_para.Items.Add("------------");
                listBox_Depn.Items.Add("------------");
                for (int j = 0; j < ((BasicBlock)logicmanager.BasicBlocks[i]).ParaIrList.Count; j++)
                {
                    listBox_para.Items.Add(((BasicBlock)logicmanager.BasicBlocks[i]).ParaIrList[j]);
                }
                listBox_Depn.Items.Add("\n");
                for (int j = 0; j < ((BasicBlock)logicmanager.BasicBlocks[i]).BasicBlocksDepend.Count; j++)
                {
                    listBox_Depn.Items.Add(((BasicBlock)logicmanager.BasicBlocks[i]).BasicBlocksDepend[j]);
                }
            }
        }

        private void openFileDialog_IR_FileOk(object sender, CancelEventArgs e)
        {
            if (!openFileDialog_IR.CheckFileExists)
            {
                MessageBox.Show("Input file doesn't exist");
                return;
            }

            logicmanager.FilePath = openFileDialog_IR.FileName;
            readParseFile.parseInputTextFile(logicmanager);
            listBox_sourceIR.Items.AddRange(logicmanager.srcLines);
        }
    }
}
