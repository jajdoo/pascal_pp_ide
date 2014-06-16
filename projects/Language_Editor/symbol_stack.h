
#ifndef _SYMBOL_STACK_H__
#define _SYMBOL_STACK_H__

typedef struct Symbol Symbol;

	#ifdef __cplusplus
	extern "C" {
	#endif


	void symbol_stack_push();
	Symbol* symbol_stack_pop();

	void symbol_stack_set_type(int type);
	void symbol_stack_set_name(char* name);
	void symbol_stack_set_address(int address);
	void symbol_stack_set_size(int size);
	void symbol_stack_set_isarray(int is_array);
	void symbol_stack_set_ispointer(int is_pointer);
	void symbol_stack_set_isprocedure(int is_procedure);
	void symbol_stack_set_isstruct(int is_struct);

	/*temp debug method*/
	void symbol_stack_showme();

	#ifdef __cplusplus
	}
	#endif

#endif