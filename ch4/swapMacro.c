#define DEBUG
#include "swapMacro.h"
#include <stdio.h>
#include "debug.h"

int main()
{
	double testDbl1 = 5e20;
	double testDbl2 = 3.0;
	DEBUGP("%-6g <-> %-6g\n", testDbl1, testDbl2);
	SWAP(double, testDbl1, testDbl2);
	DEBUGP("%-6g <-> %-6g\n", testDbl1, testDbl2);

	int testArr1[] = { 2, 4, 6 };
	int testArr2[] = { 11, 13, 15 };
	DEBUGP("%-2d, %-2d, %-2d <-> %-2d, %-2d, %-2d\n",
			testArr1[0], testArr1[1], testArr1[2], testArr2[0], testArr2[1], testArr2[2]);
	SWAPARR(int, 3, testArr1, testArr2);
	DEBUGP("%-2d, %-2d, %-2d <-> %-2d, %-2d, %-2d\n",
			testArr1[0], testArr1[1], testArr1[2], testArr2[0], testArr2[1], testArr2[2]);


	char testStr1[] = "Hello";
	char testStr2[] = "Hola";
	DEBUGP("%-9s <-> %-9s\n", testStr1, testStr2);
	SWAPSTR(testStr1, strlen(testStr1), testStr2, strlen(testStr2));
	DEBUGP("%-9s <-> %-9s\n", testStr1, testStr2);
}
