
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_acc.h"
#include "symbol.h"
#include "symbol_table.h"


extern int line_number;

Symbol* cur;
int struct_acc_error;


/*
begins struct access for symbol 'ide'.

checks if the first IDE in the struct access path is actually a struct,
if it exists in the symbol table.
sets the struct_acc_error flag accordingly.
*/
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

/*
is this struct access valid?
struct access will be considered invalid :
- after struct_acc_start		: if the symbol provided does not exist
- after struct_acc_next			: if the symbol being accessed is not a struct instance
- after struct_acc_next			: if the member being accessed does not exists
(ex: "a.b" and 'b' does not exists in 'a' as a struct member)
*/
int struct_acc_valid()
{
	return !struct_acc_error;
}

/*
validates struct access (checks of 'ide' exists in the previous symbol as a member)

if struct_acc_error is FALSE (struct_acc_start() finished successfully),
loops through the IDE's to compare each IDE in the sstruct access path.
*/
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


/*
finishes the struct access (reinit)
*/
void struct_acc_finish()
{
	cur = NULL;
	struct_acc_error = 0;
}

/*
returns the current symbol
used by parse tree to generate leaf.
*/
Symbol* struct_acc_cur_symbol()
{
	return cur;
}