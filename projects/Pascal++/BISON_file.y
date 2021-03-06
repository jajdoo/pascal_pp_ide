
%{
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
#include "typedef.h"
#define yyerror(x) { FILE *txt; txt=fopen("yyerror.txt","w"); fprintf(txt,"%s in line %d\n",x,line_number);}
#include <time.h>       /************************ time **************************/

static int n;
static int s;
static int o;
arrLST *lst;
NODE tmp1;
NODE tmp2;

/********************* add hash*****************/
typedef struct hashIDE
{
	int value;
	char *IDEName;
	
}hashIDE;
hashIDE hash[256];
/************ add hash*****************/

typedef struct stack
{
	int value;
	struct stack *next;
	struct stack *prev;
	
}stack, *Stack;


Stack headStack = 0;


//  The symbol table - hash table of 26 enteries (alphabetical) of Symbols
//	Remember : each symbol has a pointer to the next one. See decleration in typedef.h 
struct Symbol *symbTable[256];//a cell is pointer to first symbol ******26***************************size--->256
struct Symbol **first;		//pointer to a table cell - which is a pointer to symbol struct
struct Symbol *CurrSymbol;	//pointer to a symbol struct
int TableInitialized=0;		//0 - table uninitialized, 1 - table initialized
int currentAddress;			// address of the new variable in stack
int currentType;			//'0' - Boolean, '1'- Integeer */

arrList arrRoot;
NODE root;
int line_number = 1;
extern int yylex(void);
extern FILE *treefile;
//extern FILE *outFile;
NODE makenode(int op, NODE s1, NODE s2, NODE s3,int val,char *id);
NODE genLeaf(int op, int val, double rval,char *id);
arrList addToArrayList(int s, int ss,arrList next);
void PrintArray(arrList l,FILE *t, int ind);
%}

%token PROGRAM BBEGIN END DECLARE PROCEDURE LABEL INTEGER FLOAT REAL CMP
%token BOOLEAN ARRAY OF ASSIGN LC RC IF THEN ELSE FI THEN WHILE REPEAT DO OD 
%token READ WRITE TRUE FALSE ADD MMIN MUL DIV GOTO
%token MOD LES LEQ EQU NEQ GRE GEQ AND OR
%token AND OR NOT CASE FOR FIN IDENTICAL FROM BY TO CONST TYPE VAR RECORD
%token<code> INTCONST 
%token<string> IDE 
%token<string> POINTER
%token<real> REALCONST
%token<string> STRING
%token<integer> INTEGER
%token<boolean> BOOLEAN
%token<float> FLOAT

%type<node> var assign program stat_seq loop_stat case_stat bracket 
%type<node> expr atom block stat nonlable_stat cond_stat case case_list
%type<code> brk

%nonassoc LES LEQ EQU NEQ GRE GEQ
%left ADD MMIN OR
%left MUL DIV AND MOD
%right NOT DUMMY


%start  program

%%
program: PROGRAM IDE  block             {$$=makenode(PROGRAM,$3,NULL,NULL,0,$2); root=$$;} 
       ;

block :LC declarations stat_seq RC                   {$$=makenode(BBEGIN,$3,NULL,NULL,0,NULL);} 
       ;


declarations:VAR varAss ;

varAss: tyList ':' idList varAss		{} 
	|
	';'{}
	;

idList: IDE 	{addToSymbolTable($1,1,0,NULL);}idList
     |POINTER 	{addToSymbolTable($1,1,0,NULL);}idList
	|   IDE '[' INTCONST ']' 
	{
		s=1;

	} 
	brk 
	{ 
		lst[s-o].size=$3;/* calcultes size of each dimentiob*/
		lst[s-o].sumsize=n*$3;/* sum of array*/
		
		addToSymbolTable($1,n*$3,s,lst);
	}
	idList
	|',' IDE idList {addToSymbolTable($2,1,0,NULL);}
	|',' POINTER idList {addToSymbolTable($2,1,0,NULL);}
	|',' IDE '[' INTCONST ']'
	{
		s=1;

	} 
	brk 
	{ 
		lst[s-o].size=$4;/* calcultes size of each dimentiob*/
		lst[s-o].sumsize=n*$4;/* sum of array*/
		
		addToSymbolTable($2,n*$4,s,lst);
	}
	idList
	|
	{}
	;								
