
/*  A Bison parser, made from bison_file.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	PROGRAM	258
#define	PROCEDURE	259
#define	BBEGIN	260
#define	END	261
#define	DECLARE	262
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
#define	CAST	313
#define	STATEMENT	314
#define	DECLARATION	315
#define	BLOCK_BODY	316
#define	INTCONST	317
#define	IDE	318
#define	POINTER	319
#define	REALCONST	320
#define	STRING	321
#define	DUMMY	322

#line 2 "bison_file.y"

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
#include "symbol_stack.h"
#include "symbol.h"

int line_number = 1;


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



#define	YYFINAL		155
#define	YYFLAG		-32768
#define	YYNTBASE	76

#define YYTRANSLATE(x) ((unsigned)(x) <= 322 ? yytranslate[x] : 113)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    70,
    71,     2,     2,    72,     2,    73,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    69,    68,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    74,     2,    75,     2,     2,     2,     2,     2,     2,     2,
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
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     5,    13,    14,    22,    24,    25,    27,    31,
    34,    37,    40,    41,    43,    45,    46,    53,    55,    57,
    59,    61,    63,    64,    73,    74,    81,    84,    85,    87,
    89,    92,    94,    97,    99,   101,   103,   107,   113,   121,
   127,   134,   136,   139,   143,   147,   149,   151,   152,   159,
   161,   165,   166,   172,   173,   175,   179,   183,   187,   191,
   195,   199,   203,   207,   211,   215,   219,   223,   227,   231,
   236,   239,   241,   243,   245,   247,   249
};

static const short yyrhs[] = {     3,
    63,    83,     0,     0,    57,    63,    78,    17,    79,    18,
    68,     0,     0,    55,    80,    88,    69,    82,    68,    81,
     0,    79,     0,     0,    63,     0,    17,    84,    18,     0,
    90,    84,     0,    97,    84,     0,    85,    84,     0,     0,
    77,     0,    86,     0,     0,    55,    87,    88,    69,    89,
    68,     0,    13,     0,     9,     0,    10,     0,    63,     0,
    64,     0,     0,     4,    63,    91,    70,    92,    71,    83,
    68,     0,     0,    55,    93,    88,    69,    95,    94,     0,
    72,    92,     0,     0,    63,     0,    97,     0,    97,    96,
     0,    98,     0,    99,    68,     0,   100,     0,   101,     0,
   102,     0,   105,    16,   111,     0,    19,   111,    20,    96,
    22,     0,    19,   111,    20,    96,    21,    96,    22,     0,
    23,   111,    25,    96,    26,     0,    46,   111,    15,    17,
   103,    18,     0,   104,     0,   104,   103,     0,    62,    69,
    96,     0,    63,    73,   107,     0,    63,     0,    64,     0,
     0,    63,    74,   111,    75,   106,   108,     0,    63,     0,
    63,    73,   107,     0,     0,    74,   111,    75,   109,   108,
     0,     0,   110,     0,   111,    31,   111,     0,   111,    32,
   111,     0,   111,    33,   111,     0,   111,    34,   111,     0,
   111,    36,   111,     0,   111,    37,   111,     0,   111,    38,
   111,     0,   111,    39,   111,     0,   111,    40,   111,     0,
   111,    41,   111,     0,   111,    42,   111,     0,   111,    43,
   111,     0,   111,    44,   111,     0,    70,   111,    71,     0,
    88,    70,   111,    71,     0,    45,   112,     0,   112,     0,
   105,     0,    62,     0,    65,     0,    29,     0,    30,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    53,    60,    67,    74,    76,    79,    81,    84,    96,   100,
   102,   103,   104,   108,   110,   114,   116,   120,   122,   123,
   127,   133,   145,   154,   165,   167,   170,   172,   175,   187,
   188,   191,   194,   195,   196,   197,   200,   203,   204,   207,
   210,   213,   214,   216,   219,   221,   222,   223,   225,   247,
   248,   255,   258,   267,   267,   270,   271,   272,   273,   274,
   275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
   285,   286,   290,   291,   292,   293,   294
};

static const char * const yytname[] = {   "$","error","$undefined.","PROGRAM",
"PROCEDURE","BBEGIN","END","DECLARE","LABEL","INTEGER","FLOAT","REAL","CMP",
"BOOLEAN","ARRAY","OF","ASSIGN","LC","RC","IF","THEN","ELSE","FI","WHILE","REPEAT",
"DO","OD","READ","WRITE","TRUE","FALSE","ADD","MMIN","MUL","DIV","GOTO","MOD",
"LES","LEQ","EQU","NEQ","GRE","GEQ","AND","OR","NOT","CASE","FOR","FIN","IDENTICAL",
"FROM","BY","TO","CONST","TYPE","VAR","RECORD","STRUCT","CAST","STATEMENT","DECLARATION",
"BLOCK_BODY","INTCONST","IDE","POINTER","REALCONST","STRING","DUMMY","';'","':'",
"'('","')'","','","'.'","'['","']'","program","struct_decl","@1","member_decl",
"@2","member_decl_tail","member_id_list","block","dec_or_stat","declaration",
"var_decl","@3","type_list","id_list","procedure","@4","param_decl","@5","param_decl_tail",
"param_id_list","stat_seq","stat","nonlable_stat","assign","cond_stat","loop_stat",
"case_stat","case_list","case","var","@6","struct_acc_tail","bracket","@7","@8",
"expr","atom",""
};
#endif

static const short yyr1[] = {     0,
    76,    78,    77,    80,    79,    81,    81,    82,    83,    84,
    84,    84,    84,    85,    85,    87,    86,    88,    88,    88,
    89,    89,    91,    90,    93,    92,    94,    94,    95,    96,
    96,    97,    98,    98,    98,    98,    99,   100,   100,   101,
   102,   103,   103,   104,   105,   105,   105,   106,   105,   107,
   107,   109,   108,   110,   108,   111,   111,   111,   111,   111,
   111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
   111,   111,   112,   112,   112,   112,   112
};

static const short yyr2[] = {     0,
     3,     0,     7,     0,     7,     1,     0,     1,     3,     2,
     2,     2,     0,     1,     1,     0,     6,     1,     1,     1,
     1,     1,     0,     8,     0,     6,     2,     0,     1,     1,
     2,     1,     2,     1,     1,     1,     3,     5,     7,     5,
     6,     1,     2,     3,     3,     1,     1,     0,     6,     1,
     3,     0,     5,     0,     1,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
     2,     1,     1,     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,    13,     1,     0,     0,     0,     0,    16,     0,
    46,    47,    14,     0,    13,    15,    13,    13,    32,     0,
    34,    35,    36,     0,    23,    19,    20,    18,    76,    77,
     0,    74,    75,     0,     0,    73,     0,    72,     0,     0,
     0,     2,     0,     0,     9,    12,    10,    11,    33,     0,
     0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    50,    45,     0,    37,     0,    69,     0,     0,
    30,    56,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,     0,     0,     0,     0,     0,    48,
    25,     0,    70,     0,    38,    31,    40,     0,     0,    42,
    21,    22,     0,     4,     0,    51,    54,     0,     0,     0,
     0,    41,    43,    17,     0,     0,     0,    49,    55,     0,
     0,    39,    44,     0,     3,     0,     0,    24,     0,    52,
    29,    28,     8,     0,    54,     0,    26,     7,    53,    27,
     6,     5,     0,     0,     0
};

static const short yydefgoto[] = {   153,
    13,    72,   115,   125,   152,   144,     4,    14,    15,    16,
    41,    35,   113,    17,    51,   102,   118,   147,   142,    80,
    81,    19,    20,    21,    22,    23,   109,   110,    36,   117,
    74,   128,   145,   129,    37,    38
};

static const short yypact[] = {     8,
   -37,    18,    17,-32768,   -22,     3,     3,     3,-32768,   -21,
   -45,-32768,-32768,    16,    17,-32768,    17,    17,-32768,   -24,
-32768,-32768,-32768,    29,-32768,-32768,-32768,-32768,-32768,-32768,
   137,-32768,-32768,     3,    -6,-32768,   208,-32768,   228,   183,
    10,-32768,   -17,     3,-32768,-32768,-32768,-32768,-32768,     3,
    -1,-32768,   121,     3,    52,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,    52,    60,
    14,    61,    11,-32768,    93,   242,    30,-32768,   147,     9,
    52,   -29,   -29,-32768,-32768,-32768,   256,   256,   256,   256,
   256,   256,-32768,   -29,    63,    25,   -25,    35,   -17,-32768,
-32768,    20,-32768,    52,-32768,-32768,-32768,    23,    75,    25,
-32768,-32768,    26,-32768,    77,-32768,    22,    10,    18,    78,
    52,-32768,-32768,-32768,    10,    31,     3,-32768,-32768,    28,
    33,-32768,-32768,    34,-32768,   107,    39,-32768,    41,-32768,
-32768,    36,-32768,    38,    22,    30,-32768,    35,-32768,-32768,
-32768,-32768,   109,   110,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,   -41,-32768,-32768,-32768,    -5,    -9,-32768,-32768,
-32768,   -39,-32768,-32768,-32768,   -34,-32768,-32768,-32768,     1,
     0,-32768,-32768,-32768,-32768,-32768,    13,-32768,     7,-32768,
    19,   -32,-32768,-32768,    -7,    86
};


#define	YYLAST		300


static const short yytable[] = {    39,
    40,    71,    18,    58,    59,    46,    60,    47,    48,    24,
     1,    26,    27,    67,    18,    28,    18,    18,    26,    27,
     5,    24,    28,    24,    24,     2,    53,    43,    44,   104,
   105,    29,    30,    45,     3,     6,    75,   111,   112,     7,
    25,    42,    76,    49,    50,    73,    79,    31,    82,    83,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    24,     8,    54,    32,    11,    12,    33,    77,    95,
     6,     9,    34,    10,     7,    24,    96,    98,   130,    11,
    12,   106,    97,    99,   101,   134,   108,    24,   107,   114,
   119,   121,   122,   124,   126,   127,   137,     8,   135,   132,
   138,   141,   139,   143,   120,   148,   151,   146,   154,   155,
    24,   150,   149,   131,    11,    12,    52,   116,     0,   136,
     0,   133,   123,    56,    57,    58,    59,    24,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    56,    57,    58,
    59,     0,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    56,    57,    58,    59,     0,    60,    61,    62,    63,
    64,    65,    66,    67,    68,    29,    30,   100,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    56,    57,    58,
    59,   140,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    78,     0,     0,     0,     0,     0,    70,    32,    11,
    12,    33,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    56,    57,    58,    59,   103,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    55,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    56,    57,
    58,    59,     0,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    69,     0,     0,     0,     0,     0,    56,    57,
    58,    59,     0,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    56,    57,    58,    59,     0,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    56,    57,    58,    59,
     0,    60,-32768,-32768,-32768,-32768,-32768,-32768,    67,    68
};

static const short yycheck[] = {     7,
     8,    41,     3,    33,    34,    15,    36,    17,    18,     3,
     3,     9,    10,    43,    15,    13,    17,    18,     9,    10,
     4,    15,    13,    17,    18,    63,    34,    73,    74,    21,
    22,    29,    30,    18,    17,    19,    44,    63,    64,    23,
    63,    63,    50,    68,    16,    63,    54,    45,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    55,    46,    70,    62,    63,    64,    65,    70,    69,
    19,    55,    70,    57,    23,    69,    17,    17,   118,    63,
    64,    81,    69,    73,    55,   125,    62,    81,    26,    55,
    71,    69,    18,    68,    18,    74,    69,    46,    68,    22,
    68,    63,    69,    63,   104,    68,   148,    72,     0,     0,
   104,   146,   145,   119,    63,    64,    31,    99,    -1,   127,
    -1,   121,   110,    31,    32,    33,    34,   121,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    31,    32,    33,
    34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    29,    30,    75,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
    34,    75,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    71,    -1,    -1,    -1,    -1,    -1,    15,    62,    63,
    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    31,    32,    33,    34,    71,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    20,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
    33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,
    33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    31,    32,    33,    34,    -1,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    31,    32,    33,    34,
    -1,    36,    37,    38,    39,    40,    41,    42,    43,    44
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
#line 53 "bison_file.y"
{yyval.node=makenode(PROGRAM,yyvsp[0].node,NULL,NULL,0,yyvsp[-1].string); root=yyval.node;;
    break;}
case 2:
#line 62 "bison_file.y"
{
				//symbol_stack_push();
				//symbol_stack_set_isstruct(1);
				//symbol_stack_set_name($2);
			;
    break;}
case 3:
#line 68 "bison_file.y"
{
				//symbol_stack_pop();
			;
    break;}
case 4:
#line 75 "bison_file.y"
{ /*symbol_stack_push();*/ ;
    break;}
