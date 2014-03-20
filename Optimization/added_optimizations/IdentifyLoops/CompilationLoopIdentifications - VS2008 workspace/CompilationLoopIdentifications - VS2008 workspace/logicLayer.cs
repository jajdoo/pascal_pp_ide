using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CompilationLoopIdentifications
{
    class logicLayer
    {
        private IntermidiatCodeAsBasicBlocksCFG cfgRoot = null;
        
        public void identifyLoops(String filePath)
        {
            FileParser fp = new FileParser();
            cfgRoot = fp.parsVCGfile(filePath); //Test cfg creation with dominance
            cfgRoot.findLoops();         
        }
        /// <summary>
        /// This method returns the whole intermidiate code divided into basic blocks
        /// Each line is numbered according to it's original order in the intermidiate 
        /// code representation of the compiled program
        /// </summary>
        /// <returns>The whole intermidiate code with divided into basic blocks. line
        /// numbers are by the order of the line in the original intermidiat code 
        /// before dividing it in to basic blocks</returns>
        public String getIntermidiateCodeAsBasicBlocks()
        {
            if (cfgRoot == null)
                return null;
            return cfgRoot.IntermidiatCodeBasicBlocks;
        }

        /// <summary>
        /// This method returs a list of the backesges in the CFG as a formated String
        /// </summary>
        /// <returns>a list of the backedges in the CFG as a formated String</returns>
        public String getBackEdges()
        {
            if (cfgRoot == null)
                return null;
            BackEdgesList backesgeList = cfgRoot.CfgBackEdgesList;
            String[,] backedges = backesgeList.BackEdges;
            if (backedges == null)
                return "";
            String backEdgesString = "";
            for (int i = 0; i < backedges.GetLength(0); i++)
                backEdgesString += "Source: " + backedges[i,0] + "\t -->   Target: " + backedges[i,1] + "\n";
            return backEdgesString;
        }

        public String getLoops()
        {
            if (cfgRoot == null)
                return null;
            return cfgRoot.Loops;
        }
    }
}
