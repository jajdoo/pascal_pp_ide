using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CompilationLoopIdentifications
{
    /// <summary>
    /// This class is a node in a CFG (control flow graph) of basic blocks
    /// </summary>
    class GraphNode
    {
        // Id of the basic block
        private String id;
        public String ID
        {
            get { return id; }
            set { id = value; }
        }

        private String branchVariable;
        /// <summary>
        /// This this is the branch variable of the basic block
        /// </summary>
        public String BranchVariable
        {
            get { return branchVariable; }
        }


        // The code of the basic block
        private String basicBlockCode;

        public String BasicBlockCode
        {
            get { return basicBlockCode; }
            set { 
                basicBlockCode = value;
                if (basicBlockCode.Contains('R')) //If there is a register find it
                {
                    branchVariable = basicBlockCode.Substring(basicBlockCode.LastIndexOf("R"));
                    branchVariable = branchVariable.Substring(0, branchVariable.IndexOf(']') + 1);
                }
                }
        }

        //Branch 1
        private GraphNode branch1;
        public GraphNode Branch1
        {
            get { return branch1; }
            set { branch1 = value; }
        }
        //Branch 2
        private GraphNode branch2;

        public GraphNode Branch2
        {
            get { return branch2; }
            set { branch2 = value; }
        }
        
        /// <summary>
        /// Empty Constructor
        /// </summary>
        public GraphNode()
        {
            branch1 = null;
            branch2 = null;
            this.basicBlockCode = "";
        }
        /// <summary>
        /// A constructor that recives the code of the basic block
        /// </summary>
        /// <param name="basicBlockCode">The Code in the new basic block</param>
        public GraphNode(String basicBlockCode)
        {
            branch1 = null;
            branch2 = null;
            this.basicBlockCode = basicBlockCode;
        }

        private Dictionary<String, GraphNode> dominatorsList = new Dictionary<string, GraphNode>(); //Dictionary That will hold the list of my dominators

        internal Dictionary<String, GraphNode> DominatorsList
        {
            get { return dominatorsList; }
        }
        private Dictionary<String, GraphNode> dominatedList = new Dictionary<string, GraphNode>(); //Dictionary That will hold my dominated nodes

        internal Dictionary<String, GraphNode> DominatedList
        {
            get { return dominatedList; }
        }

        /// <summary>
        /// This method calculates my dominance list
        /// </summary>
        /// <param name="dominatorLost">the dominator list of my grpah parent</param>
        /// <returns>false if there is a backedge from parant to this node, true if dominator was calculated</returns>
        public bool dom(Dictionary<String,GraphNode> parantDominatorList)
        {
            if (parantDominatorList.ContainsKey(this.ID)) //if my dominator has me in his dominator list it means a back edge
            {
                return false; //BACK EDGE!
            }

            if (this.DominatorsList.Count == 0) //If my dominators list is empty copy the parants list
                unionCopy(parantDominatorList, this.DominatorsList);
            else
            {
                //Remove my self from my dominators dominated List (Will be updated again after lists intersection repair)
                foreach (KeyValuePair<String, GraphNode> pair in this.DominatorsList)
                {
                    pair.Value.RemoveFromDominated(this.ID, this);
                }
                intersectionCopy(parantDominatorList, this.DominatorsList); //else calculate intersection of dominators between me and my parant
            }
            this.DominatorsList.Add(this.ID, this); //add my selfDominance to the dominators list

            
            //Add my self to my dominators dominated List 
            foreach (KeyValuePair<String, GraphNode> pair in this.DominatorsList)
            {
                pair.Value.addToDominated(this.ID, this);
            }
            
            return true;
        }

        /// <summary>
        /// This method adds a dominatee to my dominated nodes list
        /// </summary>
        /// <param name="dominatedNodeKey">The key of the dominated node</param>
        /// <param name="dominatedNode">The dominated node</param>
        private void addToDominated(String dominatedNodeKey,GraphNode dominatedNode)
        {
            if (!this.DominatedList.ContainsKey(dominatedNodeKey)) //if node not allready in list
            {
                DominatedList.Add(dominatedNodeKey, dominatedNode);
            }

        }

        /// <summary>
        /// This method removes a dominatee to my dominated nodes list
        /// </summary>
        /// <param name="dominatedNodeKey">The key of the dominated node</param>
        /// <param name="dominatedNode">The dominated node</param>
        private void RemoveFromDominated(String dominatedNodeKey, GraphNode dominatedNode)
        {
            if (this.DominatedList.ContainsKey(dominatedNodeKey)) //if node is in the list
            {
                DominatedList.Remove(dominatedNodeKey);
            }

        }
        /// <summary>
        /// This method perfomrs an intersection copy (copys only common values) from two dictionary<String,Type>
        /// </summary>
        /// <param name="dictionarySource">Dictionary to copy from</param>
        /// <param name="dictionaryTarget">Dictionary to copy too</param>
        private void intersectionCopy(Dictionary<String, GraphNode> dictionarySource, Dictionary<String, GraphNode> dictionaryTarget)
        {           
            String[] uncommonKeys = new String[dictionaryTarget.Count]; //A string array that will be used to store common keys
            int uncommonKeysCount = 0;
            foreach (KeyValuePair<String, GraphNode> pair in dictionaryTarget)
            {
                if (!dictionarySource.ContainsKey((String)pair.Key)) //if the key is not common for both dictioanrys
                    uncommonKeys[uncommonKeysCount++] = pair.Key; //save uncommon key for deletation
            }
            ////Remove uncommon keys from dictioanry
            for (int uncommonKeyIndex = 0; uncommonKeyIndex < uncommonKeysCount; uncommonKeyIndex++)
            {
                dictionaryTarget.Remove(uncommonKeys[uncommonKeyIndex]); //remove it from target
            }


        }
        
        /// <summary>
        /// This method perfomrs a full copy of two dictionary<String,Type> copying the entire dictionary source to dictionary target
        /// </summary>
        /// <param name="dictionarySource"></param>
        /// <param name="dictionaryTarget"></param>
        private void unionCopy(Dictionary<String, GraphNode> dictionarySource, Dictionary<String, GraphNode> dictionaryTarget)
        {
            foreach (KeyValuePair<String, GraphNode> pair in dictionarySource)
            {
                if (!dictionaryTarget.ContainsKey(pair.Key)) //if value not allready in target (avoid duplicates)
                    dictionaryTarget.Add(pair.Key, pair.Value);
            }
        }

        /// <summary>
        /// To string override
        /// </summary>
        /// <returns>a string </returns>
        public override string ToString()
        {
            String nodeData = "";
            nodeData += "==================== \n";
            nodeData += "ID: " + this.ID +"\n";
            nodeData += "Branch1: ";
            if (this.branch1!=null)
                nodeData += this.branch1.ID  +"\n";
            else
                nodeData +=  "None\n";
            nodeData += "Branch2: ";
            if (this.branch2 != null)
                nodeData += this.branch2.ID + "\n";
            else
                nodeData += "None\n";
            nodeData += "Dominated nodes: ";
            foreach (KeyValuePair<String, GraphNode> pair in this.DominatedList)
            {
                nodeData += pair.Key +" ,";
            }
            nodeData += "\nDominators: ";
            foreach (KeyValuePair<String, GraphNode> pair in this.DominatorsList)
            {
                nodeData += pair.Key + " ,";
            }
            nodeData += "\n";
            return nodeData;
        }
        
        /////////////////////////////////////////////////////////
        /////////////////// STATIC METHODS //////////////////////
        /////////////////////////////////////////////////////////

        /// <summary>
        /// This method calculates the Dominance for a CFG (Recursivly) 
        /// </summary>
        /// <param name="root">Root of a CFG</param>
        static public void calculateDominanceDataforCFG(GraphNode root,BackEdgesList backEdgeList)
        {
            if (root == null) //Stoping condition
                return;
            if (root.DominatorsList.Count == 0) //If i am empty (it means I am the true root of the tree)
                root.dom(root.DominatorsList);
            //PostOrderTraverse
            if (root.branch1 != null)
            {
                if (root.branch1.dom(root.DominatorsList) == true) //If it's not a back edge
                    calculateDominanceDataforCFG(root.branch1, backEdgeList);
                else
                {
                    backEdgeList.Add(root.ID,root.branch1.ID);   
                } //TODO:deal with backedge
            }
            if (root.branch2 != null)
            {
                if (root.branch2.dom(root.DominatorsList) == true) //if it's not a back edge
                    calculateDominanceDataforCFG(root.branch2, backEdgeList);
                else
                {
                    backEdgeList.Add(root.ID, root.branch2.ID); ;
                } //TODO: deal with backedge
            }
        }
    }



}
