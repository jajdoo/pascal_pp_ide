

#include <stdlib.h>
#include "symbol.h"

Symbol* cur;


void symbol_create()
{
	cur = (Symbol*)malloc(sizeof(Symbol));
	cur->symb = NULL;
	cur->type = -1;
	cur->address = -1;
	cur->funcName = "";
	cur->is_proc = 0;
	cur->IS_ARRAY = 0;
	cur->IS_POINTER = 0;
	cur->is_struct = 0;
	cur->list = NULL;
}


void symbol_finish()
{
	Symbol* s = cur;
	//symbol_stack.pop();
	addToSymbolTable(s->symb, (void*)s);
}


void symbol_finish_as_member()
{
	SymbolWrapper* w, *prev;
	Symbol* child, *parent;

	child = cur;
	//symbol_stack.pop();
	prev = NULL; // FIND THE PROCEDURE / STRUCT
	parent = cur;

	w = (SymbolWrapper*)malloc(sizeof(SymbolWrapper));
	w->Symbol = child;

	if (parent->list == NULL)
	{
		w->next = NULL;
		parent->list = w;
	}
	else
	{
		while (prev->next != NULL)
			prev = prev->next;
		prev->next = w;
		parent->list = w;
	}
}


void symbol_finish_as_parameter()
{
}


void symbol_set_type(int type)
{
	cur->type = type;
}


void symbol_set_name(char* name)
{
	cur->symb = (char*)malloc(sizeof(char)*strlen(name));
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
