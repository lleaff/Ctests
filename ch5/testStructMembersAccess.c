#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phantomStruct { 
	char dummy1; char dummy2; char padding[sizeof(long double)-sizeof(char)*2]; int ext[]; 
} phantomStruct;

typedef struct doubleStruct { 
	char dummy1; char dummy2; char padding[sizeof(long double)-sizeof(char)*2]; double dbl;
} doubleStruct;

//Need to pad for the largest possible value type so phantomStruct and realStruct stay aligned

int main()
{
	phantomStruct yP = *(phantomStruct*)malloc(sizeof(phantomStruct) + sizeof(double));
	yP.dummy1 = 'X';
	printf("yP.dummy1=%c\n", yP.dummy1);

	double dbl = 5.555;
	memcpy(yP.ext, &dbl, sizeof(double));
	printf("memcpy(yP.ext, &dbl, sizeof(double));\n");
	printf("*(double*)(yP.ext)=%g\n", *(double*)(yP.ext));
	memcpy(&(yP.ext), &dbl, sizeof(double));
	printf("memcpy(&(yP.ext), &dbl, sizeof(double));\n");
	printf("*(double*)(yP.ext)=%g\n", *(double*)(yP.ext));

	doubleStruct y;
	memcpy(&y, &yP, sizeof(y));
	printf("y.dbl=%g\n", y.dbl);

}
