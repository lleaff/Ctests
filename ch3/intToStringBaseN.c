#include "intToStringBaseN.h"
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
	srand(time(NULL));
	randomArray(testC, testNums, -9999, 9999);
	const int basesC = 5;
	int bases[] = { 2, 8, 10, 16, 32 };
	int i, n;
	for (i = 0; i < testC; i++) {
		printf("%d:", testNums[i]);
		for (n = 0; n < basesC; n++) {
			intToStringBaseN(testNums[i], bases[n], testString);
			printf("%s%s", testString, (i < testC - 1) ? "   " : "");
		}
		printf("\n");
	}

	//Test with lowest negative int
	const int intLowerLimit = (int)-(pow(2.0, sizeof(int) * 8) / 2);
	intToStringBaseN(intLowerLimit, 10, testString);
	printf("%d\t%s\n", intLowerLimit, testString);

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
