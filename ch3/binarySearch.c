#include "binarySearch.h"
#include "sortIntArray.h"
#include <stdio.h>

int randomInt(int lowerLimit, int upperLimit);

#ifndef MAIN_FUNC
#define MAIN_FUNC
int main()
{
	const int testC = 6;

	int testArray[MAXINTARRLENGTH];
	const int testArrayLength = 10;
	const int testArrayLowerLimit = 0;
	const int testArrayUpperLimit = 16;
	const int searchedValue = 5;
	srand(time(NULL));
	int i;
	int pos;
	for (i = 1; i <= testC; i++) {
		randomArray(testArrayLength, testArray, testArrayLowerLimit, testArrayUpperLimit);
		sortIntArray(testArrayLength, testArray);
		printIntArrCommaSeparated(testArrayLength, testArray);
		printf("\n");
		for (pos = searchInIntArr(testArrayLength, testArray, searchedValue); pos > 0; pos--) {
			printf(" ");
		}
		if (pos >= 0) {
			printf("^\n");
		}
	}
	return 0;
}
#endif /* MAIN_FUNC */

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

//Binary search
int searchInIntArr(int arrayLength, int array[], int searchedValue)
{
	int low = 0, high = arrayLength;
	int mid = ( high - low ) / 2;
	int i;
	for ( i = mid; i >= 0 && i < arrayLength; ) {
		if (array[i] < searchedValue) {
			low = i + 1;
		} else if (array[i] > searchedValue) {
			high = i - 1;
		} else {
			return i;
		}
	}
	return -1; //Not found
}
