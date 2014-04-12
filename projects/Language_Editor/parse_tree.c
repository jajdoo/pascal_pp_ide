
#include "parse_tree.h"

#include <stdio.h>
#include <stdlib.h>

#include "bison_file_tab.h"
#include "globals.h"


char *print_op(int op)
{
	FILE *txt;
	txt = fopen("outputParser.txt", "a");
	switch (op) {
	case PROGRAM:
		return ("PROGRAM");
		break;
	case STATEMENT:
		return ("STATEMENT");
		break;
	case BBEGIN:
		return("BEGIN");
		break;
	case ASSIGN:
		return ("ASSIGN");
		break;
	case IDE:
		return ("IDE");
		break;
	case POINTER:
		return ("POINTER");
		break;
	case ADD:
		return ("ADD");
		break;
	case MMIN:
		return ("MMIN");
		break;
	case MUL:
		return ("MUL");
		break;
	case DIV:
		return ("DIV");
		break;
	case MOD:
		return ("MOD");
		break;
	case AND:
		return ("AND");
		break;
	case OR:
		return ("OR");
		break;
	case NOT:
		return ("NOT");
		break;
	case INTCONST:
		return ("INTCONST");
		break;
	case REALCONST:
		return ("REALCONST");
		break;
	case TRUE:
		return ("TRUE");
		break;
	case FALSE:
		return ("FALSE");
		break;
	case IF:
		return ("IF");
		break;
	case LES:
		return ("LES");
		break;
	case LEQ:
		return ("LEQ");
		break;
	case EQU:
		return ("EQU");
		break;
	case NEQ:
		return ("NEQ");
		break;
	case GRE:
		return ("GRE");
		break;
	case GEQ:
		return ("GEQ");
		break;
	case WHILE:
		return ("WHILE");
		break;
	case CASESTAT:
		return ("CASESTAT");
		break;
	case CASELIST:
		return ("CASELIST");
		break;
	case CASE:
		return ("CASE");
		break;
	case BRACKETS:
		return ("[]");
		break;
	case BOOLEAN:
		return ("BOOLEAN");
		break;
	case INTEGER:
		return ("INTEGER");
		break;
	case FLOAT:
		return ("FLOAT");
		break;
	case REAL:
		return ("REAL");
		break;
	default:
		fprintf(txt, "Error at line %d: Unknown Token is line %d\n", line_number);
		return ("UNKNOWN");
	}
	fclose(txt);
}

void print_tree(NODE r, int s)
{

	if (r != NULL)
	{
		fprintf(treefile, "type=%s\n", print_op(r->op));
		fprintf(treefile, "children=%d\n", r->children);
		if (r->name) fprintf(treefile, "my check == = = ==> %s\n", r->name);
		if (r->op == IDE) fprintf(treefile, "string=%s\n", r->name);
		if (r->op == INTCONST)  fprintf(treefile, "int value=%d\n", r->num_val.val);
		if (r->op == REALCONST) fprintf(treefile, "real value=%f\n", r->num_val.rval);

		fprintf(treefile, "node type: %s\n\n", print_op(r->type));

		if (r->s1 != NULL)
		{
			fprintf(treefile, "| Son1 of %s\n", print_op(r->op));
			fprintf(treefile, "|\n");
			fprintf(treefile, "---------------\n");
			print_tree(r->s1, s + 2);
		}


		if (r->s2 != NULL)
		{
			fprintf(treefile, "| Son2 of %s\n", print_op(r->op));
			fprintf(treefile, "|\n");
			fprintf(treefile, "---------------\n");
			print_tree(r->s2, s + 2);

		}

		if (r->s3 != NULL)
		{
			fprintf(treefile, "| Son3 of %s\n", print_op(r->op));
			fprintf(treefile, "|\n");
			fprintf(treefile, "---------------\n");
			print_tree(r->s3, s + 2);
		}
	}
}



void updateVarType(int op)
{
	FILE *txt;
	txt = fopen("outputParser.txt", "a");
	switch (op)
	{
	case BOOLEAN:
		currentType = BOOLEAN;
		break;
	case INTEGER:
		currentType = INTEGER;
		break;
	case FLOAT:
		currentType = FLOAT;
		break;
	default:
		fprintf(txt, "Error at line %d: Undefined variable type\n", line_number);
		fclose(txt);
		break;
	}
}





NODE makenode(int op, NODE s1, NODE s2, NODE s3, int val, char *id)
{
	NODE t;
	FILE *txt;

	t = (NODE)malloc(sizeof(struct node));
	t->num_val.val = val;

	if (op == CASE)
		t->s1 = genLeaf(INTCONST, val, 0, NULL);
	else
		t->s1 = s1;

	t->s2 = s2;
	t->s3 = s3;

	t->name = (id != NULL) ? id : "";

	// counting children 
	t->children = 0;
	if (t->s1 != NULL) t->children++;
	if (t->s2 != NULL) t->children++;
	if (t->s3 != NULL) t->children++;

	t->op = op;

	if (op == ADD || op == MMIN || op == MUL || op == DIV || op == AND || op == OR || op == NOT || op == ASSIGN)
	{
		if (t->s1->type == t->s2->type)
			t->type = t->s1->type;
		else
		{
			txt = fopen("outputParser.txt", "a");

			printf("\nError at line %d:  %s  %s %s\n", line_number, print_op(t->s2->type), print_op(op), print_op(t->s1->type));
			fprintf(txt, "\nError at line %d:  %s  %s %s\n", line_number, print_op(t->s2->type), print_op(op), print_op(t->s1->type));
		}
	}

	return(t);
}





NODE genLeaf(int op, int val, double rval, char *id)
{
	NODE t;
	struct Symbol* s;

	if (id != NULL&&!findSymbol(id))
	{
		FILE *txt;
		txt = fopen("outputParser.txt", "a");
		fprintf(txt, "\nError at line %d: Undeclared identifier: %s", line_number, id);
		fclose(txt);
		exit(1);
	}

	t = (NODE)malloc(sizeof(struct node));
	t->num_val.val = val;

	t->op = op;

	if (id != NULL)
		t->name = id;
	else
		t->name = "";

	t->s1 = NULL;
	t->s2 = NULL;
	t->s3 = NULL;
	t->children = 0;

	switch (op)
	{
	case IDE:
		t->type = findSymbol(id)->type;
		break;

	case INTCONST:
		t->type = INTEGER;
		t->num_val.val = val;
		break;

	case REALCONST:
		t->type = FLOAT;
		t->num_val.rval = rval;
		break;

	case TRUE:
	case FALSE:
		t->type = BOOLEAN;
		break;
	}
	return(t);
}