case 5:
#line 76 "bison_file.y"
{ ;
    break;}
case 6:
#line 80 "bison_file.y"
{;
    break;}
case 7:
#line 81 "bison_file.y"
{;
    break;}
case 8:
#line 86 "bison_file.y"
{
			//symbol_stack_set_name($1); 
			//symbol_stack_pop_as_member();
		;
    break;}
case 9:
#line 96 "bison_file.y"
{yyval.node=makenode(BBEGIN,yyvsp[-1].node,NULL,NULL,0,NULL);;
    break;}
case 10:
#line 101 "bison_file.y"
{yyval.node=makenode(BLOCK_BODY,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 11:
#line 102 "bison_file.y"
{yyval.node=makenode(BLOCK_BODY,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 12:
#line 103 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 13:
#line 104 "bison_file.y"
{yyval.node=NULL;;
    break;}
case 14:
#line 109 "bison_file.y"
{ yyval.node = NULL; ;
    break;}
case 15:
#line 110 "bison_file.y"
{ yyval.node = NULL; ;
    break;}
case 16:
#line 115 "bison_file.y"
{ ;
    break;}
case 17:
#line 116 "bison_file.y"
{ ;
    break;}
case 18:
#line 121 "bison_file.y"
{;
    break;}
case 19:
#line 122 "bison_file.y"
{;
    break;}
case 20:
#line 123 "bison_file.y"
{;
    break;}
case 21:
#line 129 "bison_file.y"
{
			//symbol_stack_set_name($1); 
			//symbol_stack_pop();
		;
    break;}
case 22:
#line 135 "bison_file.y"
{
			//symbol_stack_set_ispointer(1);
			//symbol_stack_set_name($1);
			//symbol_stack_pop();
		;
    break;}
case 23:
#line 147 "bison_file.y"
{
				//symbol_stack_push();
				//symbol_stack_set_name($2);
				//symbol_stack_set_isprocedure(1);
				enter_block(yyvsp[0].string);
				printf("entering conext %s\n", yyvsp[0].string);
			;
    break;}
case 24:
#line 155 "bison_file.y"
{
				printSymbolTable();
				exit_block();
				//symbol_stack_pop();

				printf("exiting conext\n"); 
				yyval.node = makenode(PROCEDURE, yyvsp[-1].node, NULL, NULL, 0, NULL);
			;
    break;}
case 25:
#line 166 "bison_file.y"
{ ;
    break;}
case 26:
#line 167 "bison_file.y"
{ ;
    break;}
case 27:
#line 171 "bison_file.y"
{;
    break;}
case 28:
#line 172 "bison_file.y"
{;
    break;}
case 29:
#line 177 "bison_file.y"
{
			//symbol_stack_set_name($1); 
			//symbol_stack_pop_as_indepedant_member();
		;
    break;}
case 30:
#line 187 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 31:
#line 188 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 32:
#line 191 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 33:
#line 194 "bison_file.y"
{yyval.node=yyvsp[-1].node;;
    break;}
case 34:
#line 195 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 35:
#line 196 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 36:
#line 197 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 37:
#line 200 "bison_file.y"
{yyval.node=makenode(ASSIGN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 38:
#line 203 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 39:
#line 204 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-5].node,yyvsp[-3].node,yyvsp[-1].node,0,NULL);;
    break;}
case 40:
#line 207 "bison_file.y"
{yyval.node=makenode(WHILE,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 41:
#line 210 "bison_file.y"
{yyval.node=makenode(CASESTAT,yyvsp[-4].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 42:
#line 213 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 43:
#line 214 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 44:
#line 216 "bison_file.y"
{yyval.node=makenode(CASE,NULL,yyvsp[0].node,NULL,yyvsp[-2].code,NULL);;
    break;}
case 45:
#line 220 "bison_file.y"
{ printf("struct_acc->"); ;
    break;}
case 46:
#line 221 "bison_file.y"
{ yyval.node = genLeaf(IDE,0,0,yyvsp[0].string);;
    break;}
case 47:
#line 222 "bison_file.y"
{yyval.node = genLeaf(POINTER,0,0,yyvsp[0].string);;
    break;}
case 48:
#line 223 "bison_file.y"
{s=0; /*lst=findSymbol($1)->lst;*/;
    break;}
case 49:
#line 225 "bison_file.y"
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
			/*if (n!=findSymbol($1)->IS_ARRAY ) 
			{
				fprintf(txt,"\nError at line %d: Assign problem %s: %d!=%d.",line_number, $1,n,findSymbol($1)->IS_ARRAY); 
				fclose(txt);
			}*/
	;
    break;}
case 50:
#line 247 "bison_file.y"
{printf("struct_tail->");;
    break;}
case 51:
#line 248 "bison_file.y"
{printf("\n");;
    break;}
case 52:
#line 256 "bison_file.y"
{s=s+1;;
    break;}
case 53:
#line 258 "bison_file.y"
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
case 54:
#line 267 "bison_file.y"
{;
    break;}
case 55:
#line 267 "bison_file.y"
{n=1;yyval.node=NULL;
    break;}
case 56:
#line 270 "bison_file.y"
{ yyval.node = makenode(ADD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 57:
#line 271 "bison_file.y"
{ yyval.node = makenode(MMIN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 58:
#line 272 "bison_file.y"
{ yyval.node = makenode(MUL,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 59:
#line 273 "bison_file.y"
{ yyval.node = makenode(DIV,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 60:
#line 274 "bison_file.y"
{ yyval.node = makenode(MOD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 61:
#line 275 "bison_file.y"
{ yyval.node = makenode(LES,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 62:
#line 276 "bison_file.y"
{ yyval.node = makenode(LEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 63:
#line 277 "bison_file.y"
{ yyval.node = makenode(EQU,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 64:
#line 278 "bison_file.y"
{ yyval.node = makenode(NEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 65:
#line 279 "bison_file.y"
{ yyval.node = makenode(GRE,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 66:
#line 280 "bison_file.y"
{ yyval.node = makenode(GEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 67:
#line 281 "bison_file.y"
{ yyval.node = makenode(AND,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 68:
#line 282 "bison_file.y"
{ yyval.node = makenode(OR,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 69:
#line 283 "bison_file.y"
{ yyval.node = yyvsp[-1].node; ;
    break;}
case 70:
#line 284 "bison_file.y"
{ yyval.node = makenode(CAST,yyvsp[-1].node,NULL,NULL,0,NULL); ;
    break;}
case 71:
#line 285 "bison_file.y"
{ yyval.node = makenode(NOT,yyvsp[0].node,NULL,NULL,0,NULL); ;
    break;}
case 72:
#line 286 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 73:
#line 290 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 74:
#line 291 "bison_file.y"
{ yyval.node = genLeaf(INTCONST,yyvsp[0].code,0,NULL); ;
    break;}
case 75:
#line 292 "bison_file.y"
{ yyval.node = genLeaf(REALCONST,0,yyvsp[0].real,NULL);;
    break;}
case 76:
#line 293 "bison_file.y"
{ yyval.node = genLeaf(TRUE,0,0,NULL); ;
    break;}
case 77:
#line 294 "bison_file.y"
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
#line 298 "bison_file.y"
