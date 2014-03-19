#ifndef _CONVERT_TREE_H
#define _CONVERT_TREE_H

#include "typedef.h"

#define LOAD 1000
#define STORE 1001
#define MOV 1002
#define NEG 1003
#define BRA 1004
#define	BGE 1005		
#define BGT 1006
#define BNE	1007
#define	BEQ 1008
#define	BLE 1009
#define BLT 1010
#define LOADI 1011
#define PHI 1012
#define L_VALUE 1013
#define R_VALUE 1014
#define ERROR 1015

typedef struct command command;
struct command
{
	int op;
	int trg[2];		// trg[0] - for assignment, trg[1] - to be used by the phi-node function
	int s1[2];		//first operand
	int s2[2];		//second operand
	int s3[2];			// used only in phi-node command
	int toVisit;		// next operand to rename in the phi-node. Initially 0.
	char blockName;
	int line;			//line of the command
	int brnch;			//no. of he branch label
	command* pointer;
	command* next;		//next node in linked list of commands
};

typedef struct label label;
typedef struct label
{
	command* data;
	label* next;
	label* prev;
};

void PrintCommandsToFile(const char *filename);
char* print_IL(int op);
int TreeToIL(NODE n);


#endif
