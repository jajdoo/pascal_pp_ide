
#ifndef _PROC_CALL_H__
#define _PROC_CALL_H__

// procedures related to 


// is this proc call valid?
// proc call will be considred invalid if:
// - after proc_call_setproc		- if no such symbol 'p'
// - after proc_call_setproc		- if symbol 'p' is not a procedure
// - after proc_call_validate_arg	- if the parameter is declared VAR but the argument was not an identifer (may not send expr as VAR)
// - after proc_call_validate_arg	- if the type of the current parameter is different from the type of the argument
// - after proc_call_finish         - if number of arguments != number of parameters
int proc_call_valid();

// set the proc being called.
void proc_call_setproc(char* p);

// validate next argument against proc parameter list.
void proc_call_validate_arg(int type, int is_ide);

// called when no more arguments are available at this proc call.
void proc_call_finish();



#endif