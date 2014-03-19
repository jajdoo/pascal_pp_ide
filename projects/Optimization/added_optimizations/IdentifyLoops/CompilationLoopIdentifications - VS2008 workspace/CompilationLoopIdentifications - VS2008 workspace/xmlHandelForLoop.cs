using System; 
 using System.Collections.Generic; 
 using System.Linq; 
 using System.Text; 
 using System.Xml; 
 using System.IO; 
 using System.Collections;
namespace CompilationLoopIdentifications 
 { 
     /// <summary> 
    /// This Class is cool 
    /// </summary>
	//<ROOT_NODE>
	//<LOOP_LIST>
		// <LOOP>
		//			<FIRST_BASIC_BLOCK> A </LAST_BASic_BLOCK>
		//			<LOOP_BODY> B,C,D,E,F </LOOP_BODY>
		//			<LAST_BASIC_BLOCK> Z </LAST_BASIC_BLOCK>
		//			<LOOP_ITERATION_VARIABLE>R0</LOOP_ITERATION_VARIABLE>
		//  </LOOP>
	//</LOOP_LIST>
	//</ROOT_NODE>
     class xmlHandler 
     { 

         public static void saveFile(String filename,String[] loops,String[] iterationVariables) 
         {
             createNewXmlSaveFile(filename, "LOOP_IDENTIFICATION_FOR_COMPILER_LAB_ORT_BRAUDE"); //create the save file
             for (int i = 0; i < loops.Length; i++)
             {
                 String[] loop = loops[i].Split(',');
                 if (!loops[i].Contains(',')) //if the loop body is empty
                 {
                     loop = loops[i].Split('\t');
                     loop[1] = "";
                 }
                 
                 loop[0] = loop[0].Substring(loop[0].IndexOf(':') + 2, (loop[0].IndexOf('\n') - loop[0].IndexOf(':')-2));
                 //Get loop Body
                 String temp = loop[(loop.Length - 1)];
                 //loop las basic blick
                 if (temp.Contains(':'))
                    temp = temp.Substring(temp.IndexOf(':') + 1, (temp.LastIndexOf('\n') - temp.IndexOf(':') - 1));
                 loop[(loop.Length - 1)] = temp;
                 String loopBody ="";
                 for (int j=1; j< (loop.Length - 1); j++)
                     loopBody += loop[j] + ",";
                 loopBody = loopBody.Substring(0, loopBody.Length - 1);
                 addLoopeToXmlDataBase(filename, loop[0], loopBody, loop[(loop.Length - 1)],iterationVariables[i]);
             }
 
         }

         /// <summary> 
         /// This method creates a NewXml Save File 
         /// </summary> 
         /// <param name="filepath">filePath(filename) to be saved</param> 
         /// <param name="xmlRootElementId">root elemnts name</param> 
         private static void createNewXmlSaveFile(String filepath, String xmlRootElementId) 
         { 
             //Create 
             //XmlTextWriter class is used to create an Xml file. In this,  
             //we just specify the filepath and type of xml encoding.after that, we have to create a root element of xml document. 
             //Ex: We are going to create an xml file with CustomerDetails as root element 
             //CREATE A NEW XML 
             XmlTextWriter xtw;  //create instance for xmltextwriter. Xml Text Writer 
             xtw = new XmlTextWriter(filepath, Encoding.UTF8);//assign  file path and encoding 
             xtw.WriteStartDocument(); //write start document 
             xtw.WriteStartElement(xmlRootElementId); //create root element 
             xtw.WriteEndElement(); //end root element 
             xtw.Close(); //close file. It is automatically saved. 
             //ADD THE ELEMENTS FOR SAVING DATA 
             XmlDocument xd = new XmlDocument();     //object creation for XmlDocument class 
             FileStream lfile = new FileStream(filepath, FileMode.Open); //open an xml file using file stream 
             xd.Load(lfile); //load opened file in xml document 
             
			 //Add LoopList Node 
             XmlElement cl = xd.CreateElement("LOOP_LIST"); //create an xml element                       
             xd.DocumentElement.AppendChild(cl); //append root element to xml document 
             
  
             lfile.Close(); //close the file stream 
             xd.Save(filepath); //save the xmldocument content to the file 
         } 
       
           /// <summary>
           /// This method inserts a loop to an exsisting loop save file
           /// </summary>
           /// <param name="saveFilePath">path of the save file</param>
           /// <param name="firstBasicBlock">String containg the title of the first basic block</param>
           /// <param name="loopBody">String containing the titles of the basic blocks in the loop body seperated by commas</param>
           /// <param name="lastBasicBlock">The last basic block of the loop</param>
           /// <param name="iterationVariable">The iteration variable of the loop</param>
         private static void addLoopeToXmlDataBase(String saveFilePath,String firstBasicBlock,String loopBody,String lastBasicBlock,String iterationVariable) 
         { 
             //Write- [insert into database] 
             //We can add data into an xml file by just adding child nodes to the root element. In this, we just create some 
             // xml elements and append those elements to the root as a child element and save the xml document. 
             //Before writing, one thing is very important. All the data stored into the xml  
             //file will be treated as String only. So we must convert all data types to string. 
  
             XmlDocument xd = new XmlDocument();     //object creation for XmlDocument class 
             FileStream lfile = new FileStream(saveFilePath, FileMode.Open); //open an xml file using file stream 
             xd.Load(lfile); //load opened file in xml document 
             XmlNode loopListNode = xd.GetElementsByTagName("LOOP_LIST")[0]; //Files are added to the File List element in the XML document 
             XmlElement loopElement = xd.CreateElement("LOOP"); //create an xml element 
             appendChildToNode(xd, loopElement, "FIRST_BASIC_BLOCK", firstBasicBlock); 
             appendChildToNode(xd, loopElement, "LOOP_BODY", loopBody); 
             appendChildToNode(xd, loopElement, "LAST_BASIC_BLOCK", lastBasicBlock);
             appendChildToNode(xd, loopElement, "LOOP_ITERATION_VARIABLE", iterationVariable); 
             
             loopListNode.AppendChild(loopElement); 
              
             lfile.Close(); //close the file stream 
             xd.Save(saveFilePath); //save the xmldocument content to the file 
         } 
          

         /// <summary> 
         /// This method appends a child node to an element 
         /// </summary> 
         /// <param name="xd">The xml document</param> 
         /// <param name="Node">The node of the element we want to attach a child elemnt to</param> 
         /// <param name="newChild">the child element to append</param> 
         /// <param name="childsText">the childs element text</param> 
         private static void appendChildToNode(XmlDocument xd, XmlNode Node, String newChild, String childsText) 
         { 
             XmlElement childElement = xd.CreateElement(newChild); //create an xml element 
             XmlText childElementsText = xd.CreateTextNode(childsText); //create text for xml element 
             childElement.AppendChild(childElementsText); //append address text to address node 
             Node.AppendChild(childElement); //append address node to root element 
         } 
  
         /*******************************************************************************************************************************/    
         /// <summary> 
         /// Convert comma seperated doubles string to an array of doubles 
         /// </summary> 
         /// <param name="doubleString">comma seperated doubles</param> 
         /// <returns>an array of the double numbers</returns> 
         private static double[] stringToDoubleArray(String doubleString) 
         { 
             String[] splited = doubleString.Split(','); 
             double[] doubleArray = new double[splited.Length]; 
             for (int i=0; i<doubleArray.Length; i++) 
             { 
                 doubleArray[i] = double.Parse(splited[i]); 
             } 
             return doubleArray; 
         } 
  
          
  
         /// <summary> 
         /// This method splits a string to specific part size 
         ///  </summary> 
         /// <param name="s">input string</param> 
         /// <param name="partSize">the size of the each splitted substring</param> 
         /// <returns>Retuns a string array that contains the splitted parts</returns> 
         private static String[] splitString(String s, int partSize) 
         { 
             String[] stringArray = null; 
             if (partSize == 0) 
             { 
                 stringArray = new String[1]; 
                 stringArray[0] = s; 
                 return stringArray; 
             } 
  
             while (s.Length % partSize != 0) 
             { 
                 s += " "; 
             } 
              
             stringArray = new String[s.Length / partSize]; 
             for (int i = 0; i < stringArray.Length; i++) 
             { 
                 stringArray[i] = s.Substring(0, partSize); 
                 s = s.Substring(partSize); 
             } 
             return stringArray; 
         } 
  
  
  

  

  

  
 
     } 
 } 
 