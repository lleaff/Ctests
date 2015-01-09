#include "sortIntArray.h"
#include <stdio.h>

int main()
{
	ReturnCode returnC = ERROR;


	int *testIntArrays[10];
	int testIntArraysL[10];
	int testIntArray1[MAXINTARRLENGTH] = { 43, 36, 2, 0, 65, -594, 5, 54, 70, 50, -4, 999 };
	testIntArraysL[0] = 12;
	testIntArrays[0] = testIntArray1;
	int testIntArray2[MAXINTARRLENGTH] = { 0, 432, 5, 0, 38, 0 };
	testIntArraysL[1] = 6;
	testIntArrays[1] = testIntArray2;
	int testIntArraysC = 2;

	int i;
	for (i = 0; i < testIntArraysC; i++) {
		printIntArrCommaSeparated(testIntArraysL[i], testIntArrays[i]);
		printf("\n");
		sortIntArray(testIntArraysL[i], testIntArrays[i]);
		printIntArrCommaSeparated(testIntArraysL[i], testIntArrays[i]);
		printf("\n-------------------------------------------------------------------------------\n");
	}

	returnC = YES;
	return returnC;
}

void printIntArrCommaSeparated(int arrayLength, int array[])
{
	int i;
	for (i = 0; i < arrayLength; i++) {
		printf("%d", array[i]);
		if (i < arrayLength - 1) {
			printf(", ");
		} else {
			printf(";");
		}
	}
}

void swapInts(int *val1, int *val2)
{
	int tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

int sortIntArray(int arrayLength, int array[])
{
	int i, j;
	for (i = 0; i < arrayLength - 1;i++) {
		for (j = i + 1; j < arrayLength; j++) {
			if (array[i] > array[j]) {
				swapInts(&array[i], &array[j]);
			}
		}
	}
	return 0; //Success
}
