#include <stdio.h>

#define MAXSTOREDLINE 1000

int getLine(char line[]);
void copyCharArr(char from[], char to[]);

int lineL, lineLMax;
char line[MAXSTOREDLINE], lineMax[MAXSTOREDLINE];

int main() {
	extern int lineL, lineLMax;
	extern char line[MAXSTOREDLINE], lineMax[MAXSTOREDLINE];

	lineLMax = 0;
	//find longest line
	do
	{
		lineL = getLine(line);
		if (lineL > lineLMax)
		{
			lineLMax = lineL;
			copyCharArr(line, lineMax);
		}
	} while (lineL != -1);

	//print result
	printf("Longest line: %d characters.\n%s\n", lineLMax, lineMax);
	if(lineL > MAXSTOREDLINE)
		return 1; //ERROR: Can't print full line
	else
		return 0;
}

//get line length + output line to char array
int getLine() {
	extern int lineL, lineLMax;
	extern char line[MAXSTOREDLINE], lineMax[MAXSTOREDLINE];
	int ch;
	for (lineL = 0; (ch = getchar()) != '\n'; lineL++) 
	{
		if(ch == EOF)
			return -1;
		if (lineL <= MAXSTOREDLINE - 1)
			line[lineL] = ch;
	}
	line[lineL] = '\0';
	return lineL;
}

void copyCharArr(char from[], char to[]) {
	int i;
	for (i = 0;; i++) 
	{
		to[i] = from[i];
		if (from[i] == '\0')
			break;
	}
}
