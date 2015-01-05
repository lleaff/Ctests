#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

typedef  enum {false = 0, true = 1} BOOL;
long numericTypeMin(int bytes, BOOL isSigned);
long numericTypeMax(int bytes, BOOL isSigned);

int main()
{
	printf("char:\t%22d | %-22d(from header)\n", CHAR_MIN, CHAR_MAX);
	printf("char:\t%22ld | %-22ld(computed)\n", numericTypeMin(sizeof(char), true), numericTypeMax(sizeof(char), true));
	printf("long:\t%22ld | %-22ld(from header)\n", LONG_MIN, LONG_MAX);
	printf("long:\t%22ld | %-22ld(computed)\n", numericTypeMin(sizeof(long), true), numericTypeMax(sizeof(long), true));
	printf("int:\t%22d | %-22d(from header)\n", INT_MIN, INT_MAX);
	printf("int:\t%22ld | %-22ld(computed)\n", numericTypeMin(sizeof(int), true), numericTypeMax(sizeof(int), true));
	printf("double\t%22f | %-22f(from header)\n", FLT_MIN, FLT_MAX);

	printf("\n\
sizeof(char)\t%ld\n\
sizeof(long)\t%ld\n\
sizeof(int)\t%ld\n", sizeof(char), sizeof(long), sizeof(int));
	return 0;
}

long numericTypeMin(int bytes, BOOL isSigned)
{
	int size;
	if (isSigned) {
		size = pow(2, bytes * 8);
		if (size % 2 != 0) {
			return -((size / 2) + 1);
		} else {
			return -(size / 2);
		}
	} else {
		return 0;
	}
}

long numericTypeMax(int bytes, BOOL isSigned)
{
	int size;
	size = pow(2, bytes * 8);
	if (isSigned) {
		return (size / 2) - 1;
	} else {
		return size;
	}
}
