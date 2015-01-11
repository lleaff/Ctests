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

void explicitString(int length, char myString[])
{
	int i;
	for (i = 0; i < length; i++) {
		if (myString[i] == '\0') {
			printf("\\0");
		} else {
			printf("%2c", myString[i]);
		}
	}
}

void printDoubleArrCommaSeparated(int arrayLength, double array[])
{
	int i;
	for (i = 0; i < arrayLength; i++) {
		printf("%9.0f", array[i]);
		if (i < arrayLength - 1) {
			printf(", ");
		} else {
			printf(";");
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

void printSeparator()
{
	int width = 70;
	char separatorChar = '-';
	int i;
	for (i = 0; i < width; i++) {
		printf("%c", separatorChar);
	}
	printf("\n");
}

int main()
{
	int returnC = 0;

	printf("\nGeneric swap function\n");
	printSeparator();

	char x = 'x';
	char y = 'y';
	char xB = x, yB = y;
	printf("x: %-3c y: %-3c\n", x, y);
	swap(&y, &x, sizeof(char));
	printf("\n...swap(&y, &x, sizeof(char))...\n\n");
	printf("x: %-3c y: %-3c\n", x, y);
	testResult((x == yB && y == xB), returnC);
	printSeparator();

	double z = 9999;
	double w = 1.5;
	double zB = z, wB = w;
	printf("z: %-4.1f w: %-4.1f\n", z, w);
	swap(&z, &w, sizeof(double));
	printf("\n...swap(&z, &w, sizeof(double))...\n\n");
	printf("z: %-4.1f w: %-4.1f\n", z, w);
	testResult((z == wB && w == zB), returnC);
	printSeparator();

	char husband[10] = "Peter";
	char wife[10] = "Alexandra";
	printf("husband: %-9s wife: %-9s\n", husband, wife);
	explicitString(10, husband);
	printf("\n");
	explicitString(10, wife);
	printf("\n");
	swap(husband, wife, sizeof(char) * strlen(wife));
	printf("\n...swap(husband, wife, sizeof(char) * strlen(wife))...\n\n");
	printf("husband: %-9s wife: %-9s\n", husband, wife);
	explicitString(10, husband);
	printf("\n");
	explicitString(10, wife);
	printf("\n");
	testResult((husband[5] == 'n' && husband[6] == 'd' && wife[5] == '\0'), returnC);
	printSeparator();

	double numsX[5] = { 10, 15, 20, 25, 30 };
	double numsY[5] = { 34234, 230424, 234234, 504, 54391099 };
	printDoubleArrCommaSeparated(5, numsX);
	printf("\n");
	printDoubleArrCommaSeparated(5, numsY);
	printf("\n");
	swap(numsX, numsY, sizeof(double) * 5);
	printf("\n...swap(numsX, numsY, sizeof(double) * 5)...\n\n");
	printDoubleArrCommaSeparated(5, numsX);
	printf("\n");
	printDoubleArrCommaSeparated(5, numsY);
	printf("\n");
	testResult((numsX[0] == 34234 && numsY[0] == 10), returnC);
	printSeparator();

	return returnC;
}