brk:  '[' INTCONST ']'
		{s=s+1;} 
		brk 
		{
			n=n*$2; 
			$$=lst; 
			lst[s-o].size=$2;/* calcultes size of each dimentiob*/
			lst[s-o].sumsize=n;/* sum of array*/
			
			o=o+1;
		}
	|{} 
	{
		n=1;
		o=1;
		lst =(arrLST*)malloc(sizeof(arrLST)*s); 
		
		$$=NULL;
	}
	;
tyList: BOOLEAN		{updateVarType(BOOLEAN);}
	|
	INTEGER			{updateVarType(INTEGER);}
	|
	FLOAT			{updateVarType(FLOAT);}
	;
	
	
stat_seq: stat                        {$$=makenode(STATEMENT,$1,NULL,NULL,0,NULL);} 
         | 
         stat stat_seq              {$$=makenode(STATEMENT,$1,$2,NULL,0,NULL);} 
       	 ;

stat:    nonlable_stat                    {$$=$1;}
         ;

nonlable_stat:  assign';'                   {$$=$1;}
              | cond_stat                   {$$=$1;}
			  | loop_stat                   {$$=$1;}
			  | case_stat                   {$$=$1;}
			  ;  

assign :  var ASSIGN expr             {$$=makenode(ASSIGN,$1,$3,NULL,0,NULL);}
       ;

cond_stat: IF expr THEN stat_seq FI     {$$=makenode(IF,$2,$4,NULL,0,NULL);}
          |IF expr THEN stat_seq ELSE stat_seq FI {$$=makenode(IF,$2,$4,$6,0,NULL);}  
          ; 

loop_stat: WHILE expr DO  stat_seq OD {$$=makenode(WHILE,$2,$4,NULL,0,NULL);}
           ; 

case_stat :CASE expr OF LC case_list RC {$$=makenode(CASESTAT,$2,$5,NULL,0,NULL);}
          ;
		    
case_list:  case               {$$=makenode(CASELIST,$1,NULL,NULL,0,NULL);}
           |case case_list      {$$=makenode(CASELIST,$1,$2,NULL,0,NULL);}

case :  INTCONST ':' stat_seq  {$$=makenode(CASE,NULL,$3,NULL,$1,NULL);}   


var: IDE                         { $$ = genLeaf(IDE,0,0,$1);}
|POINTER {$$ = genLeaf(POINTER,0,0,$1);}
     | IDE '[' expr ']'
     {s=0; lst=findSymbol($1)->lst;} 
     bracket  
     { 
		if(n==1)
			{$$ = makenode(ADD,genLeaf(IDE,0,0,$1),$3,NULL,0,"check");}
		else
		{
			tmp1=makenode(ADD,makenode(MUL,$3,genLeaf(INTCONST,lst[s+1].sumsize,0,NULL),NULL,0,"check"),$6,NULL,0,"check");
			$$ = makenode(ADD,genLeaf(IDE,0,0,$1),tmp1,NULL,0,"check");
		}
		FILE *txt; 
		txt=fopen("outputParser.txt","a");
		if (n!=findSymbol($1)->IS_ARRAY ) {
			fprintf(txt,"\nError at line %d: Assign problem %s: %d!=%d.",line_number, $1,n,findSymbol($1)->IS_ARRAY); 
			fclose(txt);
			}
	}
     ;

bracket: '[' expr ']' 
	{s=s+1;}
	bracket 
	{	
		/*calculation of array offset*/
		if(n==1)
			$$ = makenode(MUL,$2,genLeaf(INTCONST,1,0,NULL),NULL,0,"check");
		else
			$$ = makenode(ADD,makenode(MUL,$2,genLeaf(INTCONST,lst[s+1].sumsize,0,NULL),NULL,0,"check"),$5,NULL,0,"check");
		n=n+1;
		s=s-1;
	}
	| {} {n=1;$$=NULL}
	;

