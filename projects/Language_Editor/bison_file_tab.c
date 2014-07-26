
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
#define	VAL	311
#define	RECORD	312
#define	STRUCT	313
#define	CAST	314
#define	STATEMENT	315
#define	DECLARATION	316
#define	BLOCK_BODY	317
#define	PROC_CALL	318
#define	ARGUMENT_LIST	319
#define	STRUCT_ACC	320
#define	INTCONST	321
#define	IDE	322
#define	POINTER	323
#define	REALCONST	324
#define	STRING	325
#define	DUMMY	326

#line 2 "bison_file.y"

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



#define	YYFINAL		189
#define	YYFLAG		-32768
#define	YYNTBASE	80

#define YYTRANSLATE(x) ((unsigned)(x) <= 326 ? yytranslate[x] : 128)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    74,
    75,     2,     2,    76,     2,    79,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    73,    72,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    77,     2,    78,     2,     2,     2,     2,     2,     2,     2,
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
    66,    67,    68,    69,    70,    71
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     5,    13,    14,    22,    28,    30,    31,    33,
    37,    40,    43,    46,    49,    50,    52,    54,    56,    62,
    63,    70,    72,    74,    76,    78,    80,    81,    90,    93,
    94,    98,    99,   104,   110,   112,   114,   116,   117,   124,
   125,   129,   130,   131,   136,   137,   139,   142,   144,   147,
   149,   151,   153,   157,   163,   171,   177,   184,   186,   189,
   193,   195,   197,   199,   200,   207,   208,   213,   215,   216,
   221,   222,   228,   229,   231,   235,   239,   243,   247,   251,
   255,   259,   263,   267,   271,   275,   279,   283,   287,   292,
   295,   297,   299,   301,   303,   305
};

static const short yyrhs[] = {     3,
    67,    87,     0,     0,    58,    67,    82,    17,    83,    18,
    72,     0,     0,    55,    84,    93,    73,    86,    72,    85,
     0,    58,    67,    73,    67,    72,     0,    83,     0,     0,
    67,     0,    17,    88,    18,     0,    95,    88,     0,   109,
    88,     0,   102,    88,     0,    89,    88,     0,     0,    81,
     0,    90,     0,    91,     0,    58,    67,    73,    67,    72,
     0,     0,    55,    92,    93,    73,    94,    72,     0,    13,
     0,     9,     0,    10,     0,    67,     0,    68,     0,     0,
     4,    67,    96,    74,    97,    75,    87,    72,     0,    99,
    98,     0,     0,    76,    99,    98,     0,     0,   100,    93,
    73,   101,     0,   100,    58,    67,    73,    67,     0,    55,
     0,    56,     0,    67,     0,     0,    67,   103,    74,   104,
    75,    72,     0,     0,   126,   105,   106,     0,     0,     0,
    76,   126,   107,   106,     0,     0,   109,     0,   109,   108,
     0,   110,     0,   111,    72,     0,   112,     0,   113,     0,
   114,     0,   117,    16,   126,     0,    19,   126,    20,   108,
    22,     0,    19,   126,    20,   108,    21,   108,    22,     0,
    23,   126,    25,   108,    26,     0,    46,   126,    15,    17,
   115,    18,     0,   116,     0,   116,   115,     0,    66,    73,
   108,     0,   119,     0,    67,     0,    68,     0,     0,    67,
    77,   126,    78,   118,   123,     0,     0,    67,   120,    79,
   121,     0,    67,     0,     0,    67,   122,    79,   121,     0,
     0,    77,   126,    78,   124,   123,     0,     0,   125,     0,
   126,    31,   126,     0,   126,    32,   126,     0,   126,    33,
   126,     0,   126,    34,   126,     0,   126,    36,   126,     0,
   126,    37,   126,     0,   126,    38,   126,     0,   126,    39,
   126,     0,   126,    40,   126,     0,   126,    41,   126,     0,
   126,    42,   126,     0,   126,    43,   126,     0,   126,    44,
   126,     0,    74,   126,    75,     0,    93,    74,   126,    75,
     0,    45,   127,     0,   127,     0,   117,     0,    66,     0,
    69,     0,    29,     0,    30,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    53,    62,    72,    79,    85,    86,   102,   104,   107,   119,
   128,   130,   131,   132,   133,   141,   143,   144,   153,   174,
   176,   180,   182,   183,   187,   193,   220,   229,   236,   238,
   241,   243,   246,   248,   261,   267,   275,   297,   302,   313,
   315,   316,   319,   321,   322,   329,   330,   333,   336,   337,
   338,   339,   342,   345,   346,   349,   352,   355,   356,   358,
   361,   363,   364,   365,   367,   412,   417,   430,   445,   450,
   466,   469,   478,   478,   481,   482,   483,   484,   485,   486,
   487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
   497,   501,   502,   503,   504,   505
};

