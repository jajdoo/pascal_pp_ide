
#ifndef _GLOBALS_H__
#define _GLOBALS_H__

#include <stdio.h>

#include "typedef.h"

int currentType;

static int n;
static int s;
static int o;
arrLST *lst;

arrList arrRoot;

extern int line_number;		// in bison_file.y


int yylex(void);
FILE *treefile;

#define yyerror(x) { FILE *txt; txt=fopen("yyerror.txt","w"); fprintf(txt,"%s in line %d\n",x,line_number);}


#endif