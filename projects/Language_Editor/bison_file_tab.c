
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



#define	YYFINAL		175
#define	YYFLAG		-32768
#define	YYNTBASE	76

#define YYTRANSLATE(x) ((unsigned)(x) <= 322 ? yytranslate[x] : 115)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    73,
    74,     2,     2,    70,     2,    75,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    69,    68,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    71,     2,    72,     2,     2,     2,     2,     2,     2,     2,
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
     0,     4,    11,    12,    13,    22,    29,    31,    32,    36,
    38,    40,    42,    45,    50,    52,    53,    57,    60,    63,
    66,    67,    69,    71,    72,    79,    81,    83,    85,    86,
    95,   101,   102,   109,   110,   113,   114,   116,   118,   120,
   123,   125,   128,   130,   132,   134,   138,   144,   152,   158,
   165,   167,   170,   174,   178,   180,   182,   183,   190,   192,
   196,   197,   203,   204,   206,   210,   214,   218,   222,   226,
   230,   234,   238,   242,   246,   250,   254,   258,   262,   267,
   270,   272,   274,   276,   278,   280
};

static const short yyrhs[] = {     3,
    63,    86,     0,    57,    63,    17,    78,    18,    68,     0,
     0,     0,    57,    63,    79,    69,    82,    68,    80,    81,
     0,    55,    91,    69,    82,    68,    81,     0,    78,     0,
     0,    83,    70,    82,     0,    83,     0,    63,     0,    64,
     0,    63,    84,     0,    71,    62,    72,    85,     0,    84,
     0,     0,    17,    87,    18,     0,    92,    87,     0,    99,
    87,     0,    88,    87,     0,     0,    77,     0,    89,     0,
     0,    55,    90,    91,    69,    63,    68,     0,    13,     0,
     9,     0,    10,     0,     0,     4,    63,    73,    94,    74,
    93,    86,    68,     0,    57,    63,    69,    97,    96,     0,
     0,    55,    95,    91,    69,    97,    96,     0,     0,    70,
    78,     0,     0,    63,     0,    64,     0,    99,     0,    99,
    98,     0,   100,     0,   101,    68,     0,   102,     0,   103,
     0,   104,     0,   107,    16,   113,     0,    19,   113,    20,
    98,    22,     0,    19,   113,    20,    98,    21,    98,    22,
     0,    23,   113,    25,    98,    26,     0,    46,   113,    15,
    17,   105,    18,     0,   106,     0,   106,   105,     0,    62,
    69,    98,     0,    63,    75,   109,     0,    63,     0,    64,
     0,     0,    63,    71,   113,    72,   108,   110,     0,    63,
     0,    63,    75,   109,     0,     0,    71,   113,    72,   111,
   110,     0,     0,   112,     0,   113,    31,   113,     0,   113,
    32,   113,     0,   113,    33,   113,     0,   113,    34,   113,
     0,   113,    36,   113,     0,   113,    37,   113,     0,   113,
    38,   113,     0,   113,    39,   113,     0,   113,    40,   113,
     0,   113,    41,   113,     0,   113,    42,   113,     0,   113,
    43,   113,     0,   113,    44,   113,     0,    73,   113,    74,
     0,    91,    73,   113,    74,     0,    45,   114,     0,   114,
     0,   107,     0,    62,     0,    65,     0,    29,     0,    30,
     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    52,    59,    61,    62,    64,    64,    67,    67,    69,    70,
    73,    75,    76,    79,    82,    82,    87,    91,    93,    94,
    95,    99,   101,   108,   113,   121,   123,   124,   139,   144,
   153,   154,   155,   156,   159,   159,   161,   162,   168,   169,
   172,   175,   176,   177,   178,   181,   184,   185,   188,   191,
   194,   195,   197,   200,   202,   203,   204,   206,   228,   229,
   236,   239,   248,   248,   251,   252,   253,   254,   255,   256,
   257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
   267,   271,   272,   273,   274,   275
};

