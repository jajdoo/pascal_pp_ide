
#ifndef _SYMBOL_H__
#define _SYMBOL_H__

typedef struct SymbolWrapper
{
	struct Symbol*			Symbol;
	struct SymbolWrapper*	next;
} SymbolWrapper;


typedef struct Symbol
{
	char *symb;				// the string that holds the name of the Symbol
	char *funcName;			// the name of the function where the Symbol is decleared
	int type;
	int address;			// relative address to block
	int size;				// size of variable in bytes
	int IS_ARRAY;			// if variable is array 1 for [] , x for [][x], 0 for non array
	int IS_POINTER;			// if variable is a pointer
	/*	struct arrlist *lst;
	*/
	//----------------------
	// struct def: 
	//		- is_struct		= 1
	//		- type			= 0
	//		- address		= -1
	//		- members		= [actual members]
	//
	// struct instance: 
	//		- is_struct		= 1
	//		- type			= [index of struct def in symbol table]
	//		- address		= [actual adress]
	//		- members		- NULL

	int is_struct;					// is this symbol a struct?
	int is_proc;					// is this a procedure?
	SymbolWrapper* list;		// if this symbol is a struct, these are its members.
	// if this symbol is a procedure/function, these are its parameters;
} Symbol;


/* start a new symbol */
void symbol_new();

void symbol_free(Symbol* s);

/* move this symbol to the symbol table */
void symbol_finish();

/* same as finish, but also becomes a part of param list of the symbol (procedure) above it */
void symbol_finish_as_parameter();

/* same as finish, but also becomes a part of member list of the symbol (struct) above it */
void symbol_finish_as_member();

/*setters*/
void symbol_set_type(int type);
void symbol_set_name(char* name);
void symbol_set_address(int address);
void symbol_set_size(int size);
void symbol_set_isarray(int is_array);
void symbol_set_ispointer(int is_pointer);
void symbol_set_isprocedure(int is_procedure);
void symbol_set_isstruct(int is_struct);

#endif 