#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "symbol_table.h"

/** 
	Author : Ofek Ron
**/
#define HASH_SIZE 101
#define HASH_ADD_SUCCESS 1
#define HASH_ADD_FAILED_NO_CONTEXT -1
#define HASH_ADD_FAILED_ALREADY_EXIST 0

typedef struct Symbol_t {
	void *data;
	struct Context_t *context;
	struct Symbol_t *next,*prev;
} *Symbol;
typedef struct SymbolInContext_t {
	struct Symbol_t *symbol;
	char *name;
	struct SymbolInContext_t *next,*prev;
} *SymbolInContext;
typedef struct SymbolList_t {
	char *symbol;
	struct Symbol_t *head;
} *SymbolList;

typedef struct Context_t {
	char *symbol;
	struct Context_t *next,*prev;
	struct SymbolInContext_t *head;
} *Context;
typedef int (*Comparator)(void*,void*); 
typedef void (*FreeFunc)(void*); 

int str_cmp(void*a,void*b) {
	return strcmp((char *)a,(char *)b);
}
typedef struct List_t {
	struct Node_t *head;
	struct Node_t *tail;
	int count;
	Comparator cmp;
	FreeFunc freeFunc;
} *List,*Stack,*Queue;

typedef List * HashTable;

typedef struct Node_t {
	void *data;
	struct Node_t *prev,*next;
} *Node;

Node newNode(void *data) {
	Node n = (Node)malloc(sizeof(struct Node_t));
	n->data = data;
	n->prev=n->next=NULL;
	return n;
}

List newList(Comparator cmp,FreeFunc freeFunc) {
	List l = (List)malloc(sizeof(struct List_t));
	l->head = l->tail = NULL;
	l->cmp = cmp;
	l->freeFunc = freeFunc;
	l->count=0;
	return l;
}

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

void freeList(List l) {
	Node n = l->head;
	while (n!=NULL) {
		l->freeFunc(n->data);
		free(n);
		n=n->next;
	}
}
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

Symbol newSymbol(void *data) {
	Symbol s = (Symbol)malloc(sizeof(struct Symbol_t));

	s->data = data;
	s->prev=s->next=NULL;
	s->context = NULL;
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
	return c;
}
HashTable newHashTable() {
	int i = 0;
	List *hash = (List *)malloc(sizeof(List)*HASH_SIZE);
	for ( ; i < HASH_SIZE ; i++ ) 
		hash[i]=NULL;
	return hash;
}
int hash(char *name) {
	int hashVal,i;
	hashVal = 0;
	for (i=0;name[i]!='\0';i++) 
		hashVal+=(int)name[i]+i;
	return hashVal % HASH_SIZE;
}
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

void init(FreeFunc howToFreeYourData, PrintFunc print ) {

	freeFunc = howToFreeYourData;
	printFunc = print;
	contextStackHead = NULL;
	hashTable = newHashTable();
}


Symbol getSentinel(char *symbol) {
	SymbolList s = hash_find(symbol,hashTable);
	Symbol sentinel = NULL;
	if (s==NULL) {
		s = newSymbolList(strcpy((char *)malloc((strlen(symbol)+1)*sizeof(char)),symbol));
		s->head = sentinel = newSymbol(NULL);
		hash_put(hashTable,s);
	} else {
		sentinel = s->head;
	}
	return sentinel;
}
void insert(Symbol prev,Symbol x,Symbol next) {
	if ( prev!=NULL ) prev->next = x;
	if ( next!=NULL ) next->prev = x;
	x->next = next;
	x->prev = prev;
}
//enter data corresponds to a symbol, returns HASH_ADD_SUCCESS if succeded, HASH_ADD_FAILED_NO_CONTEXT if no context is ever entered,HASH_ADD_FAILED_ALREADY_EXIST if the current context already defined the given symbol
int addToSymbolTable(char *symbol, void *data) {
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
	news = newSymbol(data);
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

void enter_block( char *block_name ) {
	Context oldhead = contextStackHead;
	contextStackHead=newContext(strcpy((char *)malloc((strlen(block_name)+1)*sizeof(char)),block_name));
	contextStackHead->next=oldhead;
	if ( oldhead!=NULL ) 
		oldhead->prev= contextStackHead;
}

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
}

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