using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace CompilationLoopIdentifications
{
    public partial class LoopIdentificationForm : Form
    {
        private logicLayer myLogicLayer = new logicLayer();
        private String selectedFilePath = "";
        public LoopIdentificationForm()
        {
            InitializeComponent();
            richTextBoxBasicBlock.BackColor = Color.White;
            richTextBoxBackEdgesInCfg.BackColor = Color.White;
            richTextBoxLoopInformation.BackColor = Color.White;
            this.BackColor = Color.Wheat;
        }

        private void buttonIdentifyLoops_Click(object sender, EventArgs e)
        {

        }

        /// <summary>
        /// Browse button even handler
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void buttonBrowse_Click(object sender, EventArgs e)
        {
            OpenFileDialog fd = new OpenFileDialog();
            fd.Filter = "VCG files|*.vcg|All Files|*.*";
            if (fd.ShowDialog() == DialogResult.OK)
            {
                textBoxInputFilePath.Text = fd.FileName;
                selectedFilePath = fd.FileName;
                
                if (selectedFilePath != "")
                {
                    myLogicLayer.identifyLoops(selectedFilePath);
                    richTextBoxBasicBlock.Text = "";
                    richTextBoxBackEdgesInCfg.Text = "";
                    richTextBoxLoopInformation.Text = myLogicLayer.getLoops();

                    Regex r = new Regex("\\n");
                    String[] lines = r.Split(myLogicLayer.getIntermidiateCodeAsBasicBlocks());
                    //Next, I take each line and process its contents like so. 
                    foreach (string l in lines)
                    {
                        ParseLine(l);
                    }

                    lines = r.Split(myLogicLayer.getBackEdges());
                    //Next, I take each line and process its contents like so. 
                    foreach (string l in lines)
                    {
                        parseBackEdges(l);
                    }
                }

            }

        }

        /// <summary>
        /// Show graph button event handler
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void buttonShowGraph_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("VCG.EXE", selectedFilePath);
        }

        private void LoopIdentificationForm_Load(object sender, EventArgs e)
        {

        }

        private void textBoxInputFilePath_TextChanged(object sender, EventArgs e)
        {
            richTextBoxBackEdgesInCfg.Text = "";
            richTextBoxBasicBlock.Text = "";
            richTextBoxLoopInformation.Text = "";
        }


        /* Rich text box methods*/
        private void ParseLine(string line)
        {
            Regex r = new Regex("([ \\t{}():;])");
            String[] tokens = r.Split(line);
            foreach (string token in tokens)
            {
                // Set the tokens default color and font.
                richTextBoxBasicBlock.SelectionColor = Color.Black;
                richTextBoxBasicBlock.SelectionFont = new Font("Courier New", 10, FontStyle.Regular);
                // Check whether the token is a keyword. 
                String[] keywords = { "LOADI", "MUL", "ADD", "STORE","CMP","LOAD"};
                for (int i = 0; i < keywords.Length; i++)
                {
                    if (keywords[i] == token)
                    {
                        // Apply alternative color and font to highlight keyword.
                        richTextBoxBasicBlock.SelectionColor = Color.Blue;
                        richTextBoxBasicBlock.SelectionFont = new Font("Courier New", 10, FontStyle.Bold);
                        break;
                    }
                }
                String[] branchCommands = { "BNE", "BRA", "BGE"};
                for (int i = 0; i < branchCommands.Length; i++)
                {
                    if (branchCommands[i] == token)
                    {
                        // Apply alternative color and font to highlight keyword.
                        richTextBoxBasicBlock.SelectionColor = Color.Red;
                        richTextBoxBasicBlock.SelectionFont = new Font("Courier New", 10, FontStyle.Bold);
                        break;
                    }
                }

                String[] borders = { "==============================" };
                for (int i = 0; i < borders.Length; i++)
                {
                    if (borders[i] == token)
                    {
                        // Apply alternative color and font to highlight keyword.
                        richTextBoxBasicBlock.SelectionColor = Color.Purple;
                        richTextBoxBasicBlock.SelectionFont = new Font("Courier New", 10, FontStyle.Bold);
                        break;
                    }
                }

                richTextBoxBasicBlock.SelectedText = token;
            }
            richTextBoxBasicBlock.SelectedText = "\n";
        }

        //Parse backEdges
        private void parseBackEdges(string line)
        {
            Regex r = new Regex("([ \\t{}():;])");
            String[] tokens = r.Split(line);
            foreach (string token in tokens)
            {
                // Set the tokens default color and font.
                richTextBoxBackEdgesInCfg.SelectionColor = Color.Black;
                richTextBoxBackEdgesInCfg.SelectionFont = new Font("Courier New", 10, FontStyle.Regular);
                // Check whether the token is a keyword. 
                String[] keywords = { "Source", "Target"};
                for (int i = 0; i < keywords.Length; i++)
                {
                    if (keywords[i] == token)
                    {
                        // Apply alternative color and font to highlight keyword.
                        richTextBoxBackEdgesInCfg.SelectionColor = Color.Blue;
                        richTextBoxBackEdgesInCfg.SelectionFont = new Font("Courier New", 10, FontStyle.Bold);
                        break;
                    }
                }
                String[] branchCommands = { "-->"};
                for (int i = 0; i < branchCommands.Length; i++)
                {
                    if (branchCommands[i] == token)
                    {
                        // Apply alternative color and font to highlight keyword.
                        richTextBoxBackEdgesInCfg.SelectionColor = Color.Red;
                        richTextBoxBackEdgesInCfg.SelectionFont = new Font("Courier New", 10, FontStyle.Bold);
                        break;
                    }
                }

                String[] borders = { "==============================" };
                for (int i = 0; i < borders.Length; i++)
                {
                    if (borders[i] == token)
                    {
                        // Apply alternative color and font to highlight keyword.
                        richTextBoxBackEdgesInCfg.SelectionColor = Color.Purple;
                        richTextBoxBackEdgesInCfg.SelectionFont = new Font("Courier New", 10, FontStyle.Bold);
                        break;
                    }
                }

                richTextBoxBackEdgesInCfg.SelectedText = token;
            }
            richTextBoxBackEdgesInCfg.SelectedText = "\n";
        } 
    }
}
