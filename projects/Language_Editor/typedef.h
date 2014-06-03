#ifndef __TYPEDEF___
#define __TYPEDEF___

#define STATEMENT 1
#define CASESTAT 2
#define CASELIST 3
#define BRACKETS 1024


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
		int type;
} *NODE;

typedef enum{MFALSE,MTRUE} booly;

typedef struct SymbolWrapper
{
	struct Symbol*			Symbol;
	struct SymbolWrapper*	next;
};

typedef struct Symbol 
{
	char *symb;				// the string that holds the name of the Symbol
	char *funcName;			// the name of the function where the Symbol is decleared
	int type;
	int address;			// relative address to block
	int size;				// size of variable in bytes
	int IS_ARRAY;			// if variable is array 1 for [] , x for [][x], 0 for non array
	int IS_POINTER;			// if variable is a pointer
	struct arrlist *lst;
	struct Symbol *next;	// pointer to the next symbol


	//----------------------
	// struct def: 
	//		- is_struct		= 1
	//		- type			= 0
	//		- address		= -1
	//		- members		= [actual members]
	//
	// struct instance: 
	//		- is_struct		= 1
	//		- type			= [index of struct def in symbol table]
	//		- address		= [actual adress]
	//		- members		- NULL

	int is_struct;					// is this symbol a struct?
	int isProc;						// is this a procedure?
	struct SymbolWrapper* list;		// if this symbol is a struct, these are its members.
								    // if this symbol is a procedure/function, these are its parameters;
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
//int getArraySize(char *IDEName);
#endif
