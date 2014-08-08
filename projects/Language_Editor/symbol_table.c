#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "symbol_table.h"

/** 
	Author : Ofek Ron
**/
typedef struct Address_t {
	int relativeAddress;
	int size;
	int nestingDepth;
} *Address;

/** 
	Author : Ofek Ron
	PRIVATE 
	The type of struct that presents any symbol in the symbol table
**/
typedef struct Symbol_t {
	void *data;
	struct Context_t *context;
	struct Symbol_t *next,*prev;
	Address address;
} *Symbol;

/** 
	Author : Ofek Ron
	PRIVATE 
	a wrapper for the symbol object to maintain symbols in a list per context
**/
typedef struct SymbolInContext_t {
	struct Symbol_t *symbol;
	char *name;
	struct SymbolInContext_t *next,*prev;
} *SymbolInContext;

/** 
	Author : Ofek Ron
	PRIVATE 
	a wrapper for the symbol object to maintain symbols in a list
**/
typedef struct SymbolList_t {
	char *symbol;
	struct Symbol_t *head;
} *SymbolList;

/** 
	Author : Ofek Ron
	PRIVATE 
	The type of struct that presents a context (block)
**/
typedef struct Context_t {
	char *symbol;
	struct Context_t *next,*prev;
	struct SymbolInContext_t *head;
	int nestingDepth;
	int currRelativeAddress;
} *Context;
typedef int (*Comparator)(void*,void*); 
typedef void (*FreeFunc)(void*); 

int str_cmp(void*a,void*b) {
	return strcmp((char *)a,(char *)b);
}


/** 
	Author : Ofek Ron
	PRIVATE 
	The type of struct that presents list of objects
**/
typedef struct List_t {
	struct Node_t *head;
	struct Node_t *tail;
	int count;
	Comparator cmp;
	FreeFunc freeFunc;
} *List,*Stack,*Queue;

typedef List * HashTable;

/** 
	Author : Ofek Ron
	PRIVATE 
	The type of struct that presents a node in a list of object
**/
typedef struct Node_t {
	void *data;
	struct Node_t *prev,*next;
} *Node;

/** 
	Author : Ofek Ron
	PRIVATE 
	our hash table is an array of lists
**/
typedef List * HashTable;


/** 
	Author : Ofek Ron
	PRIVATE 
	maintain nesting depth
**/
int currNestingDepth = 0;

/** 
	Author : Ofek Ron
	PRIVATE 
	our hash table is an array of lists - for each "bucket" we maintain a list of objects that hash function maps them to this bucket
**/
HashTable hashTable;


/** 
	Author : Ofek Ron
	PRIVATE 
	we maintain our context (block) list in a stack
**/
Context contextStackHead;
FreeFunc freeFunc;

/***************************************************************** 
	Author : Ofek Ron
	PRIVATE 
	managing a linked list
*******************************************************************/

/** 
	Author : Ofek Ron
	PRIVATE 
	creates new node containing data
**/
Node newNode(void *data) {
	Node n = (Node)malloc(sizeof(struct Node_t));
	n->data = data;
	n->prev=n->next=NULL;
	return n;
}

/** 
	Author : Ofek Ron
	PRIVATE 
	creates new list with cmp as its comparator and freeFunc as the function that frees the data
**/
List newList(Comparator cmp,FreeFunc freeFunc) {
	List l = (List)malloc(sizeof(struct List_t));
	l->head = l->tail = NULL;
	l->cmp = cmp;
	l->freeFunc = freeFunc;
	l->count=0;
	return l;
}


/** 
	Author : Ofek Ron
	PRIVATE 
	add a node containing data to the head of list l
**/
void addToHead(List l,void *data) {
	Node prevHead;
	if (l->count==0) {
		l->head=l->tail = newNode(data);
		return;
	}
	prevHead = l->head;
	l->head = newNode(data);
	l->head->next = prevHead;
	l->count++;
	return;
}

