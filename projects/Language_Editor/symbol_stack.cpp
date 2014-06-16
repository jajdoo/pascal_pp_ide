

#include <stack>

#include "symbol_stack.h"
#include "typedef.h"

std::stack<Symbol*> symbol_stack;


void symbol_stack_push()
{
	Symbol* symbol = (Symbol*)malloc(sizeof(Symbol));
	symbol->symb = NULL;
	symbol->address = -1;
	symbol->funcName = "";
	symbol->isProc = 0;
	symbol->IS_ARRAY = 0;
	symbol->IS_POINTER = 0;
	symbol->is_struct = 0;
	symbol->list = NULL;
	symbol_stack.push(symbol);
}


Symbol* symbol_stack_pop()
{
	Symbol* s = symbol_stack.top();
	symbol_stack.pop();
	return s; 
}


void symbol_stack_set_type(int type)
{
	symbol_stack.top()->type = type;
}


void symbol_stack_set_name(char* name)
{
	symbol_stack.top()->symb = name;
}


void symbol_stack_set_address(int address)
{
	symbol_stack.top()->address = address;
}


void symbol_stack_set_size(int size)
{
	symbol_stack.top()->size = size;
}


void symbol_stack_set_isarray(int is_array)
{
	symbol_stack.top()->IS_ARRAY = is_array;
}


void symbol_stack_set_ispointer(int is_pointer)
{
	symbol_stack.top()->IS_POINTER = is_pointer;
}


void symbol_stack_set_isprocedure(int is_procedure)
{
	symbol_stack.top()->isProc = is_procedure;
}


void symbol_stack_set_isstruct(int is_struct)
{
	symbol_stack.top()->is_struct = is_struct;
}



void print_symbol(Symbol* symbol)
{
	printf("\n--------------------------------------\n");
	printf(	"symbol:		%s\n"
			"type:		%d\n"
			"add:		%d\n"
			"proc?		%d\n"
			"array?		%d\n"
			"pointer?	%d\n"
			"struct?		%d\n"
			"(list)		  \n", 
				symbol->symb,
				symbol->type,
				symbol->address,
				symbol->isProc,
				symbol->IS_ARRAY,
				symbol->IS_POINTER,
				symbol->is_struct
				);
	//symbol->list = NULL
	printf("-------------------------------------\n");
}

/* TEMP TEMP TEMP TEMP TEMP */
void symbol_stack_showme()
{
	print_symbol(symbol_stack.top());
}