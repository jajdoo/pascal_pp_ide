/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package finalproj;

/*
 * TextFieldDemo.java requires one additional file:
 * content.txt
 */
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.AbstractAction;
import javax.swing.ActionMap;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.ParallelGroup;
import javax.swing.GroupLayout.SequentialGroup;
import javax.swing.InputMap;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.KeyStroke;
import javax.swing.LayoutStyle;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import javax.swing.WindowConstants;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultHighlighter;
import javax.swing.text.Highlighter;

public class SearchTopic extends JFrame implements DocumentListener
{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 3653801961029503831L;
	private final String jarPath;
	private final String searchTopic;
	private JTextField entry;
	private JLabel jLabel1;
	private JScrollPane jScrollPane1;
	private JLabel status;
	private JTextArea textArea;
	final static Color HILIT_COLOR = Color.LIGHT_GRAY;
	final static Color ERROR_COLOR = Color.PINK;
	final static String CANCEL_ACTION = "cancel-search";
	final Color entryBg;
	final Highlighter hilit;
	final Highlighter.HighlightPainter painter;
	
	public SearchTopic(String mainPath, String topic)
	{
		this.jarPath = mainPath;
		this.searchTopic = topic;
		this.initComponents();
		
		InputStream in = this.getClass().getResourceAsStream(this.jarPath + "\\Help_Files\\" + topic + ".txt");
		
		this.hilit = new DefaultHighlighter();
		this.painter = new DefaultHighlighter.DefaultHighlightPainter(SearchTopic.HILIT_COLOR);
		this.textArea.setHighlighter(this.hilit);
		
		this.entryBg = this.entry.getBackground();
		this.entry.getDocument().addDocumentListener(this);
		
		InputMap im = this.entry.getInputMap(JComponent.WHEN_IN_FOCUSED_WINDOW);
		ActionMap am = this.entry.getActionMap();
		im.put(KeyStroke.getKeyStroke("ESCAPE"), SearchTopic.CANCEL_ACTION);
		am.put(SearchTopic.CANCEL_ACTION, new CancelAction());
	}
	