/** 
	Author : Ofek Ron
	PRIVATE 
	add a node containing data to the tail of list l
**/
void addToTail(List l,void *data) {
	Node newTail;
	if (l->count==0) {
		l->head=l->tail = newNode(data);
		return;
	}
	l->tail->next = newTail = newNode(data);
	newTail->prev = l->tail;
	l->tail = l->tail->next;
	l->count++;
	return;
}

/** 
	Author : Ofek Ron
	PRIVATE 
	remove the tail of list l
**/
void * removeTail(List l) {
	Node prevTail;
	void *data;
	if ( l->count==0 ) return NULL;
	prevTail = l->tail;
	data = prevTail->data;
	if (l->count==1) {
		l->head=l->tail = NULL;
		return data;
	} else {
		l->tail= l->tail->prev;
		l->tail->next=NULL;
	}
	free(prevTail);
	l->count--;
	return data; 
}

/** 
	Author : Ofek Ron
	PRIVATE 
	free whole list l
**/
void freeList(List l) {
	Node n = l->head;
	while (n!=NULL) {
		l->freeFunc(n->data);
		free(n);
		n=n->next;
	}
}
/** 
	Author : Ofek Ron
	PRIVATE 
	removes head of list l
**/
void * removeHead(List l) {
	Node prevHead;
	void *data;
	if ( l->count==0 ) return NULL;
	prevHead = l->head;
	data = prevHead->data;
	if (l->count==1) {
		l->head=l->tail = NULL;
		return data;
	} else {
		l->head= l->head->next;
		l->head->prev=NULL;
	}
	free(prevHead);
	l->count--;
	return data; 
}
/** 
	Author : Ofek Ron
	PRIVATE 
	removes a node n from list l
	assumes n is in l
**/
void *removeNode(List l,Node n) {
	void *data;
	if ( n == l->head ) 
		return removeHead(l); 
	if ( n == l->tail ) 
		return removeTail(l); 
	data = n->data;
	n->next->prev=n->prev;
	n->prev->next=n->next;
	free(n);
	l->count--;
	return data;
}

/***************************************************************** 
	Author : Ofek Ron
	PRIVATE 
	managing a stack and a queue using linked list
*******************************************************************/

void* pop(Stack s) {
	return removeHead(s);
}
void push(Stack s,void *e) {
	addToHead(s,e);
}
void* deq(Queue q) {
	return removeHead(q);
}
void enq(Queue q,void *e) {
	addToTail(q,e);
}

/***************************************************************** 
	Author : Ofek Ron
	PRIVATE 
	constructors for the symbol table structures
*******************************************************************/

Address newAddress(int size) {
	Address a = (Address)malloc(sizeof(struct Address_t));
	a->relativeAddress = contextStackHead->currRelativeAddress;
	a->size = size;
	a->nestingDepth = currNestingDepth;
	contextStackHead->currRelativeAddress=contextStackHead->currRelativeAddress+size;
	return a;
}
Symbol newSymbol(void *data,int size) {
	Symbol s = (Symbol)malloc(sizeof(struct Symbol_t));

	s->data = data;
	s->prev=s->next=NULL;
	s->context = NULL;
	s->address = newAddress(size);
	return s;
}
SymbolList newSymbolList(char *symbol) {
	SymbolList s = (SymbolList)malloc(sizeof(struct SymbolList_t));
	s->symbol = symbol;
	s->head=NULL;
	return s;
}
SymbolInContext newSymbolInContext(char *name,Symbol symbol) {
	SymbolInContext s = (SymbolInContext)malloc(sizeof(struct SymbolInContext_t));
	s->name = name;
	s->symbol = symbol;
	s->next=s->prev=NULL;
	return s;
}

Context newContext(char *name) {
	Context c = (Context)malloc(sizeof(struct Context_t));
	c->next = c->prev = NULL;
	c->head = NULL;
	c->symbol = name;
	c->currRelativeAddress = 0;
	c->nestingDepth = currNestingDepth;
	return c;
}

