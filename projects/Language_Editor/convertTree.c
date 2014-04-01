#include <stdio.h>
#include "convertTree.h"
#include "stdlib.h"
#include "string.h"
#include "bison_file_tab.h"

int ide_type;
int VAR_IS_ARRAY=FALSE;
/*Function decleration*/
int TwoOperandsCommand(NODE n, int Op);

char* print_IL(int op)
{
    switch (op) 
	{ 
		case ADD:
			return ("ADD");
		case MMIN:
			return ("MMIN");
		case CMP:
			return ("CMP");
		case MUL:
			return ("MUL");
		case DIV:
			return ("DIV");
		case MOD:
			return ("MOD");
		case AND:
			return ("AND");
		case OR:
			return ("OR");
		case NOT:
			return ("NOT");
		case BGE:
			return ("BGE");
		case BGT:
			return ("BGT");
		case BNE:
			return ("BNE");
		case BEQ:
			return ("BEQ");
		case BLE:
			return ("BLE");
		case BLT:
			return ("BLT");
		case LOAD:
			return ("LOAD");
		case STORE:
			return ("STORE");
		case LOADI:
			return ("LOADI");
		case MOV:
			return ("MOV");
		case BRA:
			return ("BRA");
		case PHI:
			return ("PHI");
		case ERROR:
			return ("ERROR");
		
		default:
			return("Unknown Token\n");
	}     
}

/************************************************************************/
/* functions to convert the produced tree to a linked-list with 
/* intermediate-representation 
/************************************************************************/

int current_line = 1;
int free_reg_index = 0;

/************************************************************************/
/* Stack part                                                           */
/************************************************************************/

label *stackBottom = NULL, *stackTop = NULL;

void PushCommandLabel(command *c)
{
	label *l = (label *)malloc(sizeof(label));
	
	l->data = c;

	if (stackBottom == NULL || stackTop == NULL)
	{
		stackTop = l;
		stackBottom = l;
		l->next = NULL;
		l->prev = NULL;
	}
	else
	{
		l->prev = stackTop;
		stackTop->next = l;
		stackTop = l;
	}
}

void PopCommandLabel()
{
	label *temp = stackTop;
	
	if (stackTop != NULL)
	{
		stackTop = stackTop->prev;
		free(temp);
	}
}

/************************************************************************/
/* Insruction-list part                                                 */
/************************************************************************/

command *commandHead = NULL, *commandTail = NULL;
command *lastActualNode;

void PrintCommandsToFile(const char *filename)
{
	command* temp;
	FILE* f = fopen(filename, "w");

	if (f == NULL)
		return;

	for (temp = commandHead; temp!= NULL; temp=temp->next)
	{
		fprintf(f, "[%d] %s ", temp->line, print_IL(temp->op));

		if(temp->op==ERROR){
			fprintf(f,"\n");
			continue;
		}

		if(temp->op == LOADI)
			fprintf(f, "%d,R%d\n", temp->s1[0], temp->trg[0]);
		else
		{
			if(temp->s2[0] != -1)
			{
				// 2 source operands and 1 for the target  
				fprintf(f, "R%d,R%d,R%d\n", temp->s1[0], temp->s2[0], temp->trg[0]);
			}
			else
			{
				if(temp->trg[0] != -1)
				{
					fprintf(f, "R%d,R%d\n", temp->s1[0],temp->trg[0]);
				}
				else
				{
					if(temp->brnch != 0)
					{
						// Print the condition-register
						if (temp->op != BRA)
							fprintf(f, "R%d,", temp->s1[0]);

						// Print the line number to branch to
						fprintf(f, "%d\n", temp->brnch);
					}	
				}
			}
		}
		if (temp->next==NULL)
			fprintf(f, "[%d] NOP ", temp->line+1);
	}
	fclose(f);
}