static const char * const yytname[] = {   "$","error","$undefined.","PROGRAM",
"PROCEDURE","BBEGIN","END","DECLARE","LABEL","INTEGER","FLOAT","REAL","CMP",
"BOOLEAN","ARRAY","OF","ASSIGN","LC","RC","IF","THEN","ELSE","FI","WHILE","REPEAT",
"DO","OD","READ","WRITE","TRUE","FALSE","ADD","MMIN","MUL","DIV","GOTO","MOD",
"LES","LEQ","EQU","NEQ","GRE","GEQ","AND","OR","NOT","CASE","FOR","FIN","IDENTICAL",
"FROM","BY","TO","CONST","TYPE","VAR","VAL","RECORD","STRUCT","CAST","STATEMENT",
"DECLARATION","BLOCK_BODY","PROC_CALL","ARGUMENT_LIST","STRUCT_ACC","INTCONST",
"IDE","POINTER","REALCONST","STRING","DUMMY","';'","':'","'('","')'","','","'['",
"']'","'.'","program","struct_decl","@1","member_decl","@2","member_decl_tail",
"member_id_list","block","dec_or_stat","declaration","struct_def","var_decl",
"@3","type_list","id_list","procedure","@4","param_decl","param_decl_tail","param",
"var_or_val","param_id_list","proc_call","@5","args","@6","args_tail","@7","stat_seq",
"stat","nonlable_stat","assign","cond_stat","loop_stat","case_stat","case_list",
"case","var","@8","struct_acc","@9","struct_acc_tail","@10","bracket","@11",
"@12","expr","atom",""
};
#endif

static const short yyr1[] = {     0,
    80,    82,    81,    84,    83,    83,    85,    85,    86,    87,
    88,    88,    88,    88,    88,    89,    89,    89,    90,    92,
    91,    93,    93,    93,    94,    94,    96,    95,    97,    97,
    98,    98,    99,    99,   100,   100,   101,   103,   102,   105,
   104,   104,   107,   106,   106,   108,   108,   109,   110,   110,
   110,   110,   111,   112,   112,   113,   114,   115,   115,   116,
   117,   117,   117,   118,   117,   120,   119,   121,   122,   121,
   124,   123,   125,   123,   126,   126,   126,   126,   126,   126,
   126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
   126,   127,   127,   127,   127,   127
};

static const short yyr2[] = {     0,
     3,     0,     7,     0,     7,     5,     1,     0,     1,     3,
     2,     2,     2,     2,     0,     1,     1,     1,     5,     0,
     6,     1,     1,     1,     1,     1,     0,     8,     2,     0,
     3,     0,     4,     5,     1,     1,     1,     0,     6,     0,
     3,     0,     0,     4,     0,     1,     2,     1,     2,     1,
     1,     1,     3,     5,     7,     5,     6,     1,     2,     3,
     1,     1,     1,     0,     6,     0,     4,     1,     0,     4,
     0,     5,     0,     1,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     4,     2,
     1,     1,     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,    15,     1,     0,     0,     0,     0,    20,     0,
    38,    63,    16,     0,    15,    17,    18,    15,    15,    15,
    48,     0,    50,    51,    52,     0,    61,    27,    23,    24,
    22,    95,    96,     0,    93,    62,    94,     0,     0,    92,
     0,    91,     0,     0,     0,     2,     0,     0,     0,    10,
    14,    11,    13,    12,    49,     0,     0,    90,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    42,     0,    53,    30,    88,     0,     0,    46,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
    87,     0,     0,     0,     0,     0,    64,     0,    40,    68,
    67,    35,    36,     0,    32,     0,    89,     0,    54,    47,
    56,     0,     0,    58,    25,    26,     0,    19,     4,     0,
     0,    73,     0,    45,     0,     0,     0,    29,     0,     0,
     0,     0,    57,    59,    21,     0,     0,     0,     0,    65,
    74,    39,     0,    41,     0,     0,    32,     0,     0,    55,
    60,     0,     0,     3,     0,    43,    70,    28,    31,     0,
    37,    33,     0,     0,    71,    45,    34,     9,     0,     6,
    73,    44,     8,    72,     7,     5,     0,     0,     0
};

