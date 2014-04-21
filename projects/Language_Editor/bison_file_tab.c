
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
#define	CAST	313
#define	INTCONST	314
#define	IDE	315
#define	POINTER	316
#define	REALCONST	317
#define	STRING	318
#define	DUMMY	319

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



#define	YYFINAL		187
#define	YYFLAG		-32768
#define	YYNTBASE	73

#define YYTRANSLATE(x) ((unsigned)(x) <= 319 ? yytranslate[x] : 116)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    71,
    72,     2,     2,    67,     2,    70,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    66,    65,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    68,     2,    69,     2,     2,     2,     2,     2,     2,     2,
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
    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     9,    12,    19,    20,    21,    30,    37,    39,
    40,    44,    46,    48,    50,    53,    58,    60,    61,    64,
    68,    69,    70,    79,    80,    85,    87,    88,    92,    93,
    97,    98,    99,   108,   112,   116,   117,   118,   128,   129,
   130,   136,   137,   139,   141,   143,   145,   147,   150,   152,
   155,   157,   159,   161,   165,   171,   179,   185,   192,   194,
   197,   201,   205,   207,   209,   210,   217,   219,   223,   224,
   230,   231,   233,   237,   241,   245,   249,   253,   257,   261,
   265,   269,   273,   277,   281,   285,   289,   294,   297,   299,
   301,   303,   305,   307
};

static const short yyrhs[] = {     3,
    60,    74,     0,    17,    84,    99,    18,     0,    17,    18,
     0,    57,    60,    17,    76,    18,    65,     0,     0,     0,
    57,    60,    77,    66,    80,    65,    78,    79,     0,    55,
    98,    66,    80,    65,    79,     0,    76,     0,     0,    81,
    67,    80,     0,    81,     0,    60,     0,    61,     0,    60,
    82,     0,    68,    59,    69,    83,     0,    82,     0,     0,
    75,    84,     0,    55,    87,    84,     0,     0,     0,    57,
    60,    85,    66,    88,    65,    86,    84,     0,     0,    98,
    66,    88,    87,     0,    65,     0,     0,    60,    89,    88,
     0,     0,    61,    90,    88,     0,     0,     0,    60,    68,
    59,    69,    91,    95,    92,    88,     0,    67,    60,    88,
     0,    67,    61,    88,     0,     0,     0,    67,    60,    68,
    59,    69,    93,    95,    94,    88,     0,     0,     0,    68,
    59,    69,    96,    95,     0,     0,    97,     0,    13,     0,
     9,     0,    10,     0,   100,     0,   100,    99,     0,   101,
     0,   102,    65,     0,   103,     0,   104,     0,   105,     0,
   108,    16,   114,     0,    19,   114,    20,    99,    22,     0,
    19,   114,    20,    99,    21,    99,    22,     0,    23,   114,
    25,    99,    26,     0,    46,   114,    15,    17,   106,    18,
     0,   107,     0,   107,   106,     0,    59,    66,    99,     0,
    60,    70,   110,     0,    60,     0,    61,     0,     0,    60,
    68,   114,    69,   109,   111,     0,    60,     0,    60,    70,
   110,     0,     0,    68,   114,    69,   112,   111,     0,     0,
   113,     0,   114,    31,   114,     0,   114,    32,   114,     0,
   114,    33,   114,     0,   114,    34,   114,     0,   114,    36,
   114,     0,   114,    37,   114,     0,   114,    38,   114,     0,
   114,    39,   114,     0,   114,    40,   114,     0,   114,    41,
   114,     0,   114,    42,   114,     0,   114,    43,   114,     0,
   114,    44,   114,     0,    71,   114,    72,     0,    98,    71,
   114,    72,     0,    45,   115,     0,   115,     0,   108,     0,
    59,     0,    62,     0,    29,     0,    30,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    50,    53,    54,    61,    63,    64,    66,    66,    69,    69,
    71,    72,    75,    77,    78,    81,    84,    84,    88,    89,
    90,    91,    93,    93,    95,    96,   100,   101,   101,   102,
   102,   108,   115,   115,   116,   117,   123,   130,   130,   133,
   136,   144,   145,   155,   156,   158,   163,   164,   168,   171,
   172,   173,   174,   177,   180,   181,   184,   187,   190,   191,
   193,   196,   198,   199,   200,   202,   224,   225,   232,   235,
   244,   244,   247,   248,   249,   250,   251,   252,   253,   254,
   255,   256,   257,   258,   259,   260,   261,   262,   263,   267,
   268,   269,   270,   271
};

