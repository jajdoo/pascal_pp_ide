
#ifndef _SYMBOL_TABLE_H__
#define _SYMBOL_TABLE_H__

#include "typedef.h"

int currentType;


void addToSymbolTable(char *IDEName, int size, int IS_ARRAY, arrList lst, int is_struct);

#endif