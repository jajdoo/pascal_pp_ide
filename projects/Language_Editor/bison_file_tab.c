
/*  A Bison parser, made from bison_file.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	PROGRAM	258
#define	BBEGIN	259
#define	END	260
#define	DECLARE	261
#define	PROCEDURE	262
#define	LABEL	263
#define	INTEGER	264
#define	FLOAT	265
#define	REAL	266
#define	CMP	267
#define	BOOLEAN	268
#define	ARRAY	269
#define	OF	270
#define	ASSIGN	271
#define	LC	272
#define	RC	273
#define	IF	274
#define	THEN	275
#define	ELSE	276
#define	FI	277
#define	WHILE	278
#define	REPEAT	279
#define	DO	280
#define	OD	281
#define	READ	282
#define	WRITE	283
#define	TRUE	284
#define	FALSE	285
#define	ADD	286
#define	MMIN	287
#define	MUL	288
#define	DIV	289
#define	GOTO	290
#define	MOD	291
#define	LES	292
#define	LEQ	293
#define	EQU	294
#define	NEQ	295
#define	GRE	296
#define	GEQ	297
#define	AND	298
#define	OR	299
#define	NOT	300
#define	CASE	301
#define	FOR	302
#define	FIN	303
#define	IDENTICAL	304
#define	FROM	305
#define	BY	306
#define	TO	307
#define	CONST	308
#define	TYPE	309
#define	VAR	310
#define	RECORD	311
#define	STRUCT	312
#define	INTCONST	313
#define	IDE	314
#define	POINTER	315
#define	REALCONST	316
#define	STRING	317
#define	DUMMY	318

#line 2 "bison_file.y"

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
#include "typedef.h"
#include "struct_def.h"
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

void print_struct_members( FILE* f, char* struct_name, struct Symbol* members );


#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		179
#define	YYFLAG		-32768
#define	YYNTBASE	72

#define YYTRANSLATE(x) ((unsigned)(x) <= 318 ? yytranslate[x] : 112)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    70,
    71,     2,     2,    66,     2,    69,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    65,    64,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    67,     2,    68,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,    10,    13,    20,    27,    33,    37,    39,    41,
    43,    46,    51,    53,    54,    58,    65,    66,    70,    72,
    74,    76,    79,    84,    86,    87,    91,    92,    96,    97,
    98,   107,   111,   115,   116,   117,   127,   128,   129,   135,
   136,   138,   140,   142,   144,   146,   149,   151,   154,   156,
   158,   160,   164,   170,   178,   184,   191,   193,   196,   200,
   204,   206,   208,   209,   216,   218,   222,   223,   229,   230,
   232,   236,   240,   244,   248,   252,   256,   260,   264,   268,
   272,   276,   280,   284,   288,   291,   293,   295,   297,   299,
   301
};

static const short yyrhs[] = {     3,
    59,    73,     0,    17,    74,    80,    95,    18,     0,    17,
    18,     0,    57,    59,    17,    75,    18,    64,     0,    55,
    94,    65,    76,    64,    75,     0,    55,    94,    65,    76,
    64,     0,    77,    66,    76,     0,    77,     0,    59,     0,
    60,     0,    59,    78,     0,    67,    58,    68,    79,     0,
    78,     0,     0,    55,    83,    80,     0,    57,    59,    65,
    81,    64,    80,     0,     0,    82,    66,    81,     0,    82,
     0,    59,     0,    60,     0,    59,    78,     0,    94,    65,
    84,    83,     0,    64,     0,     0,    59,    85,    84,     0,
     0,    60,    86,    84,     0,     0,     0,    59,    67,    58,
    68,    87,    91,    88,    84,     0,    66,    59,    84,     0,
    66,    60,    84,     0,     0,     0,    66,    59,    67,    58,
    68,    89,    91,    90,    84,     0,     0,     0,    67,    58,
    68,    92,    91,     0,     0,    93,     0,    13,     0,     9,
     0,    10,     0,    96,     0,    96,    95,     0,    97,     0,
    98,    64,     0,    99,     0,   100,     0,   101,     0,   104,
    16,   110,     0,    19,   110,    20,    95,    22,     0,    19,
   110,    20,    95,    21,    95,    22,     0,    23,   110,    25,
    95,    26,     0,    46,   110,    15,    17,   102,    18,     0,
   103,     0,   103,   102,     0,    58,    65,    95,     0,    59,
    69,   106,     0,    59,     0,    60,     0,     0,    59,    67,
   110,    68,   105,   107,     0,    59,     0,    59,    69,   106,
     0,     0,    67,   110,    68,   108,   107,     0,     0,   109,
     0,   110,    31,   110,     0,   110,    32,   110,     0,   110,
    33,   110,     0,   110,    34,   110,     0,   110,    36,   110,
     0,   110,    37,   110,     0,   110,    38,   110,     0,   110,
    39,   110,     0,   110,    40,   110,     0,   110,    41,   110,
     0,   110,    42,   110,     0,   110,    43,   110,     0,   110,
    44,   110,     0,    70,   110,    71,     0,    45,   111,     0,
   111,     0,   104,     0,    58,     0,    61,     0,    29,     0,
    30,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    75,    78,    79,    85,    87,    88,    91,    92,    95,    97,
    98,   101,   104,   104,   108,   109,   110,   115,   116,   119,
   120,   121,   125,   126,   130,   131,   131,   132,   132,   138,
   145,   145,   146,   147,   153,   160,   160,   163,   166,   174,
   175,   183,   184,   186,   191,   192,   196,   199,   200,   201,
   202,   205,   208,   209,   212,   215,   218,   219,   221,   224,
   226,   227,   228,   230,   250,   251,   256,   259,   268,   268,
   271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
   281,   282,   283,   284,   286,   287,   291,   292,   293,   294,
   295
};

static const char * const yytname[] = {   "$","error","$undefined.","PROGRAM",
"BBEGIN","END","DECLARE","PROCEDURE","LABEL","INTEGER","FLOAT","REAL","CMP",
"BOOLEAN","ARRAY","OF","ASSIGN","LC","RC","IF","THEN","ELSE","FI","WHILE","REPEAT",
"DO","OD","READ","WRITE","TRUE","FALSE","ADD","MMIN","MUL","DIV","GOTO","MOD",
"LES","LEQ","EQU","NEQ","GRE","GEQ","AND","OR","NOT","CASE","FOR","FIN","IDENTICAL",
"FROM","BY","TO","CONST","TYPE","VAR","RECORD","STRUCT","INTCONST","IDE","POINTER",
"REALCONST","STRING","DUMMY","';'","':'","','","'['","']'","'.'","'('","')'",
"program","block","struct_decl","member_decl","memberList","struct_member","dim",
"dim_tail","declarations","strIdeList","structIde","varAss","idList","@1","@2",
"@3","@4","@5","@6","brk","@7","@8","tyList","stat_seq","stat","nonlable_stat",
"assign","cond_stat","loop_stat","case_stat","case_list","case","var","@9","struct_acc_tail",
"bracket","@10","@11","expr","atom",""
};
#endif

static const short yyr1[] = {     0,
    72,    73,    73,    74,    75,    75,    76,    76,    77,    77,
    77,    78,    79,    79,    80,    80,    80,    81,    81,    82,
    82,    82,    83,    83,    85,    84,    86,    84,    87,    88,
    84,    84,    84,    89,    90,    84,    84,    92,    91,    93,
    91,    94,    94,    94,    95,    95,    96,    97,    97,    97,
    97,    98,    99,    99,   100,   101,   102,   102,   103,   104,
   104,   104,   105,   104,   106,   106,   108,   107,   109,   107,
   110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
   110,   110,   110,   110,   110,   110,   111,   111,   111,   111,
   111
};

static const short yyr2[] = {     0,
     3,     5,     2,     6,     6,     5,     3,     1,     1,     1,
     2,     4,     1,     0,     3,     6,     0,     3,     1,     1,
     1,     2,     4,     1,     0,     3,     0,     3,     0,     0,
     8,     3,     3,     0,     0,     9,     0,     0,     5,     0,
     1,     1,     1,     1,     1,     2,     1,     2,     1,     1,
     1,     3,     5,     7,     5,     6,     1,     2,     3,     3,
     1,     1,     0,     6,     1,     3,     0,     5,     0,     1,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     2,     1,     1,     1,     1,     1,
     1
};

static const short yydefact[] = {     0,
     0,     0,     0,     1,     3,     0,    17,     0,     0,     0,
     0,     0,    43,    44,    42,    24,    17,     0,     0,     0,
     0,     0,    61,    62,     0,    45,    47,     0,    49,    50,
    51,     0,     0,     0,    15,    37,     0,    90,    91,     0,
    88,    89,     0,    87,     0,    86,     0,     0,     0,     0,
     2,    46,    48,     0,     0,     0,    25,    27,     0,     0,
    20,    21,     0,    19,    85,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    65,    60,    52,     0,     4,     0,    37,
    37,    37,    37,    23,     0,    22,    17,     0,    84,     0,
    71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,     0,     0,    63,     0,     9,    10,     0,
     8,     0,    26,    28,     0,    32,    33,     0,    16,    18,
     0,    53,    55,     0,     0,    57,    69,    66,    11,     6,
     0,    29,     0,    14,     0,     0,    56,    58,     0,    64,
    70,     5,     7,    40,    34,    13,    12,    54,    59,     0,
     0,    30,    41,    40,    67,     0,    37,    35,    69,    38,
    31,    37,    68,    40,    36,    39,     0,     0,     0
};

static const short yydefgoto[] = {   177,
     4,     7,    34,   120,   121,    96,   157,    11,    63,    64,
    17,    60,    90,    91,   154,   167,   164,   172,   162,   174,
   163,    18,    25,    26,    27,    28,    29,    30,    31,   135,
   136,    44,   137,    85,   150,   169,   151,    45,    46
};

static const short yypact[] = {     1,
   -47,    11,    -2,-32768,-32768,   -41,     6,    24,     4,     0,
   -17,    -8,-32768,-32768,-32768,-32768,     6,    21,    22,   -10,
   -10,   -10,   -35,-32768,    44,   -17,-32768,    30,-32768,-32768,
-32768,    53,    13,    70,-32768,   -21,    -6,-32768,-32768,    95,
-32768,-32768,   -10,-32768,   159,-32768,   179,   144,   -10,    60,
-32768,-32768,-32768,   -10,    61,    54,    64,-32768,     5,     4,
    65,-32768,    63,    67,-32768,    59,   -17,   -10,   -10,   -10,
   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
   -17,   117,    73,    82,-32768,   129,     7,-32768,    78,   -21,
   -21,    62,   -21,-32768,    99,-32768,     6,    -6,-32768,    15,
    -3,    -3,-32768,-32768,-32768,   193,   193,   193,   193,   193,
   193,-32768,    -3,   132,   131,-32768,    60,    65,-32768,   100,
   128,   137,-32768,-32768,   148,-32768,-32768,   139,-32768,-32768,
   -17,-32768,-32768,   143,   191,   131,   147,-32768,-32768,    -8,
     7,-32768,   160,    65,   216,   -17,-32768,-32768,   -10,-32768,
-32768,-32768,-32768,   172,-32768,-32768,-32768,-32768,-32768,   106,
   182,-32768,-32768,   172,-32768,   173,   -21,-32768,   147,-32768,
-32768,   -21,-32768,   172,-32768,-32768,   242,   243,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,   104,   105,-32768,  -117,-32768,   -12,   149,-32768,
   185,   -83,-32768,-32768,-32768,-32768,-32768,-32768,  -153,-32768,
-32768,   215,   -23,-32768,-32768,-32768,-32768,-32768,-32768,   113,
-32768,   -11,-32768,   133,    83,-32768,-32768,     3,   211
};


#define	YYLAST		252


static const short yytable[] = {    32,
   139,    20,    52,     1,    35,    21,   123,   124,   126,   127,
   168,     2,    13,    14,    32,     5,    15,     8,    38,    39,
   176,    13,    14,    47,    48,    15,   156,     3,    22,    70,
    71,    49,    72,    50,    40,   131,   132,    57,    58,    79,
    12,    23,    24,   100,    59,    66,    33,    41,    23,    24,
    42,    83,    61,    62,     6,    32,    86,   114,    19,    43,
     9,    51,    10,    92,    93,   118,   119,    16,    54,    32,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   171,   129,    36,    37,    56,   175,    68,
    69,    70,    71,    53,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    68,    69,    70,    71,   145,    72,    73,
    74,    75,    76,    77,    78,    79,    80,    88,    84,    32,
    57,    58,   159,    38,    39,    87,    97,    59,   125,    99,
    89,    95,    98,   115,    32,   122,    68,    69,    70,    71,
   116,    72,    73,    74,    75,    76,    77,    78,    79,    80,
   117,   160,    41,    23,    24,    42,   128,   133,    82,    68,
    69,    70,    71,   140,    72,    73,    74,    75,    76,    77,
    78,    79,    80,   165,    68,    69,    70,    71,    67,    72,
    73,    74,    75,    76,    77,    78,    79,    80,   134,    68,
    69,    70,    71,   141,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    81,   142,   143,   144,   146,   147,    68,
    69,    70,    71,   149,    72,    73,    74,    75,    76,    77,
    78,    79,    80,    68,    69,    70,    71,   155,    72,-32768,
-32768,-32768,-32768,-32768,-32768,    79,    80,   158,   161,   166,
   170,   178,   179,   152,    94,   153,   130,    55,   148,   138,
    65,   173
};

static const short yycheck[] = {    11,
   118,    19,    26,     3,    17,    23,    90,    91,    92,    93,
   164,    59,     9,    10,    26,    18,    13,    59,    29,    30,
   174,     9,    10,    21,    22,    13,   144,    17,    46,    33,
    34,    67,    36,    69,    45,    21,    22,    59,    60,    43,
    17,    59,    60,    67,    66,    43,    55,    58,    59,    60,
    61,    49,    59,    60,    57,    67,    54,    81,    59,    70,
    55,    18,    57,    59,    60,    59,    60,    64,    16,    81,
    68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
    78,    79,    80,   167,    97,    65,    65,    18,   172,    31,
    32,    33,    34,    64,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    31,    32,    33,    34,   131,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    64,    59,   131,
    59,    60,   146,    29,    30,    65,    64,    66,    67,    71,
    67,    67,    66,    17,   146,    58,    31,    32,    33,    34,
    68,    36,    37,    38,    39,    40,    41,    42,    43,    44,
    69,   149,    58,    59,    60,    61,    58,    26,    15,    31,
    32,    33,    34,    64,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    68,    31,    32,    33,    34,    20,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    58,    31,
    32,    33,    34,    66,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    25,    68,    58,    68,    65,    18,    31,
    32,    33,    34,    67,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    31,    32,    33,    34,    68,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    22,    67,    58,
    68,     0,     0,   140,    60,   141,    98,    33,   136,   117,
    40,   169
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 196 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 75 "bison_file.y"
{yyval.node=makenode(PROGRAM,yyvsp[0].node,NULL,NULL,0,yyvsp[-1].string); root=yyval.node;;
    break;}
case 2:
#line 78 "bison_file.y"
{yyval.node=makenode(BBEGIN,yyvsp[-1].node,NULL,NULL,0,NULL);;
    break;}
case 3:
#line 79 "bison_file.y"
{yyval.node=makenode(BBEGIN,NULL,NULL,NULL,0,NULL);;
    break;}
case 4:
#line 85 "bison_file.y"
{struct_test_fuck();;
    break;}
case 5:
#line 87 "bison_file.y"
{printf("member_decl_1->");;
    break;}
case 6:
#line 88 "bison_file.y"
{printf("member_decl_2->");;
    break;}
case 7:
#line 91 "bison_file.y"
{printf("memberList_1->");;
    break;}
case 8:
#line 92 "bison_file.y"
{printf("memberList_2->");;
    break;}
case 9:
#line 96 "bison_file.y"
{ new_struct_member(yyvsp[0].string, 1, 0, NULL, 0); /* need to adress if IDE is a struct */ ;
    break;}