static const char * const yytname[] = {   "$","error","$undefined.","PROGRAM",
"PROCEDURE","BBEGIN","END","DECLARE","LABEL","INTEGER","FLOAT","REAL","CMP",
"BOOLEAN","ARRAY","OF","ASSIGN","LC","RC","IF","THEN","ELSE","FI","WHILE","REPEAT",
"DO","OD","READ","WRITE","TRUE","FALSE","ADD","MMIN","MUL","DIV","GOTO","MOD",
"LES","LEQ","EQU","NEQ","GRE","GEQ","AND","OR","NOT","CASE","FOR","FIN","IDENTICAL",
"FROM","BY","TO","CONST","TYPE","VAR","RECORD","STRUCT","CAST","STATEMENT","DECLARATION",
"BLOCK_BODY","INTCONST","IDE","POINTER","REALCONST","STRING","DUMMY","';'","':'",
"','","'['","']'","'('","')'","'.'","program","struct_decl","member_decl","@1",
"@2","member_decl_tail","memberList","struct_member","dim","dim_tail","block",
"dec_or_stat","declaration","var_decl","@3","type_list","procedure","@4","param_decl",
"@5","param_decl_tail","param","stat_seq","stat","nonlable_stat","assign","cond_stat",
"loop_stat","case_stat","case_list","case","var","@6","struct_acc_tail","bracket",
"@7","@8","expr","atom",""
};
#endif

static const short yyr1[] = {     0,
    76,    77,    79,    80,    78,    78,    81,    81,    82,    82,
    83,    83,    83,    84,    85,    85,    86,    87,    87,    87,
    87,    88,    88,    90,    89,    91,    91,    91,    93,    92,
    94,    95,    94,    94,    96,    96,    97,    97,    98,    98,
    99,   100,   100,   100,   100,   101,   102,   102,   103,   104,
   105,   105,   106,   107,   107,   107,   108,   107,   109,   109,
   111,   110,   112,   110,   113,   113,   113,   113,   113,   113,
   113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
   113,   114,   114,   114,   114,   114
};

static const short yyr2[] = {     0,
     3,     6,     0,     0,     8,     6,     1,     0,     3,     1,
     1,     1,     2,     4,     1,     0,     3,     2,     2,     2,
     0,     1,     1,     0,     6,     1,     1,     1,     0,     8,
     5,     0,     6,     0,     2,     0,     1,     1,     1,     2,
     1,     2,     1,     1,     1,     3,     5,     7,     5,     6,
     1,     2,     3,     3,     1,     1,     0,     6,     1,     3,
     0,     5,     0,     1,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     4,     2,
     1,     1,     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,    21,     1,     0,     0,     0,     0,    24,     0,
    55,    56,    22,     0,    21,    23,    21,    21,    41,     0,
    43,    44,    45,     0,     0,    27,    28,    26,    85,    86,
     0,    83,    84,     0,     0,    82,     0,    81,     0,     0,
     0,     0,     0,     0,    17,    20,    18,    19,    42,     0,
    34,    80,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    59,    54,    46,    32,     0,     0,    78,
     0,     0,    39,    65,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,     0,     0,     0,     0,
     0,     0,    57,     0,     0,     0,    29,    79,     0,    47,
    40,    49,     0,     0,    51,     0,     0,     3,     0,    63,
    60,     0,     0,     0,     0,     0,    50,    52,    25,     0,
     0,     2,     0,    58,    64,     0,    37,    38,    36,     0,
    48,    53,    11,    12,     0,    10,     0,     0,    36,     0,
    31,    30,     0,    13,     8,     0,     0,    61,    33,    35,
     0,     7,     6,     9,     4,    63,    16,     8,    62,    15,
    14,     5,     0,     0,     0
};

static const short yydefgoto[] = {   173,
    13,   162,   131,   168,   163,   145,   146,   154,   171,     4,
    14,    15,    16,    41,    35,    17,   124,    79,   105,   151,
   139,    82,    83,    19,    20,    21,    22,    23,   114,   115,
    36,   120,    75,   134,   166,   135,    37,    38
};

