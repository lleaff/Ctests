#include <stdio.h>

int main()
{
	return 0;
}

//Exercise: Don't use || or &&
#ifndef GETlINE_FUNC
#define GETlINE_FUNC
int getLine(char line[], int maxLineLength)
{
	int length = 0;
	int ch;
	for (; length < maxLineLength; length++) {
		ch = getchar();
		switch (ch) {
			case EOF:
				if (length == 0) {
					line[0] = '\0';
					return -1;
				}
			case '\n':
			case '\0':
				line[length] = '\0';
				return length;
			default:
				line[length] = ch;
				break;
		}
	}
	return -2; //ERROR line too long
}
#endif