expr:   expr ADD expr           { $$ = makenode(ADD,$1,$3,NULL,0,NULL);}
      | expr MMIN expr           { $$ = makenode(MMIN,$1,$3,NULL,0,NULL);}
      | expr MUL expr           { $$ = makenode(MUL,$1,$3,NULL,0,NULL);}
      | expr DIV expr           { $$ = makenode(DIV,$1,$3,NULL,0,NULL);}
      | expr MOD expr           { $$ = makenode(MOD,$1,$3,NULL,0,NULL);}
      | expr LES expr           { $$ = makenode(LES,$1,$3,NULL,0,NULL);}
      | expr LEQ expr           { $$ = makenode(LEQ,$1,$3,NULL,0,NULL);}
      | expr EQU expr           { $$ = makenode(EQU,$1,$3,NULL,0,NULL);}
      | expr NEQ expr           { $$ = makenode(NEQ,$1,$3,NULL,0,NULL);}
      | expr GRE expr           { $$ = makenode(GRE,$1,$3,NULL,0,NULL);}
      | expr GEQ expr           { $$ = makenode(GEQ,$1,$3,NULL,0,NULL);}
      | expr AND expr           { $$ = makenode(AND,$1,$3,NULL,0,NULL);}
      | expr OR expr            { $$ = makenode(OR,$1,$3,NULL,0,NULL);}
      | '(' expr ')'               { $$ = $2; }
   /*   | MMIN atom %prec DUMMY    { $$ = makenode(MMIN,$2,NULL,NULL,0,NULL); }*/
      | NOT atom                   { $$ =makenode(NOT,$2,NULL,NULL,0,NULL); }
      | atom                       { $$ = $1; }
      ;


atom:   var                        { $$ = $1; }
      | INTCONST                   { $$ = genLeaf(INTCONST,$1,0,NULL); }
      | REALCONST                  { $$ = genLeaf(REALCONST,0,$1,NULL);}
      | TRUE                       { $$ = genLeaf(TRUE,0,0,NULL); }
      | FALSE                      { $$ = genLeaf(FALSE,0,0,NULL); }
      
      ;

%%
/*==   AST - PART constructs the tree ============================*/
/*arrList addToArrayList(int s, int ss,arrList next)
{
	arrList p;
	p= (arrList)malloc(sizeof(struct arrlist));
	p->size=s;
	p->sumsize=ss;
	p->next=next;
}*/
NODE makenode(int op, NODE s1, NODE s2, NODE s3,int val,char *id)
{   int i=0;
	NODE t;
    
	t= (NODE )malloc(sizeof(struct node));
    t->num_val.val=val;
	if(op==CASE)
	  t->s1=genLeaf(INTCONST,val,0,NULL);
	else
	  t->s1 = s1;

	
	t->s2 = s2;
	
	t->s3 = s3;
    if(id != NULL) 
           t->name=id; 
	else 
	  t->name="";
	 if (t->s1!=NULL)
	   i++;
     if (s2!=NULL)
	   i++;
     if (s3!=NULL)
	   i++;
	t->children=i;
	t->op=op;
	
	if (t->op == IDE)
		push(findType(t->name));
	else
		push(t->op);
	return(t);
}

NODE genLeaf(int op, int val, double rval,char *id)
{
	NODE t;
	if(id != NULL&&!findSymbol(id)){
		FILE *txt; 
		txt=fopen("outputParser.txt","a");
		fprintf(txt,"\nError at line %d: Undeclared identifier: %s",line_number,id);
		fclose(txt);
		exit(1);
	}
	
	t= (NODE )malloc(sizeof(struct node));
        t->num_val.val=val;
        if (op == REALCONST)
			 t->num_val.rval=rval;
	t->op = op;
	if(id != NULL) 
           t->name=id;  
	else	       
		   t->name="";
	t->s1 = NULL;
	t->s2 = NULL;
	t->s3 = NULL;
	t->children=0;
	
	if (t->op == IDE)
		push(findType(t->name));
	else
		push(t->op);
	return(t);
}

