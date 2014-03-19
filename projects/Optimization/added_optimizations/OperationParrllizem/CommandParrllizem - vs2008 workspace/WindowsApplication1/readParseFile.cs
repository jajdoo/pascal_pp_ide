using System;
using System.Collections;
using System.Text;
using System.IO;
using System.Windows.Forms;

namespace CompilersLab
{
    class readParseFile
    {
        public static ArrayList parseInputTextFile(LogicManager logicMan)
        {
            ArrayList bbs = new ArrayList();
            try
            {
                BasicBlock tempBB = new BasicBlock();
                string[] lines = File.ReadAllLines(logicMan.FilePath);
                logicMan.srcLines = lines;
                for (int i = 0; i < lines.Length; i++)
                {
                    //empty line 
                    if (lines[i].Equals(""))
                        continue;
                    // new Basic block 
                    if (lines[i].Contains("----"))
                    {
                        tempBB = new BasicBlock();
                        bbs.Add(tempBB);
                    }
                    // add lines to current basic blocks
                    if (lines[i].Contains("["))
                    {
                        tempBB.SourceIrList.Add(lines[i]);
                    }
                }
            }
            catch (System.Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            logicMan.BasicBlocks = bbs;
            return bbs;
        }
    }
}
