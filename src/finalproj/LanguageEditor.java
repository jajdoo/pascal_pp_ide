/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package finalproj;

import java.awt.Component;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.filechooser.FileNameExtensionFilter;

/**
 *
 *
 */
public class LanguageEditor
{
	
	private final LinkedList<String> currentLanguage;
	private final String jarPath;
	
	@SuppressWarnings({"unchecked", "rawtypes"})
	public LanguageEditor(String pathToFile, String mainPath)
	{
		this.jarPath = mainPath;
		this.currentLanguage = new LinkedList();
		this.ReadFromFile(pathToFile);
	}
	
	public boolean IsKnownWords(String StringToCheck)
	{
		if (this.currentLanguage.contains(StringToCheck))
		{
			return true;
		}
		return false;
	}
	
	public LinkedList<String> getLanguage()
	{
		return this.currentLanguage;
	}
	
	private void ReadFromFile(String pathToFile)
	{
		File LanguageFile = new File(pathToFile); // to add the right path
		BufferedReader reader = null;
		String text = null;
		try
		{
			reader = new BufferedReader(new FileReader(LanguageFile));
		}
		catch (FileNotFoundException ex)
		{
			Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
		}
		try
		{
			text = reader.readLine();
		}
		catch (IOException ex)
		{
			Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
		}
		while (text != null)
		{
			this.currentLanguage.add(text);
			try
			{
				text = reader.readLine();
			}
			catch (IOException ex)
			{
				Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
			}
		}
		this.currentLanguage.add("(");
		this.currentLanguage.add(")");
		this.currentLanguage.add("{");
		this.currentLanguage.add("}");
		this.currentLanguage.add("[");
		this.currentLanguage.add("]");
	}
	
	@SuppressWarnings("resource")
	public boolean ReadLanguage(String pathToProject)
	{
		File LanguageFile = new File(pathToProject + "\\flexFile.l"); // to add the right path
		String newLanguage = "";
		BufferedReader reader = null;
		String text = null;
		try
		{
			reader = new BufferedReader(new FileReader(LanguageFile));
		}
		catch (FileNotFoundException ex)
		{
			Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
		}
		try
		{
			text = reader.readLine();
		}
		catch (IOException ex)
		{
			Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
		}
		while (!"%%".equals(text))
		{
			try
			{
				text = reader.readLine();
			}
			catch (IOException ex)
			{
				Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
			}
		}
		try
		{
			text = reader.readLine();
			text = reader.readLine();
		}
		catch (IOException ex)
		{
			Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
		}
		while (!"".equals(text))
		{
			try
			{
				String[] devide = text.split(" ");
				newLanguage = newLanguage + devide[0] + "\r\n";
				text = reader.readLine();
			}
			catch (IOException ex)
			{
				Logger.getLogger(LanguageEditor.class.getName()).log(Level.SEVERE, null, ex);
			}
		}
		
		FileWriter out;
		try
		{
			out = new FileWriter(pathToProject + "\\languageFile.txt");
			out.write(newLanguage);
			out.close();
		}
		catch (IOException ex)
		{
			Logger.getLogger(LanguageEditor.class
					.getName()).log(Level.SEVERE, null, ex);
		}
		
		File checkFile = new File(pathToProject + "\\languageFile.txt");
		if (checkFile.exists())
		{
			this.currentLanguage.clear();
			this.ReadFromFile(pathToProject + "\\languageFile.txt");
			return true;
		}
		else
		{
			return false;
		}
	}
	
	public void ClearLanguage()
	{
		this.currentLanguage.clear();
	}
	