/***************************************************************** 
	Author : Ofek Ron
	PRIVATE 
	managing the hash table
*******************************************************************/
/** 
	Author : Ofek Ron
	PRIVATE 
	the hash function 
	contructs a new hash table
	O(HASH_SIZE)=O(1)
**/
HashTable newHashTable() {
	int i = 0;
	List *hash = (List *)malloc(sizeof(List)*HASH_SIZE);
	for ( ; i < HASH_SIZE ; i++ ) 
		hash[i]=NULL;
	return hash;
}


/** 
	Author : Ofek Ron
	PRIVATE 
	the hash function 
**/
int hash(char *name) {
	int hashVal,i;
	hashVal = 0;
	for (i=0;name[i]!='\0';i++) 
		hashVal+=(int)name[i]+i;
	return hashVal % HASH_SIZE;
}

/** 
	Author : Ofek Ron
	PRIVATE 
	finds the "bucket" that symbol is mapped to and returns the coresponding list of objects (that wither or not contains symbol itself)
**/
SymbolList hash_find(char *symbol,HashTable hashTable) {
	List bucket = hashTable[hash(symbol)];
	Node n;
	SymbolList s;
	if ( bucket==NULL ) 
		return NULL; 
	n = bucket->head;
	while (n!=NULL) {
		s = (SymbolList)n->data;
		if (bucket->cmp(s->symbol,symbol)==0)
			return s;
		n=n->next;
	}
	return NULL;
}

/** 
	Author : Ofek Ron
	PRIVATE 
	removes symbol from the hash table, if found returns the data that node held else returns null
**/
void *hash_remove(char *symbol,HashTable hashTable) {
	List bucket = hashTable[hash(symbol)];
	Node n;
	if ( bucket==NULL ) 
		return NULL; 
	n = bucket->head;
	while (n!=NULL) {
		if ( bucket->cmp(((SymbolList)n->data)->symbol,symbol ) == 0 ) 
		return removeNode(bucket,n);
		n=n->next;
	}
	return NULL;
}

/** 
	Author : Ofek Ron
	PRIVATE 
	inits a "bucket" in the hash table with a symbol list
**/
void hash_put(HashTable hashTable,SymbolList s) {
	int i = hash(s->symbol);
	List bucket = hashTable[i];
	if ( bucket==NULL ) 
		bucket = hashTable[i] = newList(str_cmp,free);
	push(bucket,s);
}

HashTable hashTable;
Context contextStackHead;
FreeFunc freeFunc;
PrintFunc printFunc;

/***************************************************************** 
	Author : Ofek Ron
	PUBLIC INTERFACE
	using the symbol table
*******************************************************************/
/** 
	Author : Ofek Ron
	PUBLIC 
	inits the symbol table
	O(HASH_SIZE)=O(1)
**/
void init(FreeFunc howToFreeYourData, PrintFunc print ) {

	freeFunc = howToFreeYourData;
	printFunc = print;
	contextStackHead = NULL;
	hashTable = newHashTable();
}
/** 
	Author : Ofek Ron
	PRIVATE 
	each bucket's symbol list is maintained using a sentinel for easier managing
**/
Symbol getSentinel(char *symbol) {
	SymbolList s = hash_find(symbol,hashTable);
	Symbol sentinel = NULL;
	if (s==NULL) {
		s = newSymbolList(strcpy((char *)malloc((strlen(symbol)+1)*sizeof(char)),symbol));
		s->head = sentinel = newSymbol(NULL,0);
		hash_put(hashTable,s);
	} else {
		sentinel = s->head;
	}
	return sentinel;
}