case 10:
#line 97 "bison_file.y"
{ printf("struct_member(ptr)\n"); ;
    break;}
case 11:
#line 98 "bison_file.y"
{ printf("struct_member(dim)->"); ;
    break;}
case 12:
#line 101 "bison_file.y"
{printf("dim_1\n");;
    break;}
case 20:
#line 119 "bison_file.y"
{ printf("struct_member(ide)\n"); ;
    break;}
case 21:
#line 120 "bison_file.y"
{ printf("struct_member(ptr)\n"); ;
    break;}
case 22:
#line 121 "bison_file.y"
{ printf("struct_member(dim)->"); ;
    break;}
case 23:
#line 125 "bison_file.y"
{;
    break;}
case 24:
#line 127 "bison_file.y"
{;
    break;}
case 25:
#line 130 "bison_file.y"
{addToSymbolTable(yyvsp[0].string,1,0,NULL,0);;
    break;}
case 27:
#line 131 "bison_file.y"
{addToSymbolTable(yyvsp[0].string,1,0,NULL,0);;
    break;}
case 29:
#line 133 "bison_file.y"
{
		s=1;

	;
    break;}
case 30:
#line 138 "bison_file.y"
{ 
		lst[s-o].size=yyvsp[-3].code;/* calcultes size of each dimentiob*/
		lst[s-o].sumsize=n*yyvsp[-3].code;/* sum of array*/
		
		addToSymbolTable(yyvsp[-5].string,n*yyvsp[-3].code,s,lst,0);
	;
    break;}
