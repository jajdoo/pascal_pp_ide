/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package finalproj;

import java.awt.Component;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JOptionPane;

/**
 * 
 * @author Max
 */
public class DDG
{
	
	//private final String jarPath;
	
	public DDG(String mainPath)
	{
		//this.jarPath = mainPath;
	}
	
	public void OpenDDGForm(String projectPath, Component frame)
	{
		File checkFile = new File(projectPath + "\\symbol " + "table.txt");
		if (!checkFile.exists())
		{
			JOptionPane.showMessageDialog(frame, "Cannot locate 'symbol table.txt'", "Cannot Locate File", JOptionPane.ERROR_MESSAGE);
		}
		else
		{
			FileWriter out;
			try
			{
				out = new FileWriter(projectPath + "\\StartDDG.bat");
				out.write("cd " + projectPath + "\r\n"
						+ "DDG.exe\r\n"
						+ "exit");
				out.close();
			}
			catch (IOException ex)
			{
				Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
			}
			
			String command = "cmd /c start " + projectPath + "\\StartDDG.bat";
			try
			{
				//Process child = 
				Runtime.getRuntime().exec(command);
			}
			catch (IOException ex)
			{
				Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
			}
		}
		/*     Runtime runtime = Runtime.getRuntime();
		 try {
		 Process process = runtime.exec(projectPath + "\\DDG.exe");
		 } catch (IOException ex) {
		 Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
		 }
		 }*/
	}
}