char *print_op(int op)
{
	FILE *txt; 
	txt=fopen("outputParser.txt","a");
    switch (op) {
      case PROGRAM:
	    return ("PROGRAM");
	    break; 
	   case STATEMENT:
	    return ("STATEMENT");
	    break;
	  case BBEGIN:
	   return("BEGIN");
	    break;
	  case ASSIGN:
	    return ("ASSIGN");
	    break;
      case IDE:
	    return ("IDE");
		break;
	  case POINTER:
	    return ("POINTER");
		break;
      case ADD:
	    return ("ADD");
		break;
	case MMIN:
	    return ("MMIN");
		break;
    case MUL:
	    return ("MUL");
		break;
	case DIV:
	    return ("DIV");
		break;
	case MOD:
	    return ("MOD");
        break;
    case AND:
	    return ("AND");
		break;
	case OR:
	    return ("OR");
		break;
	case NOT:
	    return ("NOT");
		break;
	case INTCONST:
	    return ("INTCONST");
		break; 
    case REALCONST:
	    return ("REALCONST");
		break;
	case TRUE:
	    return ("TRUE");
		break;
	case FALSE:
	    return ("FALSE");
		break;
	case IF:
	    return ("IF");
		break;
	case LES:
	    return ("LES");
		break;
    case LEQ:
	    return ("LEQ");
		break;
    case EQU:
	    return ("EQU");
		break;
	case NEQ:
	    return ("NEQ");
		break;
	case GRE:
	    return ("GRE");
		break;
	case GEQ:
	    return ("GEQ");
		break;
	case WHILE:
	    return ("WHILE");
		break;
    case CASESTAT:
	    return ("CASESTAT");
		break;
    case CASELIST:
	    return ("CASELIST");
		break;
    case CASE:
	    return ("CASE");
		break;
	case BRACKETS:
	    return ("[]");
		break;
	case BOOLEAN:
		return ("BOOLEAN");
		break;
	case INTEGER:
		return ("INTEGER");
		break;
	case FLOAT:
		return ("FLOAT");
		break;
	case REAL:
		return ("REAL");
		break;
	default:
	      fprintf(txt,"Error at line %d: Unknown Token is line %d\n", line_number);
	}     
	fclose(txt);
}

void print_tree(NODE r, int s)
{ 
  
if(r != NULL) { 
                fprintf(treefile,"type=%s\n", print_op(r->op));
				fprintf(treefile,"children=%d\n", r->children);
				if(r->name) fprintf(treefile,"my check == = = ==> %s\n",r->name);
				if(r->op == IDE) fprintf(treefile,"string=%s\n",r->name);
                if(r->op ==INTCONST)  fprintf(treefile,"int value=%d\n", r->num_val.val); 
                if(r->op==REALCONST) fprintf(treefile,"real value=%f\n", r->num_val.rval); 
                fprintf(treefile,"\n");
				if(r->s1!=NULL){
                  fprintf(treefile,"| Son1 of %s\n",print_op(r->op));
                  fprintf(treefile,"|\n");
	              fprintf(treefile,"---------------\n");
	              print_tree(r->s1,s+2);

	            } 
	  
	           
	        if(r->s2!=NULL){
               fprintf(treefile,"| Son2 of %s\n",print_op(r->op));
               fprintf(treefile,"|\n");
	           fprintf(treefile,"---------------\n");
               print_tree(r->s2, s+2);
	
            }
 
          if(r->s3!=NULL){
               fprintf(treefile,"| Son3 of %s\n",print_op(r->op));
               fprintf(treefile,"|\n");
	           fprintf(treefile,"---------------\n");
               print_tree(r->s3, s+2);
	
            } 
 } 
}

void updateVarType(int op)
{
	FILE *txt;
	txt=fopen("outputParser.txt","a");
	switch (op)
	{
		case BOOLEAN:	
			currentType = BOOLEAN;	
			break;
		case INTEGER:		
			currentType = INTEGER;	
			break;
		case FLOAT:		
			currentType = FLOAT;	
			break;
		default:		
			fprintf(txt,"Error at line %d: Undefined variable type\n",line_number);	
			fclose(txt);
			break;
	}
}




/* ------------------------------------------------------------------------- */
/* Symbol Table Part - Functions that build the symbol table during runtime: */
/* ------------------------------------------------------------------------- */

void addToSymbolTable(char *IDEName,int size,int IS_ARRAY,arrList lst)
{
	FILE *txt;
	txt=fopen("outputParser.txt","a");
	int l,isPointer=0;
	struct Symbol* newSymb; 
	
	//fprintf(txt,"Info at line %d: adding to symbol table: %s \n",line_number,IDEName);
	if(size<=0){
		fprintf(txt,"\nErrorat line %d: illegal array size: %s has the size of %d",line_number,IDEName, size);
		fclose(txt);
		exit(1);
	}

	newSymb = (struct Symbol*)malloc(sizeof(struct Symbol));
	newSymb->lst=lst;
	
	if(!TableInitialized) // if table is uninitialized, then go initialize!
		InitializeTable();
	
	//check if the symbol was already declared
	if (findSymbol(IDEName) != NULL)
		fprintf(txt,"Error at line %d: Symbol %s already declared", line_number,IDEName);
	
	//pointer to a cell
	if (IDEName[strlen(IDEName)-1] == '^') 
	{
		int i =0;
		IDEName[strlen(IDEName)-1]=NULL;
		first = &symbTable[getTableEntry(IDEName)];
		
		isPointer = 1;
	}
	else
		first = &symbTable[getTableEntry(IDEName)];
	
	newSymb->IS_POINTER = isPointer;
	newSymb->symb = IDEName;
	newSymb->type = currentType;
	newSymb->address=currentAddress;
	newSymb->size=size;		
	newSymb->IS_ARRAY=IS_ARRAY;
	currentAddress+=newSymb->size;
	
	fprintf(txt,"Info at line %d: adding symbol  %s of type %d to table variable\n",line_number, IDEName, currentType);
	if(*first!=NULL)
		newSymb->next = (*first)->next;
	else
		newSymb->next=NULL;
	
	//cell is always points to last symbol entered into the list
	*first= newSymb;
	
	fclose(txt);
	PrintSymbolTable();//print current symbol table
}



