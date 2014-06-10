
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
#include "context.h"

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



#define	YYFINAL		211
#define	YYFLAG		-32768
#define	YYNTBASE	73

#define YYTRANSLATE(x) ((unsigned)(x) <= 319 ? yytranslate[x] : 121)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    70,
    71,     2,     2,    67,     2,    72,     2,     2,     2,     2,
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
    67,    71,    72,    73,    82,    83,    84,    93,    99,   105,
   106,   109,   110,   112,   114,   119,   121,   122,   126,   127,
   131,   132,   133,   142,   146,   150,   151,   152,   162,   163,
   164,   170,   171,   173,   175,   177,   179,   181,   184,   186,
   189,   191,   193,   195,   199,   205,   213,   219,   226,   228,
   231,   235,   239,   241,   243,   244,   251,   253,   257,   258,
   264,   265,   267,   271,   275,   279,   283,   287,   291,   295,
   299,   303,   307,   311,   315,   319,   323,   328,   331,   333,
   335,   337,   339,   341
};

static const short yyrhs[] = {     3,
    60,    74,     0,    17,    84,   104,    18,     0,    17,    18,
     0,    57,    60,    17,    76,    18,    65,     0,     0,     0,
    57,    60,    77,    66,    80,    65,    78,    79,     0,    55,
   103,    66,    80,    65,    79,     0,    76,     0,     0,    81,
    67,    80,     0,    81,     0,    60,     0,    61,     0,    60,
    82,     0,    68,    59,    69,    83,     0,    82,     0,     0,
    87,    84,     0,    75,    84,     0,    55,    92,    84,     0,
     0,     0,    57,    60,    85,    66,    93,    65,    86,    84,
     0,     0,     0,     4,    60,    88,    70,    89,    71,    74,
    65,     0,    57,    60,    66,    91,    90,     0,    55,   103,
    66,    91,    90,     0,     0,    67,    76,     0,     0,    60,
     0,    61,     0,   103,    66,    93,    92,     0,    65,     0,
     0,    60,    94,    93,     0,     0,    61,    95,    93,     0,
     0,     0,    60,    68,    59,    69,    96,   100,    97,    93,
     0,    67,    60,    93,     0,    67,    61,    93,     0,     0,
     0,    67,    60,    68,    59,    69,    98,   100,    99,    93,
     0,     0,     0,    68,    59,    69,   101,   100,     0,     0,
   102,     0,    13,     0,     9,     0,    10,     0,   105,     0,
   105,   104,     0,   106,     0,   107,    65,     0,   108,     0,
   109,     0,   110,     0,   113,    16,   119,     0,    19,   119,
    20,   104,    22,     0,    19,   119,    20,   104,    21,   104,
    22,     0,    23,   119,    25,   104,    26,     0,    46,   119,
    15,    17,   111,    18,     0,   112,     0,   112,   111,     0,
    59,    66,   104,     0,    60,    72,   115,     0,    60,     0,
    61,     0,     0,    60,    68,   119,    69,   114,   116,     0,
    60,     0,    60,    72,   115,     0,     0,    68,   119,    69,
   117,   116,     0,     0,   118,     0,   119,    31,   119,     0,
   119,    32,   119,     0,   119,    33,   119,     0,   119,    34,
   119,     0,   119,    36,   119,     0,   119,    37,   119,     0,
   119,    38,   119,     0,   119,    39,   119,     0,   119,    40,
   119,     0,   119,    41,   119,     0,   119,    42,   119,     0,
   119,    43,   119,     0,   119,    44,   119,     0,    70,   119,
    71,     0,   103,    70,   119,    71,     0,    45,   120,     0,
   120,     0,   113,     0,    59,     0,    62,     0,    29,     0,
    30,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    51,    54,    55,    62,    64,    65,    67,    67,    70,    70,
    72,    73,    76,    78,    79,    82,    85,    85,    89,    90,
    91,    92,    93,    95,    95,   101,   102,   105,   106,   107,
   109,   109,   111,   112,   117,   118,   122,   123,   123,   124,
   124,   130,   138,   138,   139,   140,   146,   155,   155,   158,
   161,   169,   170,   180,   181,   183,   188,   189,   193,   196,
   197,   198,   199,   202,   205,   206,   209,   212,   215,   216,
   218,   221,   223,   224,   225,   227,   249,   250,   257,   260,
   269,   269,   272,   273,   274,   275,   276,   277,   278,   279,
   280,   281,   282,   283,   284,   285,   286,   287,   288,   292,
   293,   294,   295,   296
};

