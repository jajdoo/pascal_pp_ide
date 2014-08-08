
#ifndef _STRUCT_ACC_H__
#define _STRUCT_ACC_H__

/*
	interface for generating struct access.
	used by 'struct_acc' bison rules.
*/

/*
	is this struct access valid?
	struct access will be considered invalid :
	- after struct_acc_start		: if the symbol provided does not exist
	- after struct_acc_next			: if the symbol being accessed is not a struct instance 
	- after struct_acc_next			: if the member being accessed does not exists 
								      (ex: "a.b" and 'b' does not exists in 'a' as a struct member)
*/
int struct_acc_valid();


/*
	begins struct access for symbol 'ide'.

	checks if the first IDE in the struct access path is actually a struct,
	if it exists in the symbol table.
	sets the struct_acc_error flag accordingly.
*/
void struct_acc_start(char* ide);


/*
	validates struct access (checks of 'ide' exists in the previous symbol as a member) 

	if struct_acc_error is FALSE (struct_acc_start() finished successfully),
	loops through the IDE's to compare each IDE in the sstruct access path.
*/
void struct_acc_next(char* ide);


/*
	finishes the struct access (reinit)
*/
void struct_acc_finish();

// predec
typedef struct Symbol Symbol;

/*
	returns the current symbol
	used by parse tree to generate leaf.
	(hack)
*/
Symbol* struct_acc_cur_symbol();

#endif