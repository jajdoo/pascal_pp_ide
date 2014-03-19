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

import javax.swing.JFileChooser;
import javax.swing.JTextField;
import javax.swing.filechooser.FileNameExtensionFilter;

/**
 *
 *
 */
public class Module3
{
	
	private final String jarPath;
	
	public Module3(String mainPath)
	{
		this.jarPath = mainPath;
	}
	
	public void GenerateVCGForm(String fileName, JTextField field)
	{
		String projectPath = field.getText();
		int lastIndex = projectPath.lastIndexOf("\\");
		String projectName = projectPath.substring(lastIndex + 1, projectPath.length());
		FileWriter out;
		try
		{
			out = new FileWriter(projectPath + "\\Module3.bat");
			out.write("cd " + this.jarPath + "\\projects\\" + projectName + "\r\n"
					+ "VCG.exe " + fileName + " > Log_Module3.txt\r\n"
					+ "exit");
			out.close();
		}
		catch (IOException ex)
		{
			Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
		}
		
		String command = "cmd /c start " + this.jarPath + "\\projects\\" + projectName + "\\Module3.bat";
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
	
	public void ViewVCGForm(Component frame)
	{
		JFileChooser fileChooser = new JFileChooser();
		fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
		FileNameExtensionFilter filter = new FileNameExtensionFilter("VCG Files", "vcg");
		fileChooser.setFileFilter(filter);
		fileChooser.setAcceptAllFileFilterUsed(true);
		File dirPath;
		dirPath = new File(this.jarPath);
		fileChooser.setCurrentDirectory(dirPath);
		int returnVal = fileChooser.showDialog(frame, "Open");
		if (returnVal == JFileChooser.APPROVE_OPTION)
		{
			File selected = fileChooser.getSelectedFile();
			String filePath = selected.getAbsolutePath();
			Runtime runtime = Runtime.getRuntime();
			try
			{
				//Process process = 
				runtime.exec("C:\\Notepad++\\notepad++.exe " + filePath);
			}
			catch (IOException ex)
			{
				Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
			}
		}
	}
}
