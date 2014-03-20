using System;
using System.Collections;
using System.Text;

namespace CompilersLab
{
    class LogicManager
    {
        private ArrayList basicBlocks;

        public ArrayList BasicBlocks
        {
            get { return basicBlocks; }
            set { basicBlocks = value; }
        }

        private string filePath;

        public string FilePath
        {
            get { return filePath; }
            set { filePath = value; }
        }

        private String[] sourcelines;

        public String[] srcLines
        {
            get { return sourcelines; }
            set { sourcelines = value; }
        }

        /// <summary>
        /// This method will build the parallel IR commands
        /// </summary>
        public void buildParallelBasicBlocks()
        {
            for (int i = 0; i < BasicBlocks.Count ; i++)
            {
                buildParallelBasicBlock((BasicBlock)BasicBlocks[i]);
            }
        }

        /// <summary>
        /// This method will build the parallel IR commands for a single Basic block
        /// </summary>
        /// <param name="bb"></param>
        private void buildParallelBasicBlock(BasicBlock bb)
        {
            int line = 0;
            // first command
            bb.ParaIrList.Add(bb.SourceIrList[0]);
            bb.ParaIrUsedRegsList.Add( getUsedRegsList((String)bb.SourceIrList[0]));
            for (int i = 1; i < bb.SourceIrList.Count; i++)
            {
                ArrayList[] usedregs = getUsedRegsList((String)bb.SourceIrList[i]);
                if (usedregs[0].Count == 0)
                {
                    // add to new line
                    bb.ParaIrList.Add(bb.SourceIrList[i]);
                    line++;
                }
                else // there are registers
                {
                    ArrayList[] currentReglist = (ArrayList[])bb.ParaIrUsedRegsList[line];
                    bool flag = false;
                    string type = "";

                    // find if a reg is used
                    string dep = "";
                    for (int j = 0 ; j < usedregs[0].Count; j++)
                    {
                        type = "";
                        // if found two same registers 
                        if (currentReglist[0].Contains(usedregs[0][j]))
                        {
                            if (((string)usedregs[1][j]).Contains("D"))
                            {
                                flag = true; // find dependency
                                //find type of dependence
                                for (int k = 0; k < currentReglist[0].Count; k++)
                                {
                                    if (((string)currentReglist[0][k]).Contains((string)usedregs[0][j]))
                                        if (((string)currentReglist[1][k]).Contains("D"))   // D:D 
                                        {
                                            type = "Output dependence: " + (string)currentReglist[0][k];
                                            dep = dep + type + " | ";
                                            //bb.BasicBlocksDepend.Add(type);
                                            break;
                                        }
                                        else    // U:D
                                        {
                                            type = "Anti dependence: " + (string)currentReglist[0][k];
                                            dep = dep + type + " | ";
                                            //bb.BasicBlocksDepend.Add(type);
                                            break;
                                        }
                                }
                                break;
                            }
                            else
                                for (int k = 0; k < currentReglist[0].Count; k++)
                                {
                                    if (((string)currentReglist[0][k]).Contains((string)usedregs[0][j]))
                                        if (((string)currentReglist[1][k]).Contains("D"))
                                        {
                                            flag = true; // find dependency
                                            type = "Flow dependence: " + (string)currentReglist[0][k];       // D:U
                                            dep = dep + type + " | ";
                                            //bb.BasicBlocksDepend.Add(type);
                                            break;
                                        }
                                }
                        }
                
                    }
                    if (flag)   //found dependency
                    {
                        bb.BasicBlocksDepend.Add(dep.Substring(0,dep.Length -2));
                        line++;
                        bb.ParaIrList.Add(bb.SourceIrList[i]);
                        bb.ParaIrUsedRegsList.Add(usedregs);
                    }
                    else
                    {
                        String currLine = (String)bb.ParaIrList[line];
                        currLine = currLine + " || " + bb.SourceIrList[i];
                        bb.ParaIrList[line] = currLine;
                        for (int j = 0; j < usedregs[0].Count; j++)
                        {
                            currentReglist[0].Add(usedregs[0][j]);
                            currentReglist[1].Add(usedregs[1][j]);
                        }
                    }
                    
                }
            }
            Console.Out.WriteLine("");
        }

        // get the list of used registers in the command
        private ArrayList[] getUsedRegsList(String irCommand)
        {
            ArrayList[] regs = new ArrayList[2];

            ArrayList regsList = new ArrayList();    // reg list
            ArrayList regsUsedList = new ArrayList();   // use / define list
            regs[0] = regsList;
            regs[1] = regsUsedList;

            if (!irCommand.Contains(","))
                return regs;

            string temp = irCommand;
            string rightOnly = temp.Substring(temp.LastIndexOf(" "));
            String[] parts = rightOnly.Split(',');
            for (int i = 0; i < parts.Length; i++)
            {
                if (parts[i].Contains("R"))
                {
                    if (i != parts.Length - 1)
                        regsUsedList.Add("U");
                    else
                        regsUsedList.Add("D");
                    string temp2 = parts[i];
                    temp2 = temp2.Trim();
                    regsList.Add(temp2);
                }
            }
            return regs;
        }
    }
}
