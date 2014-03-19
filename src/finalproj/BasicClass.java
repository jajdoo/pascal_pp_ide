/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package finalproj;

import java.awt.Component;
import java.awt.Container;
import java.awt.image.ImageObserver;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JFileChooser;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JTextPane;
import javax.swing.filechooser.FileNameExtensionFilter;

/**
 * 
 * @author Max
 */
public class BasicClass
{
	
	private final String jarPath;
	
	public BasicClass(String mainPath)
	{
		this.jarPath = mainPath;
	}
	
	public void OpenFile(JTextPane tp, Component frame, JTextField field)
	{
		try
		{
			JFileChooser fileChooser = new JFileChooser();
			fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
			FileNameExtensionFilter filter = new FileNameExtensionFilter("Pascal File", "p");
			fileChooser.setFileFilter(filter);
			File dirPath = new File(this.jarPath + "\\Code_Files");
			fileChooser.setCurrentDirectory(dirPath);
			int returnVal = fileChooser.showOpenDialog(frame);
			if (returnVal == JFileChooser.APPROVE_OPTION)
			{
				File selected = fileChooser.getSelectedFile();
				String filePath = selected.getAbsolutePath();
				//String fileName = selected.getName();
				String fileContent = this.readFileAsString(filePath);
				String adjustString = fileContent.replaceAll("\r\n", "\n");
				tp.setText("");
				tp.setText(adjustString);
				//field.setText(fileName);
				field.setText(filePath);
			}
		}
		catch (IOException ex)
		{
			Logger.getLogger(BasicClass.class.getName()).log(Level.SEVERE, null, ex);
		}
	}
	
	public void SaveFile(JTextPane tp, Component frame, JTextField field) throws IOException
	{
		
		JFileChooser fileChooser = new JFileChooser();
		fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
		//FileNameExtensionFilter filter = new FileNameExtensionFilter("Text", "txt");
		//fileChooser.setFileFilter(filter);
		File dirPath = new File(this.jarPath + "\\Code_Files");
		fileChooser.setCurrentDirectory(dirPath);
		int returnVal = fileChooser.showSaveDialog(frame);
		if (returnVal == JFileChooser.APPROVE_OPTION)
		{
			File selected = fileChooser.getSelectedFile();
			String filePath = selected.getAbsolutePath();
			String checkExtension = filePath.substring(filePath.length() - 2);
			String fileNoExtension = filePath;
			if (checkExtension.equals(".p"))
			{
				fileNoExtension = filePath.substring(0, filePath.length() - 2);
			}
			File FileCheck = new File(filePath);
			FileWriter out;
			if (FileCheck.exists())
			{
				int selection = JOptionPane.showConfirmDialog(frame, "Overwrite " + FileCheck.getName() + "?", "File already exist", JOptionPane.OK_CANCEL_OPTION);
				if (selection == 0)
				{
					out = new FileWriter(fileNoExtension + ".p");
					field.setText(fileNoExtension + ".p");
					out.write(tp.getText().replaceAll("\n", "\r\n"));
					out.close();
				}
			}
			else
			{
				out = new FileWriter(fileNoExtension + ".p");
				field.setText(fileNoExtension + ".p");
				out.write(tp.getText().replaceAll("\n", "\r\n"));
				out.close();
			}
		}
	}
	
	private String readFileAsString(String filePath) throws IOException
	{
		StringBuilder fileData = new StringBuilder();
		try (BufferedReader reader = new BufferedReader(
				new FileReader(filePath)))
		{
			char[] buf = new char[8192];
			int numRead;
			while ((numRead = reader.read(buf)) != -1)
			{
				String readData = String.valueOf(buf, 0, numRead);
				fileData.append(readData);
			}
		}
		return fileData.toString();
	}
	
	public void SaveFileNoFileChooser(JTextPane tp, Component frame, String fullFilePath) throws IOException
	{
		
		FileWriter out;
		out = new FileWriter(fullFilePath);
		out.write(tp.getText().replaceAll("\n", "\r\n"));
		out.close();
	}
	
	public void CreateNewFile(JTextPane tp, JTextField field)
	{
		tp.setText("");
		field.setText("No File Selected");
	}
	
	public void OpenFileTree(JTextPane tp, Component frame, JTextField field, String filePath)
	{
		String fileContent;
		try
		{
			fileContent = this.readFileAsString(filePath);
			String adjustString = fileContent.replaceAll("\r\n", "\n");
			tp.setText("");
			tp.setText(adjustString);
			field.setText(filePath);
		}
		catch (IOException ex)
		{
			Logger.getLogger(BasicClass.class.getName()).log(Level.SEVERE, null, ex);
		}
	}
	
