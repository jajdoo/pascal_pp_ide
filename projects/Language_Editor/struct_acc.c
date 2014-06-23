
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_acc.h"
#include "symbol.h"
#include "symbol_table.h"


extern int line_number;

Symbol* cur;
int struct_acc_error;

void struct_acc_start(char* ide)
{
	cur = (Symbol*)getFromSymbolTable(ide);

	if (cur == NULL)
	{
		printf("no such symbol '%s' - line %d\n", ide, line_number);
		struct_acc_error = 1;
		return;
	}

	struct_acc_error = 0;
}

int struct_acc_valid()
{
	return !struct_acc_error;
}


void struct_acc_next(char* ide)
{
	Symbol* struct_type;
	SymbolWrapper* w;

	if (struct_acc_error)
		return;
	
	struct_type = cur->struct_type;
	if (struct_type == NULL)
	{
		printf("left side if '.' must be a struct (namely, '%s') - line %d\n", cur->symb, line_number);
		struct_acc_error = 1;
		return;
	}

	w = struct_type->list;
	while (w != NULL)
	{
		if (strcmp(w->Symbol->symb, ide) == 0)
		{
			cur = w->Symbol;
			return;
		}
		w = w->next;
	}

	printf("no such member '%s' in struct '%s' - line %d\n", ide, cur->symb, line_number);
	struct_acc_error = 1;
	cur = NULL;
}



void struct_acc_finish()
{
	cur = NULL;
	struct_acc_error = 0;
}

