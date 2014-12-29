#include <stdio.h>

void indentSpacesToTabsStdin(int spaces);

int main()
{
	indentSpacesToTabsStdin(4);
}

void indentSpacesToTabsStdin(int spaces)
{
	short lineStart = 1, currSpaces = 0;
	int ch;
	for(ch = getchar(); ch != EOF; ch = getchar()) {
		if(ch == ' ' && lineStart) {
			currSpaces++;
			if(currSpaces == spaces) {
				currSpaces = 0;
				putchar('\t');
			}
		} else {
			if(ch == '\n' && !(lineStart && ch == '\t')) {
				lineStart = 1;
			} else {
				lineStart = 0;
			}
			while(currSpaces) {
			putchar(' ');
			currSpaces--;
			}
			putchar(ch);
		}
	}
}
