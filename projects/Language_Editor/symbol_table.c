
#include <stdio.h>
#include <stdlib.h>

#include "symbol_table.h"
#include "globals.h"

//  The symbol table - hash table of 26 enteries (alphabetical) of Symbols
//	Remember : each symbol has a pointer to the next one. See decleration in typedef.h

struct Symbol *symbTable[26];	//a cell is pointer to first symbol
struct Symbol **first;			//pointer to a table cell - which is a pointer to symbol struct
struct Symbol *CurrSymbol;		//pointer to a symbol struct
int TableInitialized = 0;		//0 - table uninitialized, 1 - table initialized
int currentAddress;				// address of the new variable in stack



void addToSymbolTable(char *IDEName, int size, int IS_ARRAY, arrList lst, int is_struct)
{
	FILE *txt;
	txt = fopen("outputParser.txt", "a");
	int l, isPointer = 0;
	struct Symbol* newSymb;

	//fprintf(txt,"Info at line %d: adding to symbol table: %s \n",line_number,IDEName);
	if (size <= 0)
	{
		fprintf(txt, "\nErrorat line %d: illegal array size: %s has the size of %d", line_number, IDEName, size);
		fclose(txt);
		exit(1);
	}

	newSymb = (struct Symbol*)malloc(sizeof(struct Symbol));
	newSymb->lst = lst;

	if (!TableInitialized) // if table is uninitialized, then go initialize!
		InitializeTable();

	//check if the symbol was already declared
	if (findSymbol(IDEName) != NULL)
		fprintf(txt, "Error at line %d: Symbol %s already declared", line_number, IDEName);

	//pointer to a cell
	if (IDEName[strlen(IDEName) - 1] == '^')
	{
		int i = 0;
		IDEName[strlen(IDEName) - 1] = NULL;
		first = &symbTable[getTableEntry(IDEName)];

		isPointer = 1;
	}
	else
		first = &symbTable[getTableEntry(IDEName)];

	newSymb->IS_POINTER = isPointer;
	newSymb->symb = IDEName;
	newSymb->type = currentType;
	newSymb->address = currentAddress;
	newSymb->size = size;
	newSymb->IS_ARRAY = IS_ARRAY;

	newSymb->is_struct = is_struct;

	currentAddress += newSymb->size;

	fprintf(txt, "Info at line %d: adding symbol  %s of type %d to table variable\n", line_number, IDEName, currentType);
	if (*first != NULL)
		newSymb->next = (*first)->next;
	else
		newSymb->next = NULL;

	//cell is always points to last symbol entered into the list
	*first = newSymb;

	fclose(txt);
	PrintSymbolTable();//print current symbol table
}





// find type of var
int findType(char *name)
{
	int i;
	if (name == "")
		return 0;
	else
	for (i = 0; i<26; ++i){
		CurrSymbol = symbTable[i];
		while (CurrSymbol != NULL)
		{
			if (strcmp(name, CurrSymbol->symb) == 0)
				return CurrSymbol->type;
			CurrSymbol = CurrSymbol->next;
		}
	}

}




struct Symbol* findSymbol(char *IDENameIn)
{
	FILE *txt;
	txt = fopen("outputParser.txt", "a");
	int symbTabEntry;
	int isPointer = 0;
	char IDEName[100];
	strcpy(IDEName, IDENameIn);
	if (IDEName[strlen(IDEName) - 1] == '^')
	{
		int i = 0;
		isPointer = 1;
		IDEName[strlen(IDEName) - 1] = NULL;
	}
	symbTabEntry = getTableEntry(IDEName);
	CurrSymbol = symbTable[symbTabEntry];

	while (CurrSymbol != NULL)
	{
		if (!strcmp(CurrSymbol->symb, IDEName))
		{

			if (isPointer)
			{
				if (!CurrSymbol->IS_POINTER)
				{
					fprintf(txt, "Error at line %d: variable is not a pointer: %s\n", line_number, IDEName);
					fclose(txt);
					break;
				}

			}


			return (CurrSymbol);
		}
		else
			CurrSymbol = CurrSymbol->next;
	}

	return (NULL);
}





int getTableEntry(char *IDEName)
{
	if (islower(IDEName[0]))
		return (IDEName[0] - 'a');
	else
		return (IDEName[0] - 'A');
}





//zero all cells i.e. NULL all the pointers
void InitializeTable(void){
	int i;
	TableInitialized = 1;

	for (i = 0; i<26; ++i)
		symbTable[i] = NULL;

}




void print_struct_members(FILE* f, char* struct_name, struct Symbol* members)
{
	fprintf(f, "members for struct %s\n", struct_name);
	fprintf(f, "index\t|Name\t|Address\t|Size\t|IS ARRAY\t\t|IS POINTER\t|TYPE\t|is_struct\n");
	fprintf(f, "--------------------------------------------------------------\n");

	while (members != NULL)
	{
		fprintf(f, "%s\t\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d|\t\t%d\n",
			members->symb,
			members->address,
			members->size,
			members->IS_ARRAY,
			members->IS_POINTER,
			members->type,
			members->is_struct);
		members = members->next;
	}
}





void PrintArray(arrLST *l, FILE *t, int ind)
{
	if (!ind) return;
	fprintf(t, "%d     %d\n", l->size, l->sumsize);
	PrintArray(l + 1, t, ind - 1);
}





//print currentsymbol table
void PrintSymbolTable()
{
	int i;
	FILE* txt;
	FILE* txt1;
	FILE* membs;
	txt = fopen("symbol_table.txt", "w");
	txt1 = fopen("symbol_table1.txt", "w");
	membs = fopen("struct_membs.txt", "w");
	fprintf(txt1, "index\t|Name\t|Address\t|Size\t|IS ARRAY\t\t|IS POINTER\t|TYPE\t|is_struct\n");
	fprintf(txt1, "--------------------------------------------------------------\n");
	fprintf(txt, "Name   |Address  |Size  |IS ARRAY   |IS RECORD\n");
	fprintf(txt, "-----------------------------------------------\n");

	for (i = 0; i<26; ++i)
	{
		CurrSymbol = symbTable[i];
		while (CurrSymbol != NULL)
		{
			fprintf(txt1, "%d\t\t|%s\t\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%d|\t\t%d\n",
				i,
				CurrSymbol->symb,
				CurrSymbol->address,
				CurrSymbol->size,
				CurrSymbol->IS_ARRAY,
				CurrSymbol->IS_POINTER,
				CurrSymbol->type,
				CurrSymbol->is_struct);

			fprintf(txt, "%s      |%d        |%d     |%d\n"
				, CurrSymbol->symb,
				CurrSymbol->address,
				CurrSymbol->size,
				CurrSymbol->IS_ARRAY);

			if (CurrSymbol->is_struct == 1 && CurrSymbol->members != NULL)
				print_struct_members(membs, CurrSymbol->symb, CurrSymbol->members);

			PrintArray(CurrSymbol->lst, txt, CurrSymbol->IS_ARRAY);
			CurrSymbol = CurrSymbol->next;
		}
	}
	fclose(txt);
	fclose(txt1);
	fclose(membs);

}