/** 
	Author : Ofek Ron
	PRIVATE 
	helper function that shove a node between two consecutive nodes
**/
void insert(Symbol prev,Symbol x,Symbol next) {
	if ( prev!=NULL ) prev->next = x;
	if ( next!=NULL ) next->prev = x;
	x->next = next;
	x->prev = prev;
}
//enter data corresponds to a symbol, returns HASH_ADD_SUCCESS if succeded, HASH_ADD_FAILED_NO_CONTEXT if no context is ever entered,HASH_ADD_FAILED_ALREADY_EXIST if the current context already defined the given symbol
/** 
	Author : Ofek Ron
	PUBLIC 
	enter data corresponds to a symbol, returns :
	HASH_ADD_SUCCESS if succeded, 
	HASH_ADD_FAILED_NO_CONTEXT if no context is ever entered,
	HASH_ADD_FAILED_ALREADY_EXIST if the current context already defined the given symbol
	O(1) in avarage
**/
int addToSymbolTable(char *symbol, void *data, int size) {
	Symbol sentinel,first,next = NULL,news;
	SymbolInContext newhead,oldhead;
	if ( contextStackHead == NULL ) {
		printf("ERROR : You have not entered a context!");
		return HASH_ADD_FAILED_NO_CONTEXT;
	}
	sentinel = getSentinel(symbol);
	first = sentinel->next;
	if (first!=NULL) {
		if (first->context == contextStackHead)
			return HASH_ADD_FAILED_ALREADY_EXIST;
	}
	news = newSymbol(data,size);
	newhead = newSymbolInContext(strcpy((char *)malloc((strlen(symbol)+1)*sizeof(char)),symbol),news);
	insert(sentinel,news,first);
	oldhead = contextStackHead -> head;
	if ( oldhead != NULL) 
		oldhead -> prev = newhead;
	newhead -> next = oldhead;
	contextStackHead -> head = newhead;
	news->context = contextStackHead;
	return HASH_ADD_SUCCESS;
}



//returns - the data corresponds to the symbol, null if not exists in the current context
/** 
	Author : Ofek Ron
	PUBLIC 
	returns - the data corresponds to the symbol, null if not exists in the current context
	O(1) in avarage
**/
void* getFromSymbolTable(char *symbol) {
	SymbolList sl;
	Symbol s=NULL;
	if ( symbol==NULL ) 
		return NULL;
	sl = hash_find(symbol,hashTable);
	if ( sl!=NULL ) 
		s = sl->head->next;
	return (s!=NULL) ? s->data : NULL;
}

//
/** 
	Author : Ofek Ron
	PUBLIC 
	get the adress structure of the symbol, free the struct when you are done
	NOTE : the struct returned need to be freed after done with by the caller!
	O(1) in avarage
**/
Address getAddress(char *symbol) {
	SymbolList sl;
	Symbol s=NULL;
	if ( symbol==NULL ) 
		return NULL;
	sl = hash_find(symbol,hashTable);
	if ( sl!=NULL ) 
		s = sl->head->next;
	return (s!=NULL) ? s->address : NULL;
}

/** 
	Author : Ofek Ron
	PUBLIC 
	enter a block (context), pushing a context to the context stack
	O(1)
**/
void enter_block( char *block_name ) {
	Context oldhead = contextStackHead;
	contextStackHead=newContext(strcpy((char *)malloc((strlen(block_name)+1)*sizeof(char)),block_name));
	contextStackHead->next=oldhead;
	if ( oldhead!=NULL ) 
		oldhead->prev= contextStackHead;
	currNestingDepth++;
}
/** 
	Author : Ofek Ron
	PUBLIC 
	exit a block (context), removing head of the context stack and the next context is the current context, 
	current nesting depth is decreased and all symbols and data on the context is freed. 
	O(n)
**/
void exit_block(  ) {
	Context oldhead = contextStackHead;
	SymbolInContext s = oldhead->head;
	SymbolInContext temp;
	Symbol tempSymbol;
	contextStackHead = oldhead->next;
	if ( contextStackHead!=NULL) 
		contextStackHead->prev = NULL;
	
	while (s!=NULL) {
		temp=s;
		s=s->next;
		if ( temp->next ) temp->next->prev = NULL;
		tempSymbol = temp->symbol;
		if ( tempSymbol->prev!=NULL ) tempSymbol->prev->next=tempSymbol->next;
		if ( tempSymbol->next!=NULL ) tempSymbol->next->prev = tempSymbol->prev;
		tempSymbol->context = NULL;
		if (tempSymbol->next==NULL) 
			hash_remove(temp->name,hashTable);
		freeFunc(tempSymbol->data);
		free(temp->name);
		free(temp->symbol);
		free(temp);
	}
	free(oldhead->symbol);
	free(oldhead);
	currNestingDepth--;
}


