%{ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typedef.h"
#include "bison_file_tab.h" 

extern int line_number; 

FILE *txt;	
int count_newline(char*);

yywrap() {return 1; }

%}

ZERO     [0]
DIGIT    [1-9]

LETTER            [a-zA-Z]
IDE               {LETTER}({LETTER}|{DIGIT})*
HEX_Digit		  [1-9a-fA-F]
HEX_Type		  0x({HEX_Digit}|({ZERO}|({HEX_Digit})*))
OCT_Digit		  [1-7]
OCT_Type		  {ZERO}({OCT_Digit}|({ZERO}|({OCT_Digit})*))
INT               {ZERO}|({DIGIT}({ZERO}|{DIGIT})*)
SCALE             E("+"|"-")?{INT}
REAL              {INT}?"."{INT}+{SCALE}?
STRING            \"(\\.|[^\\"])*\"
COMMENT           \(\*[^\*]*\*+([^\*\)][^\*]*\*+)*\)
SIGN              (":"|";"|"("|")"|"."|","|"["|"]")
POINTER			   {IDE}\^
ADDRESS			   @{IDE}


%%

CONST        {return(CONST);    }
TYPE         {return(TYPE);     }
VAR          {return(VAR);      }
AND          {return(AND);      }
OR           {return(OR);       }
ARRAY        {return(ARRAY);    }
RECORD       {return(RECORD);   }
BEGIN        {return(BBEGIN);   }
BOOLEAN      {return(BOOLEAN);  }
DECLARE      {return(DECLARE);  }
FOR          {return(FOR);      }
FROM         {return(FROM);     }
BY           {return(BY);       }
TO           {return(TO);       }
FIN          {return(FIN);      }
IDENTICAL    {return(IDENTICAL);}
ELSE         {return(ELSE);     }
END          {return(END);      }
FALSE        {return(FALSE);    }
GOTO         {return(GOTO);     }
IF           {return(IF);       }
FI           {return(FI);       }
DO           {return(DO);       }
OD           {return(OD);       }
CASE         {return(CASE);     }
INTEGER      {return(INTEGER);  }
LABEL        {return(LABEL);    }
NOT          {return(NOT);      }
OF           {return(OF);       }
PROCEDURE    {return(PROCEDURE);}
PROGRAM      {return(PROGRAM);  }
READ         {return(READ);     }
FLOAT        {return(FLOAT);    }
REPEAT       {return(REPEAT);   }
THEN         {return(THEN);     }
TRUE         {return(TRUE);     }
WHILE        {return(WHILE);    }
<<<<<<< HEAD
RCD		 	 {return(RCD)};		}
=======
>>>>>>> FETCH_HEAD

{IDE}          { yylval.string = (char*) malloc(strlen(yytext)+1);
               strcpy(yylval.string,yytext); return(IDE); }
{POINTER}      {yylval.string = (char*) malloc(strlen(yytext)+1);
               strcpy(yylval.string,yytext); return(POINTER); }
{INT}          { 
				char buf[32];
				itoa(INT_MAX, buf, 10);
					if (atoi(yytext)==INT_MAX)
						if(strcmp(yytext,buf)> 0)
						{	
							txt=fopen("lexError.txt","a");
							fprintf(txt,"number exceeds MAX_INT '%s'!\n",yytext);
							fclose(txt);
							/*exit(-1);*/
						}					
					yylval.integer = atoi(yytext);
					if (yylval.integer)  return(INTCONST); 
			   }
{HEX_Type}     { yylval.integer = strtol(yytext + 2, NULL, 16); return(INTCONST); }
{OCT_Type}     { yylval.integer = strtol(yytext , NULL, 8); return(INTCONST); }
{REAL}         { yylval.real = atof(yytext); return(REALCONST); }
{STRING}       { yylval.string = (char*) malloc(strlen(yytext)+1);
                strcpy(yylval.string,yytext); return(STRING); }
{COMMENT}      { line_number += count_newline(yytext); }
"+"            { return(ADD); }
"-"            { return(MMIN); }
"*"            { return(MUL); }
"/"            { return(DIV); }
"%"            { return(MOD); }
"<"            { return(LES); }
"<="           { return(LEQ); }
"=="           { return(EQU); }
"/="           { return(NEQ); }
">"            { return(GRE); }
">="           { return(GEQ); }
"&"            { return(AND); }
"|"            { return(OR); }
"="            { return(ASSIGN); } 
"{"            { return(LC); } 
"}"            { return(RC); } 
{SIGN}         { return(yytext[0]); }
"\n"           { line_number++; }
[\t\f\ ]+
.              { 
				txt=fopen("lexError.txt","a");
	            fprintf(txt,"unexpected char '%c'!\n",yytext[0]);
				fclose(txt);
	            exit(-1); 
	           }
%%

int count_newline(char *text)

{ unsigned int i;
  int counter;

  counter = 0;
  for (i=0;i<strlen(text);i++)
      { if (text[i] == '\n')
	   counter++;
      }
  return(counter);
}