struct Symbol* findSymbol(char *IDENameIn)
{
	FILE *txt; 
	txt=fopen("outputParser.txt","a");
	int symbTabEntry;
	int isPointer = 0;
	char IDEName[100];
	strcpy(IDEName,IDENameIn);
	if (IDEName[strlen(IDEName)-1]=='^')
	{
		int i =0;
		isPointer = 1;
		IDEName[strlen(IDEName)-1] = NULL;
	}
	symbTabEntry = getTableEntry(IDEName);
	CurrSymbol = symbTable[symbTabEntry];
	
	while (CurrSymbol != NULL)
	{
		if (!strcmp(CurrSymbol->symb,IDEName))
			{
			
			if (isPointer)
			{
				if (!CurrSymbol->IS_POINTER)
					{
					fprintf(txt,"Error at line %d: variable is not a pointer: %s\n",line_number,IDEName);
					fclose(txt);
					break;
					}
			
			}
			
			
			return (CurrSymbol);
			}
		else
			CurrSymbol = CurrSymbol->next;
	}
	
	return (NULL);
}

int getTableEntry (char *IDEName) /* change all function **************************************************************/
{	
	int entry,temp=0;
	int i;
	
	for(i=0;i<strlen(IDEName);i++)
	{
		if (islower(IDEName[i]))
			entry = (IDEName[i] - 'a');
		else
			entry = (IDEName[i] - 'A');
			
		if(i==0)
			temp = (hash[entry].value ^ entry)% 256;
		else 
			temp=(temp ^ entry)% 256;
	}	
	if(hash[temp].IDEName == NULL)
	{
		hash[temp].IDEName= ( char *)malloc(strlen(IDEName));
		strcpy(hash[temp].IDEName,IDEName);
		return temp;
	}
	else if((strcmp(hash[temp].IDEName,IDEName))==0)
	{
		return temp;
	}
	else{
		for(i=temp;i<256;i++)
		{
			if(hash[i].IDEName == NULL)
			{
				hash[i].IDEName= ( char *)malloc(strlen(IDEName));
				strcpy(hash[i].IDEName,IDEName);	
				return i;
			}
			if((strcmp(hash[i].IDEName,IDEName))==0)
			{	
				return i;
			}
		}
		for(i=temp;i>0;i--)
		{
				if(hash[i].IDEName == NULL)
				{
					hash[i].IDEName= ( char *)malloc(strlen(IDEName));
					strcpy(hash[i].IDEName,IDEName);
					return i;
				}
			if((strcmp(hash[i].IDEName,IDEName))==0)
			{	
				return i;
			}
		}
	} /*end else*/	
		
}/* change all function *************************************************************
end of func*/




//zero all cells i.e. NULL all the pointers /* initialize hash****************/
void InitializeTable(void){
int i;
	TableInitialized=1;
	
	srand (time(NULL));
	for(i=0;i<256;++i)
	{
		symbTable[i]=NULL;
		hash[i].IDEName=NULL;
		hash[i].value= rand() % 256;
	}
}
/* initialize hash*********************************/

