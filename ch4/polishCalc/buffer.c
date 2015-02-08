#include "buffer.h"
#include "commands.h"
#include "getOp.h"
#include <math.h>
#include <float.h>
#include <stdio.h>
#include <string.h>

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

/*---Numbers---*/
double incompleteNum = NAN;
int fractionPart = 0;

int charToInt(char digit)
{
	return digit - '0';
}

BOOL doubleIsNAN(double num)
{
	return !(DBL_MIN <= num && num <= DBL_MAX);
}

void storeNum(char digit)
{
	if (doubleIsNAN(incompleteNum)) {
		incompleteNum = 0;
	}
	if (digit == '.') {
		fractionPart = 1;
	} else if (fractionPart) {
		incompleteNum += pow(charToInt(digit), -(10 * fractionPart));
		fractionPart++;
	} else {
		incompleteNum = incompleteNum * 10 + charToInt(digit);
	}
}

void resetNum()
{
	fractionPart	= 0;
	incompleteNum	= NAN;
}

double pullNum(void)
{
	double num = incompleteNum;
	resetNum();
	return num;
}

/*---Commands---*/
char incompleteCommand[MAXCOMMANDSIZE] = "";
int comPos = 0;

void storeCommand(char myChar)
{
	if (comPos < MAXCOMMANDSIZE) {
		incompleteCommand[comPos++] = myChar;
		incompleteCommand[comPos] = '\0';
	} else {
		fprintf(stderr, "ERROR: Command stack full (> %d)", MAXCOMMANDSIZE);
	}
}

// Returns the index + 1 of a string in an array of
//strings if it matches the stored command string.
int compareCommand(void)
{
	extern char commands[COMMANDC][MAXCOMMANDSIZE];

	if (comPos == 0) {
		return -2; //Command buffer empty
	} else if (comPos == 1) {
		//We know it's a variable since only and all variables are 1 character long
		return VARIABLE; 
	}
	int i;
	for (i = 0; i < COMMANDC; i++) {
		if (!strcmp(incompleteCommand, commands[i])) {
			return i + 1;
		}
	}
	return 0; //No match
}

char readCharInCommand(int index)
{
	return incompleteCommand[index];
}

void resetCommand()
{
	comPos = 0;
	incompleteCommand[0] = '\0';
}
