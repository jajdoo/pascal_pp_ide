
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
#define	PROC_CALL	317
#define	INTCONST	318
#define	IDE	319
#define	POINTER	320
#define	REALCONST	321
#define	STRING	322
#define	DUMMY	323

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



#define	YYFINAL		169
#define	YYFLAG		-32768
#define	YYNTBASE	77

#define YYTRANSLATE(x) ((unsigned)(x) <= 323 ? yytranslate[x] : 118)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    71,
    72,     2,     2,    73,     2,    74,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    70,    69,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    75,     2,    76,     2,     2,     2,     2,     2,     2,     2,
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
    66,    67,    68
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     5,    13,    14,    22,    24,    25,    27,    31,
    34,    37,    40,    43,    44,    46,    48,    49,    56,    58,
    60,    62,    64,    66,    67,    76,    79,    80,    81,    87,
    91,    92,    94,   100,   103,   104,   108,   109,   111,   114,
   116,   119,   121,   123,   125,   129,   135,   143,   149,   156,
   158,   161,   165,   169,   171,   173,   174,   181,   183,   187,
   188,   194,   195,   197,   201,   205,   209,   213,   217,   221,
   225,   229,   233,   237,   241,   245,   249,   253,   258,   261,
   263,   265,   267,   269,   271
};

static const short yyrhs[] = {     3,
    64,    84,     0,     0,    57,    64,    79,    17,    80,    18,
    69,     0,     0,    55,    81,    89,    70,    83,    69,    82,
     0,    80,     0,     0,    64,     0,    17,    85,    18,     0,
    91,    85,     0,   102,    85,     0,    98,    85,     0,    86,
    85,     0,     0,    78,     0,    87,     0,     0,    55,    88,
    89,    70,    90,    69,     0,    13,     0,     9,     0,    10,
     0,    64,     0,    65,     0,     0,     4,    64,    92,    71,
    93,    72,    84,    69,     0,    94,    96,     0,     0,     0,
    55,    95,    89,    70,    97,     0,    73,    94,    96,     0,
     0,    64,     0,    64,    71,    99,    72,    69,     0,   116,
   100,     0,     0,    73,   116,   100,     0,     0,   102,     0,
   102,   101,     0,   103,     0,   104,    69,     0,   105,     0,
   106,     0,   107,     0,   110,    16,   116,     0,    19,   116,
    20,   101,    22,     0,    19,   116,    20,   101,    21,   101,
    22,     0,    23,   116,    25,   101,    26,     0,    46,   116,
    15,    17,   108,    18,     0,   109,     0,   109,   108,     0,
    63,    70,   101,     0,    64,    74,   112,     0,    64,     0,
    65,     0,     0,    64,    75,   116,    76,   111,   113,     0,
    64,     0,    64,    74,   112,     0,     0,    75,   116,    76,
   114,   113,     0,     0,   115,     0,   116,    31,   116,     0,
   116,    32,   116,     0,   116,    33,   116,     0,   116,    34,
   116,     0,   116,    36,   116,     0,   116,    37,   116,     0,
   116,    38,   116,     0,   116,    39,   116,     0,   116,    40,
   116,     0,   116,    41,   116,     0,   116,    42,   116,     0,
   116,    43,   116,     0,   116,    44,   116,     0,    71,   116,
    72,     0,    89,    71,   116,    72,     0,    45,   117,     0,
   117,     0,   110,     0,    63,     0,    66,     0,    29,     0,
    30,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    52,    59,    70,    78,    83,    86,    88,    91,   103,   107,
   109,   110,   111,   112,   116,   118,   122,   124,   128,   130,
   131,   135,   141,   153,   163,   173,   175,   178,   184,   187,
   189,   192,   210,   219,   221,   224,   226,   233,   234,   237,
   240,   241,   242,   243,   246,   249,   250,   253,   256,   259,
   260,   262,   265,   267,   268,   269,   271,   293,   294,   301,
   304,   313,   313,   316,   317,   318,   319,   320,   321,   322,
   323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
   336,   337,   338,   339,   340
};

