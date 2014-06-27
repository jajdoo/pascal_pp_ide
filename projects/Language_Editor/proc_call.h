
#ifndef _PROC_CALL_H__
#define _PROC_CALL_H__


int proc_call_valid();
void proc_call_setproc(char* p);
void proc_call_finish();

void proc_call_validate_arg(int type, int is_ide);

#endif