static const short yypact[] = {     5,
   -47,     6,    68,-32768,   -37,    55,    55,    55,-32768,   -32,
   -62,-32768,-32768,    23,    68,-32768,    68,    68,-32768,   -23,
-32768,-32768,-32768,    32,    -3,-32768,-32768,-32768,-32768,-32768,
   -25,-32768,-32768,    55,     2,-32768,   218,-32768,   179,   193,
    20,    69,    55,    25,-32768,-32768,-32768,-32768,-32768,    55,
   -13,-32768,   103,    55,    58,    55,    55,    55,    55,    55,
    55,    55,    55,    55,    55,    55,    55,    55,    58,    72,
    24,    12,   131,    21,-32768,   232,-32768,    29,    27,-32768,
   117,    52,    58,   -22,   -22,-32768,-32768,-32768,   246,   246,
   246,   246,   246,   246,-32768,   -22,    71,    33,    31,    20,
    35,    81,-32768,    25,    20,    34,-32768,-32768,    58,-32768,
-32768,-32768,    36,    84,    33,    38,    39,-32768,    41,    40,
-32768,    43,    15,     6,    85,    58,-32768,-32768,-32768,    19,
    44,-32768,    55,-32768,-32768,    15,-32768,-32768,    45,    42,
-32768,-32768,    53,-32768,    59,    60,    19,   156,    45,    12,
-32768,-32768,    67,-32768,    12,    19,    70,-32768,-32768,-32768,
    80,-32768,-32768,-32768,-32768,    40,    53,    12,-32768,-32768,
-32768,-32768,   166,   176,-32768
};

static const short yypgoto[] = {-32768,
-32768,   -70,-32768,-32768,    10,  -128,-32768,    13,-32768,    57,
    17,-32768,-32768,-32768,   -34,-32768,-32768,-32768,-32768,    30,
    46,   -63,     0,-32768,-32768,-32768,-32768,-32768,    86,-32768,
     7,-32768,    79,    18,-32768,-32768,    -7,   154
};


#define	YYLAST		290


static const short yytable[] = {    39,
    40,   102,    18,    29,    30,    97,    71,     1,    43,    24,
    58,    59,    44,    60,    18,     2,    18,    18,   157,   111,
    67,    24,     3,    24,    24,    25,    53,   164,    26,    27,
    42,    46,    28,    47,    48,    73,    32,    11,    12,    33,
    45,    77,    76,    78,    49,   125,    81,    50,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    24,   142,    26,    27,   117,   100,    28,   101,    51,
   122,     5,   109,   110,    54,    24,     6,   137,   138,   160,
     7,   143,   144,    29,    30,    72,     6,    74,    98,    24,
     7,   106,    99,   116,   113,   104,   112,   118,   119,    31,
   107,   127,   123,     8,   126,   129,   141,   130,   132,   152,
   133,   136,   147,     8,   150,    24,    32,    11,    12,    33,
    11,    12,     9,   153,    10,   148,   155,    34,   161,   156,
    11,    12,    24,    56,    57,    58,    59,   165,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    56,    57,    58,
    59,   167,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    56,    57,    58,    59,   174,    60,    61,    62,    63,
    64,    65,    66,    67,    68,   175,    80,   172,   159,   170,
   140,   149,   121,   169,    52,     0,    56,    57,    58,    59,
   108,    60,    61,    62,    63,    64,    65,    66,    67,    68,
   128,     0,   103,    69,     0,     0,     0,    70,     0,    56,
    57,    58,    59,     0,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    56,    57,    58,    59,   158,    60,    61,
    62,    63,    64,    65,    66,    67,    68,    55,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    56,    57,
    58,    59,     0,    60,    61,    62,    63,    64,    65,    66,
    67,    68,    56,    57,    58,    59,     0,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    56,    57,    58,    59,
     0,    60,-32768,-32768,-32768,-32768,-32768,-32768,    67,    68
};