static const char * const yytname[] = {   "$","error","$undefined.","PROGRAM",
"PROCEDURE","BBEGIN","END","DECLARE","LABEL","INTEGER","FLOAT","REAL","CMP",
"BOOLEAN","ARRAY","OF","ASSIGN","LC","RC","IF","THEN","ELSE","FI","WHILE","REPEAT",
"DO","OD","READ","WRITE","TRUE","FALSE","ADD","MMIN","MUL","DIV","GOTO","MOD",
"LES","LEQ","EQU","NEQ","GRE","GEQ","AND","OR","NOT","CASE","FOR","FIN","IDENTICAL",
"FROM","BY","TO","CONST","TYPE","VAR","RECORD","STRUCT","CAST","INTCONST","IDE",
"POINTER","REALCONST","STRING","DUMMY","';'","':'","','","'['","']'","'('","')'",
"'.'","program","block","struct_decl","member_decl","@1","@2","member_decl_tail",
"memberList","struct_member","dim","dim_tail","declarations","@3","@4","procedure",
"@5","param_decl","param_decl_tail","param","varAss","idList","@6","@7","@8",
"@9","@10","@11","brk","@12","@13","tyList","stat_seq","stat","nonlable_stat",
"assign","cond_stat","loop_stat","case_stat","case_list","case","var","@14",
"struct_acc_tail","bracket","@15","@16","expr","atom",""
};
#endif

static const short yyr1[] = {     0,
    73,    74,    74,    75,    77,    78,    76,    76,    79,    79,
    80,    80,    81,    81,    81,    82,    83,    83,    84,    84,
    84,    85,    86,    84,    84,    88,    87,    89,    89,    89,
    90,    90,    91,    91,    92,    92,    94,    93,    95,    93,
    96,    97,    93,    93,    93,    98,    99,    93,    93,   101,
   100,   102,   100,   103,   103,   103,   104,   104,   105,   106,
   106,   106,   106,   107,   108,   108,   109,   110,   111,   111,
   112,   113,   113,   113,   114,   113,   115,   115,   117,   116,
   118,   116,   119,   119,   119,   119,   119,   119,   119,   119,
   119,   119,   119,   119,   119,   119,   119,   119,   119,   120,
   120,   120,   120,   120
};

static const short yyr2[] = {     0,
     3,     4,     2,     6,     0,     0,     8,     6,     1,     0,
     3,     1,     1,     1,     2,     4,     1,     0,     2,     2,
     3,     0,     0,     8,     0,     0,     8,     5,     5,     0,
     2,     0,     1,     1,     4,     1,     0,     3,     0,     3,
     0,     0,     8,     3,     3,     0,     0,     9,     0,     0,
     5,     0,     1,     1,     1,     1,     1,     2,     1,     2,
     1,     1,     1,     3,     5,     7,     5,     6,     1,     2,
     3,     3,     1,     1,     0,     6,     1,     3,     0,     5,
     0,     1,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     4,     2,     1,     1,
     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,    25,     1,     0,     3,     0,     0,    25,     0,
    25,    26,    55,    56,    54,    36,    25,     0,    22,    20,
     0,     0,     0,    73,    74,     0,    57,    59,     0,    61,
    62,    63,     0,    19,     0,    21,    49,     0,     0,   103,
   104,     0,   101,   102,     0,     0,   100,     0,    99,     0,
     0,     0,     0,     2,    58,    60,     0,    30,    37,    39,
     0,     0,     0,     0,     0,    49,    98,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    77,    72,    64,     0,
     0,     0,     0,    49,    49,    49,    49,    35,     0,     5,
     0,     0,    96,     0,     0,    83,    84,    85,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
    75,     0,     0,     0,     0,     0,    38,    40,     0,    44,
    45,     0,     0,     4,    23,    97,     0,    65,    67,     0,
     0,    69,    81,    78,     0,     0,     0,    41,     0,    13,
    14,     0,    12,     0,    25,     0,     0,    68,    70,     0,
    76,    82,    33,    34,    32,    32,    27,    52,    46,     0,
    15,    10,     0,     0,    24,    66,    71,     0,     0,    29,
    28,     0,    42,    53,    52,     0,     9,     8,    11,     6,
    79,    31,     0,    49,    47,    18,    10,    81,    50,    43,
    49,    17,    16,     7,    80,    52,    48,    51,     0,     0,
     0
};

