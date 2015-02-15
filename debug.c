#include "debug.h"
#include <stdio.h>

void Debug__putcharLit(char myChar)
{
	switch (myChar) {
		case '\t':
			printf("\\t");
			break;
		case '\n':
			printf("\\n");
			break;
		case '\0':
			printf("\\0");
			break;
		case ' ':
			printf("_space_");
			break;
		default:
			putchar(myChar);
			break;
	}
}
