#include "getch.h"
//For EOF
#include <stdio.h>
//For isdigit()
#include <ctype.h>
//For pow()
#include <math.h>

int charToInt(char ch)
{
	return ch - '0';
}

#define NOTNUM 0
#define ISNUM 1
int getdouble(double *dptr)
{
	int ch;
	int sign = 1;
	while ((ch = getch()) == ' ' || ch == '\t') //Skip whitespace
		;
	if (ch == '-' || ch == '+') {
		if (ch == '-') {
			sign = -1;
		}
		//Lone sign check
		if (!isdigit(ch = getch()) && ch != '.') {
			return NOTNUM; //Not a number
		} else {
			ungetch();
		}
	} else {
		if (ch == EOF) {
			return EOF;
		} else if (!isdigit(ch) && ch != '.') {
			return NOTNUM; //Not a number
		}
		ungetch();
	}
	*dptr = 0;
	int fractionPart = 0;
	ch = getch();
	while (isdigit(ch) || (!fractionPart && ch == '.')) {
		if (ch == '.') {
			fractionPart = 1;
		} else if (!fractionPart) {
			*dptr = (*dptr * 10) + charToInt(ch);
		} else {
			*dptr += charToInt(ch) * pow(10, -fractionPart++);
		}
		ch = getch();
	}
	*dptr *= sign;
	return ISNUM; //Number written to *dptr
}

int main()
{
#define MAXFLOATS 100
	double floats[MAXFLOATS];

	int i;
	int getdR;
	for (i = 0; i < MAXFLOATS; i++) {
		getdR = getdouble(&floats[i]);
		if (getdR == NOTNUM) {
			i--;
		} else if (getdR == EOF) {
			break;
		}
	}

	int n;
	for (n = 0; n < i; n++) {
		printf("[%d]: %g\n", n, floats[n]);
	}

	return 0;
}
