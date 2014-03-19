using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CompilationLoopIdentifications
{
    class IntermidiatCodeAsBasicBlocksCFG
    {
        /// <summary>
        /// Empty constructor
        /// </summary>
        public IntermidiatCodeAsBasicBlocksCFG()
        {
            root = null;
            cfgBackEdgesList = null;
        }

        /// <summary>
        /// This is the root of the CFG graph
        /// </summary>
        private GraphNode root;
        internal GraphNode Root
        {
            get { return root; }
            set { root = value; }
        }

        private BackEdgesList cfgBackEdgesList = new BackEdgesList();
        /// <summary>
        /// The list of the back edges in the cfg graph
        /// </summary>
        internal BackEdgesList CfgBackEdgesList
        {
            get { return cfgBackEdgesList; }
            set { cfgBackEdgesList = value; }
        }

        /// <summary>
        /// This is the String that represents the loops in the system
        /// </summary>
        private String loopsAsString = null;
        public String LoopsAsString
        {
            get { return loopsAsString; }
            set { loopsAsString = value; }
        }


        private String intermidiatCodeBasicBlocks = null;

        public String IntermidiatCodeBasicBlocks
        {
            get { return intermidiatCodeBasicBlocks; }
            set { intermidiatCodeBasicBlocks = value; }
        }

        /// <summary>
        /// This is a recursive method that extract the nodes that belong to the body of the loop.
        /// </summary>
        /// <param name="root">The node that is the target of the backedge</param>
        /// <param name="source">the first node ID, the target of the backedge</param>
        /// <param name="target">the ID of the last node in the loop, the source of the backedge</param>
        /// <param name="loopBody">This is a dictionary that will be used to store the nodes that belong to the body of the loop</param>
        /// <returns>false if the root doesn't belong to the loop body, otherwize true</returns>
        private bool getLoopBodyFromHeaderToLast(GraphNode root, String source,String target,Dictionary<String,GraphNode> loopBody)
        {
            if (root == null) return false;  
            if (!root.DominatorsList.ContainsKey(source)) return false; //if the root is not dominated by the loop entrence return false
            if (loopBody.ContainsKey(root.ID)) return true; //if root is allready in the loop return true;
            if (root.ID == target) //if the root is the target add it to the loopBody
            {
                if (!loopBody.ContainsKey(root.ID)) //prevent duplicates
                    loopBody.Add(root.ID, root);
                return true;
            }
            bool returnValue = false;
            //Try going to the first branch
            if (getLoopBodyFromHeaderToLast(root.Branch1, source, target, loopBody) && root.DominatorsList.ContainsKey(source))
            {
                if (!loopBody.ContainsKey(root.ID)) //prevent duplicates
                    loopBody.Add(root.ID, root);
                returnValue = true;
            }
            //Try going to the second branch
            if (getLoopBodyFromHeaderToLast(root.Branch2, source, target, loopBody) && root.DominatorsList.ContainsKey(source))
            {
                if (!loopBody.ContainsKey(root.ID) )
                    loopBody.Add(root.ID, root);
                returnValue = true;
            }
            return returnValue;
        }
    /// <summary>
    /// This method is a finds the the loop body of all the backedges of the CFG
    /// Algorithm: 
    /// </summary>
    /// <returns>and  array of string, each string represents a loop. The string contains the ID's of the basic blocks that make the body of the loop 
    /// first ID is the first block in the loop and the last ID is the last block in the loop, the other ID's order of appearance doesn't have any  meaning 
    /// </returns>
        private String[] loops = null;
        public String Loops
        {
            get {
                String loopsAsFormatedString = "";
                for (int i = 0; i < loops.Length; i++)
                {
                    loopsAsFormatedString += loops[i];
                    if (loopVariables[i] != "")
                        loopsAsFormatedString += "\n\t Loop Variable " + loopVariables[i] + "\n==============================\n";
                    else
                        loopsAsFormatedString += "\n==============================\n";
                }
                
                return loopsAsFormatedString; 
                }
        }

        private String[] loopVariables = null;



    public void findLoops()
    {
        string[,] backedges = cfgBackEdgesList.BackEdges;
        Dictionary<String,GraphNode> loopBody = new Dictionary<string,GraphNode>();
        //root is the source (headr of loop node) source is the node ID, target is the loopBack start point, loopBody will contain all the nodes
        //in the list
        if (backedges == null)
        {
            this.loops = new String[1];
            this.loops[0] = "No loops";
            this.loopVariables = new String[1];
            this.loopVariables[0] = "";
            return;
        }
        String[] loops = new String[backedges.GetLength(0)];
        String[] loopsVariables = new String[backedges.GetLength(0)];
        for (int i = 0; i < backedges.GetLength(0); i++) //Go over all backEdges
        {
            this.getLoopBodyFromHeaderToLast(this.root.DominatedList[backedges[i, 1 ]], backedges[i, 1], backedges[i, 0], loopBody);
            {
                loops[i] = "Loop header: " + backedges[i, 1] + "\n\tLoop body:\n\t"; //loop header
                foreach (KeyValuePair<String, GraphNode> pair in loopBody) //add loop body
                {
                    if ((pair.Key != backedges[i, 1]) && (pair.Key != backedges[i, 0]))
                    {
                        loops[i] += pair.Key + ",";
                        loopsVariables[i] = pair.Value.BranchVariable;
                    }
                }
                //getLoopVariable(loopBody[loopBody.Count - 1].BasicBlockCode);
                loops[i] += "\nLast basic block:";
                loops[i] += backedges[i, 0] + "\n"; //loop end point
                loopBody.Clear(); //Clear the list
            }
        }
        this.loopVariables = loopsVariables;
        this.loops = loops;
        xmlHandler.saveFile("loops.xml",loops,loopVariables);
    }

    }

    

    /// <summary>
    /// This class implements a List of backedes, it supports addition to the list and reciving all the backeges as a double array of strings
    /// </summary>
    class BackEdgesList
    {
        private Dictionary<String,int> backEdgeTargetIndexs= new Dictionary<String,int>(); //This dictioanry is used to link a source to index in the arrayLists
        //In the 3 List below all items that are located at the same index are related, where the backEdgeSource[i] is the source of backEdgeTarge1[i] and backEdgeTarget2[i]
        //if there is only one backedge backEsgeTarget2[i] = null
        private System.Collections.ArrayList backEdgeSource = new System.Collections.ArrayList(); //List of all the sources
        private System.Collections.ArrayList backEdgeTarget1 = new System.Collections.ArrayList(); //List of all the first targets
        private System.Collections.ArrayList backEdgeTarget2 = new System.Collections.ArrayList(); //List of all the second target
        private int count = 0;          //number of sources
        private int backEdgesCount = 0; //number of backedges in the CFG (a source might have to targets)
        
        /// <summary>
        /// This property holds the nubmer of Backedges in the list
        /// </summary>
        public int Count
        {
            get { return backEdgesCount; }
        }
        /// <summary>
        /// This method adds a backedge to the list
        /// </summary>
        /// <param name="source">the source of the backedge (the node the edge originates from)</param>
        /// <param name="target">the target of the backedge (the node where the edge ends)</param>
        /// <returns></returns>
        public bool Add(String source,String target)
        {
            if (backEdgeTargetIndexs.ContainsKey(source)) //if source allready in List
            {
                int targetIndex = backEdgeTargetIndexs[source];
                if ((String)backEdgeTarget1[targetIndex] == target) //if it's the same Target
                    return false;
                else
                {
                    if ((String)backEdgeTarget2[targetIndex] == target) //if it's the same Target
                        return false;
                    backEdgeTarget2[targetIndex] = target;
                    backEdgesCount++;
                }

            }
            else
            {
                backEdgesCount++;
                backEdgeTargetIndexs.Add(source, count++);
                backEdgeSource.Add(source);
                backEdgeTarget1.Add(target);
                backEdgeTarget2.Add(null);
            }
            return true;
        }
        private String[,] backEdges = null;

        /// <summary>
        /// This property returns the back edges in the CFG
        /// Data is stored in a 2d String array each row is an esge
        /// format [source,target]
        /// example this.BackEdges[0,0] = I
        ///         this.BackEdges[0,1] = J
        /// There is an esge from I to J
        /// </summary>
        public String[,] BackEdges
        {
            get 
            {
                if (backEdgesCount == 0) return null;
                backEdges = new String[backEdgesCount, 2];
                int index = 0;
                for (int i = 0; i < count; i++)
                {
                    backEdges[index, 0] = (String)backEdgeSource[i];
                    backEdges[index++, 1] = (String)backEdgeTarget1[i];
                    if ((String)backEdgeTarget2[i] != null)
                    {
                        backEdges[index, 0] = (String)backEdgeSource[i];
                        backEdges[index++, 1] = (String)backEdgeTarget2[i];
                    }
                }
                return backEdges; 
            }
        }
    }
}
