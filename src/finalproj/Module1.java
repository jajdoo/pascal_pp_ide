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

import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JTextPane;

/**
 * 
 * @author Max
 */
public class Module1
{
	
	private final String jarPath;
	
	public Module1(String mainPath)
	{
		this.jarPath = mainPath;
	}
	
	public void GenerateMachineCode(Component frame, JTextField compilerField, JTextField fileField, JTextPane tp, BasicClass bs, JMenuItem item1, JMenuItem item2) throws IOException
	{
		// Save current content first
		if (tp.getText().equals(""))
		{
			JOptionPane.showMessageDialog(frame, "Cannot compile an empty project");
		}
		else
		{
			if (fileField.getText().equals("No File Selected"))
			{
				while (fileField.getText().equals("No File Selected"))
				{
					bs.SaveFile(tp, frame, fileField);
				}
			}
			else
			{
				bs.SaveFileNoFileChooser(tp, frame, fileField.getText());
			}
			
			String filePath = fileField.getText();
			int lastIndex = filePath.lastIndexOf("\\");
			String fileName = filePath.substring(lastIndex + 1, filePath.length());
			
			String projectPath = compilerField.getText();
			lastIndex = projectPath.lastIndexOf("\\");
			String projectName = projectPath.substring(lastIndex + 1, projectPath.length());
			File checkIfFileExists = new File(projectPath + "\\" + fileName);
			if (checkIfFileExists.exists())
			{
				if (!filePath.equals(projectPath + "\\" + fileName))
				{
					bs.copyFile(filePath, projectPath + "\\" + "1_" + fileName);
					fileName = "1_" + fileName;
				}
			}
			else
			{
				bs.copyFile(filePath, projectPath + "\\" + fileName);
			}
			// Move all files to the same folder
			
			FileWriter out;
			try
			{
				out = new FileWriter(projectPath + "\\" + projectName + ".bat");
				out.write("cd " + this.jarPath + "\\projects\\" + projectName + "\r\n"
						+ projectName + ".exe " + fileName + " 2> Log_Module1.txt\r\n"
						+ "exit");
				out.close();
			}
			catch (IOException ex)
			{
				Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
			}
			
			String command = "cmd /c start " + this.jarPath + "\\projects\\" + projectName + "\\" + projectName + ".bat";
			try
			{
				//Process child = Runtime.getRuntime().exec(command);
				// no reason to keep that ref
				Runtime.getRuntime().exec(command);
			}
			catch (IOException ex)
			{
				Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
			}
		}
	}
	
	public void ViewMachineCode(String content)
	{
		DisplayOutput display = new DisplayOutput(content, "Machine Code");
		display.setVisible(true);
	}
	
	public void ViewSymbolTable(String content)
	{
		DisplayOutput display = new DisplayOutput(content, "Symbol Table");
		display.setVisible(true);
	}
	
	public void ViewCompilationOutput(String content)
	{
		DisplayOutput display = new DisplayOutput(content, "Compilation Output");
		display.setVisible(true);
	}
}
