#include "getOp.h"
#include "buffer.h"
#include "valStack.h"
#include <ctype.h>
#include <stdio.h>

int charToDigit(char input)
{
	return input - '0';
}

#define EMPTY -2

char getOp(char input)
{
	char ch;
	static char chBuffer = EMPTY;
	if (chBuffer == EMPTY || chBuffer == NUMBER) {
		ch = input;
	} else {
		ch = chBuffer;
	}

	if (isdigit(ch)) {
		storeNum(ch);
		chBuffer = NUMBER;
		return NUMBER;
	} else if (chBuffer == NUMBER){
		push(pullNum());
		chBuffer = EMPTY;
	}
	switch (ch) {
		case ' ':
		case '\t':
		case ',':
			return SKIP;
		case EOF:
		case '\0':
			return EOF;
		default:
			return ch;
	}
}
