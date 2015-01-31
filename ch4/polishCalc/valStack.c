#include "valStack.h"
#include <math.h>
#include <stdio.h>

#define STACKSIZE 100

double valStack[STACKSIZE];
int stackPos = 0; //Current stack position

void push(double value)
{
	extern int stackPos;
	if (stackPos < STACKSIZE) {
		valStack[stackPos] = value;
		stackPos++;
	} else {
		fprintf(stderr, "ERROR: stack full (%d values) can't push: %g\n", STACKSIZE, value);
	}
}

double pull(void)
{
	extern int stackPos;
	if (stackPos > 0) {
		--stackPos;
		return valStack[stackPos];
	} else {
		fprintf(stderr, "ERROR: stack empty\n");
		return 0.0;
	}
}