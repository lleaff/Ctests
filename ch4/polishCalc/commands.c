#include "commands.h"
#include "buffer.h"
#include "valStack.h"
#include "valStackInternals.h"
#include <stdio.h>

void cmdPrint() /* 0 */
{
	if (stackPos) {
		printf("\"%g\"\n", readTopValue());
	} else {
		fprintf(stderr, "ERROR: stack empty can't print\n");
	}
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

void cmdClear()
{
	stackPos = 0;
}

void cmdTrim()
{
	if (stackPos) {
		stackPos--;
	} else {
		fprintf(stderr, "ERROR: stack empty can't delete top value\n");
	}
}

char commands[COMMANDC][MAXCOMMANDSIZE] = { 
	"print", 
	"duplicate", 
	"swap",
	"clear",
	"trim"
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
		case 3: cmdClear();
				break;
		case 4: cmdTrim();
				break;
		default: fprintf(stderr, "ERROR: No function at index %d\n", commandNum - 1);
				break;
	}
}
