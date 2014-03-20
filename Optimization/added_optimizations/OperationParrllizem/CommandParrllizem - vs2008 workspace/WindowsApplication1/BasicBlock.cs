using System;
using System.Collections;
using System.Text;

namespace CompilersLab
{
    class BasicBlock
    {
        private ArrayList sourceIrList;

        private ArrayList paraIrUsedRegsList;

        private ArrayList paraIrList;

        private ArrayList basicBlocksDepend;

        public BasicBlock()
        {
            sourceIrList = new ArrayList();
            paraIrUsedRegsList = new ArrayList();
            paraIrList = new ArrayList();
            basicBlocksDepend = new ArrayList();
        }

        
        public ArrayList BasicBlocksDepend
        {
            get { return basicBlocksDepend; }
            set { basicBlocksDepend = value; }
        }

        public ArrayList SourceIrList
        {
            get { return sourceIrList; }
            set { sourceIrList = value; }
        }

        public ArrayList ParaIrList
        {
            get { return paraIrList; }
            set { paraIrList = value; }
        }

        public ArrayList ParaIrUsedRegsList
        {
            get { return paraIrUsedRegsList; }
            set { paraIrUsedRegsList = value; }
        }
    }
}