static const short yydefgoto[] = {   209,
     4,     9,   187,   133,   197,   188,   152,   153,   171,   203,
    10,    39,   155,    11,    35,    92,   180,   165,    17,    62,
    94,    95,   168,   194,   185,   201,   183,   206,   184,    46,
    26,    27,    28,    29,    30,    31,    32,   141,   142,    47,
   143,    88,   161,   198,   162,    48,    49
};

static const short yypact[] = {    15,
   -46,     7,    35,-32768,   -25,-32768,     2,   -19,    38,    -3,
    38,-32768,-32768,-32768,-32768,-32768,    38,   -28,    29,-32768,
    59,    59,    59,   -59,-32768,    33,    -3,-32768,    -6,-32768,
-32768,-32768,    39,-32768,    24,-32768,    56,   -36,    32,-32768,
-32768,   150,-32768,-32768,    59,    44,-32768,   208,-32768,   228,
   193,    59,    62,-32768,-32768,-32768,    59,    -5,    31,-32768,
     5,     2,    27,    66,   110,    56,-32768,    69,    59,    -3,
    59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
    59,    59,    59,    -3,   113,   134,    60,-32768,   242,    27,
    73,    63,    77,    56,    56,   -38,    56,-32768,    71,-32768,
    74,    76,-32768,   118,    49,    11,    11,-32768,-32768,-32768,
   256,   256,   256,   256,   256,   256,-32768,    11,   117,    85,
-32768,    62,    79,    80,     7,    84,-32768,-32768,   104,-32768,
-32768,    36,   103,-32768,-32768,-32768,    -3,-32768,-32768,   115,
   164,    85,   116,-32768,    64,    64,   135,-32768,   114,   131,
-32768,   136,   137,    36,    38,   180,    -3,-32768,-32768,    59,
-32768,-32768,-32768,-32768,   138,   138,-32768,   139,-32768,   147,
-32768,   -36,    36,   148,-32768,-32768,-32768,   154,   -36,-32768,
-32768,   155,-32768,-32768,   139,   146,-32768,-32768,-32768,-32768,
-32768,-32768,   149,    56,-32768,   131,   -36,   116,-32768,-32768,
    56,-32768,-32768,-32768,-32768,   139,-32768,-32768,   216,   217,
-32768
};

static const short yypgoto[] = {-32768,
    94,-32768,   -37,-32768,-32768,    23,  -148,-32768,    25,-32768,
    -7,-32768,-32768,-32768,-32768,-32768,    72,    97,   160,   -63,
-32768,-32768,-32768,-32768,-32768,-32768,  -178,-32768,-32768,     1,
   -22,-32768,-32768,-32768,-32768,-32768,-32768,   112,-32768,   -10,
-32768,   133,    58,-32768,-32768,     4,   215
};


#define	YYLAST		300


static const short yytable[] = {    33,
    65,    20,   102,    34,    55,   174,   195,    18,    52,    36,
    13,    14,    53,     2,    15,    21,    33,     1,    63,    22,
    64,    59,    60,     3,   189,    50,    51,   208,    61,   129,
   127,   128,   130,   131,    12,    13,    14,    37,     5,    15,
    19,     5,    23,    73,    74,    38,    75,   105,    68,    90,
    54,    91,     6,    82,    57,    86,    24,    25,    56,    33,
    89,   119,    18,    99,    96,    97,    16,    13,    14,   137,
   138,    15,   104,    33,   106,   107,   108,   109,   110,   111,
   112,   113,   114,   115,   116,   117,   118,    40,    41,     7,
   123,     8,     7,    58,     8,   150,   151,    66,    93,    71,
    72,    73,    74,    42,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    69,   156,    59,    60,    43,    24,    25,
    44,    87,    61,   163,   164,   100,    33,   101,    45,   120,
   200,   122,   124,   125,   177,   126,   132,   207,   134,   103,
   135,   192,   139,   140,   145,   146,    33,   175,    71,    72,
    73,    74,   148,    75,    76,    77,    78,    79,    80,    81,
    82,    83,   149,   178,    71,    72,    73,    74,   154,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    40,    41,
   157,   158,   169,   160,    71,    72,    73,    74,   136,    75,
    76,    77,    78,    79,    80,    81,    82,    83,   170,   167,
   172,   176,   121,   173,   179,   186,   182,    85,    43,    24,
    25,    44,   190,   193,   196,   210,   211,   199,   147,   204,
   202,    98,   191,    71,    72,    73,    74,    70,    75,    76,
    77,    78,    79,    80,    81,    82,    83,   181,    71,    72,
    73,    74,   166,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    84,   159,   144,   205,    67,     0,    71,    72,
    73,    74,     0,    75,    76,    77,    78,    79,    80,    81,
    82,    83,    71,    72,    73,    74,     0,    75,    76,    77,
    78,    79,    80,    81,    82,    83,    71,    72,    73,    74,
     0,    75,-32768,-32768,-32768,-32768,-32768,-32768,    82,    83
};