command* AddCommand(command *c)
{
	if (commandTail == NULL)
	{
		commandTail = (command *)malloc(sizeof(command));
		commandHead = commandTail;
	}

	commandTail->brnch = c->brnch;
	commandTail->line = c->line;
	commandTail->next = c->next;
	commandTail->op = c->op;
	commandTail->pointer = c->pointer;
	commandTail->s1[0] = c->s1[0];
	commandTail->s1[1] = 0;
	commandTail->s2[0] = c->s2[0];
	commandTail->s2[1] = 0;
	commandTail->trg[0] = c->trg[0];
	commandTail->trg[1] = 0;

	lastActualNode = commandTail;
	commandTail->next = (command *)malloc(sizeof(command));
	commandTail = commandTail->next;
	
	// In case no more commands will be added, mark this as null operation
	commandTail->op = -1;
	commandTail->brnch = 0;
    commandTail->blockName = ' ';
    commandTail->next = NULL;

	return lastActualNode;
}

command* GetEndCommand()
{
	return commandTail;
}

/************************************************************************/
/* Symbol-Table part                                                    */
/************************************************************************/

int Constant(int val)
{
	command tempCommand;
	
    tempCommand.op = LOADI;
	tempCommand.trg[0] = free_reg_index;
	tempCommand.s1[0] = val;
	tempCommand.s2[0] = -1;
	tempCommand.line = current_line++;
	tempCommand.brnch = 0;
	tempCommand.pointer = GetEndCommand();
	AddCommand(&tempCommand);
	return free_reg_index++;
}


int Variable(char *varName)
{
	command *newCommand=(command*)malloc(sizeof(command));
	int target_register;
		// loadi x,R0        R0 has x address
	target_register=Constant(findSymbol(varName)->address);
	

	// load R0,R1       R1 has x content
	//array x[i] ,x is always l-value
	if(ide_type==R_VALUE||(VAR_IS_ARRAY==TRUE))
	{
		if ((findSymbol(varName)->IS_ARRAY>0&&ide_type==L_VALUE)||(findSymbol(varName)->IS_ARRAY==0&&ide_type==R_VALUE)) 
		{
			newCommand->op = LOAD;
			newCommand->s1[0] = target_register;
			newCommand->s2[0] = -1;
			newCommand->trg[0] = free_reg_index;
			newCommand->brnch = 0;
			newCommand->line = current_line++;
			newCommand->pointer = GetEndCommand();	
			AddCommand(newCommand);
			target_register=free_reg_index++;
		}
	}   
	if (findSymbol(varName)->IS_ARRAY>0) VAR_IS_ARRAY=TRUE;
	
	
		
		
	return target_register;
}
/************************************************************************/
/* Add LOAD command			                                                */
/************************************************************************/
int AddLOAD(NODE n)
{
	command *newCommand=(command*)malloc(sizeof(command));
		
	newCommand->op = LOAD;
	newCommand->s1[0] = TwoOperandsCommand(n, ADD);
	newCommand->s2[0] = -1;
	newCommand->trg[0] = free_reg_index;
	newCommand->brnch = 0;
	newCommand->line = current_line++;
	newCommand->pointer = GetEndCommand();	
	AddCommand(newCommand);
		   
	return free_reg_index++;
}

/************************************************************************/
/* Insruction			                                                */
/************************************************************************/

int TwoOperandsCommand(NODE n, int Op)
{
	command newCommand;

	newCommand.op = Op;
	newCommand.s1[0] = TreeToIL(n->s1);
	newCommand.s2[0] = TreeToIL(n->s2);

	newCommand.trg[0] = free_reg_index;
	newCommand.line = current_line++;
	newCommand.brnch = 0;
	newCommand.pointer = GetEndCommand();
	
	AddCommand(&newCommand);
	return free_reg_index++;
}

int CTwoOperandsCommand(int Op,int operand1_reg,int operand2_reg)
{
	command newCommand;

	newCommand.op = Op;
	newCommand.s1[0] = operand1_reg;
	newCommand.s2[0] = operand2_reg;
	newCommand.trg[0] = free_reg_index;
	newCommand.line = current_line++;
	newCommand.brnch = 0;
	newCommand.pointer = GetEndCommand();

	AddCommand(&newCommand);
	return free_reg_index++;
}



