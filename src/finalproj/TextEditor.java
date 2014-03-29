/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package finalproj;

import java.awt.Color;
import java.awt.Font;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JTextField;
import javax.swing.JTextPane;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultEditorKit;
import javax.swing.text.DefaultHighlighter;
import javax.swing.text.Highlighter;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyleContext;

/**
 * 
 * @author Max
 */
public class TextEditor
{
	
	//private String jarPath;
	private int regBrackets;
	private int roundBrackets;
	private int squareBrackets;
	final static Color HILIT_COLOR = Color.LIGHT_GRAY;
	final static Color ERROR_COLOR = Color.PINK;
	final static String CANCEL_ACTION = "cancel-search";
	final Color entryBg;
	final Highlighter hilit;
	final Highlighter.HighlightPainter painter;
	int numOfLines;
	
	public TextEditor(String mainPath)
	{
		//this.jarPath = mainPath;
		this.regBrackets = 0;
		this.roundBrackets = 0;
		this.squareBrackets = 0;
		this.numOfLines = 0;
		this.entryBg = null;
		this.hilit = new DefaultHighlighter();
		this.painter = new DefaultHighlighter.DefaultHighlightPainter(TextEditor.HILIT_COLOR);
	}
	
	public void CheckCode(JTextPane tp, LanguageEditor languageEditor)
	{
		this.regBrackets = 0;
		this.roundBrackets = 0;
		this.squareBrackets = 0;
		int NewLineCounter = 0;
		try
		{
			if (tp.getDocument().getLength() > 0)
			{
				if (tp.getDocument().getText((tp.getDocument().getLength()) - 1, 1).equals("\n"))
				{
					NewLineCounter = 1;
					while (tp.getDocument().getText((tp.getDocument().getLength()) - NewLineCounter, 1).equals("\n"))
					{
						NewLineCounter++;
					}
					NewLineCounter--;
				}
				this.numOfLines = NewLineCounter;
			}
		}
		catch (BadLocationException ex)
		{
			Logger.getLogger(TextEditor.class.getName()).log(Level.SEVERE, null, ex);
		}
		tp.getDocument().putProperty(DefaultEditorKit.EndOfLineStringProperty, "\n");
		String[] lines = tp.getText().split("\n");
		//   tp.setText("");
		int currLine = 0;
		String[] getLine;
		
		while (currLine < lines.length)
		{
			int lineLenght = 0;
			getLine = lines[currLine].split(" ");
			int currWord = 0;
			while (currWord < getLine.length)
			{
				if ("".equals(getLine[currWord]) && (getLine.length > 1))
				{
					//   try {
					//   this.appendWordToPane(tp, " ", Color.black, false, true);
					lineLenght++;
					//   } catch (BadLocationException ex) {
					//      Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
					//   }
				}
				else
				{
					if (languageEditor.IsKnownWords(getLine[currWord]))
					{
						this.UpdateBracketsCount(getLine[currWord]);
						//    try {
						//         this.appendWordToPane(tp, getLine[currWord], Color.black, false, false);
						lineLenght = lineLenght + getLine[currWord].length();
						if (currWord < (getLine.length - 1))
						{
							//           this.appendWordToPane(tp, " ", Color.black, false, true);
							lineLenght++;
						}
						//    } catch (BadLocationException ex) {
						//        Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
						//    }
					}
					else
					{
						this.UpdateBracketsCount(getLine[currWord]);
						//   try {
						//     this.appendWordToPane(tp, getLine[currWord], Color.black, false, false);
						lineLenght = lineLenght + getLine[currWord].length();
						if (currWord < (getLine.length - 1))
						{
							//       this.appendWordToPane(tp, " ", Color.black, false, true);
							lineLenght++;
						}
						// } catch (BadLocationException ex) {
						//     Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
						// }
					}
				}
				currWord++;
			}
			
			while (lines[currLine].length() > lineLenght)
			{
				//   try {
				//      this.appendWordToPane(tp, " ", Color.black, false, true);
				//  } catch (BadLocationException ex) {
				//     Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
				//  }
				lineLenght++;
			}
			/*    char[] characters = lines[currLine].toCharArray();
			 for (char c : characters) {
			 System.out.printf("%d ", (int) c);
			 }

			 System.out.println();*/
			
			//  try {
			//    if (currLine < (lines.length - 1)) {
			//       this.appendWordToPane(tp, "\n", Color.black, false, false);
			//    }
			//  } catch (BadLocationException ex) {
			//     Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
			//  }
			currLine++;
		}
		
		while (NewLineCounter > 0)
		{
			//    try {
			//       this.appendWordToPane(tp, "\n", Color.black, false, false);
			//   } catch (BadLocationException ex) {
			//      Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
			//  }
			NewLineCounter--;
		}
	}
	