	public void SaveBeforeOpenFile(JTextPane tp, Component frame, JTextField field) throws IOException
	{
		JFileChooser fileChooser = new JFileChooser();
		fileChooser.setFileSelectionMode(JFileChooser.FILES_ONLY);
		File dirPath = new File(this.jarPath + "\\Code_Files");
		fileChooser.setCurrentDirectory(dirPath);
		int returnVal = fileChooser.showSaveDialog(frame);
		if (returnVal == JFileChooser.APPROVE_OPTION)
		{
			File selected = fileChooser.getSelectedFile();
			String filePath = selected.getAbsolutePath();
			String checkExtension = filePath.substring(filePath.length() - 2);
			String fileNoExtension = filePath;
			if (checkExtension.equals(".p"))
			{
				fileNoExtension = filePath.substring(0, filePath.length() - 2);
			}
			File FileCheck = new File(filePath);
			FileWriter out;
			if (FileCheck.exists())
			{
				int selection = JOptionPane.showConfirmDialog(frame, "Overwrite " + FileCheck.getName() + "?", "File already exist", JOptionPane.OK_CANCEL_OPTION);
				if (selection == 0)
				{
					out = new FileWriter(fileNoExtension + ".p");
					field.setText("No File Selected");
					out.write(tp.getText().replaceAll("\n", "\r\n"));
					out.close();
				}
			}
			else
			{
				out = new FileWriter(fileNoExtension + ".p");
				field.setText("No File Selected");
				out.write(tp.getText().replaceAll("\n", "\r\n"));
				out.close();
			}
		}
	}
	
	public void createProject(JTextField field, Component frame)
	{
		String projectName = JOptionPane.showInputDialog("Enter Project Name:");
		if (projectName != null)
		{
			String projectPath = this.jarPath + "\\projects\\" + projectName;
			File dirPath = new File(projectPath);
			while ((dirPath.exists() || projectName.equals("")) && projectName != null)
			{
				projectName = JOptionPane.showInputDialog("Project under the same name allready exist\n"
						+ "Please Enter another project Name:");
				if (projectName != null)
				{
					projectPath = this.jarPath + "\\projects\\" + projectName;
					dirPath = new File(projectPath);
				}
			}
			if (projectName != null)
			{
				if (!dirPath.mkdir())
				{
					JOptionPane.showMessageDialog(frame, "Cannot create project", "Unable to create new project!", JOptionPane.ERROR_MESSAGE);
				}
				field.setText(projectPath);
				try
				{
					this.copyFile(this.jarPath + "\\Language_Editor\\flex.exe", projectPath + "\\flex.exe");
					this.copyFile(this.jarPath + "\\Language_Editor\\BISON.EXE", projectPath + "\\BISON.exe");
					this.copyFile(this.jarPath + "\\Language_Editor\\bison.simple", projectPath + "\\bison.simple");
					this.copyFile(this.jarPath + "\\Language_Editor\\flexFile.l", projectPath + "\\flexFile.l");
					this.copyFile(this.jarPath + "\\Language_Editor\\BISON_file.y", projectPath + "\\BISON_file.y");
					this.copyFile(this.jarPath + "\\Language_Editor\\Module2.exe", projectPath + "\\Module2.exe");
					this.copyFile(this.jarPath + "\\Language_Editor\\VCG.exe", projectPath + "\\VCG.exe");
					this.copyFile(this.jarPath + "\\Language_Editor\\main.c", projectPath + "\\main.c");
					this.copyFile(this.jarPath + "\\Language_Editor\\convertTree.c", projectPath + "\\convertTree.c");
					this.copyFile(this.jarPath + "\\Language_Editor\\convertTree.h", projectPath + "\\convertTree.h");
					this.copyFile(this.jarPath + "\\Language_Editor\\global.h", projectPath + "\\global.h");
					this.copyFile(this.jarPath + "\\Language_Editor\\typedef.h", projectPath + "\\typedef.h");
					this.copyFile(this.jarPath + "\\DDG\\DDG.exe", projectPath + "\\DDG.exe");
				}
				catch (IOException ex)
				{
					Logger.getLogger(BasicClass.class.getName()).log(Level.SEVERE, null, ex);
				}
			}
		}
	}
	
