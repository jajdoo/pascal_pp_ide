#ifndef __TYPEDEF___
#define __TYPEDEF___

#define CASESTAT 2
#define CASELIST 3
#define BRACKETS 1024

// WHY THE FUCK DID THEY REDEFINE INT_MAX???
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
