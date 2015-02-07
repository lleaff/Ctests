#include "valStack.h"
#include "valStackInternals.h"
#include <math.h>
#include <stdio.h>
#include <ctype.h>

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

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
		fprintf(stderr, "ERROR: stack empty can't pull\n");
		return 0.0;
	}
}

double readTopValue(void)
{
	if (stackPos > 0) {
		return valStack[stackPos - 1];
	} else {
		fprintf(stderr, "ERROR: stack empty can't read\n");
		return 0.0;
	}
}

/*---Variables---*/
#define VARIABLEC 26 //Number of letters in the alphabet
double variables[VARIABLEC];
BOOL varSet[VARIABLEC] = { FALSE };

int workingVar;

void setVar(char myChar)
{
	myChar = tolower(myChar);
	workingVar = myChar - 'a';
}

void pushVar(double value)
{
	variables[workingVar] = value;
	varSet[workingVar] = TRUE;
}

double readVar(void)
{
	return variables[workingVar];
}

BOOL isVarInit(void)
{
	return varSet[workingVar];
}
