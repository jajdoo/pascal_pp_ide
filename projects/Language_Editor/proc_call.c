

#include <stdlib.h>
#include <stdio.h>
#include "symbol.h"
#include "proc_call.h"
#include "symbol_table.h"
#include "parse_tree.h"


Symbol* proc_symbol;
SymbolWrapper* cur_child;
int args_count;

int proc_call_error;

extern int line_number;

void proc_call_setproc(char* p)
{
	printf("starting proc call validation for %s\n", p);

	proc_symbol = (Symbol*) getFromSymbolTable(p);

	if (proc_symbol == NULL)
	{
		printf("no such symbol: %s - line %d\n", p, line_number );
		proc_call_error = 1;
		return;
	}

	if (!proc_symbol->is_proc)
	{
		printf("symbol %s is not a proc - line %d\n", p, line_number);
		proc_call_error = 1;
		return;
	}

	proc_call_error = 0;
	args_count = 0;
	cur_child = proc_symbol->list;
}


int proc_call_valid()
{
	return !proc_call_error;
}


void proc_call_finish()
{
	if (proc_symbol!=NULL && proc_symbol->child_count != args_count)
	{
		printf("argument count missmatch: expacted: %d recieved: %d  - line %d\n", proc_symbol->child_count, args_count, line_number);
		proc_call_error = 1;
	}
	proc_symbol = NULL;
	cur_child = NULL;

	printf("proc call validation finished\n");
}


void proc_call_validate_arg(int type)
{
	Symbol* s;

	if (proc_call_error)
		return;

	args_count++;

	if (cur_child == NULL)
		return;

	s = cur_child->Symbol;

	if (type != cur_child->Symbol->type)
	{
		printf("parameter type missmatch; argument %d : expacted %s, recieved %s  - line %d\n",
			args_count,
			print_op(cur_child->Symbol->type),
			print_op(type),
			line_number
			);
		proc_call_error = 1;
	}

	cur_child = cur_child->next;
}