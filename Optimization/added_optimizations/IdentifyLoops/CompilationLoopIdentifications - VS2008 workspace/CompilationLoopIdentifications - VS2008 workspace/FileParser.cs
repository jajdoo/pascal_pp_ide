using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CompilationLoopIdentifications
{
    class FileParser
    {
        /// <summary>
        /// This method reads a graph input file and builds a tree 
        /// of it
        /// </summary>
        /// <param name="filePath"></param>
        public IntermidiatCodeAsBasicBlocksCFG parsVCGfile(String filePath)
        {
            TextReader tr = new StreamReader(filePath);
            String line = "";
            String basicBlockCode = "";
            String intermidiatCodeInBasicBlocks = "";
            Dictionary<String, GraphNode> basicBlockDictionary = new Dictionary<string, GraphNode>(); //Dictionary will be used for indexing
            BackEdgesList backEdgeList = new BackEdgesList();
            IntermidiatCodeAsBasicBlocksCFG code = new IntermidiatCodeAsBasicBlocksCFG();
            GraphNode root = null;
            while ((line = tr.ReadLine()) != null) //read the file till the end
            {
                if (line.Contains("node")) //Create nodes
                    {
                        GraphNode basicBlock = new GraphNode();
                        line = tr.ReadLine(); //get basic block header
                        int titleIndex = line.IndexOf('\"')+1;
                        line = line.Substring(titleIndex);
                        titleIndex = line.IndexOf('\"');
                        line = line.Substring(0, titleIndex);
                        intermidiatCodeInBasicBlocks += "==============================\n";
                        intermidiatCodeInBasicBlocks += "Basic Block Title = " + line +"\n";
                        intermidiatCodeInBasicBlocks += "==============================\n";
                        basicBlock.ID = line;
                        //Extract the basic blocks code from the file
                        basicBlockCode = "";
                        while (!(line = tr.ReadLine()).Contains('}'))
                            basicBlockCode += line +"\n";
                        if (line.Contains('['))
                        {
                            line = line.Split('}')[0];
                            line = line.Substring(0, line.Length - 2);
                            basicBlockCode += line + "\n";
                        }
                        intermidiatCodeInBasicBlocks += basicBlockCode;
                        
                        basicBlock.BasicBlockCode = basicBlockCode;
                        basicBlockDictionary.Add(basicBlock.ID, basicBlock); //Add basic block to list
                        if (root == null)
                            root = basicBlock;
                        intermidiatCodeInBasicBlocks += "\n";
                    }
                if (line.Contains("edge:")) //Connect nodes
                {
                    line = tr.ReadLine(); //Read color settings of edge
                    line = tr.ReadLine(); //Source
                    //Read source Basic Block
                    int titleIndex = line.IndexOf('\"') + 1;
                    line = line.Substring(titleIndex);
                    titleIndex = line.IndexOf('\"');
                    line = line.Substring(0, titleIndex);
                    GraphNode source = null;
                    if (basicBlockDictionary.ContainsKey(line)) //Check if label exsists
                        source = basicBlockDictionary[line];
                    else
                        throw new KeyNotFoundException();
                    //Read Target Basic Block
                    line = tr.ReadLine(); //Target
                    titleIndex = line.IndexOf('\"') + 1;
                    line = line.Substring(titleIndex);
                    titleIndex = line.IndexOf('\"');
                    line = line.Substring(0, titleIndex);
                    GraphNode target;
                    if (basicBlockDictionary.ContainsKey(line))
                        target = basicBlockDictionary[line];
                    else
                        throw new KeyNotFoundException();
                    //Attach target Basic block to source basic block
                    if (source.Branch1 == null)
                        source.Branch1 = target;
                    else
                        source.Branch2 = target;  
                }
                
            }
            tr.Close();
            GraphNode.calculateDominanceDataforCFG(root,backEdgeList); //Calculate dominance for tree
            code.IntermidiatCodeBasicBlocks = intermidiatCodeInBasicBlocks;
            code.CfgBackEdgesList = backEdgeList;
            code.Root = root;
           
            return code;
        }
    }
}