	public void EditFlexFile(Component frame, JTextField field)
	{
		JOptionPane.showMessageDialog(frame, "1. Create a language file in the notepad editor.\n"
				+ "2. Save the file by choosing File->Save As->All Types->nameOfFile.l");
		
		JFileChooser fileChooser = new JFileChooser();
		fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
		FileNameExtensionFilter filter = new FileNameExtensionFilter("Flex Files", "l");
		fileChooser.setFileFilter(filter);
		fileChooser.setAcceptAllFileFilterUsed(true);
		File dirPath;
		if (field.getText().equals("No Project Selected"))
		{
			dirPath = new File(this.jarPath);
		}
		else
		{
			dirPath = new File(field.getText());
		}
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
				Logger.getLogger(PascalPlusPlus.class
						.getName()).log(Level.SEVERE, null, ex);
			}
		}
	}
	
	public void EditBisonFile(Component frame, JTextField field)
	{
		JOptionPane.showMessageDialog(frame, "1. Create a language file in the notepad editor.\n"
				+ "2. Save the file by choosing File->Save As->All Types->nameOfFile.y");
		
		JFileChooser fileChooser = new JFileChooser();
		fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
		FileNameExtensionFilter filter = new FileNameExtensionFilter("BISON Files", "y");
		fileChooser.setFileFilter(filter);
		fileChooser.setAcceptAllFileFilterUsed(true);
		File dirPath;
		if (field.getText().equals("No Project Selected"))
		{
			dirPath = new File(this.jarPath);
		}
		else
		{
			dirPath = new File(field.getText());
		}
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
				Logger.getLogger(PascalPlusPlus.class
						.getName()).log(Level.SEVERE, null, ex);
			}
		}
	}
	
	public void UseFlex(Component frame, JTextField field, BasicClass bc)
	{
		JOptionPane.showMessageDialog(frame, "Please choose '.l' file to create the Lexical Analyzer");
		JFileChooser fileChooser = new JFileChooser();
		fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
		FileNameExtensionFilter filter = new FileNameExtensionFilter("Flex Files", "l");
		fileChooser.setFileFilter(filter);
		fileChooser.setAcceptAllFileFilterUsed(false);
		int lastIndex = field.getText().lastIndexOf("\\");
		String projectName = field.getText().substring(lastIndex + 1, field.getText().length());
		File dirPath = new File(this.jarPath + "\\projects\\" + projectName);
		fileChooser.setCurrentDirectory(dirPath);
		int returnVal = fileChooser.showDialog(frame, "Select");
		if (returnVal == JFileChooser.APPROVE_OPTION)
		{
			// Create compFlex.bat
			File selected = fileChooser.getSelectedFile();
			String filePath = selected.getAbsolutePath();
			String path = this.jarPath + "\\projects\\" + projectName + "\\compFlex.bat";
			FileWriter out;
			try
			{
				out = new FileWriter(path);
				out.write("cd ..\r\n"
						+ "cd ..\r\n"
						+ "cd " + field.getText() + "\r\n"
						+ "flex " + filePath + " 2> createFlex.txt\r\n"
						+ "exit");
				out.close();
			}
			catch (IOException ex)
			{
				Logger.getLogger(LanguageEditor.class
						.getName()).log(Level.SEVERE, null, ex);
			}
			
			String command = "cmd /c start " + this.jarPath + "\\projects\\" + projectName + "\\compFlex.bat";
			
			try
			{
				//Process child = 
				Runtime.getRuntime().exec(command);
			}
			catch (IOException ex)
			{
				Logger.getLogger(PascalPlusPlus.class
						.getName()).log(Level.SEVERE, null, ex);
			}
			try
			{
				String content = bc.readFromFile(this.jarPath + "\\projects\\" + projectName + "\\createFlex.txt");
				if (!content.equals(""))
				{
					JOptionPane.showMessageDialog(frame, "Flex Error, Please check log file in:\n"
							+ this.jarPath + "\\projects\\" + projectName + "\\createFlex.txt");
				}
			}
			catch (FileNotFoundException ex)
			{
				Logger.getLogger(LanguageEditor.class
						.getName()).log(Level.SEVERE, null, ex);
			}
			catch (IOException ex)
			{
				Logger.getLogger(LanguageEditor.class
						.getName()).log(Level.SEVERE, null, ex);
			}
		}
	}
	
	public void UseBison(Component frame, JTextField field, BasicClass bc)
	{
		JOptionPane.showMessageDialog(frame, "Please choose '.y' file to create the Syntax Analyzer");
		JFileChooser fileChooser = new JFileChooser();
		fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
		FileNameExtensionFilter filter = new FileNameExtensionFilter("BISON Files", "y");
		fileChooser.setFileFilter(filter);
		fileChooser.setAcceptAllFileFilterUsed(false);
		int lastIndex = field.getText().lastIndexOf("\\");
		String projectName = field.getText().substring(lastIndex + 1, field.getText().length());
		File dirPath = new File(this.jarPath + "\\projects\\" + projectName);
		fileChooser.setCurrentDirectory(dirPath);
		int returnVal = fileChooser.showDialog(frame, "Select");
		File selected = fileChooser.getSelectedFile();
		
		if (returnVal == JFileChooser.APPROVE_OPTION)
		{
			// Create compFlex.bat
			String filePath = selected.getAbsolutePath();
			
			// this one is never used?
			//String fileName = selected.getName().replace(".y", "");
			String path = this.jarPath + "\\projects\\" + projectName + "\\compBISON.bat";
			FileWriter out;
			try
			{
				out = new FileWriter(path);
				out.write("cd ..\r\n"
						+ "cd ..\r\n"
						+ "cd " + field.getText() + "\r\n"
						+ "bison -d " + filePath + " 2> createBISON.txt\r\n"
						+ "exit");
				out.close();
			}
			catch (IOException ex)
			{
				Logger.getLogger(LanguageEditor.class
						.getName()).log(Level.SEVERE, null, ex);
			}
			String command = "cmd /c start " + this.jarPath + "\\projects\\" + projectName + "\\compBISON.bat";
			
			try
			{
				//Process child = 
				Runtime.getRuntime().exec(command);
			}
			catch (IOException ex)
			{
				Logger.getLogger(PascalPlusPlus.class
						.getName()).log(Level.SEVERE, null, ex);
			}
			
			try
			{
				String content = bc.readFromFile(this.jarPath + "\\projects\\" + projectName + "\\createBISON.txt");
				if (!content.equals(""))
				{
					JOptionPane.showMessageDialog(frame, "BISON Error, Please check log file in:\n"
							+ this.jarPath + "\\projects\\" + projectName + "\\createBISON.txt");
				}
			}
			catch (FileNotFoundException ex)
			{
				Logger.getLogger(LanguageEditor.class
						.getName()).log(Level.SEVERE, null, ex);
			}
			catch (IOException ex)
			{
				Logger.getLogger(LanguageEditor.class
						.getName()).log(Level.SEVERE, null, ex);
			}
		}
	}
	
	public boolean CreateCompiler(Component frame, JTextField field, BasicClass bc)
	{
		JOptionPane.showMessageDialog(frame, "Please choose all the '.c' files were required for creating the compiler");
		JFileChooser fileChooser = new JFileChooser();
		fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
		fileChooser.setMultiSelectionEnabled(true);
		FileNameExtensionFilter filter = new FileNameExtensionFilter("C Files", "c");
		fileChooser.setFileFilter(filter);
		fileChooser.setAcceptAllFileFilterUsed(false);
		int lastIndex = field.getText().lastIndexOf("\\");
		String projectName = field.getText().substring(lastIndex + 1, field.getText().length());
		File dirPath = new File(this.jarPath + "\\projects\\" + projectName);
		fileChooser.setCurrentDirectory(dirPath);
		int returnVal = fileChooser.showDialog(frame, "Select");
		if (returnVal == JFileChooser.APPROVE_OPTION)
		{
			// Create compFlex.bat
			// File selected = fileChooser.getSelectedFile();
			File checkExist = new File(this.jarPath + "\\projects\\" + projectName + "\\" + projectName + ".exe");
			if (checkExist.exists())
			{
				checkExist.delete();
			}
			File[] files = fileChooser.getSelectedFiles();
			String allFilePath = "";
			int counter = 0;
			while (counter < files.length)
			{
				allFilePath = allFilePath + " " + files[counter].getAbsolutePath();
				counter++;
			}
			System.out.println(allFilePath);
			System.out.println("Number Of Files: " + files.length);
			System.out.println("Counter: " + counter);
			String path = this.jarPath + "\\projects\\" + projectName + "\\CreateCompiler.bat";
			FileWriter out;
			try
			{
				out = new FileWriter(path);
				out.write("cd ..\r\n"
						+ "cd ..\r\n"
						+ "cd " + field.getText() + "\r\n"
						+ "gcc" + allFilePath + " -o " + projectName + ".exe 2> createComp.txt\r\n"
						+ "exit");
				/*   out.write("cd ..\r\n"
				           + "cd ..\r\n"
				           + "cd " + field.getText() + "\r\n"
				           + "cc" + allFilePath + " -o " + projectName + ".exe 2> createComp.txt\r\n"
				           + "exit");*/
				out.close();
			}
			catch (IOException ex)
			{
				Logger.getLogger(LanguageEditor.class
						.getName()).log(Level.SEVERE, null, ex);
			}
			String command = "cmd /c start " + this.jarPath + "\\projects\\" + projectName + "\\CreateCompiler.bat";
			
			try
			{
				//Process child = 
				Runtime.getRuntime().exec(command);
			}
			catch (IOException ex)
			{
				Logger.getLogger(PascalPlusPlus.class
						.getName()).log(Level.SEVERE, null, ex);
			}
			try
			{
				Thread.sleep(5000);
			}
			catch (InterruptedException ex)
			{
				Logger.getLogger(LanguageEditor.class
						.getName()).log(Level.SEVERE, null, ex);
			}
			
			File checkExistNew = new File(this.jarPath + "\\projects\\" + projectName + "\\" + projectName + ".exe");
			if (!checkExistNew.exists())
			{
				JOptionPane.showMessageDialog(frame, "Compailer could not be created!", "Failure", JOptionPane.ERROR_MESSAGE);
				String content;
				try
				{
					content = bc.readFromFile(this.jarPath + "\\projects\\" + projectName + "\\createComp.txt");
					DisplayOutput display = new DisplayOutput(content, "Flex & BISON Compilation Output");
					display.setVisible(true);
				}
				catch (FileNotFoundException ex)
				{
					Logger.getLogger(LanguageEditor.class
							.getName()).log(Level.SEVERE, null, ex);
				}
				catch (IOException ex)
				{
					Logger.getLogger(LanguageEditor.class
							.getName()).log(Level.SEVERE, null, ex);
				}
				return false;
			}
			else
			{
				JOptionPane.showMessageDialog(frame, "Compailer was successfully created!", "Success", JOptionPane.INFORMATION_MESSAGE);
				return true;
			}
		}
		return false;
	}
}
