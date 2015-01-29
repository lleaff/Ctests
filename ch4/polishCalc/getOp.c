#include "getOp.h"
#include "buffer.h"
#include <ctype.h>
#include <stdio.h>

int charToDigit(char input)
{
	return input - '0';
}

char getOp(char input)
{
	int i = 0;
	switch (input) {
		case ' ':
		case '\t':
		case ',':
			return SKIP;
		case EOF:
		case '\0':
			return EOF;
	}
	if (isdigit(input)) {
		storeNum(charToDigit(input));
		return NUMBER;
	} else if ()
}
