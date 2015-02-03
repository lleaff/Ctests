#include "commands.h"
#include "buffer.h"
#include "valStack.h"
#include "valStackInternals.h"
#include <stdio.h>

void cmdPrint() /* 0 */
{
	printf("Stack = %g\n", valStack[stackPos - 1]);
}

void cmdDuplicate() /* 1 */
{
	push(valStack[stackPos - 1]);
}

void cmdSwap() /* 2 */
{
	double tmp = valStack[stackPos - 1];
	valStack[stackPos - 1] = valStack[stackPos - 2];
	valStack[stackPos - 2] = tmp;
}

char commands[COMMANDC][MAXCOMMANDSIZE] = { 
	"print", 
	"duplicate", 
	"swap" 
};

void execCommand(int commandNum)
{
	switch (commandNum - 1) {
		case -1: break; //Default value if compareCommand() returns no match
		case 0: cmdPrint();
				break;
		case 1: cmdDuplicate();
				break;
		case 2: cmdSwap();
				break;
		default: fprintf(stderr, "ERROR: No function at index %d\n", commandNum - 1);
				break;
	}
}
