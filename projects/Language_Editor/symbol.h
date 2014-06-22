
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

	int is_param;
	int is_struct;					// is this symbol a struct?
	int is_struct_member;
	int is_proc;					// is this a procedure?
	int child_count;				// if is_proc - how many params ?
	SymbolWrapper* list;		// if this symbol is a struct, these are its members.
	// if this symbol is a procedure/function, these are its parameters;
} Symbol;


/* start a new symbol */
void symbol_new();

void symbol_free(void *a);

void symbol_print(struct Symbol* symbol);

/* move this symbol to the symbol table */
void symbol_finish();

/*setters*/
void symbol_set_type(int type);
void symbol_set_name(char* name);
void symbol_set_address(int address);
void symbol_set_size(int size);
void symbol_set_isarray(int is_array);
void symbol_set_ispointer(int is_pointer);
void symbol_set_isprocedure(int is_procedure);
void symbol_set_isstruct(int is_struct);
void symbol_set_isparameter(int is_param);
void symbol_set_isstructmember(int struc_member);

#endif 