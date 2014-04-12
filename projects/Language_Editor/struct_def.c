

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globals.h"
#include "struct_def.h"
#include "symbol_table.h"

struct Symbol* cur_symbol_list = NULL;

int current_member_add = 0;



int member_exists(char* IDEName)
{
	struct Symbol* memb = cur_symbol_list;
	while (memb != NULL)
	{
		if (strcmp(memb->symb, IDEName) == 0)
			return 1;
		memb = memb->next;
	}

	return 0;
}




void struct_def_prints()
{

	FILE *txt;
	struct Symbol* members = cur_symbol_list;

	txt = fopen("struct_membs.txt","a");

	fprintf(txt,"Name\t\t|Address\t|Size\t\t|IS ARRAY\t|IS POINTER\t|TYPE\t\t|is_struct\n");
	fprintf(txt, "--------------------------------------------------------------\n");

	while (members != NULL)
	{
		fprintf(txt, "%s\t\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d\n",
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





void new_struct_member(char* IDEName, int size, int IS_ARRAY, arrList lst, int is_struct)
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
	newSymb->lst = lst;


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
	newSymb->size = size;
	newSymb->IS_ARRAY = IS_ARRAY;

	newSymb->is_struct = is_struct;
	newSymb->members = NULL;

	current_member_add += newSymb->size;

	fprintf(txt, "Info at line %d: adding member  %s of type %d to member list variable\n", line_number, IDEName, currentType);

	if (cur_symbol_list != NULL)
		newSymb->next = cur_symbol_list;
	else
		newSymb->next = NULL;

	cur_symbol_list = newSymb;

	fclose(txt);
}