static const char * const yytname[] = {   "$","error","$undefined.","PROGRAM",
"PROCEDURE","BBEGIN","END","DECLARE","LABEL","INTEGER","FLOAT","REAL","CMP",
"BOOLEAN","ARRAY","OF","ASSIGN","LC","RC","IF","THEN","ELSE","FI","WHILE","REPEAT",
"DO","OD","READ","WRITE","TRUE","FALSE","ADD","MMIN","MUL","DIV","GOTO","MOD",
"LES","LEQ","EQU","NEQ","GRE","GEQ","AND","OR","NOT","CASE","FOR","FIN","IDENTICAL",
"FROM","BY","TO","CONST","TYPE","VAR","RECORD","STRUCT","CAST","STATEMENT","DECLARATION",
"BLOCK_BODY","PROC_CALL","INTCONST","IDE","POINTER","REALCONST","STRING","DUMMY",
"';'","':'","'('","')'","','","'.'","'['","']'","program","struct_decl","@1",
"member_decl","@2","member_decl_tail","member_id_list","block","dec_or_stat",
"declaration","var_decl","@3","type_list","id_list","procedure","@4","param_decl",
"param","@5","param_decl_tail","param_id_list","proc_call","args","args_tail",
"stat_seq","stat","nonlable_stat","assign","cond_stat","loop_stat","case_stat",
"case_list","case","var","@6","struct_acc_tail","bracket","@7","@8","expr","atom",
""
};
#endif

static const short yyr1[] = {     0,
    77,    79,    78,    81,    80,    82,    82,    83,    84,    85,
    85,    85,    85,    85,    86,    86,    88,    87,    89,    89,
    89,    90,    90,    92,    91,    93,    93,    95,    94,    96,
    96,    97,    98,    99,    99,   100,   100,   101,   101,   102,
   103,   103,   103,   103,   104,   105,   105,   106,   107,   108,
   108,   109,   110,   110,   110,   111,   110,   112,   112,   114,
   113,   115,   113,   116,   116,   116,   116,   116,   116,   116,
   116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
   117,   117,   117,   117,   117
};

static const short yyr2[] = {     0,
     3,     0,     7,     0,     7,     1,     0,     1,     3,     2,
     2,     2,     2,     0,     1,     1,     0,     6,     1,     1,
     1,     1,     1,     0,     8,     2,     0,     0,     5,     3,
     0,     1,     5,     2,     0,     3,     0,     1,     2,     1,
     2,     1,     1,     1,     3,     5,     7,     5,     6,     1,
     2,     3,     3,     1,     1,     0,     6,     1,     3,     0,
     5,     0,     1,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     4,     2,     1,
     1,     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,    14,     1,     0,     0,     0,     0,    17,     0,
    54,    55,    15,     0,    14,    16,    14,    14,    14,    40,
     0,    42,    43,    44,     0,    24,    20,    21,    19,    84,
    85,     0,    82,    54,    83,     0,     0,    81,     0,    80,
     0,     0,     0,     2,    35,     0,     0,     9,    13,    10,
    12,    11,    41,     0,     0,    79,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    37,    58,    53,
     0,    45,    27,    77,     0,     0,    38,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
     0,     0,     0,     0,     0,     0,    34,     0,    56,    28,
     0,    31,    78,     0,    46,    39,    48,     0,     0,    50,
    22,    23,     0,     4,     0,    33,    37,    59,    62,     0,
     0,     0,    26,     0,     0,    49,    51,    18,     0,     0,
    36,     0,    57,    63,     0,     0,    31,    47,    52,     0,
     3,     0,     0,    25,    30,     0,    60,    32,    29,     8,
     0,    62,     7,    61,     6,     5,     0,     0,     0
};

static const short yydefgoto[] = {   167,
    13,    76,   125,   139,   166,   161,     4,    14,    15,    16,
    43,    37,   123,    17,    55,   111,   112,   130,   133,   159,
    18,    77,   107,    86,    19,    20,    21,    22,    23,    24,
   119,   120,    38,   129,    80,   143,   162,   144,    39,    40
};

