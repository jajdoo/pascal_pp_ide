using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace CompilationLoopIdentifications
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            if (args.Length == 1)
            {
                (new logicLayer()).identifyLoops(args[0]);
            }
            else
                Application.Run(new LoopIdentificationForm());
        }
    }
}
