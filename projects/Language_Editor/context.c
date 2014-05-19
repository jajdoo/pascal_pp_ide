

#include <string.h>
#include <stdio.h>

#include "context.h"




char context[1024];
int buff_pos;



void initContext()
{
	strcpy(context, "\0");
}



char* getContext()
{
	return context;
}



void enterContext(char* c)
{
	printf("================================\n");
	printf("entering context: %s \n prev context: %s\n", c, context);

	strcat(context, c);
	strcat(context, ".");

	printf("new context: %s: \n", context);
	printf("================================\n");
}



void exitContext()
{
	char* pos;

	printf("================================\n");
	printf("exiting context:\n prev context: %s\n", context);

	pos = strrchr(context, '.');
	*pos= '\0';

	pos = strrchr(context, '.');
	if (pos != NULL)
		*(pos + 1) = '\0';
	else
		context[0] = '\0';

	printf("new context: %s: \n", context);
	printf("================================\n");
}