int OneOperandCommand(NODE n, int Op)
{
	command newCommand;
	
	newCommand.op = Op;
	newCommand.s1[0] = TreeToIL(n->s1);
	newCommand.s2[0] = -1;
	newCommand.trg[0] = free_reg_index;
	newCommand.line = current_line++;
	newCommand.pointer = GetEndCommand();
	newCommand.brnch = 0;

	AddCommand(&newCommand);	
	return free_reg_index++;
}

//every relation in source must yield COMPARE,BRANCH
int ComparisonCommand(NODE n, int Op)
{
	command newCommand;
	ide_type=R_VALUE;
	newCommand.op = Op;
	newCommand.s1[0] = TwoOperandsCommand(n,CMP);
	newCommand.s2[0] = -1;
	newCommand.trg[0] = -1;
	newCommand.line = current_line++;
	newCommand.brnch = 0;
	ide_type=L_VALUE;
	PushCommandLabel(AddCommand(&newCommand));
	return (newCommand.s1[0]);
}

int CComparisonCommand(int Op,int operand1_reg)
{
	command newCommand;
	
	newCommand.op = Op;
	newCommand.s1[0] = operand1_reg;
	newCommand.s2[0] = -1;
	newCommand.trg[0] = -1;
	newCommand.line = current_line++;
	newCommand.brnch = 0;

	PushCommandLabel(AddCommand(&newCommand));
	return (newCommand.s1[0]);
}



void ErrorCommand()
{
	command newCommand;
	
	newCommand.op = ERROR;
	newCommand.s1[0] = -1;
	newCommand.s2[0] = -1;
	newCommand.trg[0] = -1;
	newCommand.line = current_line++;
	newCommand.brnch = 0;

	AddCommand(&newCommand);	
	return;
}






/************************************************************************/
/* Main processing function                                             */
/************************************************************************/

//calculations are left to right
//a=6+3+5;
//     =
//   /   \
//  x      +
//       /   \
//      +     5
//    /   \
//   6    3 
//