	/*char[] characters = fullText[k].toCharArray();
	 for (char c : characters) {
	 System.out.printf("%d ", (int) c);
	 }
	            
	 System.out.println();
	            
	 characters = temp.toCharArray();
	 for (char c : characters) {
	 System.out.printf("%d ", (int) c);
	 }
	 }*/
	public void appendWordToPane(JTextPane jTextPane1, String msg, Color c, boolean knownWord, boolean newLineFlag) throws BadLocationException
	{
		// Document doc = this.jTextPane1.getDocument();
		
		StyleContext sc = new StyleContext();
		Style style = sc.addStyle("yourStyle", null);
		
		Font font = new Font("Arial", Font.BOLD, 20);
		
		StyleConstants.setForeground(style, c);
		StyleConstants.setFontFamily(style, font.getFamily());
		StyleConstants.setFontSize(style, 20);
		
		jTextPane1.getDocument().insertString(jTextPane1.getCaretPosition(), msg, style);
	}
	
	//  public void CheckTextOnTheFly(JTextPane tp, LanguageEditor languageEditor){
	/*     LinkedList<String> a = languageEditor.returnLanguage();
	  int i = 0;
	  while (i < a.size()) {
	  this.updateKnownWords(tp, a.get(i)); /// to continue!!!
	  i++;
	  }*/
	//  }
	public void CheckTextOnTheFly(JTextPane tp, LanguageEditor languageEditor)
	{
		
		this.regBrackets = 0;
		this.roundBrackets = 0;
		int NewLineCounter = 0;
		int pos = tp.getCaretPosition();
		try
		{
			if (tp.getDocument().getLength() > 0)
			{
				if (tp.getDocument().getText((tp.getDocument().getLength()) - 1, 1).equals("\n"))
				{
					NewLineCounter = 1;
					while (tp.getDocument().getText((tp.getDocument().getLength()) - NewLineCounter, 1).equals("\n"))
					{
						NewLineCounter++;
					}
					NewLineCounter--;
				}
				
			}
		}
		catch (BadLocationException ex)
		{
			Logger.getLogger(TextEditor.class.getName()).log(Level.SEVERE, null, ex);
		}
		tp.getDocument().putProperty(DefaultEditorKit.EndOfLineStringProperty, "\n");
		//newLine = System.getProperty("line.separator");
		String[] lines = tp.getText().split("\n");
		tp.setText("");
		int currLine = 0;
		String[] getLine;
		
		while (currLine < lines.length)
		{
			int lineLenght = 0;
			getLine = lines[currLine].split(" ");
			int currWord = 0;
			while (currWord < getLine.length)
			{
				if ("".equals(getLine[currWord]) && (getLine.length > 1))
				{
					try
					{
						this.appendWordToPane(tp, " ", Color.black, false, true);
						lineLenght++;
					}
					catch (BadLocationException ex)
					{
						Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
					}
				}
				else
				{
					if (languageEditor.IsKnownWords(getLine[currWord]))
					{
						try
						{
							this.appendWordToPane(tp, getLine[currWord], Color.blue, true, false);
							lineLenght = lineLenght + getLine[currWord].length();
							if (currWord < (getLine.length - 1))
							{
								this.appendWordToPane(tp, " ", Color.black, false, true);
								lineLenght++;
							}
						}
						catch (BadLocationException ex)
						{
							Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
						}
					}
					else
					{
						try
						{
							this.appendWordToPane(tp, getLine[currWord], Color.black, false, false);
							lineLenght = lineLenght + getLine[currWord].length();
							if (currWord < (getLine.length - 1))
							{
								this.appendWordToPane(tp, " ", Color.black, false, true);
								lineLenght++;
							}
						}
						catch (BadLocationException ex)
						{
							Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
						}
					}
				}
				currWord++;
			}
			
			while (lines[currLine].length() > lineLenght)
			{
				try
				{
					this.appendWordToPane(tp, " ", Color.black, false, true);
				}
				catch (BadLocationException ex)
				{
					Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
				}
				lineLenght++;
			}
			
			try
			{
				if (currLine < (lines.length - 1))
				{
					this.appendWordToPane(tp, "\n", Color.black, false, false);
				}
			}
			catch (BadLocationException ex)
			{
				Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
			}
			currLine++;
		}
		
		while (NewLineCounter > 0)
		{
			try
			{
				this.appendWordToPane(tp, "\n", Color.black, false, false);
			}
			catch (BadLocationException ex)
			{
				Logger.getLogger(PascalPlusPlus.class.getName()).log(Level.SEVERE, null, ex);
			}
			NewLineCounter--;
		}
		tp.setCaretPosition(pos);
		int i = 0;
		while (i < languageEditor.getLanguage().size())
		{
			this.updateKnownWords(tp, languageEditor.getLanguage().get(i));
			i++;
		}
	}
	
	void UpdateBracketsCount(String word)
	{
		if (word.contains("("))
		{
			this.regBrackets += this.countMatches(word, "(");
		}
		if (word.contains(")"))
		{
			this.regBrackets -= this.countMatches(word, ")");
		}
		if (word.contains("{"))
		{
			this.roundBrackets += this.countMatches(word, "{");
		}
		if (word.contains("}"))
		{
			this.roundBrackets -= this.countMatches(word, "}");
		}
		if (word.contains("["))
		{
			this.squareBrackets += this.countMatches(word, "[");
		}
		if (word.contains("]"))
		{
			this.squareBrackets -= this.countMatches(word, "]");
		}
	}
	