	public void openProject(JTextField field, Component frame, JMenuItem item)
	{
		JFileChooser fileChooser = new JFileChooser();
		this.disableTextField(fileChooser);
		fileChooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
		File projectsPath = new File(this.jarPath + "\\projects");
		fileChooser.setCurrentDirectory(projectsPath);
		int returnVal = fileChooser.showDialog(frame, "Select");
		if (returnVal == JFileChooser.APPROVE_OPTION)
		{
			File selected = fileChooser.getSelectedFile();
			String dirPath = selected.getAbsolutePath();
			field.setText(dirPath);
			int lastIndex = field.getText().lastIndexOf("\\");
			String projectName = field.getText().substring(lastIndex + 1, field.getText().length());
			File checkCompilerInProject = new File(dirPath + "\\" + projectName + ".exe");
			if (checkCompilerInProject.exists() || dirPath.equals(this.jarPath + "\\projects\\Pascal++"))
			{
				item.setEnabled(true);
			}
			else
			{
				item.setEnabled(false);
			}
		}
	}
	
	public boolean disableTextField(Container c)
	{
		Component[] cmps = c.getComponents();
		for ( Component cmp : cmps )
		{
			if (cmp instanceof JTextField)
			{
				((JTextField) cmp).setEnabled(false);
				return true;
			}
			if (cmp instanceof Container)
			{
				if (this.disableTextField((Container) cmp))
				{
					return true;
				}
			}
		}
		return false;
	}
	
	public void copyFile(String sourcePath, String destPath) throws IOException
	{
		File source = new File(sourcePath);
		File dest = new File(destPath);
		InputStream input = null;
		OutputStream output = null;
		try
		{
			input = new FileInputStream(source);
			output = new FileOutputStream(dest);
			byte[] buf = new byte[4096];
			int bytesRead;
			while ((bytesRead = input.read(buf)) > 0)
			{
				output.write(buf, 0, bytesRead);
			}
		}
		finally
		{
			input.close();
			output.close();
		}
	}
	
	public void deleteDir(JTextField field, Component frame)
	{
		{
			if (field.getText().equals("No Project Selected"))
			{
				JOptionPane.showMessageDialog(frame, "No project are currently in use");
			}
			else
			{
				File directory = new File(field.getText());
				//make sure directory exists
				if (!directory.exists())
				{
					JOptionPane.showMessageDialog(frame, "Cannot find directory", "Error", ImageObserver.ERROR);
				}
				else
				{
					try
					{
						BasicClass.delete(directory);
					}
					catch (IOException ex)
					{
						Logger.getLogger(BasicClass.class.getName()).log(Level.SEVERE, null, ex);
					}
				}
			}
			field.setText("No Project Selected");
		}
	}
	
	public static void delete(File file) throws IOException
	{
		if (file.isDirectory())
		{
			//directory is empty, then delete it
			if (file.list().length == 0)
			{
				file.delete();
				System.out.println("Directory is deleted : "
						+ file.getAbsolutePath());
			}
			else
			{
				//list all the directory contents
				String files[] = file.list();
				for ( String temp : files )
				{
					//construct the file structure
					File fileDelete = new File(file, temp);
					//recursive delete
					BasicClass.delete(fileDelete);
				}
				//check the directory again, if empty then delete it
				if (file.list().length == 0)
				{
					file.delete();
					System.out.println("Directory is deleted : "
							+ file.getAbsolutePath());
				}
			}
		}
		else
		{
			//if file, then delete it
			file.delete();
			System.out.println("File is deleted : " + file.getAbsolutePath());
		}
	}
	
	public int checkDeleteFile(File file)
	{
		if (file.exists())
		{
			if (file.delete())
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 2;
		}
	}
	
	public String readFromFile(String path) throws FileNotFoundException, IOException
	{
		try (BufferedReader br = new BufferedReader(new FileReader(path)))
		{
			StringBuilder sb = new StringBuilder();
			String line = br.readLine();
			while (line != null)
			{
				sb.append(line);
				sb.append("\n");
				line = br.readLine();
			}
			return sb.toString();
		}
	}
	
	public String deleteFile(Component frame, JTextField field)
	{
		int selection = JOptionPane.showConfirmDialog(frame, "Are you sure you want to permenantly delete:\n" + field.getText(), "Delete File", JOptionPane.OK_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE);
		File deleteFile = new File(field.getText());
		if (selection == 0)
		{
			if (!deleteFile.exists())
			{
				return "NotExist";
			}
			else
			{
				if (deleteFile.delete())
				{
					return "Deleted";
				}
				else
				{
					return "NotDeleted";
				}
			}
		}
		else
		{
			return "DontDelete";
		}
	}
}
