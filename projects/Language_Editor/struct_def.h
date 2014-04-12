
#ifndef _STRUCT_DEF_H__
#define _STRUCT_DEF_H__

#include "typedef.h"

/*  structs - part of symbol table  */

extern struct Symbol* cur_members;		// in struct_def.c

void new_struct_member(char *IDEName, int size, int IS_ARRAY, arrList lst, int is_struct);

#endif