

#include <stdlib.h>
#include <stdio.h>
#include "symbol.h"
#include "proc_call.h"
#include "symbol_table.h"
#include "parse_tree.h"


Symbol* proc_symbol;
SymbolWrapper* cur_child;
int args_count;


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
		return;
	}

	args_count = 0;
	cur_child = proc_symbol->list;
}


void proc_call_finish()
{
	if (proc_symbol->child_count!=args_count)
		printf("argument count missmatch - expacted: %d recieved: %d \n", proc_symbol->child_count, args_count);

	proc_symbol = NULL;
	cur_child = NULL;

	printf("proc call validation finished\n");
}


void proc_call_validate_arg(int type)
{
	Symbol* s;
	
	args_count++;

	if (cur_child == NULL)
		return;

	s = cur_child->Symbol;

	if (type != cur_child->Symbol->type)
	{
		printf("parameter type missmatch; argument %d : expacted %s, recieved %s \n",
			args_count,
			print_op(cur_child->Symbol->type),
			print_op(type)
			);
	}

	cur_child = cur_child->next;
}