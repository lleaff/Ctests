#include <stdio.h>

#define MAXSTOREDLINE 1000

int getLine(char line[]);
void copyCharArr(char from[], char to[]);

int main() {
	int lineL, lineLMax;
	char line[MAXSTOREDLINE];
	char lineMax[MAXSTOREDLINE];
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
	} while (lineL > 0);

	//print result
	printf("Longest line: %d characters.\n%s\n", lineLMax, lineMax);
	if(lineL > MAXSTOREDLINE)
		return 1; //ERROR: Can't print full line
	else
		return 0;
}

//get line length + output line to char array
int getLine(char line[]) {
	int ch, lineLength;
	for (lineLength = 0; (ch = getchar()) != '\n' && ch != EOF; lineLength++) 
	{
		if (lineLength <= MAXSTOREDLINE - 1)
			line[lineLength] = ch;
	}
	line[lineLength] = '\0';
	return lineLength;
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
