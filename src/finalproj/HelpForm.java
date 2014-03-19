/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package finalproj;

import java.awt.Color;

import javax.swing.WindowConstants;

/**
 *
 *
 */
public class HelpForm extends javax.swing.JFrame
{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = -6734455327865167486L;
	/**
	 * Creates new form HelpForm
	 */
	private final String jarPath;
	
	public HelpForm(String mainPath)
	{
		this.jarPath = mainPath;
		this.initComponents();
		this.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		this.setResizable(false);
		this.topicsList.setBackground(Color.LIGHT_GRAY);
		//this.topicsList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
	}
	
	/**
	 * This method is called from within the constructor to initialize the form. WARNING: Do NOT modify this code. The content of this method is always regenerated by the Form Editor.
	 */
	@SuppressWarnings({"unchecked", "rawtypes"})
	// <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
	private void initComponents()
	{
		
		this.mainLabel = new javax.swing.JLabel();
		this.jScrollPane1 = new javax.swing.JScrollPane();
		this.topicsList = new javax.swing.JList();
		this.helpButton = new javax.swing.JButton();
		this.closeButton = new javax.swing.JButton();
		
		this.setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
		
		this.mainLabel.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
		this.mainLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
		this.mainLabel.setText("Select Topic To Search:");
		
		this.topicsList.setModel(new javax.swing.AbstractListModel()
		{
			/**
			 * 
			 */
			private static final long serialVersionUID = -4773601553678019533L;
			
			String[] strings = {"1. Installation", "2. Creating New Project", "3. Creating New Language", "4. Compiling Your Code File", "5. Generate Basic Blocks", "6. Generate VCG Form", "7. Add New Optimization", "8. Using Existing Optimization", "9. DDG Tool"};
			
			@Override
			public int getSize()
			{
				return this.strings.length;
			}
			
			@Override
			public Object getElementAt(int i)
			{
				return this.strings[i];
			}
		});
		this.jScrollPane1.setViewportView(this.topicsList);
		
		this.helpButton.setText("Show Help ");
		this.helpButton.addActionListener(new java.awt.event.ActionListener()
		{
			@Override
			public void actionPerformed(java.awt.event.ActionEvent evt)
			{
				HelpForm.this.helpButtonActionPerformed(evt);
			}
		});
		
		this.closeButton.setText("Close");
		this.closeButton.addActionListener(new java.awt.event.ActionListener()
		{
			@Override
			public void actionPerformed(java.awt.event.ActionEvent evt)
			{
				HelpForm.this.closeButtonActionPerformed(evt);
			}
		});
		
		javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this.getContentPane());
		this.getContentPane().setLayout(layout);
		layout.setHorizontalGroup(
				layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
						.addGroup(layout.createSequentialGroup()
								.addComponent(this.mainLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 219, javax.swing.GroupLayout.PREFERRED_SIZE)
								.addGap(0, 0, Short.MAX_VALUE))
						.addGroup(layout.createSequentialGroup()
								.addContainerGap()
								.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
										.addGroup(layout.createSequentialGroup()
												.addComponent(this.jScrollPane1)
												.addContainerGap())
										.addGroup(layout.createSequentialGroup()
												.addComponent(this.helpButton)
												.addGap(18, 18, 18)
												.addComponent(this.closeButton, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
												.addGap(24, 24, 24))))
				);
		layout.setVerticalGroup(
				layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
						.addGroup(layout.createSequentialGroup()
								.addComponent(this.mainLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
								.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
								.addComponent(this.jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 156, Short.MAX_VALUE)
								.addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
								.addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
										.addComponent(this.helpButton)
										.addComponent(this.closeButton))
								.addContainerGap())
				);
		
		this.pack();
	}// </editor-fold>//GEN-END:initComponents
	
	private void helpButtonActionPerformed(java.awt.event.ActionEvent evt)
	{//GEN-FIRST:event_helpButtonActionPerformed
		if (this.topicsList.getSelectedValue() != null)
		{
			String getTopic = this.topicsList.getSelectedValue().toString();
			String[] getTopicNoSpace = getTopic.split(" ");
			String fileName = "";
			for ( int i = 0 ; i < getTopicNoSpace.length ; i++ )
			{
				fileName = fileName + getTopicNoSpace[i];
			}
			String fileNoNumber = fileName.substring(2, fileName.length());
			SearchTopic st = new SearchTopic(this.jarPath, fileNoNumber);
			st.setVisible(true);
		}
	}//GEN-LAST:event_helpButtonActionPerformed
	
	private void closeButtonActionPerformed(java.awt.event.ActionEvent evt)
	{//GEN-FIRST:event_closeButtonActionPerformed
		this.dispose();
	}//GEN-LAST:event_closeButtonActionPerformed
	
	/**
	 * @param args
	 *            the command line arguments
	 */
	public static void main(String args[])
	{
		/* Set the Nimbus look and feel */
		//<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
		/* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
		 * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
		 */
		try
		{
			for ( javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels() )
			{
				if ("Nimbus".equals(info.getName()))
				{
					javax.swing.UIManager.setLookAndFeel(info.getClassName());
					break;
				}
			}
		}
		catch (ClassNotFoundException | InstantiationException | IllegalAccessException | javax.swing.UnsupportedLookAndFeelException ex)
		{
			java.util.logging.Logger.getLogger(HelpForm.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
		}
		//</editor-fold>
		
		/* Create and display the form */
		java.awt.EventQueue.invokeLater(new Runnable()
		{
			@Override
			public void run()
			{
				new HelpForm("").setVisible(true);
			}
		});
	}
	
	// Variables declaration - do not modify//GEN-BEGIN:variables
	private javax.swing.JButton closeButton;
	private javax.swing.JButton helpButton;
	private javax.swing.JScrollPane jScrollPane1;
	private javax.swing.JLabel mainLabel;
	@SuppressWarnings("rawtypes")
	private javax.swing.JList topicsList;
	// End of variables declaration//GEN-END:variables
}