static const short yydefgoto[] = {   187,
    13,    79,   131,   146,   186,   179,     4,    14,    15,    16,
    17,    45,    39,   127,    18,    57,   114,   138,   115,   116,
   172,    19,    48,   108,   134,   154,   176,    87,    20,    21,
    22,    23,    24,    25,   123,   124,    40,   132,    27,    49,
   111,   135,   150,   181,   151,    41,    42
};

static const short yypact[] = {     5,
   -55,     0,    65,-32768,   -47,    70,    70,    70,-32768,   -35,
    -2,-32768,-32768,    21,    65,-32768,-32768,    65,    65,    65,
-32768,   -36,-32768,-32768,-32768,    27,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    60,-32768,   -66,-32768,    70,   -29,-32768,
   207,-32768,   227,   192,    28,   -26,    70,   -22,    -3,-32768,
-32768,-32768,-32768,-32768,-32768,    70,     4,-32768,   147,    70,
    25,    70,    70,    70,    70,    70,    70,    70,    70,    70,
    70,    70,    70,    70,    25,    64,    14,    24,    77,   119,
    70,    30,   241,   -32,-32768,   162,    29,    25,   -15,   -15,
-32768,-32768,-32768,   255,   255,   255,   255,   255,   255,-32768,
   -15,    72,    35,    18,    32,   -51,-32768,    31,   241,    23,
-32768,-32768,-32768,    33,    34,    -4,-32768,    25,-32768,-32768,
-32768,    36,    87,    35,-32768,-32768,    40,-32768,-32768,    46,
    89,    37,    44,    41,    39,     0,   -32,-32768,    52,    48,
   100,    25,-32768,-32768,-32768,    28,    51,    58,    70,-32768,
-32768,-32768,    70,-32768,    30,    59,    34,    61,    68,-32768,
-32768,    67,    74,-32768,   133,   241,-32768,-32768,-32768,    76,
-32768,-32768,    78,    75,-32768,    41,-32768,-32768,    82,-32768,
    37,-32768,   -51,-32768,-32768,-32768,   148,   168,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,    -1,-32768,-32768,-32768,    56,    15,-32768,-32768,
-32768,-32768,   -43,-32768,-32768,-32768,-32768,    53,    71,-32768,
-32768,-32768,-32768,-32768,-32768,    38,-32768,   -72,   -46,-32768,
-32768,-32768,-32768,-32768,    85,-32768,     7,-32768,-32768,-32768,
    57,-32768,    73,-32768,-32768,    -7,   179
};


#define	YYLAST		299


static const short yytable[] = {    43,
    44,    77,   102,   129,    29,    30,   130,     1,    31,    26,
    47,     2,   -66,   -62,    88,   120,     3,    64,    65,    28,
    66,    26,   112,   113,    26,    26,    26,    73,    88,    51,
    59,    46,    52,    53,    54,    55,    29,    30,    50,    80,
    31,    88,    56,     6,    60,   141,    78,     7,    83,   118,
   119,    81,    86,   139,    89,    90,    91,    92,    93,    94,
    95,    96,    97,    98,    99,   100,   101,    26,     5,   161,
     8,    88,   140,   109,    47,    82,   -66,    84,    29,    30,
   103,    26,    31,     6,   125,   126,   104,     7,    32,    33,
   105,    36,    12,   106,    26,    88,   110,   121,    32,    33,
   122,   -69,   162,   128,   143,   133,   148,   136,   142,   137,
     8,   145,   147,   149,    34,   152,   153,   155,   158,     9,
   159,   160,    10,   163,    26,    35,    36,    12,    37,   164,
   168,    11,    12,   170,   171,    35,    36,    12,    37,   173,
   174,   165,   177,    38,   178,   166,   180,   188,    26,    62,
    63,    64,    65,   183,    66,    67,    68,    69,    70,    71,
    72,    73,    74,    62,    63,    64,    65,   189,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    62,    63,    64,
    65,   185,    66,    67,    68,    69,    70,    71,    72,    73,
    74,   156,    62,    63,    64,    65,   107,    66,    67,    68,
    69,    70,    71,    72,    73,    74,    76,   157,   144,   169,
   175,   167,    58,   182,     0,     0,     0,     0,     0,     0,
     0,    85,    62,    63,    64,    65,    61,    66,    67,    68,
    69,    70,    71,    72,    73,    74,   117,    62,    63,    64,
    65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    75,     0,   184,     0,     0,     0,    62,    63,    64,
    65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
    74,    62,    63,    64,    65,     0,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    62,    63,    64,    65,     0,
    66,-32768,-32768,-32768,-32768,-32768,-32768,    73,    74
};

