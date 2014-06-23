
%{
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

#include "globals.h"
#include "typedef.h"
#include "parse_tree.h"
#include "symbol_table.h"
#include "symbol.h"
#include "proc_call.h"
#include "struct_acc.h"

int line_number = 1;

%}

%token PROGRAM PROCEDURE BBEGIN END DECLARE PROCEDURE LABEL INTEGER FLOAT REAL CMP
%token BOOLEAN ARRAY OF ASSIGN LC RC IF THEN ELSE FI THEN WHILE REPEAT DO OD 
%token READ WRITE TRUE FALSE ADD MMIN MUL DIV GOTO
%token MOD LES LEQ EQU NEQ GRE GEQ AND OR
%token AND OR NOT CASE FOR FIN IDENTICAL FROM BY TO CONST TYPE VAR RECORD

%token STRUCT CAST STATEMENT DECLARATION BLOCK_BODY PROC_CALL ARGUMENT_LIST STRUCT_ACC

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
%type<node> declaration dec_or_stat struct_decl proc_call args args_tail struct_acc struct_acc_tail
%type<integer> type_list

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

struct_decl:  
			STRUCT IDE				
			{
				symbol_new();
				symbol_set_isstruct(1);
				symbol_set_name($2);
				symbol_set_address(-1);
				symbol_set_type(0); 
				symbol_finish();
				enter_block($2);
			} 
			LC member_decl RC ';'	
			{
				exit_block();
			} 
;


member_decl :
	VAR												
	{  
		symbol_new();
		symbol_set_isstructmember(1);
	}
	type_list ':' member_id_list ';' member_decl_tail	{ }
|
	STRUCT IDE ':' IDE ';'
	{
		symbol_new();
		symbol_set_isstructmember(1);
		if(symbol_set_struct_type($2))
		{
			symbol_set_name($4);
			symbol_finish();
		}
		else
			symbol_cancel();
	}
;


member_decl_tail	:
						member_decl	{}
					|				{}
;

member_id_list: 
		IDE
		{
			symbol_set_name($1); 
			symbol_finish();
		}
;

/*-----------------------------------------------------------------------*/
/*************************************************************************/


block :	  LC dec_or_stat RC				{$$=makenode(BBEGIN,$2,NULL,NULL,0,NULL);} 
;


dec_or_stat : 
				procedure	dec_or_stat	{$$=makenode(BLOCK_BODY,$1,$2,NULL,0,NULL);}
			|	stat		dec_or_stat	{$$=makenode(BLOCK_BODY,$1,$2,NULL,0,NULL);}
			|	proc_call	dec_or_stat	{$$=makenode(BLOCK_BODY,$1,$2,NULL,0,NULL);}
			|	declaration	dec_or_stat	{$$=$2;}
			|							{$$=NULL;}
;


declaration:    
				struct_decl		{ $$ = NULL; }
			 |  struct_def		{ $$ = NULL; }
			 |  var_decl		{ $$ = NULL; }
;

struct_def:
			STRUCT IDE ':' IDE ';'
			{
				symbol_new();
				if(symbol_set_struct_type($2))
				{
					symbol_set_name($4);
					symbol_finish();
				}
				else
					symbol_cancel();
			}
;

var_decl :
			VAR							{ symbol_new(); }
			type_list ':' id_list ';'	{ }
;
 

type_list:
		BOOLEAN		{ symbol_set_type(BOOLEAN); }
	|	INTEGER		{ symbol_set_type(INTEGER); }
	|	FLOAT		{ symbol_set_type(FLOAT); }
;


id_list: 
		IDE 		
		{
			symbol_set_name($1); 
			symbol_finish();
		} 
     |	
		POINTER 	
		{
			//symbol_stack_set_ispointer(1);
			//symbol_stack_set_name($1);
			//symbol_stack_pop();
		} 
;

/*************************************************************************/
/*                          PROCEDURE DECLARATION                        */
/*-----------------------------------------------------------------------*/
procedure : 
			PROCEDURE IDE  	
			{
				symbol_new();
				symbol_set_name($2);
				symbol_set_isprocedure(1);
				symbol_finish();
				enter_block($2);
				//printf("entering context %s\n", $2);
			} 
			'(' param_decl ')' block ';'
			{
				//printSymbolTable();
				exit_block();

				//printf("exiting context\n"); 
				$$ = makenode(PROCEDURE, $7, NULL, NULL, 0, NULL);
			}
;

param_decl :
			param param_decl_tail { }
			|					  { }
;

param: 
	VAR											
	{ 
		symbol_new();
		symbol_set_isparam(1);
	}
	type_list ':' param_id_list
;

param_decl_tail	:
	',' param param_decl_tail	{}
				|				{}
;

param_id_list: 
	IDE
	{
		symbol_set_name($1);
		symbol_finish();
	}
;

/*----------------------------------------------------------------------*/
/*************************************************************************/


/*************************************************************************/
/*                          PROCEDURE CALL                               */
/*----------------------------------------------------------------------*/



proc_call : 
	IDE 
	{
		
		proc_call_setproc($1);
	}
	'(' args ')' ';'
	{ 
		proc_call_finish();
		if( proc_call_valid())
			$$ = makenode(PROC_CALL,$4,NULL,NULL,0,NULL);
		else
			$$ = NULL;
	}
;


args : 
		expr		{ proc_call_validate_arg($1->type); }
		args_tail	{ $$ = makenode(ARGUMENT_LIST,$1,$3,NULL,0,NULL); }
	|				{ $$ = NULL;}
;

args_tail :
		',' expr	{ proc_call_validate_arg($2->type); }
		args_tail	{ $$ = makenode(ARGUMENT_LIST,$2,$4,NULL,0,NULL); }
	|				{ $$ = NULL; }
;


/*----------------------------------------------------------------------*/
/*************************************************************************/
	
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
	struct_acc						{ $$ = $1; }			
	| IDE							{ $$ = genLeaf(IDE,0,0,$1); }
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

struct_acc: 
	IDE
	{
		struct_acc_start($1);
	}
	'.' struct_acc_tail
	{
		if( struct_acc_valid() )
		{
			NODE left = makenode(IDE, NULL, NULL, NULL, 0, $1);
			$$ = makenode(STRUCT_ACC, left, $4, NULL, 0, NULL);
		}
		else 
			$$ = $4;
	}
;

struct_acc_tail: 
	IDE 
	{
		struct_acc_next($1);
		
		if( struct_acc_valid() )
			$$ = makenode(IDE, NULL, NULL, NULL, 0, $1);
		else 
			$$ = NULL;

		struct_acc_finish();
	}
|	
	IDE
	{
		struct_acc_next($1);
	} 
	'.' struct_acc_tail 
	{
		if( struct_acc_valid() )
		{
			NODE left = makenode(IDE, NULL, NULL, NULL, 0, $1);
			$$ = makenode(STRUCT_ACC, left, $4, NULL, 0, NULL);
		}
		else 
			$$ = $4;
	}
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
	  |  type_list '(' expr ')'	{ $$ = makenode(CAST,$3,NULL,NULL,0,NULL); }
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