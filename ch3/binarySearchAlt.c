#include "binarySearch.h"
#include "sortIntArray.h"
#include <stdio.h>

int randomInt(int lowerLimit, int upperLimit);
int charToDigit(char myChar);
int stringToInt(char myString[]);

#ifndef MAIN_FUNC
#define MAIN_FUNC
int main(int argc, char *argv[])
{
	const int testC = 6; // number of tests

	const int testArrayLength = 10;
	const int testArrayLowerLimit = 0;
	const int testArrayUpperLimit = 16;
	int searchedValue = 0;

	if (argc <= 1) {
	printf("What value between %d and %d do you want to search for?\n", testArrayLowerLimit, testArrayUpperLimit);
		scanf("%d", &searchedValue);
	} else {
		searchedValue = stringToInt(argv[1]);
	}
	printf("Let's search the number %d in those arrays:\n", searchedValue);

	int testArray[MAXINTARRLENGTH];

	srand(time(NULL));
	int i, j, curVal;
	int pos;
	for (i = 1; i <= testC; i++) {
		randomArray(testArrayLength, testArray, testArrayLowerLimit, testArrayUpperLimit);
		sortIntArray(testArrayLength, testArray);
		printIntArrCommaSeparated(testArrayLength, testArray);
		printf("\n");
		//Put spaces before arrow
		for (pos = searchInIntArr(testArrayLength, testArray, searchedValue), j = 0; pos > 0 && j < pos; j++) {
			//Compensate for spaces, commas and number of digits, dependant on printIntArrCommaSeparated
			for (curVal = ((testArray[j] == 0) ? 1 : testArray[j]) * (j > 0 ? 100 : 10); curVal > 0; curVal /= 10) {
				printf(" ");
			}
		}
		if (pos >= 0) {
			for (curVal = ((testArray[j] == 0) ? 1 : testArray[j]); curVal > 0 && pos > 0; curVal /= 10) {
				printf(" ");
			}
			printf("^\n");
		} else {
			printf("Not found.\n");
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
	for (i = mid; low < high; i = ((high - low) / 2) + low) {
		if (array[i] < searchedValue) {
			low = i + 1;
		} else {
			high = i - 1;
		}
	}
	if (array[i] == searchedValue) {
		return i;
	} else {
		return -1; //Not found
	}
}


//Binary search 
int searchInIntArr2Tests(int arrayLength, int array[], int searchedValue)
{
	int low = 0, high = arrayLength;
	int mid = ( high - low ) / 2;
	int i;
	for (i = mid; low < high; i = ((high - low) / 2) + low) {
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

int charToDigit(char myChar)
{
	if (myChar >= '0' && myChar <= '9') {
		return myChar - '0';
	} else {
		return -1; //char is not digit
	}
}

int stringToInt(char myString[])
{
	int i, digit, result = 0;
	for (i = 0; myString[i] != '\0'; i++) {
		if ((digit = charToDigit(myString[i])) >= 0) {
			result = (result * 10) + digit;
		}
	}
	return result;
}
