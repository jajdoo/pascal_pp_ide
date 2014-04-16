
#ifndef _STRUCT_DEF_H__
#define _STRUCT_DEF_H__

#include "typedef.h"

/*  structs - part of symbol table  */

extern struct Symbol* cur_members;		// in struct_def.c

void new_struct_member(char *IDEName, int size, int IS_ARRAY, arrList lst);
void set_current_struct_name( char* struct_name );
void clear_current_struct();
void post_struct_def();

#endif