static const short yycheck[] = {     7,
     8,    72,     3,    29,    30,    69,    41,     3,    71,     3,
    33,    34,    75,    36,    15,    63,    17,    18,   147,    83,
    43,    15,    17,    17,    18,    63,    34,   156,     9,    10,
    63,    15,    13,    17,    18,    43,    62,    63,    64,    65,
    18,    55,    50,    57,    68,   109,    54,    16,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    55,   126,     9,    10,   100,    55,    13,    57,    73,
   105,     4,    21,    22,    73,    69,    19,    63,    64,   150,
    23,    63,    64,    29,    30,    17,    19,    63,    17,    83,
    23,    63,    69,    63,    62,    75,    26,    63,    18,    45,
    74,    18,    69,    46,    69,    68,    22,    69,    68,    68,
    71,    69,    69,    46,    70,   109,    62,    63,    64,    65,
    63,    64,    55,    71,    57,   133,    68,    73,    62,    70,
    63,    64,   126,    31,    32,    33,    34,    68,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    31,    32,    33,
    34,    72,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    31,    32,    33,    34,     0,    36,    37,    38,    39,
    40,    41,    42,    43,    44,     0,    74,   168,   149,   167,
   124,   136,   104,   166,    31,    -1,    31,    32,    33,    34,
    74,    36,    37,    38,    39,    40,    41,    42,    43,    44,
   115,    -1,    72,    25,    -1,    -1,    -1,    15,    -1,    31,
    32,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    31,    32,    33,    34,    72,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    20,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
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
#line 52 "bison_file.y"
{yyval.node=makenode(PROGRAM,yyvsp[0].node,NULL,NULL,0,yyvsp[-1].string); root=yyval.node;;
    break;}
case 2:
#line 59 "bison_file.y"
{addToSymbolTable(yyvsp[-4].string,yyvsp[-4].string); post_struct_def(); ;
    break;}
case 3:
#line 61 "bison_file.y"
{set_current_struct_name(yyvsp[0].string);;
    break;}
case 4:
#line 62 "bison_file.y"
{clear_current_struct(); ;
    break;}
case 6:
#line 64 "bison_file.y"
{printf("member_primitive_decl_1->");;
    break;}
case 9:
#line 69 "bison_file.y"
{printf("memberList_1->");;
    break;}
case 10:
#line 70 "bison_file.y"
{printf("memberList_2->");;
    break;}
case 11:
#line 74 "bison_file.y"
{ new_struct_member(yyvsp[0].string, 1, 0, NULL); ;
    break;}
case 12:
#line 75 "bison_file.y"
{ new_struct_member(yyvsp[0].string, 1, 0, NULL); ;
    break;}
case 13:
#line 76 "bison_file.y"
{ printf("struct_member(dim)->"); ;
    break;}
case 14:
#line 79 "bison_file.y"
{printf("dim_1\n");;
    break;}
case 17:
#line 87 "bison_file.y"
{yyval.node=makenode(BBEGIN,yyvsp[-1].node,NULL,NULL,0,NULL);;
    break;}
case 18:
#line 92 "bison_file.y"
{yyval.node=makenode(BLOCK_BODY,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 19:
#line 93 "bison_file.y"
{yyval.node=makenode(BLOCK_BODY,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 20:
#line 94 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 21:
#line 95 "bison_file.y"
{yyval.node=NULL;;
    break;}
case 22:
#line 100 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 23:
#line 101 "bison_file.y"
{ yyval.node = NULL; ;
    break;}
case 24:
#line 110 "bison_file.y"
{
				symbol_stack_push(); 
			;
    break;}
case 25:
#line 114 "bison_file.y"
{
				symbol_stack_set_name(yyvsp[-1].string);
				addToSymbolTable( yyvsp[-1].string, (void*) symbol_stack_pop() );
			;
    break;}
case 26:
#line 122 "bison_file.y"
{ symbol_stack_set_type(BOOLEAN);;
    break;}
case 27:
#line 123 "bison_file.y"
{ symbol_stack_set_type(INTEGER);;
    break;}
case 28:
#line 124 "bison_file.y"
{ symbol_stack_set_type(FLOAT);;
    break;}
case 29:
#line 140 "bison_file.y"
{
				enter_block(yyvsp[-3].string); 
				printf("entering conext %s\n", yyvsp[-3].string);
			;
    break;}
case 30:
#line 145 "bison_file.y"
{
				printSymbolTable(); 
				exit_block(); 
				printf("exiting conext\n"); 
				yyval.node = makenode(PROCEDURE, yyvsp[-1].node, NULL, NULL, 0, NULL);
			;
    break;}
case 31:
#line 153 "bison_file.y"
{ printf("param_decl_1->"); ;
    break;}
case 32:
#line 154 "bison_file.y"
{ ;
    break;}
case 33:
#line 155 "bison_file.y"
{ printf("primitive_param_decl_1->"); ;
    break;}
case 34:
#line 156 "bison_file.y"
{ ;
    break;}
case 37:
#line 161 "bison_file.y"
{ printf("ide->"); ;
    break;}
case 38:
#line 162 "bison_file.y"
{ printf("pointer->"); ;
    break;}
case 39:
#line 168 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 40:
#line 169 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 41:
#line 172 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 42:
#line 175 "bison_file.y"
{yyval.node=yyvsp[-1].node;;
    break;}
case 43:
#line 176 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 44:
#line 177 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 45:
#line 178 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 46:
#line 181 "bison_file.y"
{yyval.node=makenode(ASSIGN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 47:
#line 184 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 48:
#line 185 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-5].node,yyvsp[-3].node,yyvsp[-1].node,0,NULL);;
    break;}
case 49:
#line 188 "bison_file.y"
{yyval.node=makenode(WHILE,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 50:
#line 191 "bison_file.y"
{yyval.node=makenode(CASESTAT,yyvsp[-4].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 51:
#line 194 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 52:
#line 195 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 53:
#line 197 "bison_file.y"
{yyval.node=makenode(CASE,NULL,yyvsp[0].node,NULL,yyvsp[-2].code,NULL);;
    break;}
case 54:
#line 201 "bison_file.y"
{ printf("struct_acc->"); ;
    break;}
case 55:
#line 202 "bison_file.y"
{ yyval.node = genLeaf(IDE,0,0,yyvsp[0].string);;
    break;}
case 56:
#line 203 "bison_file.y"
{yyval.node = genLeaf(POINTER,0,0,yyvsp[0].string);;
    break;}
case 57:
#line 204 "bison_file.y"
{s=0; /*lst=findSymbol($1)->lst;*/;
    break;}
case 58:
#line 206 "bison_file.y"
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
case 59:
#line 228 "bison_file.y"
{printf("struct_tail->");;
    break;}
case 60:
#line 229 "bison_file.y"
{printf("\n");;
    break;}
case 61:
#line 237 "bison_file.y"
{s=s+1;;
    break;}
case 62:
#line 239 "bison_file.y"
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
case 63:
#line 248 "bison_file.y"
{;
    break;}
case 64:
#line 248 "bison_file.y"
{n=1;yyval.node=NULL;
    break;}
case 65:
#line 251 "bison_file.y"
{ yyval.node = makenode(ADD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 66:
#line 252 "bison_file.y"
{ yyval.node = makenode(MMIN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 67:
#line 253 "bison_file.y"
{ yyval.node = makenode(MUL,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 68:
#line 254 "bison_file.y"
{ yyval.node = makenode(DIV,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 69:
#line 255 "bison_file.y"
{ yyval.node = makenode(MOD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 70:
#line 256 "bison_file.y"
{ yyval.node = makenode(LES,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 71:
#line 257 "bison_file.y"
{ yyval.node = makenode(LEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 72:
#line 258 "bison_file.y"
{ yyval.node = makenode(EQU,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 73:
#line 259 "bison_file.y"
{ yyval.node = makenode(NEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 74:
#line 260 "bison_file.y"
{ yyval.node = makenode(GRE,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 75:
#line 261 "bison_file.y"
{ yyval.node = makenode(GEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 76:
#line 262 "bison_file.y"
{ yyval.node = makenode(AND,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 77:
#line 263 "bison_file.y"
{ yyval.node = makenode(OR,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 78:
#line 264 "bison_file.y"
{ yyval.node = yyvsp[-1].node; ;
    break;}
case 79:
#line 265 "bison_file.y"
{ yyval.node = makenode(CAST,yyvsp[-1].node,NULL,NULL,0,NULL); ;
    break;}
case 80:
#line 266 "bison_file.y"
{ yyval.node = makenode(NOT,yyvsp[0].node,NULL,NULL,0,NULL); ;
    break;}
case 81:
#line 267 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 82:
#line 271 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 83:
#line 272 "bison_file.y"
{ yyval.node = genLeaf(INTCONST,yyvsp[0].code,0,NULL); ;
    break;}
case 84:
#line 273 "bison_file.y"
{ yyval.node = genLeaf(REALCONST,0,yyvsp[0].real,NULL);;
    break;}
case 85:
#line 274 "bison_file.y"
{ yyval.node = genLeaf(TRUE,0,0,NULL); ;
    break;}
case 86:
#line 275 "bison_file.y"
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
#line 279 "bison_file.y"
