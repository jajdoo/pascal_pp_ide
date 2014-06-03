#ifndef _SYMBOL_TABLE_H__
#define _SYMBOL_TABLE_H__




int addToSymbolTable(char *symbol, void *data);
void* getFromSymbolTable(char *symbol);
void enter_block(char *block_name);
void exit_block();

#endif