//print currentsymbol table
void PrintSymbolTable(){
	int i;
	FILE *txt;
	FILE *txt1;
	txt=fopen("symbol table.txt","w");
	txt1=fopen("symbol_table.txt","w");
	fprintf(txt1,"Name\t|Address\t|Size\t|IS ARRAY\t\t|IS POINTER\t|TYPE\n");
	fprintf(txt1,"--------------------------------------------------------------\n");
	fprintf(txt,"Name   |Address  |Size  |IS ARRAY   |IS RECORD\n");
	fprintf(txt,"-----------------------------------------------\n");
	for(i=0;i<256;++i){	/**************************change from 26******************/
		CurrSymbol=symbTable[i];
		while (CurrSymbol != NULL)
		{
			fprintf(txt1,"%s\t\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d\n"
				  ,CurrSymbol->symb,CurrSymbol->address,CurrSymbol->size,CurrSymbol->IS_ARRAY,CurrSymbol->IS_POINTER,CurrSymbol->type);
			fprintf(txt,"%s      |%d        |%d     |%d\n"
				  ,CurrSymbol->symb,CurrSymbol->address,CurrSymbol->size,CurrSymbol->IS_ARRAY);
			PrintArray(CurrSymbol->lst,txt,CurrSymbol->IS_ARRAY);
			CurrSymbol=CurrSymbol->next;
		}
	}
	fclose(txt);
	fclose(txt1);

}

void PrintArray(arrLST *l,FILE *t,int ind)
{
	if (!ind) return;
	fprintf(t,"%d     %d\n",l->size,l->sumsize);
	PrintArray(l+1,t,ind-1);
}
int checkn(int n)
{
	if (n==1) 
		return 1;
	else 
		lst[s+1].sumsize;
}




// find type of var
int findType(char *name)
{
	int i;
	if ( name == "")
		return 0;
	else
		for(i=0;i<256;++i){	/********************************change from 26**********/
		CurrSymbol=symbTable[i];
		while (CurrSymbol != NULL)
		{
			if (strcmp(name, CurrSymbol->symb) == 0)
				return CurrSymbol->type;
			CurrSymbol=CurrSymbol->next;
		}
	}

}


// pop from stack
int pop()
{
	Stack temp;
	int value;

	if (empty())	
			return 0;						
		
	value = headStack->value;
	if (headStack->prev == NULL)
	{
		free(headStack);
		headStack = 0;
	}
	else
	{
		temp = headStack->prev;
		temp->next = 0;
		headStack = temp;	
	}
		
	return value;						
}




// check if stack empty
int empty()
{
	if (headStack == NULL)
		return 1;
	else		
		return 0;
}


// push in to stack
int push(int n)
{
	int temp1, temp2, flag = 0, error = 0;
	char t1[20],t2[20],t3[20];
	Stack temp;
	
	FILE *txt;
	txt = fopen("outputParser.txt","a");
			
	if ( (n == ADD) || (n == MMIN) || (n == MUL) || (n == DIV) || n == AND || n == OR || n == NOT || n == ASSIGN)
	{
		temp1 = pop();
		temp2 = pop();
		flag = 1;
		
		switch (temp1) 
		{	 
			case INTEGER:
			{
				if (temp2 == INTEGER || temp2 == INTCONST)
				{
					push(INTEGER);
					break;
				}
				error = 1;
				break;
			}
			
			case INTCONST:
			{
				if (temp2 == INTEGER || temp2 == INTCONST ||temp2 == FLOAT || temp2 == REAL || temp2 == REALCONST || temp2 == BOOLEAN)
				{
					push(temp2);
					break;
				}
				error = 1;
				break;
			}
			
			case FLOAT:
			{
				if (temp2 == FLOAT || temp2 == INTCONST)
				{
					push(FLOAT);
					break;
				}
				error = 1;
				break;
			}
			
			case REAL:
			{
				if (temp2 == REAL || temp2 == INTCONST || temp2 == REALCONST)
				{
					push(REAL);
					break;
				}
				error = 1;
				break;
			}
			
			case REALCONST:
			{
				if (temp2 == REAL)
				{
					push(REAL);
					break;
				}
				if (temp2 == REALCONST || temp2 == INTCONST)
				{
					push(REALCONST);
					break;
				}
				error = 1;
				break;
			}
			case BOOLEAN:
			{	
				if (temp2 == BOOLEAN || temp2 == INTCONST)
				{
					push(temp2);
					break;
				}
				error = 1;
				break;
			}
		}				
	}
	if (flag == 1 && error == 1)
	{
		strcpy(t1, print_op(temp1));
		strcpy(t2,print_op(n));
		strcpy(t3 ,print_op(temp2));
		fprintf(txt, "\nError at line %d:  %s  %s %s\n", line_number, t3, t2, t1);
	}
	if (flag == 0)
	{
		temp = (Stack)malloc(sizeof(stack));
		temp->value = n;
		temp->next = 0;
		temp->prev = headStack;
		if (headStack != NULL)
			headStack->next = temp;
		headStack = temp;	
	}
	fclose(txt);
	return 1;	
	
}