case 32:
#line 145 "bison_file.y"
{addToSymbolTable(yyvsp[-1].string,1,0,NULL,0);;
    break;}
case 33:
#line 146 "bison_file.y"
{addToSymbolTable(yyvsp[-1].string,1,0,NULL,0);;
    break;}
case 34:
#line 148 "bison_file.y"
{
		s=1;

	;
    break;}
case 35:
#line 153 "bison_file.y"
{ 
		lst[s-o].size=yyvsp[-3].code;/* calcultes size of each dimentiob*/
		lst[s-o].sumsize=n*yyvsp[-3].code;/* sum of array*/
		
		addToSymbolTable(yyvsp[-5].string,n*yyvsp[-3].code,s,lst,0);
	;
    break;}
case 37:
#line 161 "bison_file.y"
{;
    break;}
case 38:
#line 164 "bison_file.y"
{s=s+1;;
    break;}
case 39:
#line 166 "bison_file.y"
{
			n=n*yyvsp[-3].code; 
			yyval.code=lst; 
			lst[s-o].size=yyvsp[-3].code;/* calcultes size of each dimentiob*/
			lst[s-o].sumsize=n;/* sum of array*/
			
			o=o+1;
		;
    break;}
case 40:
#line 174 "bison_file.y"
{;
    break;}
