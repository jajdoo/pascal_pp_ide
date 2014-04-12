
#ifndef _GLOBALS_H__
#define _GLOBALS_H__

#include <stdio.h>

#include "typedef.h"

static int n;
static int s;
static int o;
arrLST *lst;
NODE tmp1;
NODE tmp2;

arrList arrRoot;
NODE root;
extern int line_number;		// in bison_file.y


int yylex(void);
FILE *treefile;

#define yyerror(x) { FILE *txt; txt=fopen("yyerror.txt","w"); fprintf(txt,"%s in line %d\n",x,line_number);}


#endif