
#ifndef _SYMBOL_H__
#define _SYMBOL_H__

// this file exposes all procedures associated with declaring
// a new symbol prior to sending it to the symbol table
// use:
// symbol_new => symbol_set_* => symbol_finish (or symbol_cancel if something went wrong)



// list object
typedef struct SymbolWrapper
{
	struct Symbol*			Symbol;
	struct SymbolWrapper*	next;
} SymbolWrapper;


typedef struct Symbol
{
	char *symb;					// the string that holds the name of the Symbol
	int type;					//
	int size;					// size of variable in bytes
	int IS_ARRAY;				// if variable is array 1 for [] , x for [][x], 0 for non array
	int IS_POINTER;				// if variable is a pointer
	int is_val_param;			// param passed by value
	int is_var_param;			// param passed by reference
	int is_struct;				// is this symbol a struct?
	int is_struct_member;		// is this a struct member?
	struct Symbol* struct_type;	// pointer to struct type
	int is_proc;				// is this a procedure?
	int child_count;			// if is_proc - how many params ?
	SymbolWrapper* list;		// if this symbol is a struct or a procedure, these are its members.
} Symbol;


// start a new symbol
// called whenever a new symbol (of any type) is declared 
void symbol_new();


// destroy the symbol currently being defined.
// if something went wrong while preparing the symbol, this proc is called.
// currently, this proc is only used when 'symbol_set_struct_type' failed.
void symbol_cancel();


// dealloc symbol
void symbol_free(void *a);

// prints the symbol to printf
void symbol_print(struct Symbol* symbol);

// called when the symbol configuration is complete.
// this proc will move the symbol to the symbol table
void symbol_finish();

// the follwing setters are called between calls to 'symbol_new' and 'symbol_cancel'/'symbol_finish'
// to configure the symbol
void symbol_set_type(int type);
void symbol_set_name(char* name);
void symbol_set_isarray(int is_array);
void symbol_set_ispointer(int is_pointer);
void symbol_set_isprocedure(int is_procedure);
void symbol_set_isstruct(int is_struct);
void symbol_set_isvalparam(int is_val_param);
void symbol_set_isvarparam(int is_var_param);
void symbol_set_isstructmember(int struc_member);
int  symbol_set_struct_type(char* struct_name);

#endif 