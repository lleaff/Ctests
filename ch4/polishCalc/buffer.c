#include "buffer.h"
#include <math.h>

double incompleteNum = 0;
int fractionPart = 0;
char charBuffer = '\0';

int charToInt(char digit)
{
	return digit - '0';
}

void storeNum(char digit)
{
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
	incompleteNum	= 0;
}

double pullNum(void)
{
	double num = incompleteNum;
	resetNum();
	return num;
}

void pushChar(char character)
{
	charBuffer = character;
}

char pullChar(void)
{
	return charBuffer;
}