/** 
	Author : Ofek Ron
	PUBLIC 
	prints the symbol table with all relevant data
	for debuging purposes
**/
void printSymbolTable() {
	
	int i = 0;
	Context t = contextStackHead;
	SymbolInContext s;
	printf("\n\n\n\n\n                    symbol table                 \n");
	printf("=================================================\n");
	printf("-------------------------------------------------\n");

	printf("context symbol::::::::::::::::::::: \n");
	printFunc( (Symbol*)symbol_table_getcontext() );
	
	printf("symbols::::::::::::::::::::;\n");
	while (t!=NULL) {
		//printf("%s : ",t->symbol);
		s = t->head;
		while(s!=NULL) {
			//printf("%s ",s->name);
			printFunc(s->symbol->data);
			s = s->next;
		}
		printf("\n");
		t= t->next;
	}

	printf("-------------------------------------------------\n");
	printf("=================================================\n\n\n\n\n\n");
}







/**
Author: nir
PUBLIC
wrote a hack to get the current context
**/
void* symbol_table_getcontext()
{
	return getFromSymbolTable(contextStackHead->symbol);
}





/*
void _free(void *a) {

}*/
/*
void main(char *args[],int argc) {
	init(_free);
	enter_block("ProcM");
	add("a","M a");
	add("b","M b");
	add("c","M c");
	printf("\n\nStarted ProcM :\n");
	printSymbolTable();
	printf("\n\nRequesting for variables :\n");
	printf("a : %s\n",get("a"));
	printf("b : %s\n",get("b"));
	printf("c : %s\n",get("c"));
	printf("d : %s\n",get("d"));


	enter_block("ProcA");
	add("a","A a");
	add("c","A c");
	add("d","A d");
	printf("\n\nStarted ProcA :\n");
	printSymbolTable();
	printf("\n\nRequesting for variables :\n");
	printf("a : %s\n",get("a"));
	printf("b : %s\n",get("b"));
	printf("c : %s\n",get("c"));
	printf("d : %s\n",get("d"));


	enter_block("ProcB");
	add("d","B d");
	add("c","B c");
	printf("\n\nStarted ProcB :\n");
	printSymbolTable();
	printf("\n\nRequesting for variables :\n");
	printf("a : %s\n",get("a"));
	printf("b : %s\n",get("b"));
	printf("c : %s\n",get("c"));
	printf("d : %s\n",get("d"));

	printf("Trying to add d again...\n");
	if (add("d","data_c")==HASH_ADD_FAILED_ALREADY_EXIST) 
		printf("Already Defined!\n");
	else
		printf("BUG!!!\n");
	

	printf("\n\nRequesting for variables :\n");
	printf("a : %s\n",get("a"));
	printf("b : %s\n",get("b"));
	printf("c : %s\n",get("c"));
	printf("d : %s\n",get("d"));

	exit_block();
	printf("\n\nExit ProcB :\n");
	printSymbolTable();
	printf("\n\nRequesting for variables :\n");
	printf("a : %s\n",get("a"));
	printf("b : %s\n",get("b"));
	printf("c : %s\n",get("c"));
	printf("d : %s\n",get("d"));

	exit_block();
	printf("\n\nExit ProcA :\n");
	printSymbolTable();
	printf("\n\nRequesting for variables :\n");
	printf("a : %s\n",get("a"));
	printf("b : %s\n",get("b"));
	printf("c : %s\n",get("c"));
	printf("d : %s\n",get("d"));


	exit_block();
	printf("\n\nExit ProcM :\n");
	printSymbolTable();
	printf("\n\nRequesting for variables :\n");
	printf("a : %s\n",get("a"));
	printf("b : %s\n",get("b"));
	printf("c : %s\n",get("c"));
	printf("d : %s\n",get("d"));
	printf("\n");

	getchar();
}
*/