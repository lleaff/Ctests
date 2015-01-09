#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

void swap(void *vpt1, void *vpt2, int size)
{
	void *tmp = malloc(size);
	memcpy(tmp, vpt1, size);
	memcpy(vpt1, vpt2, size);
	memcpy(vpt2, tmp, size);
}

void swapArrValues(void *arr1, void *arr2, int elementSize, int arrayLength)
{
	for (; arrayLength >= 0; arrayLength--) {
		swap(&arr1[arrayLength], &arr2[arrayLength], elementSize);
	}
}

void explicitString(int length, char myString[])
{
	int i;
	for (i = 0; i <= length; i++) {
		if (myString[i] == '\0') {
			printf("\\0");
		} else {
			printf("%2c", myString[i]);
		}
	}
}

void testResult(BOOL result, int returnC)
{
	printf("\t");
	if (result) {
		printf("[SUCCESS]");
	} else {
		returnC++;
		printf("[FAILURE]");
	}
	printf("\n");
}

int main()
{
	int returnC = 0;

	printf("\n\
Generic swap function\n\
---------------------\n");

	char x = 'x';
	char y = 'y';
	char xB = x, yB = y;
	printf("x: %-3c y: %-3c\n", x, y);
	swap(&y, &x, sizeof(char));
	printf("...swap(&y, &x, sizeof(char))...\n");
	printf("x: %-3c y: %-3c\n", x, y);
	testResult((x == yB && y == xB), returnC);
	printf("\n---------\n");

	double z = 9999;
	double w = 1.5;
	double zB = z, wB = w;
	printf("z: %-4f w: %-4f\n", z, w);
	swap(&z, &w, sizeof(double));
	printf("...swap(&z, &w, sizeof(double))...\n");
	printf("z: %-4f w: %-4f\n", z, w);
	testResult((z == wB && w == zB), returnC);
	printf("\n---------\n");

	char husband[9] = "Peter";
	char wife[] = "Alexandra";
	printf("husband: %-9s wife: %-9s\n", husband, wife);
	swap(&husband, &wife, sizeof(char*));
	printf("...swap(&husband, &wife, sizeof(char*))...\n");
	printf("husband: %-9s wife: %-9s\n", husband, wife);
	testResult((husband[5] == 'n' && husband[6] == 'd' && wife[5] == '\0'), returnC);
	explicitString(9, husband);
	printf("\n");
	explicitString(9, wife);
	printf("\n");
	printf("\n---------\n");

	char husband2[9] = "Peter";
	char wife2[] = "Alexandra";
	printf("husband2: %-9s wife2: %-9s\n", husband2, wife2);
	swapArrValues(husband2, wife2, sizeof(char), 9);
	printf("...swapArrValues(husband2, wife2, sizeof(char), 9)...\n");
	printf("husband2: %-9s wife2: %-9s\n", husband2, wife2);
	testResult((husband2[5] == 'n' && husband2[6] == 'd' && wife2[5] == '\0'), returnC);
	explicitString(9, husband2);
	printf("\n");
	explicitString(9, wife2);
	printf("\n");
	printf("\n---------\n");
	return returnC;
}
