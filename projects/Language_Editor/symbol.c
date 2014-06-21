

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"
#include "symbol_table.h"

Symbol* cur;


void symbol_new()
{
	cur = (Symbol*)malloc(sizeof(Symbol));
	cur->symb = NULL;
	cur->type = -1;
	cur->address = -1;
	cur->funcName = "";
	cur->is_proc = 0;
	cur->IS_ARRAY = 0;
	cur->IS_POINTER = 0;
	cur->is_param = 0;
	cur->is_struct = 0;
	cur->is_struct_member = 0;
	cur->list = NULL;
}


void symbol_finish()
{
	int table_ret_code;
	SymbolWrapper* w, *prev;
	Symbol* context_symbol;

	if (cur->is_param || cur->is_struct_member)
	{
		context_symbol = (Symbol*)symbol_table_getcontext();
		w = (SymbolWrapper*)malloc(sizeof(SymbolWrapper));
		w->Symbol = cur;
		w->next = NULL;

		prev = context_symbol->list;

		if ( prev != NULL )
		{
			while ( prev->next != NULL )
				prev = prev->next;
			prev->next = w;
		}
		else
			context_symbol->list = w;
	}
	
	table_ret_code = addToSymbolTable(cur->symb, (void*)cur);

	switch (table_ret_code)
	{
	case HASH_ADD_FAILED_NO_CONTEXT:
		printf("could not add symbol %s - no context\n", cur->symb);
		symbol_free(cur);
		break;
	case HASH_ADD_FAILED_ALREADY_EXIST:
		printf("could not add symbol %s - redifinition\n", cur->symb);
		symbol_free(cur);
		break;
	case HASH_ADD_SUCCESS:
		printf("successfuly added symbol %s \n", cur->symb);
		break;
	}

	cur = NULL;
}


void symbol_set_isparam(int param) 
{
	cur->is_param = param;
}


void symbol_set_type(int type)
{
	cur->type = type;
}
void symbol_set_isstructmember(int struc_member)
{
	cur->is_struct_member = struc_member;
}


void symbol_set_name(char* name)
{
	cur->symb = (char*)malloc(sizeof(char)*(strlen(name) + 1));
	strcpy(cur->symb, name);
}


void symbol_set_address(int address)
{
	cur->address = address;
}


void symbol_set_size(int size)
{
	cur->size = size;
}


void symbol_set_isarray(int is_array)
{
	cur->IS_ARRAY = is_array;
}


void symbol_set_ispointer(int is_pointer)
{
	cur->IS_POINTER = is_pointer;
}


void symbol_set_isprocedure(int is_procedure)
{
	cur->is_proc = is_procedure;
	cur->is_struct = 0;
}


void symbol_set_isstruct(int is_struct)
{
	cur->is_struct = is_struct;
}


/* later use */
void symbol_free(void *a)
{
	SymbolWrapper* w,* p;
	Symbol* s = (Symbol*)a;

	if (s->is_param)
		return;
	if (s->is_struct_member)
		return;

	if (s->symb != NULL)
		free(s->symb);

	w = s->list;
	while (w != NULL)
	{
		w->Symbol->is_param = 0;
		symbol_free(w->Symbol);

		p = w;
		w = w->next;
		free(p);
	}

	free(s);
}

void symbol_print(struct Symbol* symbol)
{
	int n;
	SymbolWrapper* w;

	if (symbol == NULL)
		return;

	//printf("\n--------------------------------------\n");
	printf("symbol:		%s\n"
		"type:		%d\n"
		"add:		%d\n"
		"proc?		%d\n"
		"array?		%d\n"
		"pointer?	%d\n"
		"parameter?	%d\n"
		"struct_member?	%d\n"
		"struct?		%d\n\n\n",
		symbol->symb,
		symbol->type,
		symbol->address,
		symbol->is_proc,
		symbol->IS_ARRAY,
		symbol->IS_POINTER,
		symbol->is_param,
		symbol->is_struct_member,
		symbol->is_struct
		);

	n = 0;
	w = symbol->list;
	while (w != NULL)
	{
		printf("child %d of %s ::: \n", n, symbol->symb);
		symbol_print(w->Symbol);
		w = w->next;
		n++;
	}
	//symbol->list = NULL
	//printf("--------------------------------------\n");
}