#include "binarySearch.h"
#include "sortIntArray.h"
#include <stdio.h>

int randomInt(int lowerLimit, int upperLimit);

int main()
{
	const int testC = 6;

	int testArray[MAXINTARRLENGTH];
	const int testArrayLength = 10;
	const int testArrayLowerLimit = 0;
	const int testArrayUpperLimit = 16;
	srand(time(NULL));
	int i;
	for (i = 1; i <= testC; i++) {
		randomArray(testArrayLength, testArray, testArrayLowerLimit, testArrayUpperLimit);
		sortIntArray(testArrayLength, testArray);
		printIntArrCommaSeparated(testArrayLength, testArray);
		printf("\n");
	}
	return 0;
}

int randomInt(int lowerLimit, int upperLimit)
{
	return ( ( rand() * (upperLimit + 1 - lowerLimit) ) / RAND_MAX ) + lowerLimit;
}

void randomArray(int length, int array[], int lowerLimit, int upperLimit)
{
	int i;
	for (i = 0; i < length; i++) {
		array[i] = randomInt(lowerLimit, upperLimit);
	}
}

int searchInIntArr(int num, int array[])
{
	int position = -1;

	return position;
}
