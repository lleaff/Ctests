#include "sortIntArray.h"
#include <stdio.h>

//#ifndef MAIN_FUNC
//#define MAIN_FUNC
//int main()
//{
//	ReturnCode returnC = ERROR;
//
//
//	int *testIntArrays[10];
//	int testIntArraysL[10];
//	int testIntArray1[MAXINTARRLENGTH] = { 43, 36, 2, 0, 65, -594, 5, 54, 70, 50, -4, 999 };
//	testIntArraysL[0] = 12;
//	testIntArrays[0] = testIntArray1;
//	int testIntArray2[MAXINTARRLENGTH] = { 0, 432, 5, 0, 38, 0 };
//	testIntArraysL[1] = 6;
//	testIntArrays[1] = testIntArray2;
//	int testIntArraysC = 2;
//
//	int i;
//	for (i = 0; i < testIntArraysC; i++) {
//		printIntArrCommaSeparated(testIntArraysL[i], testIntArrays[i]);
//		printf("\n");
//		sortIntArray(testIntArraysL[i], testIntArrays[i]);
//		printIntArrCommaSeparated(testIntArraysL[i], testIntArrays[i]);
//		printf("\n-------------------------------------------------------------------------------\n");
//	}
//
//	returnC = YES;
//	return returnC;
//}
//#endif /* MAIN_FUNC */

int power(int operand, int power)
{
	int num = operand;
	for(; power > 0; power--) {
		num *= operand;
	}
	return num;
}

//void alignNumbers(char formattedNum[], int num, int align)
//{
//	int numL = 0;
//	int tmp = num;
//	while (tmp > 0) {
//		tmp = num / 10;
//		numL++;
//	}
//	int i;
//	if (align) {
//		formattedNum[align] = '\0';
//		for (i = align; align >= 0; align--) {
//
//		}
//	} else {
//		formattedNum[-align] = '\0';
//	}
//}

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
