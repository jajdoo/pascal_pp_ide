/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package finalproj;

import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 *
 */
public class Optimization
{
	
	private final String jarPath;
	
	public Optimization(String mainPath)
	{
		this.jarPath = mainPath;
	}
	
	public void OpenOptimizationWindow()
	{
		
		FileWriter out;
		try
		{
			out = new FileWriter(this.jarPath + "\\Optimization\\main\\StartOPT.bat");
			out.write("cd " + this.jarPath + "\\Optimization\\main\r\n"
					+ "OPT.exe\r\n"
					+ "exit");
			out.close();
		}
		catch (IOException ex)
		{
			Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
		}
		
		String command = "cmd /c start " + this.jarPath + "\\Optimization\\main\\StartOPT.bat";
		try
		{
			//Process child = Runtime.getRuntime().exec(command);
			Runtime.getRuntime().exec(command);
		}
		catch (IOException ex)
		{
			Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
		}
	}
}
