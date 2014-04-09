
%{
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
#include "typedef.h"
#define yyerror(x) { FILE *txt; txt=fopen("yyerror.txt","w"); fprintf(txt,"%s in line %d\n",x,line_number);}

static int n;
static int s;
static int o;
arrLST *lst;
NODE tmp1;
NODE tmp2;

//  The symbol table - hash table of 26 enteries (alphabetical) of Symbols
//	Remember : each symbol has a pointer to the next one. See decleration in typedef.h 
struct Symbol *symbTable[26];//a cell is pointer to first symbol
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
char* print_op(int op);
%}

%token PROGRAM BBEGIN END DECLARE PROCEDURE LABEL INTEGER FLOAT REAL CMP
%token BOOLEAN ARRAY OF ASSIGN LC RC IF THEN ELSE FI THEN WHILE REPEAT DO OD 
%token READ WRITE TRUE FALSE ADD MMIN MUL DIV GOTO
%token MOD LES LEQ EQU NEQ GRE GEQ AND OR
%token AND OR NOT CASE FOR FIN IDENTICAL FROM BY TO CONST TYPE VAR RECORD

%token STRUCT

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

program:	PROGRAM IDE block				{$$=makenode(PROGRAM,$3,NULL,NULL,0,$2); root=$$;} 					
       ;

block :LC struct_decl declarations stat_seq RC       {$$=makenode(BBEGIN,$4,NULL,NULL,0,NULL);} 
		| LC RC										 {$$=makenode(BBEGIN,NULL,NULL,NULL,0,NULL);} 
       ;



struct_decl: STRUCT IDE LC member_decl RC ';' ;

member_decl:  VAR tyList ':' memberList ';' member_decl {printf("member_decl_1->");}
			| VAR tyList ':' memberList ';'				{printf("member_decl_2->");}
			;

memberList:		single_member ',' memberList			{printf("memberList_1->");}
			|	single_member							{printf("memberList_2->");}
			;

single_member : 
			  IDE			{ printf("single_member(ide)\n"); }
			| POINTER		{ printf("single_member(ptr)\n"); }
			| IDE dim		{ printf("single_member(dim)->"); }
			;

dim: '[' INTCONST ']' dim_tail		{printf("dim_1\n");}
			;
dim_tail: dim | ;


declarations:VAR varAss declarations | ;

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

NODE makenode(int op, NODE s1, NODE s2, NODE s3,int val,char *id)
{  
	NODE t;
	FILE *txt;

	t= (NODE )malloc(sizeof(struct node));
	t->num_val.val=val;

	if(op==CASE)
		t->s1=genLeaf(INTCONST,val,0,NULL);
	else
		t->s1 = s1;
	
	t->s2 = s2;	
	t->s3 = s3;

	t->name = (id != NULL) ? id : "";

	// counting children 
	t->children = 0;
	if (t->s1!=NULL) t->children++;
	if (t->s2!=NULL) t->children++;
	if (t->s3!=NULL) t->children++;

	t->op=op;

	if ( op==ADD || op==MMIN || op==MUL || op==DIV || op==AND || op==OR || op==NOT || op==ASSIGN )
	{
		if( t->s1->type == t->s2->type )
			t->type = t->s1->type;
		else
		{
			txt = fopen("outputParser.txt","a");

			printf("\nError at line %d:  %s  %s %s\n", line_number, print_op(t->s2->type), print_op(op), print_op(t->s1->type) );
			fprintf(txt, "\nError at line %d:  %s  %s %s\n", line_number, print_op(t->s2->type), print_op(op), print_op(t->s1->type));
		}
	}

	return(t);
}


NODE genLeaf(int op, int val, double rval,char *id)
{
	NODE t;
	struct Symbol* s;

	if(id != NULL&&!findSymbol(id))
	{
		FILE *txt; 
		txt=fopen("outputParser.txt","a");
		fprintf(txt,"\nError at line %d: Undeclared identifier: %s",line_number,id);
		fclose(txt);
		exit(1);
	}
	
	t= (NODE )malloc(sizeof(struct node));
	t->num_val.val=val;
	
	t->op = op;
	
	if(id != NULL) 
           t->name=id;  
	else	       
		   t->name="";

	t->s1 = NULL;
	t->s2 = NULL;
	t->s3 = NULL;
	t->children=0;
	
	switch(op)
	{
		case IDE:
			t->type = findSymbol(id)->type;
			break;

		case INTCONST:
			t->type = INTEGER;
			t->num_val.val = val;
			break;

		case REALCONST:
			t->type = FLOAT;
			t->num_val.rval = rval;
			break;

		case TRUE:
		case FALSE:
			t->type = BOOLEAN;
		break;
	}
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
		  return ("UNKNOWN");
	}     
	fclose(txt);
}

void print_tree(NODE r, int s)
{ 
  
	if(r != NULL) 
	{ 
		fprintf(treefile,"type=%s\n", print_op(r->op));
		fprintf(treefile,"children=%d\n", r->children);
		if(r->name) fprintf(treefile,"my check == = = ==> %s\n",r->name);
		if(r->op == IDE) fprintf(treefile,"string=%s\n",r->name);
		if(r->op ==INTCONST)  fprintf(treefile,"int value=%d\n", r->num_val.val); 
		if(r->op==REALCONST) fprintf(treefile,"real value=%f\n", r->num_val.rval);
		
		fprintf( treefile, "node type: %s\n\n", print_op(r->type) );

		if(r->s1!=NULL)
		{
			fprintf(treefile,"| Son1 of %s\n",print_op(r->op));
			fprintf(treefile,"|\n");
			fprintf(treefile,"---------------\n");
			print_tree(r->s1,s+2);
		} 
	  
	           
		if(r->s2!=NULL)
		{
			fprintf(treefile,"| Son2 of %s\n",print_op(r->op));
			fprintf(treefile,"|\n");
			fprintf(treefile,"---------------\n");
			print_tree(r->s2, s+2);
	
		}
 
		if(r->s3!=NULL)
		{
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

void addToSymbolTable( char *IDEName, int size, int IS_ARRAY, arrList lst )
{
	FILE *txt;
	txt=fopen("outputParser.txt","a");
	int l,isPointer=0;
	struct Symbol* newSymb; 
	
	//fprintf(txt,"Info at line %d: adding to symbol table: %s \n",line_number,IDEName);
	if(size<=0)
	{
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

int getTableEntry (char *IDEName)
{	
	if (islower(IDEName[0]))
		return (IDEName[0] - 'a');
	else
		return (IDEName[0] - 'A');
}



//zero all cells i.e. NULL all the pointers
void InitializeTable(void){
int i;
	TableInitialized=1;
	
	for(i=0;i<26;++i)
		symbTable[i]=NULL;

}

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
	for(i=0;i<26;++i){	
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
		for(i=0;i<26;++i){	
		CurrSymbol=symbTable[i];
		while (CurrSymbol != NULL)
		{
			if (strcmp(name, CurrSymbol->symb) == 0)
				return CurrSymbol->type;
			CurrSymbol=CurrSymbol->next;
		}
	}

}