#include "commands.h"
#include "buffer.h"
#include "valStackInternals.h"
#include <stdio.h>

char commands[COMMANDC][MAXCOMMANDSIZE] = { 
	"print", 
	"duplicate", 
	"swap" 
};

void cmdPrint()
{
	printf("%g\n", valStack[stackPos]);
}