static const char * const yytname[] = {   "$","error","$undefined.","PROGRAM",
"BBEGIN","END","DECLARE","PROCEDURE","LABEL","INTEGER","FLOAT","REAL","CMP",
"BOOLEAN","ARRAY","OF","ASSIGN","LC","RC","IF","THEN","ELSE","FI","WHILE","REPEAT",
"DO","OD","READ","WRITE","TRUE","FALSE","ADD","MMIN","MUL","DIV","GOTO","MOD",
"LES","LEQ","EQU","NEQ","GRE","GEQ","AND","OR","NOT","CASE","FOR","FIN","IDENTICAL",
"FROM","BY","TO","CONST","TYPE","VAR","RECORD","STRUCT","CAST","INTCONST","IDE",
"POINTER","REALCONST","STRING","DUMMY","';'","':'","','","'['","']'","'.'","'('",
"')'","program","block","struct_decl","member_decl","@1","@2","member_decl_tail",
"memberList","struct_member","dim","dim_tail","declarations","@3","@4","varAss",
"idList","@5","@6","@7","@8","@9","@10","brk","@11","@12","tyList","stat_seq",
"stat","nonlable_stat","assign","cond_stat","loop_stat","case_stat","case_list",
"case","var","@13","struct_acc_tail","bracket","@14","@15","expr","atom",""
};
#endif

static const short yyr1[] = {     0,
    73,    74,    74,    75,    77,    78,    76,    76,    79,    79,
    80,    80,    81,    81,    81,    82,    83,    83,    84,    84,
    85,    86,    84,    84,    87,    87,    89,    88,    90,    88,
    91,    92,    88,    88,    88,    93,    94,    88,    88,    96,
    95,    97,    95,    98,    98,    98,    99,    99,   100,   101,
   101,   101,   101,   102,   103,   103,   104,   105,   106,   106,
   107,   108,   108,   108,   109,   108,   110,   110,   112,   111,
   113,   111,   114,   114,   114,   114,   114,   114,   114,   114,
   114,   114,   114,   114,   114,   114,   114,   114,   114,   115,
   115,   115,   115,   115
};

static const short yyr2[] = {     0,
     3,     4,     2,     6,     0,     0,     8,     6,     1,     0,
     3,     1,     1,     1,     2,     4,     1,     0,     2,     3,
     0,     0,     8,     0,     4,     1,     0,     3,     0,     3,
     0,     0,     8,     3,     3,     0,     0,     9,     0,     0,
     5,     0,     1,     1,     1,     1,     1,     2,     1,     2,
     1,     1,     1,     3,     5,     7,     5,     6,     1,     2,
     3,     3,     1,     1,     0,     6,     1,     3,     0,     5,
     0,     1,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     4,     2,     1,     1,
     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,    24,     1,     3,     0,     0,    24,     0,    45,
    46,    44,    26,    24,     0,    21,    19,     0,     0,     0,
    63,    64,     0,    47,    49,     0,    51,    52,    53,     0,
    20,    39,     0,     0,    93,    94,     0,    91,    92,     0,
     0,    90,     0,    89,     0,     0,     0,     0,     2,    48,
    50,     0,    27,    29,     0,     0,     0,     0,     0,    39,
    88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    67,    62,    54,     0,    39,    39,    39,    39,    25,     0,
     5,     0,     0,    86,     0,     0,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
     0,    65,     0,     0,    28,    30,     0,    34,    35,     0,
     0,     4,    22,    87,     0,    55,    57,     0,     0,    59,
    71,    68,    31,     0,    13,    14,     0,    12,     0,    24,
     0,     0,    58,    60,     0,    66,    72,    42,    36,     0,
    15,    10,     0,     0,    23,    56,    61,     0,     0,    32,
    43,    42,     0,     9,     8,    11,     6,    69,     0,    39,
    37,    18,    10,    71,    40,    33,    39,    17,    16,     7,
    70,    42,    38,    41,     0,     0,     0
};