static const short yypact[] = {     1,
   -58,    -5,    74,-32768,   -37,    62,    62,    62,-32768,   -27,
   -40,-32768,-32768,     5,    74,-32768,    74,    74,    74,-32768,
   -30,-32768,-32768,-32768,    25,-32768,-32768,-32768,-32768,-32768,
-32768,   157,-32768,   -54,-32768,    62,   -26,-32768,   227,-32768,
   247,   202,    23,-32768,    62,   -14,    62,-32768,-32768,-32768,
-32768,-32768,-32768,    62,   -19,-32768,   141,    62,   -16,    62,
    62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
    62,    62,   -16,    51,     0,    59,    10,   127,     3,-32768,
    72,   261,    24,-32768,   165,    22,   -16,   -25,   -25,-32768,
-32768,-32768,   275,   275,   275,   275,   275,   275,-32768,   -25,
    55,    20,     9,    29,    16,    62,-32768,   -14,-32768,-32768,
    14,    15,-32768,   -16,-32768,-32768,-32768,    17,    77,    20,
-32768,-32768,    27,-32768,    82,-32768,   127,-32768,    26,    23,
    -5,    24,-32768,    80,   -16,-32768,-32768,-32768,    23,    48,
-32768,    62,-32768,-32768,    49,    53,    15,-32768,-32768,    54,
-32768,   113,    66,-32768,-32768,    68,-32768,-32768,-32768,-32768,
    65,    26,    29,-32768,-32768,-32768,   118,   123,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,   -23,-32768,-32768,-32768,     6,    -2,-32768,-32768,
-32768,   -41,-32768,-32768,-32768,-32768,     4,-32768,    -6,-32768,
-32768,-32768,    35,   -68,   -45,-32768,-32768,-32768,-32768,-32768,
    56,-32768,     7,-32768,    83,    28,-32768,-32768,    -7,   111
};


#define	YYLAST		319


static const short yytable[] = {    41,
    42,    75,     6,     1,   101,     2,     7,    62,    63,    25,
    64,     3,    49,    87,    50,    51,    52,    71,   116,    46,
    47,    25,    48,    25,    25,    25,    26,    87,    57,     8,
    45,    27,    28,    46,    47,    29,    44,    78,    53,    81,
    54,    87,   114,   115,    58,   134,    82,    34,    12,    79,
    85,    83,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,    25,   149,   102,    87,   103,
    27,    28,   121,   122,    29,   104,   108,     5,   110,    25,
   117,   105,   118,   124,   126,   131,   135,   132,   145,    87,
    30,    31,     6,    25,   136,   138,     7,   150,   127,   140,
   142,   148,    60,    61,    62,    63,    32,    64,    65,    66,
    67,    68,    69,    70,    71,    72,   151,   168,   153,     8,
    25,   154,   169,   156,    33,    34,    12,    35,     9,   158,
    10,   160,    36,   163,   152,   147,   146,    11,    12,   165,
   155,    25,    56,    60,    61,    62,    63,   109,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    60,    61,    62,
    63,   141,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    60,    61,    62,    63,   137,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    30,    31,     0,   157,   164,
   128,     0,     0,     0,     0,    60,    61,    62,    63,   106,
    64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
     0,     0,    84,     0,     0,     0,    74,     0,     0,    33,
    34,    12,    35,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    60,    61,    62,    63,   113,    64,    65,    66,
    67,    68,    69,    70,    71,    72,    59,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
    63,     0,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    73,     0,     0,     0,     0,     0,    60,    61,    62,
    63,     0,    64,    65,    66,    67,    68,    69,    70,    71,
    72,    60,    61,    62,    63,     0,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    60,    61,    62,    63,     0,
    64,-32768,-32768,-32768,-32768,-32768,-32768,    71,    72
};

