#ifndef _SYMBOL_TABLE_H__
#define _SYMBOL_TABLE_H__


/**

	documentation is in the .c file

*/

#define HASH_SIZE 101
#define HASH_ADD_SUCCESS 1
#define HASH_ADD_FAILED_NO_CONTEXT -1
#define HASH_ADD_FAILED_ALREADY_EXIST 0

typedef void(*FreeFunc)(void*);
typedef void(*PrintFunc)(struct Symbol*);


/**
Author : Ofek Ron
PUBLIC
inits the symbol table
O(HASH_SIZE)=O(1)
**/
void init(FreeFunc howToFreeYourData, PrintFunc print);


//enter data corresponds to a symbol, returns HASH_ADD_SUCCESS if succeded, HASH_ADD_FAILED_NO_CONTEXT if no context is ever entered,HASH_ADD_FAILED_ALREADY_EXIST if the current context already defined the given symbol
/**
Author : Ofek Ron
PUBLIC
enter data corresponds to a symbol, returns :
HASH_ADD_SUCCESS if succeded,
HASH_ADD_FAILED_NO_CONTEXT if no context is ever entered,
HASH_ADD_FAILED_ALREADY_EXIST if the current context already defined the given symbol
O(1) in avarage
**/
int addToSymbolTable(char *symbol, void *data, int size);


//returns - the data corresponds to the symbol, null if not exists in the current context
/**
Author : Ofek Ron
PUBLIC
returns - the data corresponds to the symbol, null if not exists in the current context
O(1) in avarage
**/
void* getFromSymbolTable(char *symbol);


/**
Author : Ofek Ron
PUBLIC
enter a block (context), pushing a context to the context stack
O(1)
**/
void enter_block(char *block_name);


/**
Author : Ofek Ron
PUBLIC
exit a block (context), removing head of the context stack and the next context is the current context,
current nesting depth is decreased and all symbols and data on the context is freed.
O(n)
**/
void exit_block();


/**
Author : Ofek Ron
PUBLIC
prints the symbol table with all relevant data
for debuging purposes
**/
void printSymbolTable();


/**
Author: nir 
PUBLIC 
wrote a hack to get the current context
**/
void* symbol_table_getcontext();

#endif