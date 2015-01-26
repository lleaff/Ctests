#include "integerToString.h"
#include "binarySearch.h"
#include <stdio.h>
#include <math.h>

#define MAXSTRINGSIZE 1000

typedef enum { FALSE, TRUE } BOOL;

int main()
{
	const int testC = 20;
	char testString[MAXSTRINGSIZE];
	int testNums[testC];
	randomArray(testC, testNums, -9999, 9999);
	int i;
	for (i = 0; i < testC; i++) {
		integerToString(testNums[i], testString);
		printf("%5d\t%s\n", testNums[i], testString);
	}
}

int integerToString(int myInt, char myString[])
{
	int numLength = 0;
	BOOL neg = FALSE;
	if (myInt < 0) {
		neg = TRUE;
		myString[0] = '-';
		numLength++;
	}
	//get num length in decimal representation
	int tempNum = myInt;
	for (; tempNum != 0; tempNum /= 10, numLength++) {
	}
	int i;
	for (i = 0; i < (numLength - (neg ? 1 : 0)); myInt /= 10, i++) {
		myString[numLength - 1 - i] = (myInt % 10) * (myInt % 10 < 0 ? -1 : 1) + '0';
	}
	myString[numLength] = '\0'; //Close string
	return numLength;
}
