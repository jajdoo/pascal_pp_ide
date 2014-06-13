
%{
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

#include "globals.h"
#include "typedef.h"
#include "parse_tree.h"
#include "struct_def.h"
#include "symbol_table.h"
#include "context.h"

int line_number = 1;

%}

%token PROGRAM PROCEDURE BBEGIN END DECLARE PROCEDURE LABEL INTEGER FLOAT REAL CMP
%token BOOLEAN ARRAY OF ASSIGN LC RC IF THEN ELSE FI THEN WHILE REPEAT DO OD 
%token READ WRITE TRUE FALSE ADD MMIN MUL DIV GOTO
%token MOD LES LEQ EQU NEQ GRE GEQ AND OR
%token AND OR NOT CASE FOR FIN IDENTICAL FROM BY TO CONST TYPE VAR RECORD

%token STRUCT CAST STATEMENT DECLARATION

%token<code> INTCONST 
%token<string> IDE 
%token<string> POINTER
%token<real> REALCONST
%token<string> STRING
%token<integer> INTEGER
%token<boolean> BOOLEAN
%token<float> FLOAT

%type<node> var assign program procedure stat_seq loop_stat case_stat bracket 
%type<node> expr atom block stat nonlable_stat cond_stat case case_list 
%type<node> declaration dec_or_stat
%type<code> brk 

%nonassoc LES LEQ EQU NEQ GRE GEQ
%left ADD MMIN OR
%left MUL DIV AND MOD
%right NOT DUMMY


%start  program

%%

program:	PROGRAM IDE block				{$$=makenode(PROGRAM,$3,NULL,NULL,0,$2); root=$$;} 					
       ;

/*************************************************************************/
/*                          STRUCT DECLARATION                           */
/*-----------------------------------------------------------------------*/

struct_decl:  STRUCT IDE LC member_decl RC ';'					{addToSymbolTable($2,$2); post_struct_def(); } ;

member_decl:  STRUCT IDE										{set_current_struct_name($2);} 
			  ':' memberList ';'								{clear_current_struct(); }
			  member_decl_tail
			| VAR tyList ':' memberList ';' member_decl_tail	{printf("member_primitive_decl_1->");}
			;

member_decl_tail: member_decl | ;

memberList:		struct_member ',' memberList			{printf("memberList_1->");}
			|	struct_member							{printf("memberList_2->");}
			;

struct_member : 
			  IDE					{ new_struct_member($1, 1, 0, NULL); }
			| POINTER				{ new_struct_member($1, 1, 0, NULL); }
			| IDE dim				{ printf("struct_member(dim)->"); }
			;

dim: '[' INTCONST ']' dim_tail		{printf("dim_1\n");}
			;

dim_tail: dim | ;
/*-----------------------------------------------------------------------*/
/*************************************************************************/


block :	  LC dec_or_stat RC				{$$=makenode(BBEGIN,NULL,NULL,NULL,0,NULL);} 
       ;

dec_or_stat : declaration dec_or_stat	{$$=makenode(DECLARATION,NULL,NULL,NULL,0,NULL);}
			| stat dec_or_stat			{$$=makenode(STATEMENT,NULL,NULL,NULL,0,NULL);}
			|							{$$=NULL;}
			;

declaration:	procedure			{}
			 |  struct_decl			{}
			 |  VAR varAss			{}
			 |	STRUCT IDE			{set_current_struct_name($2);} 
				':' idList ';'		{clear_current_struct();} 
				;


/*************************************************************************/
/*                          PROCEDURE DECLARATION                        */
/*-----------------------------------------------------------------------*/
procedure : PROCEDURE IDE '(' param_decl ')' 	{enter_block($2); printf("entering conext %s\n", $2);} 
			block ';'							{ printSymbolTable(); exit_block(); printf("exiting conext\n");} 
			;

param_decl :	STRUCT IDE ':' param param_decl_tail	{ printf("param_decl_1->"); }
			|	VAR tyList ':' param param_decl_tail	{ printf("primitive_param_decl_1->"); }
			| ;

param_decl_tail: ',' member_decl | ;

param :		  IDE					{ printf("ide->"); }
			| POINTER				{ printf("pointer->"); }
			;
/*-----------------------------------------------------------------------*/
/*************************************************************************/

varAss: tyList ':' idList varAss		{} 
	|
	';'{}
	;

idList: IDE 	{addToSymbolTable($1,$1);}idList
     |POINTER 	{addToSymbolTable($1,$1);}idList
	|   IDE '[' INTCONST ']' 
	{
		s=1;

	} 
	brk 
	{ 
		lst[s-o].size=$3;/* calcultes size of each dimentiob*/
		lst[s-o].sumsize=n*$3;/* sum of array*/
		
		addToSymbolTable($1,$1);
		// addToSymbolTable($1,n*$3,s,lst);
	}
	idList
	|',' IDE idList {addToSymbolTable($2,$2);}
	|',' POINTER idList {addToSymbolTable($2,$2);}
	|',' IDE '[' INTCONST ']'
	{
		s=1;

	} 
	brk 
	{ 
		lst[s-o].size=$4;/* calcultes size of each dimentiob*/
		lst[s-o].sumsize=n*$4;/* sum of array*/
		

		addToSymbolTable($2,$2);
		//addToSymbolTable($2,n*$4,s,lst);
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
	
	
stat_seq:  stat                       {$$=makenode(STATEMENT,$1,NULL,NULL,0,NULL);} 
         | stat stat_seq              {$$=makenode(STATEMENT,$1,$2,NULL,0,NULL);} 
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


var:
	IDE '.' struct_acc_tail			{ printf("struct_acc->"); }					
	| IDE							{ $$ = genLeaf(IDE,0,0,$1);}
	| POINTER						{$$ = genLeaf(POINTER,0,0,$1);}
    | IDE '[' expr ']'				{s=0; /*lst=findSymbol($1)->lst;*/} 
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
			/*if (n!=findSymbol($1)->IS_ARRAY ) 
			{
				fprintf(txt,"\nError at line %d: Assign problem %s: %d!=%d.",line_number, $1,n,findSymbol($1)->IS_ARRAY); 
				fclose(txt);
			}*/
	}
     ;

/*************************************************************************/
/*                             STRUCT access                             */
/*-----------------------------------------------------------------------*/

struct_acc_tail:  IDE 										{printf("struct_tail->");}
				| IDE '.' struct_acc_tail					{printf("\n");}
		; 

/*-----------------------------------------------------------------------*/
/************************************************************************/


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
      | '(' expr ')'            { $$ = $2; }
	  |  tyList '(' expr ')'	{ $$ = makenode(CAST,$3,NULL,NULL,0,NULL); }
      | NOT atom                { $$ = makenode(NOT,$2,NULL,NULL,0,NULL); }
      | atom                    { $$ = $1; }
      ;


atom:   var                        { $$ = $1; }
      | INTCONST                   { $$ = genLeaf(INTCONST,$1,0,NULL); }
      | REALCONST                  { $$ = genLeaf(REALCONST,0,$1,NULL);}
      | TRUE                       { $$ = genLeaf(TRUE,0,0,NULL); }
      | FALSE                      { $$ = genLeaf(FALSE,0,0,NULL); }
      
      ;

%%