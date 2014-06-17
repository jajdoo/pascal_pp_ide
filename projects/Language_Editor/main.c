#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "typedef.h"
#include "bison_file_tab.h"
#include "convertTree.h"
#include "symbol_table.h"

FILE  *treefile;
extern FILE *yyin;			//  a pointer to the program file that should be compiled.
//extern int yyparse (void);  // do syntax checking and build the tree.
extern YYSTYPE yyval;
extern int line_number;

NODE getTree(char *progFile) 
{
	char *file;

	file = (char*) malloc (strlen(progFile)+1);
	strcpy(file,progFile);

	// yyin is an external variable that been used in yyparse as pointer to the pearl 
	// source file.
	if ((yyin = fopen(progFile,"r")) == NULL)
	{ 
	   fprintf(stderr,"Error: file %s does not exist \n",file);
       exit(-1);
    }
  
	// yyparse is yacc (pearl_tab.c) function that parse over the pearl program,
	// check syntax and build the program tree.
	yyparse();

	//printSymbolTable();

	printf("line number :%d", line_number);
	// root was initialized in yyparse while it was building the tree.
	// root is the pointer of the returning tree.
	if (root==NULL) 
        exit(-1);

	return(root);
}


void PrintTree(){
	treefile = fopen("tree.txt", "w");
	print_tree(root,0);
	fclose(treefile);
}



/* later use */
void _free(void *a) {

}

void print_symbol(struct Symbol* symbol)
{
	int n;
	SymbolWrapper* w;
	//printf("\n--------------------------------------\n");
	printf("symbol:		%s\n"
		"type:		%d\n"
		"add:		%d\n"
		"proc?		%d\n"
		"array?		%d\n"
		"pointer?	%d\n"
		"struct?		%d\n\n\n",
		symbol->symb,
		symbol->type,
		symbol->address,
		symbol->isProc,
		symbol->IS_ARRAY,
		symbol->IS_POINTER,
		symbol->is_struct
		);

	n = 0;
	w = symbol->list;
	while (w != NULL)
	{
		printf("child %d of %s ::: \n", n, symbol->symb);
		print_symbol(w->Symbol);
		w = w->next;
		n++;
	}
	//symbol->list = NULL
	//printf("--------------------------------------\n");
}


int main(int argc, char* argv[])
{
	FILE *txt;
	txt=fopen("outputParser.txt","w");
	fprintf(txt,"");
	fclose(txt);
	NODE theProgram;
	freopen("Error_Log.txt", "w", stderr);

	if (argc < 2)
	{
		printf("Input filename is missing.\n");
		return 0;
	}

	init(_free, print_symbol);
	enter_block("program");

	// Build the program tree
	theProgram = getTree(argv[1]);

	// Output an IL file from the program tree
	TreeToIL(root);						// Converts the program tree to an intermediate-language representation
	PrintCommandsToFile("out1.txt");	// Prints the output IL file
	PrintTree();
	printSymbolTable();
	_getch();
	return (0);
}