case 41:
#line 175 "bison_file.y"
{
		n=1;
		o=1;
		lst =(arrLST*)malloc(sizeof(arrLST)*s); 
		
		yyval.code=NULL;
	;
    break;}
case 42:
#line 183 "bison_file.y"
{updateVarType(BOOLEAN);;
    break;}
case 43:
#line 185 "bison_file.y"
{updateVarType(INTEGER);;
    break;}
case 44:
#line 187 "bison_file.y"
{updateVarType(FLOAT);;
    break;}
case 45:
#line 191 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 46:
#line 193 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 47:
#line 196 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 48:
#line 199 "bison_file.y"
{yyval.node=yyvsp[-1].node;;
    break;}
case 49:
#line 200 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 50:
#line 201 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 51:
#line 202 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 52:
#line 205 "bison_file.y"
{yyval.node=makenode(ASSIGN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 53:
#line 208 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 54:
#line 209 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-5].node,yyvsp[-3].node,yyvsp[-1].node,0,NULL);;
    break;}
case 55:
#line 212 "bison_file.y"
{yyval.node=makenode(WHILE,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 56:
#line 215 "bison_file.y"
{yyval.node=makenode(CASESTAT,yyvsp[-4].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 57:
#line 218 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 58:
#line 219 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 59:
#line 221 "bison_file.y"
{yyval.node=makenode(CASE,NULL,yyvsp[0].node,NULL,yyvsp[-2].code,NULL);;
    break;}
case 60:
#line 225 "bison_file.y"
{ printf("struct_acc->"); ;
    break;}
case 61:
#line 226 "bison_file.y"
{ yyval.node = genLeaf(IDE,0,0,yyvsp[0].string);;
    break;}
case 62:
#line 227 "bison_file.y"
{yyval.node = genLeaf(POINTER,0,0,yyvsp[0].string);;
    break;}
case 63:
#line 228 "bison_file.y"
{s=0; lst=findSymbol(yyvsp[-3].string)->lst;;
    break;}
case 64:
#line 230 "bison_file.y"
{ 
		if(n==1)
			{yyval.node = makenode(ADD,genLeaf(IDE,0,0,yyvsp[-5].string),yyvsp[-3].node,NULL,0,"check");}
		else
		{
			tmp1=makenode(ADD,makenode(MUL,yyvsp[-3].node,genLeaf(INTCONST,lst[s+1].sumsize,0,NULL),NULL,0,"check"),yyvsp[0].node,NULL,0,"check");
			yyval.node = makenode(ADD,genLeaf(IDE,0,0,yyvsp[-5].string),tmp1,NULL,0,"check");
		}
			FILE *txt; 
			txt=fopen("outputParser.txt","a");
			if (n!=findSymbol(yyvsp[-5].string)->IS_ARRAY ) 
			{
				fprintf(txt,"\nError at line %d: Assign problem %s: %d!=%d.",line_number, yyvsp[-5].string,n,findSymbol(yyvsp[-5].string)->IS_ARRAY); 
				fclose(txt);
			}
	;
    break;}
case 65:
#line 250 "bison_file.y"
{printf("struct_tail->");;
    break;}
case 66:
#line 251 "bison_file.y"
{printf("\n");;
    break;}
case 67:
#line 257 "bison_file.y"
{s=s+1;;
    break;}
case 68:
#line 259 "bison_file.y"
{	
		/*calculation of array offset*/
		if(n==1)
			yyval.node = makenode(MUL,yyvsp[-3].node,genLeaf(INTCONST,1,0,NULL),NULL,0,"check");
		else
			yyval.node = makenode(ADD,makenode(MUL,yyvsp[-3].node,genLeaf(INTCONST,lst[s+1].sumsize,0,NULL),NULL,0,"check"),yyvsp[0].node,NULL,0,"check");
		n=n+1;
		s=s-1;
	;
    break;}
case 69:
#line 268 "bison_file.y"
{;
    break;}
case 70:
#line 268 "bison_file.y"
{n=1;yyval.node=NULL;
    break;}
case 71:
#line 271 "bison_file.y"
{ yyval.node = makenode(ADD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 72:
#line 272 "bison_file.y"
{ yyval.node = makenode(MMIN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 73:
#line 273 "bison_file.y"
{ yyval.node = makenode(MUL,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 74:
#line 274 "bison_file.y"
{ yyval.node = makenode(DIV,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 75:
#line 275 "bison_file.y"
{ yyval.node = makenode(MOD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 76:
#line 276 "bison_file.y"
{ yyval.node = makenode(LES,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 77:
#line 277 "bison_file.y"
{ yyval.node = makenode(LEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 78:
#line 278 "bison_file.y"
{ yyval.node = makenode(EQU,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 79:
#line 279 "bison_file.y"
{ yyval.node = makenode(NEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 80:
#line 280 "bison_file.y"
{ yyval.node = makenode(GRE,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 81:
#line 281 "bison_file.y"
{ yyval.node = makenode(GEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 82:
#line 282 "bison_file.y"
{ yyval.node = makenode(AND,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 83:
#line 283 "bison_file.y"
{ yyval.node = makenode(OR,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 84:
#line 284 "bison_file.y"
{ yyval.node = yyvsp[-1].node; ;
    break;}
case 85:
#line 286 "bison_file.y"
{ yyval.node =makenode(NOT,yyvsp[0].node,NULL,NULL,0,NULL); ;
    break;}
case 86:
#line 287 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 87:
#line 291 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 88:
#line 292 "bison_file.y"
{ yyval.node = genLeaf(INTCONST,yyvsp[0].code,0,NULL); ;
    break;}
case 89:
#line 293 "bison_file.y"
{ yyval.node = genLeaf(REALCONST,0,yyvsp[0].real,NULL);;
    break;}
case 90:
#line 294 "bison_file.y"
{ yyval.node = genLeaf(TRUE,0,0,NULL); ;
    break;}
case 91:
#line 295 "bison_file.y"
{ yyval.node = genLeaf(FALSE,0,0,NULL); ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 498 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 299 "bison_file.y"

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

void addToSymbolTable( char *IDEName, int size, int IS_ARRAY, arrList lst, int is_struct )
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

	newSymb->is_struct = is_struct;

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
void PrintSymbolTable()
{
	int i;
	FILE* txt;
	FILE* txt1;
	FILE* membs;
	txt=fopen("symbol_table.txt","w");
	txt1=fopen("symbol_table1.txt","w");
	membs=fopen("struct_membs.txt","w");
	fprintf(txt1,"index\t|Name\t|Address\t|Size\t|IS ARRAY\t\t|IS POINTER\t|TYPE\t|is_struct\n");
	fprintf(txt1,"--------------------------------------------------------------\n");
	fprintf(txt,"Name   |Address  |Size  |IS ARRAY   |IS RECORD\n");
	fprintf(txt,"-----------------------------------------------\n");

	for(i=0;i<26;++i)
	{	
		CurrSymbol=symbTable[i];
		while (CurrSymbol != NULL)
		{
			fprintf(txt1,"%d\t\t|%s\t\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d|\t\t%d\n",
				i, 
				CurrSymbol->symb,
				CurrSymbol->address,
				CurrSymbol->size,
				CurrSymbol->IS_ARRAY,
				CurrSymbol->IS_POINTER,
				CurrSymbol->type,
				CurrSymbol->is_struct);

			fprintf(txt,"%s      |%d        |%d     |%d\n"
				  ,CurrSymbol->symb,
				  CurrSymbol->address,
				  CurrSymbol->size,
				  CurrSymbol->IS_ARRAY);
			
			if( CurrSymbol->is_struct==1 && CurrSymbol->members!=NULL )
				print_struct_members(membs, CurrSymbol->symb, CurrSymbol->members );

			PrintArray(CurrSymbol->lst,txt,CurrSymbol->IS_ARRAY);
			CurrSymbol=CurrSymbol->next;
		}
	}
	fclose(txt);
	fclose(txt1);
	fclose(membs);

}

void PrintArray(arrLST *l,FILE *t,int ind)
{
	if (!ind) return;
	fprintf(t,"%d     %d\n",l->size,l->sumsize);
	PrintArray(l+1,t,ind-1);
}



void print_struct_members( FILE* f, char* struct_name, struct Symbol* members )
{
	fprintf(f, "members for struct %s\n", struct_name);	
	fprintf(f,"index\t|Name\t|Address\t|Size\t|IS ARRAY\t\t|IS POINTER\t|TYPE\t|is_struct\n");
	fprintf(f,"--------------------------------------------------------------\n");

	while( members!=NULL )
	{
		fprintf(f,"%s\t\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d|\t\t%d\n",
		members->symb,
		members->address,
		members->size,
		members->IS_ARRAY,
		members->IS_POINTER,
		members->type,
		members->is_struct);
		members = members->next;
	}
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