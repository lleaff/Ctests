#include <stdio.h>

#define MAXLENGTH 1000
#define LONGERTHAN 30

int getLine();
int lineL;
char line[MAXLENGTH];

int main() {
	extern char line[];
	extern int lineL;
	while (getLine(line) != -1)
	{
		if (lineL > LONGERTHAN)
			printf("%s", line);
	}
}

int getLine()
{
	int ch;
	extern int lineL;
	for (lineL = 0; ch != '\n' && ch != EOF;lineL++)
	{
		ch = getchar();
		line[lineL] = ch;
	}
	line[lineL + 1] = '\0';
	if (ch == EOF)
		return -1;
	else
		return 0;
}
