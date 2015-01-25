#include "shellSortIntArray.h"
#include "binarySearchAlt.h"
#include "sortIntArray.h"
#include <stdio.h>

#ifndef MAIN_FUNC
#define MAIN_FUNC
int main()
{
	int testC = 8;

	int testArrayLength = 20;
	int testArray[testArrayLength];

	int x;
	for(x = testC; x >= 0; x--) {
		randomArray(testArrayLength, testArray, 0, 99);
		printIntArrCommaSeparated(testArrayLength, testArray);
		printf("\n");
		shellSortIntArray(testArrayLength, testArray);
		printIntArrCommaSeparated(testArrayLength, testArray);
		printf("\n%s", (x > 0) ? "----------------------------------------------------\n" : "");
	}


	return 0;
}
#endif /* MAIN_FUNC */

void shellSortIntArray(int arrLength, int arr[])
{
	int gap, i, j, tmp;
	for (gap = arrLength / 2; gap > 0; gap /= 2) {
		for (i = gap; i < arrLength; i++) {
			for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
				tmp = arr[j + gap];
				arr[j + gap] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
