

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globals.h"
#include "struct_def.h"
#include "symbol_table.h"

int current_member_add = 0;

struct Symbol* cur_members = NULL;


struct Symbol* cur_struct;



struct Symbol* get_cur_struct()
{
	return cur_struct;
}



/**	clear struct selection 
	(after declarations of concrete structs is done)
	*/
void clear_current_struct()
{
	cur_struct = NULL;
}



/** called after struct definition is done */
void post_struct_def()
{
	cur_members = NULL;
	current_member_add = 0;
}


/**
	select struct type for declaring concrete struct variables
*/
void set_current_struct_name(char* struct_name)
{
	/*
	cur_struct = findSymbol(struct_name);

	if (cur_struct == NULL)
	{
		yyerror("no such symbol");
		return;
	}
	if (!cur_struct->is_struct || cur_struct->list == NULL)
	{
		yyerror("no such struct");
		return;
	}*/
}



int member_exists(char* IDEName)
{
	struct Symbol* memb = cur_members;
	while (memb != NULL)
	{
		if (strcmp(memb->symb, IDEName) == 0)
			return 1;
//		memb = memb->next;
	}

	return 0;
}




void new_struct_member(char* IDEName, int size, int IS_ARRAY, arrList lst)
{
	FILE *txt;
	txt = fopen("outputParser.txt", "a");
	int l, isPointer = 0;
	struct Symbol* newSymb;

	//fprintf(txt,"Info at line %d: adding to symbol table: %s \n",line_number,IDEName);
	if (size <= 0)
	{
		fprintf(txt, "\nErrorat line %d: illegal array size: %s has the size of %d", line_number, IDEName, size);
		fclose(txt);
		exit(1);
	}

	newSymb = (struct Symbol*)malloc(sizeof(struct Symbol));
	//newSymb->lst = lst;


	//check if the symbol was already declared
	if (member_exists(IDEName))
		fprintf(txt, "Error at line %d: member %s already declared", line_number, IDEName);

	//pointer to a cell
	if (IDEName[strlen(IDEName) - 1] == '^')
	{
		IDEName[strlen(IDEName) - 1] = NULL;
		isPointer = 1;
	}

	newSymb->IS_POINTER = isPointer;
	newSymb->symb = IDEName;
	newSymb->type = currentType;
	newSymb->address = current_member_add;
	newSymb->IS_ARRAY = IS_ARRAY;


	if (cur_struct != NULL)
	{
		newSymb->size = cur_struct->size;
		//newSymb->type = getTableEntry(cur_struct->symb);
	}
	else
		newSymb->size = size;

	newSymb->is_struct = (cur_struct != NULL);
	//newSymb->list = NULL;

	current_member_add += newSymb->size;

	fprintf(txt, "Info at line %d: adding member  %s of type %d to member list variable\n", line_number, IDEName, currentType);
	/*
	if (cur_members != NULL)
		newSymb->next = cur_members;
	else
		newSymb->next = NULL;
	*/
	cur_members = newSymb;

	fclose(txt);
}