static const short yydefgoto[] = {   185,
     4,     8,   164,   121,   173,   165,   137,   138,   151,   179,
     9,    34,   140,    14,    56,    85,    86,   148,   170,   162,
   177,   160,   182,   161,    41,    23,    24,    25,    26,    27,
    28,    29,   129,   130,    42,   131,    82,   146,   174,   147,
    43,    44
};

static const short yypact[] = {    15,
   -38,    26,    28,-32768,-32768,    -4,    24,   -41,   -12,-32768,
-32768,-32768,-32768,   -41,    20,    39,-32768,    78,    78,    78,
   -47,-32768,    74,   -12,-32768,    29,-32768,-32768,-32768,    79,
-32768,   -25,   -16,    30,-32768,-32768,     3,-32768,-32768,    78,
    27,-32768,   230,-32768,   191,   205,    78,    37,-32768,-32768,
-32768,    78,    31,-32768,   -10,    -4,    80,    40,    83,   -25,
-32768,   120,    78,   -12,    78,    78,    78,    78,    78,    78,
    78,    78,    78,    78,    78,    78,    78,   -12,    85,   157,
    33,-32768,   244,    45,   -25,   -25,   -48,   -25,-32768,    43,
-32768,    41,    47,-32768,   134,    38,     4,     4,-32768,-32768,
-32768,   258,   258,   258,   258,   258,   258,-32768,     4,    84,
    54,-32768,    37,    46,-32768,-32768,    55,-32768,-32768,     6,
    51,-32768,-32768,-32768,   -12,-32768,-32768,    53,   102,    54,
    56,-32768,-32768,    52,    57,-32768,    61,    60,     6,   -41,
   106,   -12,-32768,-32768,    78,-32768,-32768,    62,-32768,    70,
-32768,   -16,     6,    66,-32768,-32768,-32768,   171,    73,-32768,
-32768,    62,    67,-32768,-32768,-32768,-32768,-32768,    72,   -25,
-32768,    57,   -16,    56,-32768,-32768,   -25,-32768,-32768,-32768,
-32768,    62,-32768,-32768,   135,   142,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,   110,-32768,-32768,   -29,  -122,-32768,   -27,-32768,
    -6,-32768,-32768,    90,   -59,-32768,-32768,-32768,-32768,-32768,
-32768,  -152,-32768,-32768,    -3,   -20,-32768,-32768,-32768,-32768,
-32768,-32768,    17,-32768,    -9,-32768,    35,   -19,-32768,-32768,
     5,   132
};


#define	YYLAST		302