static const short yycheck[] = {    10,
    38,     9,    66,    11,    27,   154,   185,     7,    68,    17,
     9,    10,    72,    60,    13,    19,    27,     3,    55,    23,
    57,    60,    61,    17,   173,    22,    23,   206,    67,    68,
    94,    95,    96,    97,    60,     9,    10,    66,     4,    13,
    60,     4,    46,    33,    34,    17,    36,    70,    45,    55,
    18,    57,    18,    43,    16,    52,    60,    61,    65,    70,
    57,    84,    62,    63,    60,    61,    65,     9,    10,    21,
    22,    13,    69,    84,    71,    72,    73,    74,    75,    76,
    77,    78,    79,    80,    81,    82,    83,    29,    30,    55,
    90,    57,    55,    70,    57,    60,    61,    66,    68,    31,
    32,    33,    34,    45,    36,    37,    38,    39,    40,    41,
    42,    43,    44,    70,   137,    60,    61,    59,    60,    61,
    62,    60,    67,    60,    61,    60,   137,    18,    70,    17,
   194,    72,    60,    71,   157,    59,    66,   201,    65,    71,
    65,   179,    26,    59,    66,    66,   157,   155,    31,    32,
    33,    34,    69,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    59,   160,    31,    32,    33,    34,    66,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    29,    30,
    66,    18,    69,    68,    31,    32,    33,    34,    71,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    68,    65,
    65,    22,    69,    67,    67,    59,    68,    15,    59,    60,
    61,    62,    65,    59,    69,     0,     0,    69,   125,   197,
   196,    62,    69,    31,    32,    33,    34,    20,    36,    37,
    38,    39,    40,    41,    42,    43,    44,   166,    31,    32,
    33,    34,   146,    36,    37,    38,    39,    40,    41,    42,
    43,    44,    25,   142,   122,   198,    42,    -1,    31,    32,
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
#line 51 "bison_file.y"
{yyval.node=makenode(PROGRAM,yyvsp[0].node,NULL,NULL,0,yyvsp[-1].string); root=yyval.node;;
    break;}
case 2:
#line 54 "bison_file.y"
{yyval.node=makenode(BBEGIN,yyvsp[-1].node,NULL,NULL,0,NULL);;
    break;}
case 3:
#line 55 "bison_file.y"
{yyval.node=makenode(BBEGIN,NULL,NULL,NULL,0,NULL);;
    break;}
case 4:
#line 62 "bison_file.y"
{addToSymbolTable(yyvsp[-4].string,yyvsp[-4].string); post_struct_def(); ;
    break;}
case 5:
#line 64 "bison_file.y"
{set_current_struct_name(yyvsp[0].string);;
    break;}
case 6:
#line 65 "bison_file.y"
{clear_current_struct(); ;
    break;}
case 8:
#line 67 "bison_file.y"
{printf("member_primitive_decl_1->");;
    break;}
case 11:
#line 72 "bison_file.y"
{printf("memberList_1->");;
    break;}
case 12:
#line 73 "bison_file.y"
{printf("memberList_2->");;
    break;}
case 13:
#line 77 "bison_file.y"
{ new_struct_member(yyvsp[0].string, 1, 0, NULL); ;
    break;}
case 14:
#line 78 "bison_file.y"
{ new_struct_member(yyvsp[0].string, 1, 0, NULL); ;
    break;}
case 15:
#line 79 "bison_file.y"
{ printf("struct_member(dim)->"); ;
    break;}
case 16:
#line 82 "bison_file.y"
{printf("dim_1\n");;
    break;}
case 19:
#line 89 "bison_file.y"
{return NULL;;
    break;}
case 22:
#line 92 "bison_file.y"
{set_current_struct_name(yyvsp[0].string);;
    break;}
case 23:
#line 93 "bison_file.y"
{clear_current_struct();;
    break;}
case 26:
#line 101 "bison_file.y"
{enter_block(yyvsp[0].string); printf("entering conext %s\n", yyvsp[0].string);;
    break;}
case 27:
#line 102 "bison_file.y"
{exit_block(); printf("exiting conext\n");;
    break;}
case 28:
#line 105 "bison_file.y"
{ printf("param_decl_1->"); ;
    break;}
case 29:
#line 106 "bison_file.y"
{ printf("primitive_param_decl_1->"); ;
    break;}
case 33:
#line 111 "bison_file.y"
{ printf("ide->"); ;
    break;}
case 34:
#line 112 "bison_file.y"
{ printf("pointer->"); ;
    break;}
case 35:
#line 117 "bison_file.y"
{;
    break;}
case 36:
#line 119 "bison_file.y"
{;
    break;}
case 37:
#line 122 "bison_file.y"
{addToSymbolTable(yyvsp[0].string,yyvsp[0].string);;
    break;}
case 39:
#line 123 "bison_file.y"
{addToSymbolTable(yyvsp[0].string,yyvsp[0].string);;
    break;}
case 41:
#line 125 "bison_file.y"
{
		s=1;

	;
    break;}
case 42:
#line 130 "bison_file.y"
{ 
		lst[s-o].size=yyvsp[-3].code;/* calcultes size of each dimentiob*/
		lst[s-o].sumsize=n*yyvsp[-3].code;/* sum of array*/
		
		addToSymbolTable(yyvsp[-5].string,yyvsp[-5].string);
		// addToSymbolTable($1,n*$3,s,lst);
	;
    break;}
case 44:
#line 138 "bison_file.y"
{addToSymbolTable(yyvsp[-1].string,yyvsp[-1].string);;
    break;}
case 45:
#line 139 "bison_file.y"
{addToSymbolTable(yyvsp[-1].string,yyvsp[-1].string);;
    break;}
case 46:
#line 141 "bison_file.y"
{
		s=1;

	;
    break;}
case 47:
#line 146 "bison_file.y"
{ 
		lst[s-o].size=yyvsp[-3].code;/* calcultes size of each dimentiob*/
		lst[s-o].sumsize=n*yyvsp[-3].code;/* sum of array*/
		

		addToSymbolTable(yyvsp[-5].string,yyvsp[-5].string);
		//addToSymbolTable($2,n*$4,s,lst);
	;
    break;}
case 49:
#line 156 "bison_file.y"
{;
    break;}
case 50:
#line 159 "bison_file.y"
{s=s+1;;
    break;}
case 51:
#line 161 "bison_file.y"
{
			n=n*yyvsp[-3].code; 
			yyval.code=lst; 
			lst[s-o].size=yyvsp[-3].code;/* calcultes size of each dimentiob*/
			lst[s-o].sumsize=n;/* sum of array*/
			
			o=o+1;
		;
    break;}
case 52:
#line 169 "bison_file.y"
{;
    break;}
case 53:
#line 170 "bison_file.y"
{
		n=1;
		o=1;
		lst =(arrLST*)malloc(sizeof(arrLST)*s); 
		
		yyval.code=NULL;
	;
    break;}
case 54:
#line 180 "bison_file.y"
{updateVarType(BOOLEAN);;
    break;}
case 55:
#line 182 "bison_file.y"
{updateVarType(INTEGER);;
    break;}
case 56:
#line 184 "bison_file.y"
{updateVarType(FLOAT);;
    break;}
case 57:
#line 188 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 58:
#line 190 "bison_file.y"
{yyval.node=makenode(STATEMENT,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 59:
#line 193 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 60:
#line 196 "bison_file.y"
{yyval.node=yyvsp[-1].node;;
    break;}
case 61:
#line 197 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 62:
#line 198 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 63:
#line 199 "bison_file.y"
{yyval.node=yyvsp[0].node;;
    break;}
case 64:
#line 202 "bison_file.y"
{yyval.node=makenode(ASSIGN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 65:
#line 205 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 66:
#line 206 "bison_file.y"
{yyval.node=makenode(IF,yyvsp[-5].node,yyvsp[-3].node,yyvsp[-1].node,0,NULL);;
    break;}
case 67:
#line 209 "bison_file.y"
{yyval.node=makenode(WHILE,yyvsp[-3].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 68:
#line 212 "bison_file.y"
{yyval.node=makenode(CASESTAT,yyvsp[-4].node,yyvsp[-1].node,NULL,0,NULL);;
    break;}
case 69:
#line 215 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[0].node,NULL,NULL,0,NULL);;
    break;}
case 70:
#line 216 "bison_file.y"
{yyval.node=makenode(CASELIST,yyvsp[-1].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 71:
#line 218 "bison_file.y"
{yyval.node=makenode(CASE,NULL,yyvsp[0].node,NULL,yyvsp[-2].code,NULL);;
    break;}
case 72:
#line 222 "bison_file.y"
{ printf("struct_acc->"); ;
    break;}
case 73:
#line 223 "bison_file.y"
{ yyval.node = genLeaf(IDE,0,0,yyvsp[0].string);;
    break;}
case 74:
#line 224 "bison_file.y"
{yyval.node = genLeaf(POINTER,0,0,yyvsp[0].string);;
    break;}
case 75:
#line 225 "bison_file.y"
{s=0; /*lst=findSymbol($1)->lst;*/;
    break;}
case 76:
#line 227 "bison_file.y"
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
case 77:
#line 249 "bison_file.y"
{printf("struct_tail->");;
    break;}
case 78:
#line 250 "bison_file.y"
{printf("\n");;
    break;}
case 79:
#line 258 "bison_file.y"
{s=s+1;;
    break;}
case 80:
#line 260 "bison_file.y"
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
case 81:
#line 269 "bison_file.y"
{;
    break;}
case 82:
#line 269 "bison_file.y"
{n=1;yyval.node=NULL;
    break;}
case 83:
#line 272 "bison_file.y"
{ yyval.node = makenode(ADD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 84:
#line 273 "bison_file.y"
{ yyval.node = makenode(MMIN,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 85:
#line 274 "bison_file.y"
{ yyval.node = makenode(MUL,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 86:
#line 275 "bison_file.y"
{ yyval.node = makenode(DIV,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 87:
#line 276 "bison_file.y"
{ yyval.node = makenode(MOD,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 88:
#line 277 "bison_file.y"
{ yyval.node = makenode(LES,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 89:
#line 278 "bison_file.y"
{ yyval.node = makenode(LEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 90:
#line 279 "bison_file.y"
{ yyval.node = makenode(EQU,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 91:
#line 280 "bison_file.y"
{ yyval.node = makenode(NEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 92:
#line 281 "bison_file.y"
{ yyval.node = makenode(GRE,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 93:
#line 282 "bison_file.y"
{ yyval.node = makenode(GEQ,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 94:
#line 283 "bison_file.y"
{ yyval.node = makenode(AND,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 95:
#line 284 "bison_file.y"
{ yyval.node = makenode(OR,yyvsp[-2].node,yyvsp[0].node,NULL,0,NULL);;
    break;}
case 96:
#line 285 "bison_file.y"
{ yyval.node = yyvsp[-1].node; ;
    break;}
case 97:
#line 286 "bison_file.y"
{ yyval.node = makenode(CAST,yyvsp[-1].node,NULL,NULL,0,NULL); ;
    break;}
case 98:
#line 287 "bison_file.y"
{ yyval.node = makenode(NOT,yyvsp[0].node,NULL,NULL,0,NULL); ;
    break;}
case 99:
#line 288 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 100:
#line 292 "bison_file.y"
{ yyval.node = yyvsp[0].node; ;
    break;}
case 101:
#line 293 "bison_file.y"
{ yyval.node = genLeaf(INTCONST,yyvsp[0].code,0,NULL); ;
    break;}
case 102:
#line 294 "bison_file.y"
{ yyval.node = genLeaf(REALCONST,0,yyvsp[0].real,NULL);;
    break;}
case 103:
#line 295 "bison_file.y"
{ yyval.node = genLeaf(TRUE,0,0,NULL); ;
    break;}
case 104:
#line 296 "bison_file.y"
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
#line 300 "bison_file.y"
