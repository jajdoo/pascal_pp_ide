
#ifndef _STRUCT_DEF_H__
#define _STRUCT_DEF_H__

#include "typedef.h"

/*  structs - part of symbol table  */

void struct_def_prints();
void new_struct_member(char *IDEName, int size, int IS_ARRAY, arrList lst, int is_struct);

#endif