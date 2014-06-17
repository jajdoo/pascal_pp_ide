
#ifndef _SYMBOL_STACK_H__
#define _SYMBOL_STACK_H__

typedef struct Symbol Symbol;

	#ifdef __cplusplus
	extern "C" {
	#endif

		
		/* start a new synbol above the previous one*/
		void symbol_stack_push();

		/* move this symbol to the symbol table */
		void symbol_stack_pop();

		/* make the last symbol be a member of the symbol before it (struct member, procedure param etc)*/
		void symbol_stack_pop_as_member();

		/*setters*/
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