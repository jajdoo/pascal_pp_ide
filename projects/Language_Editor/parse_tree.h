
#ifndef _PARSE_TREE_H__
#define _PARSE_TREE_H__

#include "typedef.h"


NODE tmp1;
NODE tmp2;
NODE root;

NODE makenode(int op, NODE s1, NODE s2, NODE s3, int val, char *id);
NODE genLeaf(int op, int val, double rval, char *id);

#endif