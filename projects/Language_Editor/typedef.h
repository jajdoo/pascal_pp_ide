#ifndef __TYPEDEF___
#define __TYPEDEF___

#define STATEMENT 1
#define CASESTAT 2
#define CASELIST 3
/*#define BOOLEAN 0*/ /*DELETED BECAUSE THARE WAS A REDECLERATION IN THE miny_tab.h file*/
/*#define INTEGER 1*/ /*DELETED BECAUSE THARE WAS A REDECLERATION IN THE miny_tab.h file*/
#define BRACKETS 316


#define INT_MAX 32000

/************/
/* typedefs */
/************/
typedef struct arrlist{
	int size;
	int sumsize;
	
} *arrList,arrLST;

typedef union
   { int val;
	 double rval;	
   } NUM_VAL;

typedef struct node {    /* abstract syntax tree record */
		int op;      /* type of operation */
        NUM_VAL num_val;   /*the value of the number*/
        char *name;  /* hold names of identfiers*/
        int children;
		struct node *s1,*s2,*s3;  /* urguments */
} *NODE;

typedef enum{MFALSE,MTRUE} booly;

typedef struct Symbol 
{
	char *symb;				// the string that holds the name of the Symbol
	char *funcName;			// the name of the function where the Symbol is decleared
	int type;				// the type (0 - Bool, 1 - Int ...)
	int address;			// relative address to block
	int size;				// size of variable in bytes
	int IS_ARRAY;			// if variable is array 1 for [] , x for [][x], 0 for non array
	int IS_POINTER;			// if variable is a pointer
	struct arrlist *lst;
	struct Symbol *next;	// pointer to the next symbol
};

typedef union
   { int code;
     double real;
     char *string;
	 int integer;
	 booly boolean;
	 NODE node;
   } YYSTYPE;
/*********************/
/* global variables: */
/*********************/
extern NODE root;

//tree functions
void print_tree(NODE r, int s);
void updateVarType(int op);

/* SymbolTable function declerations */
void addToSymbolTable(char *IDEName,int size,int IS_ARRAY,arrList lst);
struct Symbol* findSymbol(char *IDEName);
int getTableEntry (char *IDEName);
void InitializeTable();
void PrintSymbolTable();
//int getArraySize(char *IDEName);
#endif
