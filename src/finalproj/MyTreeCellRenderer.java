/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package finalproj;

import java.awt.Component;
import java.io.File;

import javax.swing.JTree;
import javax.swing.filechooser.FileSystemView;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeCellRenderer;

/**
 *
 *
 */
public class MyTreeCellRenderer extends DefaultTreeCellRenderer
{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = -2922434618500646886L;
	
	private final FileSystemView fsv = FileSystemView.getFileSystemView();
	
	@Override
	public Component getTreeCellRendererComponent(JTree tree, Object value, boolean sel, boolean expanded, boolean leaf, int row, boolean hasFocus)
	{
		//   System.out.println(value);
		super.getTreeCellRendererComponent(tree, value, sel, expanded, leaf, row, hasFocus);
		if (value instanceof DefaultMutableTreeNode)
		{
			value = ((DefaultMutableTreeNode) value).getUserObject();
			if (value instanceof File)
			{
				File file = (File) value;
				if (file.isFile())
				{
					this.setIcon(this.fsv.getSystemIcon(file));
					this.setText(file.getName());
				}
				else
				{
					this.setIcon(this.fsv.getSystemIcon(file));
					this.setText(file.getName());
				}
			}
		}
		return this;
	}
}