static const short yytable[] = {    30,
    93,    17,    15,    50,    10,    11,    18,    31,    12,   171,
    19,    53,    54,     6,    30,     7,   154,     1,    55,   117,
    47,     2,    48,    45,    46,   115,   116,   118,   119,   184,
   166,    35,    36,    20,    53,    54,    67,    68,    57,    69,
    58,    55,     3,    96,    62,     5,    76,    21,    22,    87,
    88,    80,    15,    90,    30,    33,    83,   110,   125,   126,
    13,    38,    21,    22,    39,   135,   136,    95,    30,    97,
    98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,     6,    16,     7,    32,    10,    11,    10,    11,
    12,    49,    12,    51,    52,    60,    81,    63,    84,    91,
    92,   111,   113,   114,   141,   122,    35,    36,   120,   127,
   176,   123,   128,   134,   133,    30,   139,   183,   142,   143,
   149,   157,    37,   145,   150,   152,   153,   156,   163,   159,
   167,   169,    30,   155,   186,   172,    38,    21,    22,    39,
   175,   187,    59,   180,   178,    89,   144,   132,    40,   158,
    65,    66,    67,    68,   181,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    65,    66,    67,    68,    61,    69,
    70,    71,    72,    73,    74,    75,    76,    77,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
    68,    94,    69,    70,    71,    72,    73,    74,    75,    76,
    77,    65,    66,    67,    68,   124,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    78,     0,     0,     0,    79,
     0,    65,    66,    67,    68,   112,    69,    70,    71,    72,
    73,    74,    75,    76,    77,    65,    66,    67,    68,   168,
    69,    70,    71,    72,    73,    74,    75,    76,    77,    64,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
    74,    75,    76,    77,    65,    66,    67,    68,     0,    69,
    70,    71,    72,    73,    74,    75,    76,    77,    65,    66,
    67,    68,     0,    69,-32768,-32768,-32768,-32768,-32768,-32768,
    76,    77
};

