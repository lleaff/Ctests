#include "getch.h"
#include <stdio.h>

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif


static char buffer;
static BOOL empty = TRUE;
static char lastCh = '\0';

char charBuffer(int push)
{
	if (push >= 0) { // getch mode
		if (empty) {
			lastCh = getchar();
			return lastCh;
		} else {
			empty = FALSE;
			lastCh = buffer;
			return lastCh;
		}
	} else { // ungetch mode
		if (empty) {
			buffer = lastCh;
			return '0';
		} else {
			fprintf(stderr, "ERROR: buffer full (%c), can't push back: %c\n", buffer, lastCh);
			return '\0';
		}
	}
}

void ungetch(void)
{
	charBuffer(-1);
}

char getch(void)
{
	return charBuffer(1);
}

void resetGetchBuffer(void)
{
	empty = TRUE;
	lastCh = '\0';
}
