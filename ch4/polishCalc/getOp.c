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
	if ((ch = pullChar()) == EMPTY || ch == NUMBER) {
		ch = input;
		printf("\t\t\tpullChar()\n");//DEBUG
	} else {
		pushChar(input);
		printf("\t\t\tpushChar(%c)\n", input);//DEBUG
	}
	printf("--ch=%c input=%c", ch, input);//DEBUG

	if (isdigit(ch)) {
		storeNum(charToDigit(ch));
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
