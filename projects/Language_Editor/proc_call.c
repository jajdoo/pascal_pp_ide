

#include <stdlib.h>
#include <stdio.h>
#include "symbol.h"
#include "proc_call.h"
#include "symbol_table.h"


Symbol* proc_symbol;
SymbolWrapper* cur_child;

void proc_call_setproc(char* p)
{
	printf("starting proc call validation for %s\n", p);

	proc_symbol = (Symbol*) getFromSymbolTable(p);
	if (proc_symbol == NULL)
	{
		printf("no such symbol: %s\n", p);
		return;
	}

	if (!proc_symbol->is_proc)
	{
		printf("symbol %s is not a proc\n", p);
	}

	cur_child = proc_symbol->list;
}


void proc_call_finish()
{
	proc_symbol = NULL;
	cur_child = NULL;

	printf("proc call validation finished");
}


void proc_call_validate_arg(int type)
{
	Symbol* s;
	
	if (cur_child == NULL)
		return;

	s = cur_child->Symbol;

	
}