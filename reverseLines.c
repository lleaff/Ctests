#include <stdio.h>

#define MAXLINELENGTH 1000

int getLine(char line[]);
void reverseLine(char line[], char reversedLine[]);

int main() {
	char line[MAXLINELENGTH], reversed[MAXLINELENGTH];
	int lineL;
	while ((lineL = getLine(line)) > 0)
	{
		reverseLine(line, reversed);
		printf("%s", reversed);
	}
}

int getLine(char line[]) {
	int ch;
	int i = 0;
	while ((ch = getchar()) != EOF && ch != '\n') {
		line[i] = ch;
		i++;
	}
	return i;
}

void reverseLine(char line[], char reversed[]) {
	char ch;
	for(;ch != '\n' && ch != EOF && ch != '\')
}