static const short yycheck[] = {     7,
     8,    45,    75,    55,     9,    10,    58,     3,    13,     3,
    77,    67,    79,    16,    61,    88,    17,    33,    34,    67,
    36,    15,    55,    56,    18,    19,    20,    43,    75,    15,
    38,    67,    18,    19,    20,    72,     9,    10,    18,    47,
    13,    88,    16,    19,    74,   118,    73,    23,    56,    21,
    22,    74,    60,    58,    62,    63,    64,    65,    66,    67,
    68,    69,    70,    71,    72,    73,    74,    61,     4,   142,
    46,   118,   116,    81,    77,    79,    79,    74,     9,    10,
    17,    75,    13,    19,    67,    68,    73,    23,    29,    30,
    67,    67,    68,    17,    88,   142,    67,    26,    29,    30,
    66,    79,   146,    72,    18,    75,    18,    75,    73,    76,
    46,    72,    67,    77,    45,    72,    76,    79,    67,    55,
    73,    22,    58,    73,   118,    66,    67,    68,    69,    72,
    72,    67,    68,    73,    67,    66,    67,    68,    69,    73,
    67,   149,    67,    74,    67,   153,    72,     0,   142,    31,
    32,    33,    34,    72,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    31,    32,    33,    34,     0,    36,    37,
    38,    39,    40,    41,    42,    43,    44,    31,    32,    33,
    34,   183,    36,    37,    38,    39,    40,    41,    42,    43,
    44,   136,    31,    32,    33,    34,    78,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    15,   137,   124,   157,
    78,   155,    34,   176,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    75,    31,    32,    33,    34,    20,    36,    37,    38,
    39,    40,    41,    42,    43,    44,    75,    31,    32,    33,
    34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
    44,    25,    -1,   181,    -1,    -1,    -1,    31,    32,    33,
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
#line 53 "bison_file.y"
{yyval.node=makenode(PROGRAM,yyvsp[0].node,NULL,NULL,0,yyvsp[-1].string); root=yyval.node;;
    break;}
case 2:
#line 64 "bison_file.y"
{
				symbol_new();
				symbol_set_isstruct(1);
				symbol_set_name(yyvsp[0].string);
				symbol_set_type(0); 
				symbol_finish();
				enter_block(yyvsp[0].string);
			;
    break;}
case 3:
#line 73 "bison_file.y"
{
				exit_block();
			;
    break;}
case 4:
#line 81 "bison_file.y"
{  
		symbol_new();
		symbol_set_isstructmember(1);
	;
    break;}
case 5:
#line 85 "bison_file.y"
{ ;
    break;}
case 6:
#line 88 "bison_file.y"
{
		symbol_new();
		symbol_set_isstructmember(1);
		if(symbol_set_struct_type(yyvsp[-3].string))
		{
			symbol_set_name(yyvsp[-1].string);
			symbol_finish();
		}
		else
			symbol_cancel();
	;
    break;}
case 7:
#line 103 "bison_file.y"
{;
    break;}
case 8:
#line 104 "bison_file.y"
{;
    break;}
case 9:
#line 109 "bison_file.y"
{
			symbol_set_name(yyvsp[0].string); 
			symbol_finish();
		;
    break;}
case 10:
#line 119 "bison_file.y"
{yyval.node=makenode(BBEGIN,yyvsp[-1].node,NULL,NULL,0,NULL);;
    break;}
case 11:
#line 129 "bison_file.y"
{yyval.node=makenode(BLOCK_BODY,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 12:
#line 130 "bison_file.y"
{yyval.node=makenode(BLOCK_BODY,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 13:
#line 131 "bison_file.y"
{yyval.node=makenode(BLOCK_BODY,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 14:
#line 132 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 15:
#line 133 "bison_file.y"
{yyval.node=NULL;;
    break;}
case 16:
#line 142 "bison_file.y"
{ yyval.node = NULL; ;
    break;}
case 17:
#line 143 "bison_file.y"
{ yyval.node = NULL; ;
    break;}
case 18:
#line 144 "bison_file.y"
{ yyval.node = NULL; ;
    break;}
case 19:
#line 155 "bison_file.y"
{
				symbol_new();
				if(symbol_set_struct_type(yyvsp[-3].string))
				{
					symbol_set_name(yyvsp[-1].string);
					symbol_finish();
				}
				else
					symbol_cancel();
			;
    break;}
case 20:
#line 175 "bison_file.y"
{ symbol_new(); ;
    break;}
case 21:
#line 176 "bison_file.y"
{ ;
    break;}
case 22:
#line 181 "bison_file.y"
{ symbol_set_type(BOOLEAN); ;
    break;}
case 23:
#line 182 "bison_file.y"
{ symbol_set_type(INTEGER); ;
    break;}
case 24:
#line 183 "bison_file.y"
{ symbol_set_type(FLOAT); ;
    break;}
case 25:
#line 189 "bison_file.y"
{
			symbol_set_name(yyvsp[0].string); 
			symbol_finish();
		;
    break;}
case 26:
#line 195 "bison_file.y"
{
			//symbol_stack_set_ispointer(1);
			//symbol_stack_set_name($1);
			//symbol_stack_pop();
		;
    break;}
case 27:
#line 222 "bison_file.y"
{
				symbol_new();
				symbol_set_name(yyvsp[0].string);
				symbol_set_isprocedure(1);
				symbol_finish();
				enter_block(yyvsp[0].string);
			;
    break;}
case 28:
#line 230 "bison_file.y"
{
				exit_block();
				yyval.node = makenode(PROCEDURE, yyvsp[-1].node, NULL, NULL, 0, NULL);
			;
    break;}
case 29:
#line 237 "bison_file.y"
{ ;
    break;}
case 30:
#line 238 "bison_file.y"
{ ;
    break;}
case 31:
#line 242 "bison_file.y"
{;
    break;}
case 32:
#line 243 "bison_file.y"
{;
    break;}
case 34:
#line 250 "bison_file.y"
{
		if(symbol_set_struct_type(yyvsp[-2].string))
		{
			symbol_set_name(yyvsp[0].string);
			symbol_finish();
		}
		else
			symbol_cancel();
	;
    break;}
case 35:
#line 263 "bison_file.y"
{ 
		symbol_new();
		symbol_set_isvalparam(1);
	;
    break;}
case 36:
#line 269 "bison_file.y"
{ 
		symbol_new();
		symbol_set_isvalparam(1);
	;
    break;}
case 37:
#line 277 "bison_file.y"
{
		symbol_set_name(yyvsp[0].string);
		symbol_finish();
	;
    break;}
case 38:
#line 299 "bison_file.y"
{
		proc_call_setproc(yyvsp[0].string);
	;
    break;}
case 39:
#line 303 "bison_file.y"
{ 
		proc_call_finish();
		if( proc_call_valid() )
			yyval.node = makenode(PROC_CALL,yyvsp[-2].node,NULL,NULL,0,NULL);
		else
			yyval.node = NULL;
	;
    break;}
case 40:
#line 314 "bison_file.y"
{ proc_call_validate_arg(yyvsp[0].node->type, yyvsp[0].node->op==IDE ? 1:0 ); ;
    break;}
case 41:
#line 315 "bison_file.y"
{ yyval.node = makenode(ARGUMENT_LIST,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL); ;
    break;}
case 42:
#line 316 "bison_file.y"
{ yyval.node = NULL;;
    break;}
case 43:
#line 320 "bison_file.y"
{ proc_call_validate_arg(yyvsp[0].node->type, yyvsp[0].node->op==IDE ? 1:0 ); ;
    break;}
case 44:
#line 321 "bison_file.y"
{ yyval.node = makenode(ARGUMENT_LIST,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL); ;
    break;}
case 45:
#line 322 "bison_file.y"
{ yyval.node = NULL; ;
    break;}
case 46:
#line 329 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 47:
#line 330 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 48:
#line 333 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 49:
#line 336 "bison_file.y"
{yyval.node=yyvsp[-1].node;;
    break;}
case 50:
#line 337 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 51:
#line 338 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 52:
#line 339 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 53:
#line 342 "bison_file.y"
{yyval.node=makenode(ASSIGN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 54:
#line 345 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 55:
#line 346 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-5].node,yyvsp[-3].node,yyvsp[-1].node,0,NULL);;
    break;}
case 56:
#line 349 "bison_file.y"
{yyval.node=makenode(WHILE,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 57:
#line 352 "bison_file.y"
{yyval.node=makenode(CASESTAT,yyvsp[-4].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 58:
#line 355 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 59:
#line 356 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 60:
#line 358 "bison_file.y"
{yyval.node=makenode(CASE,NULL,yyvsp[0].node,NULL,yyvsp[-2].code,NULL);;
    break;}
case 61:
#line 362 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 62:
#line 363 "bison_file.y"
{ yyval.node = genLeaf(IDE,0,0,yyvsp[0].string); ;
    break;}
case 63:
#line 364 "bison_file.y"
{yyval.node = genLeaf(POINTER,0,0,yyvsp[0].string);;
    break;}
case 64:
#line 365 "bison_file.y"
{s=0; /*lst=findSymbol($1)->lst;*/;
    break;}
case 65:
#line 367 "bison_file.y"
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
case 66:
#line 414 "bison_file.y"
{
		struct_acc_start(yyvsp[0].string);
	;
    break;}
case 67:
#line 418 "bison_file.y"
{
		if( struct_acc_valid() )
		{
			NODE left = makenode(IDE, NULL, NULL, NULL, 0, yyvsp[-3].string);
			//NODE left = genLeaf(IDE, 0, 0, $1);
			yyval.node = makenode(STRUCT_ACC, left, yyvsp[0].node, NULL, 0, NULL);
		}
		else 
			yyval.node = yyvsp[0].node;
	;
    break;}
case 68:
#line 432 "bison_file.y"
{
		struct_acc_next(yyvsp[0].string);
		
		if( struct_acc_valid() )
		{
			yyval.node= genLeaf(IDE, 0, 0, yyvsp[0].string);
			//$$ = makenode(IDE, NULL, NULL, NULL, 0, $1);
		}
		else 
			yyval.node = NULL;

		struct_acc_finish();
	;
    break;}
case 69:
#line 447 "bison_file.y"
{
		struct_acc_next(yyvsp[0].string);
	;
    break;}
case 70:
#line 451 "bison_file.y"
{
		if( struct_acc_valid() )
		{
			NODE left = makenode(IDE, NULL, NULL, NULL, 0, yyvsp[-3].string);
			yyval.node = makenode(STRUCT_ACC, left, yyvsp[0].node, NULL, 0, NULL);
		}
		else 
			yyval.node = yyvsp[0].node;
	;
    break;}
case 71:
#line 467 "bison_file.y"
{s=s+1;;
    break;}
case 72:
#line 469 "bison_file.y"
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
case 73:
#line 478 "bison_file.y"
{;
    break;}
case 74:
#line 478 "bison_file.y"
{n=1;yyval.node=NULL;
    break;}
case 75:
#line 481 "bison_file.y"
{ yyval.node = makenode(ADD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 76:
#line 482 "bison_file.y"
{ yyval.node = makenode(MMIN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 77:
#line 483 "bison_file.y"
{ yyval.node = makenode(MUL,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 78:
#line 484 "bison_file.y"
{ yyval.node = makenode(DIV,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 79:
#line 485 "bison_file.y"
{ yyval.node = makenode(MOD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 80:
#line 486 "bison_file.y"
{ yyval.node = makenode(LES,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 81:
#line 487 "bison_file.y"
{ yyval.node = makenode(LEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 82:
#line 488 "bison_file.y"
{ yyval.node = makenode(EQU,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 83:
#line 489 "bison_file.y"
{ yyval.node = makenode(NEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 84:
#line 490 "bison_file.y"
{ yyval.node = makenode(GRE,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 85:
#line 491 "bison_file.y"
{ yyval.node = makenode(GEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 86:
#line 492 "bison_file.y"
{ yyval.node = makenode(AND,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 87:
#line 493 "bison_file.y"
{ yyval.node = makenode(OR,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 88:
#line 494 "bison_file.y"
{ yyval.node = yyvsp[-1].node; ;
    break;}
case 89:
#line 495 "bison_file.y"
{ yyval.node = makenode(CAST,yyvsp[-1].node,NULL,NULL,0,NULL); ;
    break;}
case 90:
#line 496 "bison_file.y"
{ yyval.node = makenode(NOT,yyvsp[0].node,NULL,NULL,0,NULL); ;
    break;}
case 91:
#line 497 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 92:
#line 501 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 93:
#line 502 "bison_file.y"
{ yyval.node = genLeaf(INTCONST,yyvsp[0].code,0,NULL); ;
    break;}
case 94:
#line 503 "bison_file.y"
{ yyval.node = genLeaf(REALCONST,0,yyvsp[0].real,NULL);;
    break;}
case 95:
#line 504 "bison_file.y"
{ yyval.node = genLeaf(TRUE,0,0,NULL); ;
    break;}
case 96:
#line 505 "bison_file.y"
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
#line 509 "bison_file.y"