static const short yycheck[] = {     7,
     8,    43,    19,     3,    73,    64,    23,    33,    34,     3,
    36,    17,    15,    59,    17,    18,    19,    43,    87,    74,
    75,    15,    18,    17,    18,    19,    64,    73,    36,    46,
    71,     9,    10,    74,    75,    13,    64,    45,    69,    47,
    16,    87,    21,    22,    71,   114,    54,    64,    65,    64,
    58,    71,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    59,   135,    17,   114,    70,
     9,    10,    64,    65,    13,    17,    74,     4,    55,    73,
    26,    72,    63,    55,    69,    72,    70,    73,   130,   135,
    29,    30,    19,    87,    18,    69,    23,   139,   106,    18,
    75,    22,    31,    32,    33,    34,    45,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    69,     0,    70,    46,
   114,    69,     0,    70,    63,    64,    65,    66,    55,    64,
    57,    64,    71,    69,   142,   132,   131,    64,    65,   163,
   147,   135,    32,    31,    32,    33,    34,    76,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    31,    32,    33,
    34,   127,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    31,    32,    33,    34,   120,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    29,    30,    -1,    76,   162,
   108,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    73,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
    -1,    -1,    72,    -1,    -1,    -1,    15,    -1,    -1,    63,
    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    31,    32,    33,    34,    72,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    20,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
    34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
    34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
    40,    41,    42,    43,    44,    31,    32,    33,    34,    -1,
    36,    37,    38,    39,    40,    41,    42,    43,    44
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
#line 61 "bison_file.y"
{
				symbol_new();
				symbol_set_isstruct(1); //symbol_stack_set_isstruct(1);
				symbol_set_name(yyvsp[0].string); //symbol_stack_set_name($2);
				symbol_set_address(-1);
				symbol_set_type(0); 
				symbol_finish();
				enter_block(yyvsp[0].string);
			;
    break;}
case 3:
#line 71 "bison_file.y"
{
				exit_block();
				//symbol_stack_pop();
			;
    break;}
case 4:
#line 80 "bison_file.y"
{  symbol_new();  /*symbol_stack_push();*/ 
				   symbol_set_isstructmember(1);
				;
    break;}
case 5:
#line 83 "bison_file.y"
{ ;
    break;}
case 6:
#line 87 "bison_file.y"
{;
    break;}
case 7:
#line 88 "bison_file.y"
{;
    break;}
case 8:
#line 93 "bison_file.y"
{
			symbol_set_name(yyvsp[0].string); 
			symbol_finish();
		;
    break;}
case 9:
#line 103 "bison_file.y"
{yyval.node=makenode(BBEGIN,yyvsp[-1].node,NULL,NULL,0,NULL);;
    break;}
case 10:
#line 108 "bison_file.y"
{yyval.node=makenode(BLOCK_BODY,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 11:
#line 109 "bison_file.y"
{yyval.node=makenode(BLOCK_BODY,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 12:
#line 110 "bison_file.y"
{yyval.node=yyvsp[-1].node;;
    break;}
case 13:
#line 111 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 14:
#line 112 "bison_file.y"
{yyval.node=NULL;;
    break;}
case 15:
#line 117 "bison_file.y"
{ yyval.node = NULL; ;
    break;}
case 16:
#line 118 "bison_file.y"
{ yyval.node = NULL; ;
    break;}
case 17:
#line 123 "bison_file.y"
{ symbol_new(); ;
    break;}
case 18:
#line 124 "bison_file.y"
{ ;
    break;}
case 19:
#line 129 "bison_file.y"
{ symbol_set_type(BOOLEAN); ;
    break;}
case 20:
#line 130 "bison_file.y"
{ symbol_set_type(INTEGER); ;
    break;}
case 21:
#line 131 "bison_file.y"
{ symbol_set_type(FLOAT); ;
    break;}
case 22:
#line 137 "bison_file.y"
{
			symbol_set_name(yyvsp[0].string); 
			symbol_finish();
		;
    break;}
case 23:
#line 143 "bison_file.y"
{
			//symbol_stack_set_ispointer(1);
			//symbol_stack_set_name($1);
			//symbol_stack_pop();
		;
    break;}
case 24:
#line 155 "bison_file.y"
{
				symbol_new();
				symbol_set_name(yyvsp[0].string);
				symbol_set_isprocedure(1);
				symbol_finish();
				enter_block(yyvsp[0].string);
				printf("entering conext %s\n", yyvsp[0].string);
			;
    break;}
case 25:
#line 164 "bison_file.y"
{
				printSymbolTable();
				exit_block();

				printf("exiting conext\n"); 
				yyval.node = makenode(PROCEDURE, yyvsp[-1].node, NULL, NULL, 0, NULL);
			;
    break;}
case 26:
#line 174 "bison_file.y"
{ ;
    break;}
case 27:
#line 175 "bison_file.y"
{ ;
    break;}
case 28:
#line 180 "bison_file.y"
{ 
		symbol_new();
		symbol_set_isparam(1);
	;
    break;}
case 30:
#line 188 "bison_file.y"
{;
    break;}
case 31:
#line 189 "bison_file.y"
{;
    break;}
case 32:
#line 194 "bison_file.y"
{
		symbol_set_name(yyvsp[0].string);
		symbol_finish();
	;
    break;}
case 33:
#line 212 "bison_file.y"
{ 
		printf("FUNCTION CALL %s\n\n", yyvsp[-4].string); 
		yyval.node = makenode(PROC_CALL,NULL,NULL,NULL,0,NULL);
	;
    break;}
case 34:
#line 220 "bison_file.y"
{ printf(" ARG %d\n", yyvsp[-1].node->num_val ); ;
    break;}
case 36:
#line 225 "bison_file.y"
{ printf(" ARG %d\n", yyvsp[-1].node->num_val); ;
    break;}
case 37:
#line 226 "bison_file.y"
{ printf(" ARGS FINISH\n"); ;
    break;}
case 38:
#line 233 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 39:
#line 234 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 40:
#line 237 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 41:
#line 240 "bison_file.y"
{yyval.node=yyvsp[-1].node;;
    break;}
case 42:
#line 241 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 43:
#line 242 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 44:
#line 243 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 45:
#line 246 "bison_file.y"
{yyval.node=makenode(ASSIGN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 46:
#line 249 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 47:
#line 250 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-5].node,yyvsp[-3].node,yyvsp[-1].node,0,NULL);;
    break;}
case 48:
#line 253 "bison_file.y"
{yyval.node=makenode(WHILE,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 49:
#line 256 "bison_file.y"
{yyval.node=makenode(CASESTAT,yyvsp[-4].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 50:
#line 259 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 51:
#line 260 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 52:
#line 262 "bison_file.y"
{yyval.node=makenode(CASE,NULL,yyvsp[0].node,NULL,yyvsp[-2].code,NULL);;
    break;}
case 53:
#line 266 "bison_file.y"
{ printf("struct_acc->"); ;
    break;}
case 54:
#line 267 "bison_file.y"
{ yyval.node = genLeaf(IDE,0,0,yyvsp[0].string);;
    break;}
case 55:
#line 268 "bison_file.y"
{yyval.node = genLeaf(POINTER,0,0,yyvsp[0].string);;
    break;}
case 56:
#line 269 "bison_file.y"
{s=0; /*lst=findSymbol($1)->lst;*/;
    break;}
case 57:
#line 271 "bison_file.y"
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
case 58:
#line 293 "bison_file.y"
{printf("struct_tail->");;
    break;}
case 59:
#line 294 "bison_file.y"
{printf("\n");;
    break;}
case 60:
#line 302 "bison_file.y"
{s=s+1;;
    break;}
case 61:
#line 304 "bison_file.y"
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
case 62:
#line 313 "bison_file.y"
{;
    break;}
case 63:
#line 313 "bison_file.y"
{n=1;yyval.node=NULL;
    break;}
case 64:
#line 316 "bison_file.y"
{ yyval.node = makenode(ADD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 65:
#line 317 "bison_file.y"
{ yyval.node = makenode(MMIN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 66:
#line 318 "bison_file.y"
{ yyval.node = makenode(MUL,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 67:
#line 319 "bison_file.y"
{ yyval.node = makenode(DIV,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 68:
#line 320 "bison_file.y"
{ yyval.node = makenode(MOD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 69:
#line 321 "bison_file.y"
{ yyval.node = makenode(LES,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 70:
#line 322 "bison_file.y"
{ yyval.node = makenode(LEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 71:
#line 323 "bison_file.y"
{ yyval.node = makenode(EQU,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 72:
#line 324 "bison_file.y"
{ yyval.node = makenode(NEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 73:
#line 325 "bison_file.y"
{ yyval.node = makenode(GRE,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 74:
#line 326 "bison_file.y"
{ yyval.node = makenode(GEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 75:
#line 327 "bison_file.y"
{ yyval.node = makenode(AND,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 76:
#line 328 "bison_file.y"
{ yyval.node = makenode(OR,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 77:
#line 329 "bison_file.y"
{ yyval.node = yyvsp[-1].node; ;
    break;}
case 78:
#line 330 "bison_file.y"
{ yyval.node = makenode(CAST,yyvsp[-1].node,NULL,NULL,0,NULL); ;
    break;}
case 79:
#line 331 "bison_file.y"
{ yyval.node = makenode(NOT,yyvsp[0].node,NULL,NULL,0,NULL); ;
    break;}
case 80:
#line 332 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 81:
#line 336 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 82:
#line 337 "bison_file.y"
{ yyval.node = genLeaf(INTCONST,yyvsp[0].code,0,NULL); ;
    break;}
case 83:
#line 338 "bison_file.y"
{ yyval.node = genLeaf(REALCONST,0,yyvsp[0].real,NULL);;
    break;}
case 84:
#line 339 "bison_file.y"
{ yyval.node = genLeaf(TRUE,0,0,NULL); ;
    break;}
case 85:
#line 340 "bison_file.y"
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
#line 344 "bison_file.y"
