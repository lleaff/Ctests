#include "buffer.h"
#include <math.h>
#include <float.h>

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

double incompleteNum = NAN;
int fractionPart = 0;

//Digits
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

//All characters
char charBuffer = EMPTY;

void pushChar(char character)
{
	charBuffer = character;
}

char pullChar(void)
{
	return charBuffer;
}
