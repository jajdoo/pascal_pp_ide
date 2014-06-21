#ifndef _SYMBOL_TABLE_H__
#define _SYMBOL_TABLE_H__

#define HASH_SIZE 101
#define HASH_ADD_SUCCESS 1
#define HASH_ADD_FAILED_NO_CONTEXT -1
#define HASH_ADD_FAILED_ALREADY_EXIST 0

typedef void(*FreeFunc)(void*);
typedef void(*PrintFunc)(struct Symbol*);

void init(FreeFunc howToFreeYourData, PrintFunc print);
int addToSymbolTable(char *symbol, void *data);
void* getFromSymbolTable(char *symbol);
void enter_block(char *block_name);
void exit_block();
void printSymbolTable();

void* symbol_table_getcontext();

#endif