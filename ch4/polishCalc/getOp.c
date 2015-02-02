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

	//0-9
	if (isdigit(ch)) {
		storeNum(ch);
		chBuffer = NUMBER;
		return NUMBER;
	} else if (chBuffer == NUMBER){
		push(pullNum());
		chBuffer = EMPTY;

		//A-Z or a-z
		if (isalpha(ch)) {
			storeCommand(ch);
			return COMMAND;
		}
	}

	switch (ch) {
		//is whitespace
		case ' ':
		case '\t':
			return SKIP;
		//End of statement
		case EOF:
		case '\0':
		case ',':
			return EOF;
		default:
			return ch;
	}
}