	public int countMatches(String str, String sub)
	{
		int count = 0;
		int idx = 0;
		while ((idx = str.indexOf(sub, idx)) != -1)
		{
			count++;
			idx += sub.length();
		}
		return count;
	}
	
	public int getRegBracketsStatus()
	{
		return this.regBrackets;
	}
	
	public int getRoundBracketStatus()
	{
		return this.roundBrackets;
	}
	
	public int getSquareBracketStatus()
	{
		return this.squareBrackets;
	}
	
	public String checkBracketsResult(String bracketType)
	{
		String result = "Error"; //in case no match, result will return error
		switch (bracketType)
		{
			case "()":
				if (this.getRegBracketsStatus() == 0)
				{
					result = "OK";
				}
				else if (this.getRegBracketsStatus() > 0)
				{
					result = "Missing " + this.getRegBracketsStatus() + "   )";
				}
				else
				{
					result = "Missing " + this.getRegBracketsStatus() * -1 + "   (";
				}
				break;
			case "{}":
				if (this.getRoundBracketStatus() == 0)
				{
					result = "OK";
				}
				else if (this.getRoundBracketStatus() > 0)
				{
					result = "Missing " + this.getRoundBracketStatus() + "   }";
				}
				else
				{
					result = "Missing " + this.getRoundBracketStatus() * -1 + "   {";
				}
				break;
			case "[]":
				if (this.getSquareBracketStatus() == 0)
				{
					result = "OK";
				}
				else if (this.getSquareBracketStatus() > 0)
				{
					result = "Missing " + this.getSquareBracketStatus() + "   ]";
				}
				else
				{
					result = "Missing " + this.getSquareBracketStatus() * -1 + "   [";
				}
				break;
		}
		return result;
	}
	
	public void search(JTextPane tp, JTextField tf, String searchString)
	{
		tp.setHighlighter(this.hilit);
		this.hilit.removeAllHighlights();
		if (searchString.length() <= 0)
		{
			//  message("Nothing to search");
			return;
		}
		
		String content = tp.getText();
		int contentSize = content.length();
		int index = content.indexOf(searchString, 0);
		while (index < contentSize && index >= 0)
		{
			if (index >= 0)
			{ // match found
				int end = index + searchString.length();
				try
				{
					this.hilit.addHighlight(index, end, this.painter);
				}
				catch (BadLocationException ex)
				{
					Logger.getLogger(SearchTopic.class.getName()).log(Level.SEVERE, null, ex);
				}
				tp.setCaretPosition(end);
				tf.setBackground(tp.getBackground());
				//     message("'" + searchString + "' found. Press ESC to end search");
			}
			else
			{
				tf.setBackground(TextEditor.ERROR_COLOR);
				// message("'" + searchString + "' not found. Press ESC to start a new search");
			}
			index = content.indexOf(searchString, index + searchString.length());
		}
	}
	
	public int searchNext(JTextPane tp, JTextField tf, String searchString, int fromIndex)
	{
		tp.setHighlighter(this.hilit);
		this.hilit.removeAllHighlights();
		String content = tp.getText();
		//int contentSize = content.length();
		int index = content.indexOf(searchString, fromIndex);
		if (index >= 0)
		{ // match found
			int end = index + searchString.length();
			try
			{
				this.hilit.addHighlight(index, end, this.painter);
			}
			catch (BadLocationException ex)
			{
				Logger.getLogger(SearchTopic.class.getName()).log(Level.SEVERE, null, ex);
			}
			tp.setCaretPosition(end);
			tf.setBackground(tp.getBackground());
			//     message("'" + searchString + "' found. Press ESC to end search");
		}
		else
		{
			tf.setBackground(TextEditor.ERROR_COLOR);
			// message("'" + searchString + "' not found. Press ESC to start a new search");
		}
		return index + searchString.length();
	}
	
	public void clearSearch(JTextPane tp, JTextField tf)
	{
		tp.setHighlighter(this.hilit);
		this.hilit.removeAllHighlights();
		tf.setText("");
		tf.setBackground(tp.getBackground());
	}
	
	public int getNumOfLines()
	{
		return this.numOfLines;
	}
	
	public void updateKnownWords(JTextPane tp, String searchString)
	{
		if (searchString.length() <= 0)
		{
			return;
		}
		
		String content = tp.getText();
		int contentSize = content.length();
		int index = content.indexOf(searchString, 0);
		while (index < contentSize && index >= 0)
		{
			if (index >= 0)
			{ // match found
				int end = index + searchString.length();
				try
				{
					//hilit.addHighlight(index, end, painter);
					tp.setForeground(Color.blue);
					Font font = new Font("Arial", Font.BOLD, 20);
					tp.setFont(font);
					System.out.println(index + "  " + end + " " + contentSize);
					tp.getDocument().remove(index, searchString.length());
					tp.getDocument().insertString(index, searchString, null);
				}
				catch (BadLocationException ex)
				{
					Logger.getLogger(SearchTopic.class.getName()).log(Level.SEVERE, null, ex);
				}
				// tp.setCaretPosition(end);
			}
			index = content.indexOf(searchString, index + searchString.length());
		}
	}
}
