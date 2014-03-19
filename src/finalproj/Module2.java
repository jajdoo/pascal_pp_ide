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
import javax.swing.JTextField;

/**
 *
 *
 */
public class Module2
{
	
	private final String jarPath;
	
	public Module2(String mainPath)
	{
		this.jarPath = mainPath;
	}
	
	public void GenerateBasicBlocks(JTextField field, Component frame)
	{
		
		String projectPath = field.getText();
		int lastIndex = projectPath.lastIndexOf("\\");
		String projectName = projectPath.substring(lastIndex + 1, projectPath.length());
		
		File checkFileIr = new File(field.getText() + "\\out2.ir");
		File checkFileVCG = new File(field.getText() + "\\vcg_out2.vcg");
		boolean goFlag = true;
		if (checkFileIr.exists())
		{
			if (!checkFileIr.delete())
			{
				JOptionPane.showMessageDialog(frame, "Old basic blocks file exists at:\n"
						+ field.getText() + "\\out2.ir\n"
						+ "The program cannot delete it\n"
						+ "Please delete it manually", "Error", JOptionPane.ERROR_MESSAGE);
				goFlag = false;
			}
		}
		if (checkFileVCG.exists())
		{
			if (!checkFileVCG.delete())
			{
				JOptionPane.showMessageDialog(frame, "Old VCG file exists at:\n"
						+ field.getText() + "\\vcg_out2.vcg\n"
						+ "The program cannot delete it\n"
						+ "Please delete it manually", "Error", JOptionPane.ERROR_MESSAGE);
				goFlag = false;
			}
		}
		if (goFlag)
		{
			FileWriter out;
			try
			{
				out = new FileWriter(projectPath + "\\Module2.bat");
				out.write("cd " + this.jarPath + "\\projects\\" + projectName + "\r\n"
						+ "Module2.exe out1.txt 2> Log_Module2.txt\r\n"
						+ "exit");
				out.close();
			}
			catch (IOException ex)
			{
				Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
			}
			
			String command = "cmd /c start " + this.jarPath + "\\projects\\" + projectName + "\\Module2.bat";
			System.out.print(command);
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
	
	public void ViewBasicBlocks(String content)
	{
		DisplayOutput display = new DisplayOutput(content, "Basic Blocks");
		display.setVisible(true);
	}
}