static const short yycheck[] = {     9,
    60,     8,     6,    24,     9,    10,    19,    14,    13,   162,
    23,    60,    61,    55,    24,    57,   139,     3,    67,    68,
    68,    60,    70,    19,    20,    85,    86,    87,    88,   182,
   153,    29,    30,    46,    60,    61,    33,    34,    55,    36,
    57,    67,    17,    64,    40,    18,    43,    60,    61,    60,
    61,    47,    56,    57,    64,    17,    52,    78,    21,    22,
    65,    59,    60,    61,    62,    60,    61,    63,    78,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    55,    60,    57,    66,     9,    10,     9,    10,
    13,    18,    13,    65,    16,    66,    60,    71,    68,    60,
    18,    17,    70,    59,   125,    65,    29,    30,    66,    26,
   170,    65,    59,    59,    69,   125,    66,   177,    66,    18,
    69,   142,    45,    68,    68,    65,    67,    22,    59,    68,
    65,    59,   142,   140,     0,    69,    59,    60,    61,    62,
    69,     0,    33,   173,   172,    56,   130,   113,    71,   145,
    31,    32,    33,    34,   174,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    31,    32,    33,    34,    37,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
    34,    72,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    31,    32,    33,    34,    72,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    25,    -1,    -1,    -1,    15,
    -1,    31,    32,    33,    34,    69,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    31,    32,    33,    34,    69,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    20,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    31,    32,    33,    34,    -1,    36,    37,    38,    39,    40,
    41,    42,    43,    44,    31,    32,    33,    34,    -1,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    31,    32,
    33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
    43,    44
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
#line 50 "bison_file.y"
{yyval.node=makenode(PROGRAM,yyvsp[0].node,NULL,NULL,0,yyvsp[-1].string); root=yyval.node;;
    break;}
case 2:
#line 53 "bison_file.y"
{yyval.node=makenode(BBEGIN,yyvsp[-1].node,NULL,NULL,0,NULL);;
    break;}
case 3:
#line 54 "bison_file.y"
{yyval.node=makenode(BBEGIN,NULL,NULL,NULL,0,NULL);;
    break;}
case 4:
#line 61 "bison_file.y"
{addToSymbolTable(yyvsp[-4].string,0,0,NULL); post_struct_def(); ;
    break;}
case 5:
#line 63 "bison_file.y"
{set_current_struct_name(yyvsp[0].string);;
    break;}
case 6:
#line 64 "bison_file.y"
{clear_current_struct(); ;
    break;}
case 8:
#line 66 "bison_file.y"
{printf("member_primitive_decl_1->");;
    break;}
case 11:
#line 71 "bison_file.y"
{printf("memberList_1->");;
    break;}
case 12:
#line 72 "bison_file.y"
{printf("memberList_2->");;
    break;}
case 13:
#line 76 "bison_file.y"
{ new_struct_member(yyvsp[0].string, 1, 0, NULL); ;
    break;}
case 14:
#line 77 "bison_file.y"
{ new_struct_member(yyvsp[0].string, 1, 0, NULL); ;
    break;}
case 15:
#line 78 "bison_file.y"
{ printf("struct_member(dim)->"); ;
    break;}
case 16:
#line 81 "bison_file.y"
{printf("dim_1\n");;
    break;}
case 21:
#line 90 "bison_file.y"
{set_current_struct_name(yyvsp[0].string);;
    break;}
case 22:
#line 91 "bison_file.y"
{clear_current_struct();;
    break;}
case 25:
#line 95 "bison_file.y"
{;
    break;}
case 26:
#line 97 "bison_file.y"
{;
    break;}
case 27:
#line 100 "bison_file.y"
{addToSymbolTable(yyvsp[0].string,1,0,NULL);;
    break;}
case 29:
#line 101 "bison_file.y"
{addToSymbolTable(yyvsp[0].string,1,0,NULL);;
    break;}
case 31:
#line 103 "bison_file.y"
{
		s=1;

	;
    break;}
case 32:
#line 108 "bison_file.y"
{ 
		lst[s-o].size=yyvsp[-3].code;/* calcultes size of each dimentiob*/
		lst[s-o].sumsize=n*yyvsp[-3].code;/* sum of array*/
		
		addToSymbolTable(yyvsp[-5].string,n*yyvsp[-3].code,s,lst);
	;
    break;}
case 34:
#line 115 "bison_file.y"
{addToSymbolTable(yyvsp[-1].string,1,0,NULL);;
    break;}
case 35:
#line 116 "bison_file.y"
{addToSymbolTable(yyvsp[-1].string,1,0,NULL);;
    break;}
case 36:
#line 118 "bison_file.y"
{
		s=1;

	;
    break;}
case 37:
#line 123 "bison_file.y"
{ 
		lst[s-o].size=yyvsp[-3].code;/* calcultes size of each dimentiob*/
		lst[s-o].sumsize=n*yyvsp[-3].code;/* sum of array*/
		
		addToSymbolTable(yyvsp[-5].string,n*yyvsp[-3].code,s,lst);
	;
    break;}
case 39:
#line 131 "bison_file.y"
{;
    break;}
case 40:
#line 134 "bison_file.y"
{s=s+1;;
    break;}
case 41:
#line 136 "bison_file.y"
{
			n=n*yyvsp[-3].code; 
			yyval.code=lst; 
			lst[s-o].size=yyvsp[-3].code;/* calcultes size of each dimentiob*/
			lst[s-o].sumsize=n;/* sum of array*/
			
			o=o+1;
		;
    break;}
case 42:
#line 144 "bison_file.y"
{;
    break;}
case 43:
#line 145 "bison_file.y"
{
		n=1;
		o=1;
		lst =(arrLST*)malloc(sizeof(arrLST)*s); 
		
		yyval.code=NULL;
	;
    break;}
case 44:
#line 155 "bison_file.y"
{updateVarType(BOOLEAN);;
    break;}
case 45:
#line 157 "bison_file.y"
{updateVarType(INTEGER);;
    break;}
case 46:
#line 159 "bison_file.y"
{updateVarType(FLOAT);;
    break;}
case 47:
#line 163 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 48:
#line 165 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 49:
#line 168 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 50:
#line 171 "bison_file.y"
{yyval.node=yyvsp[-1].node;;
    break;}
case 51:
#line 172 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 52:
#line 173 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 53:
#line 174 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 54:
#line 177 "bison_file.y"
{yyval.node=makenode(ASSIGN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 55:
#line 180 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 56:
#line 181 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-5].node,yyvsp[-3].node,yyvsp[-1].node,0,NULL);;
    break;}
case 57:
#line 184 "bison_file.y"
{yyval.node=makenode(WHILE,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 58:
#line 187 "bison_file.y"
{yyval.node=makenode(CASESTAT,yyvsp[-4].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 59:
#line 190 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 60:
#line 191 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 61:
#line 193 "bison_file.y"
{yyval.node=makenode(CASE,NULL,yyvsp[0].node,NULL,yyvsp[-2].code,NULL);;
    break;}
case 62:
#line 197 "bison_file.y"
{ printf("struct_acc->"); ;
    break;}
case 63:
#line 198 "bison_file.y"
{ yyval.node = genLeaf(IDE,0,0,yyvsp[0].string);;
    break;}
case 64:
#line 199 "bison_file.y"
{yyval.node = genLeaf(POINTER,0,0,yyvsp[0].string);;
    break;}
case 65:
#line 200 "bison_file.y"
{s=0; lst=findSymbol(yyvsp[-3].string)->lst;;
    break;}
case 66:
#line 202 "bison_file.y"
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
case 67:
#line 224 "bison_file.y"
{printf("struct_tail->");;
    break;}
case 68:
#line 225 "bison_file.y"
{printf("\n");;
    break;}
case 69:
#line 233 "bison_file.y"
{s=s+1;;
    break;}
case 70:
#line 235 "bison_file.y"
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
case 71:
#line 244 "bison_file.y"
{;
    break;}
case 72:
#line 244 "bison_file.y"
{n=1;yyval.node=NULL;
    break;}
case 73:
#line 247 "bison_file.y"
{ yyval.node = makenode(ADD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 74:
#line 248 "bison_file.y"
{ yyval.node = makenode(MMIN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 75:
#line 249 "bison_file.y"
{ yyval.node = makenode(MUL,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 76:
#line 250 "bison_file.y"
{ yyval.node = makenode(DIV,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 77:
#line 251 "bison_file.y"
{ yyval.node = makenode(MOD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 78:
#line 252 "bison_file.y"
{ yyval.node = makenode(LES,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 79:
#line 253 "bison_file.y"
{ yyval.node = makenode(LEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 80:
#line 254 "bison_file.y"
{ yyval.node = makenode(EQU,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 81:
#line 255 "bison_file.y"
{ yyval.node = makenode(NEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 82:
#line 256 "bison_file.y"
{ yyval.node = makenode(GRE,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 83:
#line 257 "bison_file.y"
{ yyval.node = makenode(GEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 84:
#line 258 "bison_file.y"
{ yyval.node = makenode(AND,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 85:
#line 259 "bison_file.y"
{ yyval.node = makenode(OR,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 86:
#line 260 "bison_file.y"
{ yyval.node = yyvsp[-1].node; ;
    break;}
case 87:
#line 261 "bison_file.y"
{ yyval.node = makenode(CAST,yyvsp[-1].node,NULL,NULL,0,NULL); ;
    break;}
case 88:
#line 262 "bison_file.y"
{ yyval.node = makenode(NOT,yyvsp[0].node,NULL,NULL,0,NULL); ;
    break;}
case 89:
#line 263 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 90:
#line 267 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 91:
#line 268 "bison_file.y"
{ yyval.node = genLeaf(INTCONST,yyvsp[0].code,0,NULL); ;
    break;}
case 92:
#line 269 "bison_file.y"
{ yyval.node = genLeaf(REALCONST,0,yyvsp[0].real,NULL);;
    break;}
case 93:
#line 270 "bison_file.y"
{ yyval.node = genLeaf(TRUE,0,0,NULL); ;
    break;}
case 94:
#line 271 "bison_file.y"
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
#line 275 "bison_file.y"
