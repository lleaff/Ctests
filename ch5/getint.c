#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "getch.h"

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif


int getint(int *iptr)
{
	int ch, sign = 1;

	while ((ch = getch()) == ' ' || ch == '\t') //Skip whitespace
		;
	if (!isdigit(ch)) {
		if (ch == '-') {
			sign = -1;
		} else if (ch == '+') {
			sign = 1;
		} else if (ch != EOF) {
			return 0; //Not a number
		} else {
			return EOF;
		}
	} else {
		ungetch();
	}
	if (!isdigit(ch = getch())) { //Lone sign check
		return 0; //Not a number
	} else {
		ungetch();
	}
	*iptr = 0;
	while (isdigit(ch = getch())) {
		*iptr = (*iptr * 10) + (ch - '0');
	}
	*iptr *= sign;
	return 1; //Number written on *iptr
}

//Fill an array with values from stdin
int main()
{
#define MAXINTARRSIZE 100
	int integers[MAXINTARRSIZE];
	int i;
	int getintReturn;
	for (i = 0; i < MAXINTARRSIZE; i++) {
		getintReturn = getint(&integers[i]);
		if (getintReturn == EOF) {
			break;
		} else if (!getintReturn) {
			i--;
		}
	}

	int n;
	for (n = 0; n < i; n++) {
		printf("[%d]: %d\n", n, integers[n]);
	}

	return 0;
}

