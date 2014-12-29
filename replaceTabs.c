#include <stdio.h>

#define MAXLINELENGTH 1000

void replaceTabsStdin(int startOfLineTabs, int inlineTabs);

int main()
{
	replaceTabsStdin(4, 2);
}

void replaceTabsStdin(int startOfLineTabs, int inlineTabs)
{
	int ch = getchar();
	short startOfLine = 1;
	short i = 1;
	while(ch != EOF) {
		ch = getchar();
		if (ch == '\t') {
			if (startOfLine) {
				while(i <= startOfLineTabs) {
				putchar(' ');
				i++;
				}
			} else {
				while(i <= inlineTabs) {
					putchar(' ');
					i++;
				}
			}
		} else {
			putchar(ch);
			if(ch == '\n') {
				startOfLine = 1;
			} else {
				startOfLine = 0;
			}
			i = 1;
		}
	}
}
