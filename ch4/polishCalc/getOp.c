#include "getOp.h"
#include "buffer.h"
#include "valStack.h"
#include <ctype.h>
#include <stdio.h>

int charToDigit(char input)
{
	return input - '0';
}

char getOp(char input)
{
	char ch;
	if ((ch = pullChar()) == EMPTY) {
		ch = input;
	} else {
		pushChar(input);
	}

	if (isdigit(input)) {
		storeNum(charToDigit(input));
		pushChar(NUMBER);
		return NUMBER;
	} else {
		push(pullNum());
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