int TreeToIL(NODE n)
{
	
	command tempCommand, *tempCommandPtr;
	int line_marker;
	int actual_address_reg;
	int array_size_reg;

	int base_reg,offset_reg,limit_reg,result_reg;

	switch (n->op) 
	{
		case PROGRAM:

			// Recursively process entire program
			TreeToIL(n->s1);
			
			// Removing the dummy tail-node used for IL production
			free(lastActualNode->next);
			lastActualNode->next = NULL;
			
			return 1;
		
		case STATEMENT:

			TreeToIL(n->s1);
		    
			if(n->s2!=NULL)
			   TreeToIL(n->s2);

		   return 1;

		case BBEGIN:

			TreeToIL(n->s1);
			return 1;

		case ASSIGN:

			VAR_IS_ARRAY=FALSE;
			tempCommand.op = STORE;
			tempCommand.trg[0] = TreeToIL(n->s1),ide_type=R_VALUE;	
			tempCommand.s1[0] = TreeToIL(n->s2),ide_type=L_VALUE;
			tempCommand.s2[0] = -1;
			tempCommand.line = current_line;
			tempCommand.brnch = 0;
			tempCommand.pointer = GetEndCommand();

			AddCommand(&tempCommand);
			current_line++;
			return 1;
		
		case IDE:	

			return Variable(n->name);
			  
		case ADD:
			if (n->s1->op==IDE&&findSymbol(n->s1->name)->IS_ARRAY>0&&ide_type==R_VALUE)
				return AddLOAD(n);
			else
				return TwoOperandsCommand(n, ADD);
		case MMIN:
			return TwoOperandsCommand(n, MMIN);
		
		case CMP:

			if (n->s2 != NULL)
				return TwoOperandsCommand(n, CMP);
			else
				return OneOperandCommand(n, CMP);

		case MUL:

			return TwoOperandsCommand(n, MUL);

		case DIV:
			//=================================================
			if ( n->s2->op==INTCONST )
			{
				if (n->s2->num_val.val == 0)
					printf("\nDIVIDE BY ZERO int !");
			}
			else if (n->s2->op == REALCONST)
			{
				if (n->s2->num_val.rval == 0.0f)
					printf("\nDIVIDE BY ZERO! real");
			}
			//=================================================
			return TwoOperandsCommand(n, DIV);
			
		case MOD:

			return TwoOperandsCommand(n, MOD);

		case AND:

			return TwoOperandsCommand(n, AND);

		case OR:

			return TwoOperandsCommand(n, OR);

		case NOT:
			
			return TwoOperandsCommand(n, NOT);
		
		case IF:

			// Process the condition part
			TreeToIL(n->s1);

			// Process the 'THEN' part
			TreeToIL(n->s2);

			// The command which comes at the end of the 'THEN' part,
			// which jumps to the line after the 'ELSE' part
			tempCommand.op = BRA;
			tempCommand.s1[0] = - 1;
			tempCommand.s2[0] = - 1;
			tempCommand.trg[0] = -1;
			tempCommand.line = current_line++;

			// Getting the actual place of the new command in the linked-list
			tempCommandPtr = AddCommand(&tempCommand);

			// Push the command to the stack
			PushCommandLabel(tempCommandPtr);

			// the node below the head holds conditional branch (the condition 
			// inside the 'IF', and its branch should be updated to the start of 
			// the 'ELSE' part
			stackTop->prev->data->brnch = current_line;
			stackTop->prev->data->pointer = GetEndCommand();

			if(n->s3 != NULL)
				TreeToIL(n->s3);

			// Updating the branch for the node with the BRA command (at the end of the 
			// 'THEN' part) with the line-number of the end of the 'ELSE' part
			stackTop->data->brnch = current_line;
			stackTop->data->pointer = GetEndCommand(); //was previoulsy: = tempCommandPtr;

			// After nodes were updated, no need for it in the stack
			PopCommandLabel();
			PopCommandLabel();

			return 1;
		
		case WHILE:
			
			// marking the point before the condition checking is made,
			// needed for branching at the end of the loop's body in order
			// to re-evaluate the condition
			line_marker = current_line;
					
			// Processing the condition part
			TreeToIL(n->s1);
			
			// setting tempcommandPtr to point to the condition-checking command
			tempCommandPtr = commandHead;
			while(tempCommandPtr->line != line_marker)
				tempCommandPtr = tempCommandPtr->next;

			// Processing the loop's body
			TreeToIL(n->s2);

			// The command to branch back to the condition, to be put at the end
			// of the loop's body
			tempCommand.op = BRA;
			tempCommand.s1[0] = -1;
			tempCommand.s2[0] = -1;
			tempCommand.trg[0] = -1;
			tempCommand.line = current_line;
			tempCommand.brnch = line_marker; 

			// Letting the branch command at the end of the loop body point to the 
			// condition-part
			tempCommand.pointer = tempCommandPtr;
			AddCommand(&tempCommand);
			
			// Updating the branch for the node pushed to the stack earlier,
			// with the place to branch to if condition doesn't hold,
			// (which is after the end of the loop's body and the BRA at the end of the body)
			stackTop->data->pointer = GetEndCommand();
			stackTop->data->brnch = ++current_line;

			// After node was updated, no need for it in the stack
			PopCommandLabel();
			return 1;
		
		case LES:
			return ComparisonCommand(n,BGE);
		
		case LEQ:
			return ComparisonCommand(n,BGT);
			
		case EQU:
			return ComparisonCommand(n,BNE);
			
		case NEQ:
			return ComparisonCommand(n,BEQ);
	 		
		case GRE:
			return ComparisonCommand(n,BLE);
		
		case GEQ:
			return ComparisonCommand(n,BLT);

		case CONST:
		case INTCONST:
			return Constant(n->num_val.val);
		case REALCONST:
		case TRUE:
		case FALSE:	
		case CASESTAT:
		case CASELIST:
	 	case CASE:
			return 1;			
	}
}