	/**
	 * This method is called from within the constructor to initialize the form.
	 */
	private void initComponents()
	{
		this.entry = new JTextField();
		this.textArea = new JTextArea();
		this.status = new JLabel();
		this.jLabel1 = new JLabel();
		JButton searchButton = new JButton("Search");
		JButton cancelButton = new JButton("Cancel");
		
		this.setTitle("Help Menu");
		
		this.textArea.setColumns(20);
		this.textArea.setLineWrap(true);
		this.textArea.setRows(5);
		this.textArea.setWrapStyleWord(true);
		this.textArea.setEditable(false);
		String fileContent;
		try
		{
			fileContent = this.readFileAsString(this.jarPath + "\\Help_Files\\" + this.searchTopic + ".txt");
			this.textArea.setText(fileContent);
		}
		catch (IOException ex)
		{
			Logger.getLogger(SearchTopic.class.getName()).log(Level.SEVERE, null, ex);
		}
		this.jScrollPane1 = new JScrollPane(this.textArea);
		this.jScrollPane1.setWheelScrollingEnabled(true);
		
		this.jLabel1.setText("Enter text to search:");
		
		GroupLayout layout = new GroupLayout(this.getContentPane());
		this.getContentPane().setLayout(layout);
		
		//Create a parallel group for the horizontal axis
		ParallelGroup hGroup = layout.createParallelGroup(GroupLayout.Alignment.LEADING);
		
		//Create a sequential and a parallel groups
		SequentialGroup h1 = layout.createSequentialGroup();
		ParallelGroup h2 = layout.createParallelGroup(GroupLayout.Alignment.TRAILING);
		SequentialGroup a1 = layout.createSequentialGroup();
		//Add a container gap to the sequential group h1
		h1.addContainerGap();
		
		//Add a scroll pane and a label to the parallel group h2
		h2.addComponent(this.jScrollPane1, GroupLayout.Alignment.LEADING, GroupLayout.DEFAULT_SIZE, 450, Short.MAX_VALUE);
		h2.addComponent(this.status, GroupLayout.Alignment.LEADING, GroupLayout.DEFAULT_SIZE, 450, Short.MAX_VALUE);
		
		//Create a sequential group h3
		SequentialGroup h3 = layout.createSequentialGroup();
		h3.addComponent(this.jLabel1);
		h3.addPreferredGap(LayoutStyle.ComponentPlacement.RELATED);
		h3.addComponent(this.entry, GroupLayout.DEFAULT_SIZE, 321, Short.MAX_VALUE);
		
		SequentialGroup h4 = layout.createSequentialGroup();
		
		//Add the group h3 to the group h2
		h2.addGroup(h3);
		//Add the group h2 to the group h1
		h1.addGroup(h2);
		
		h1.addContainerGap();
		
		//Add the group h1 to the hGroup
		hGroup.addGroup(GroupLayout.Alignment.TRAILING, h1);
		//Create the horizontal group
		layout.setHorizontalGroup(hGroup);
		
		//Create a parallel group for the vertical axis
		ParallelGroup vGroup = layout.createParallelGroup(GroupLayout.Alignment.LEADING);
		//Create a sequential group v1
		SequentialGroup v1 = layout.createSequentialGroup();
		//Add a container gap to the sequential group v1
		v1.addContainerGap();
		//Create a parallel group v2
		ParallelGroup v2 = layout.createParallelGroup(GroupLayout.Alignment.BASELINE);
		v2.addComponent(this.jLabel1);
		v2.addComponent(this.entry, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE);
		//Add the group v2 tp the group v1
		v1.addGroup(v2);
		v1.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED);
		v1.addComponent(this.jScrollPane1, GroupLayout.DEFAULT_SIZE, 233, Short.MAX_VALUE);
		v1.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED);
		v1.addComponent(this.status);
		v1.addContainerGap();
		
		//Add the group v1 to the group vGroup
		vGroup.addGroup(v1);
		//Create the vertical group
		layout.setVerticalGroup(vGroup);
		this.pack();
		this.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		
		this.setVisible(true);
	}
	
	public void search()
	{
		this.hilit.removeAllHighlights();
		
		String s = this.entry.getText();
		if (s.length() <= 0)
		{
			this.message("Nothing to search");
			return;
		}
		
		String content = this.textArea.getText();
		int index = content.indexOf(s, 0);
		if (index >= 0)
		{ // match found
		
			int end = index + s.length();
			try
			{
				this.hilit.addHighlight(index, end, this.painter);
			}
			catch (BadLocationException ex)
			{
				Logger.getLogger(SearchTopic.class.getName()).log(Level.SEVERE, null, ex);
			}
			this.textArea.setCaretPosition(end);
			this.entry.setBackground(this.entryBg);
			this.message("'" + s + "' found. Press ESC to end search");
			
		}
		else
		{
			this.entry.setBackground(SearchTopic.ERROR_COLOR);
			this.message("'" + s + "' not found. Press ESC to start a new search");
		}
	}
	
	void message(String msg)
	{
		this.status.setText(msg);
	}
	
	// DocumentListener methods
	@Override
	public void insertUpdate(DocumentEvent ev)
	{
		this.search();
	}
	
	@Override
	public void removeUpdate(DocumentEvent ev)
	{
		this.search();
	}
	
	@Override
	public void changedUpdate(DocumentEvent ev)
	{
	}
	
	class CancelAction extends AbstractAction
	{
		
		/**
		 * 
		 */
		private static final long serialVersionUID = 2809293646734491531L;
		
		@Override
		public void actionPerformed(ActionEvent ev)
		{
			SearchTopic.this.hilit.removeAllHighlights();
			SearchTopic.this.entry.setText("");
			SearchTopic.this.entry.setBackground(SearchTopic.this.entryBg);
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
	
	public static void main(String args[])
	{
		//Schedule a job for the event dispatch thread:
		//creating and showing this application's GUI.
		SwingUtilities.invokeLater(new Runnable()
		{
			@Override
			public void run()
			{
				//Turn off metal's use of bold fonts
				UIManager.put("swing.boldMetal", Boolean.FALSE);
				new SearchTopic("", "").setVisible(true);
			}
		});
	}
}
