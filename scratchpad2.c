#include <stdio.h>

#define MAXLINELENGTH 1000

char line[MAXLINELENGTH];
int i = 0;

int main()
{
	char word[MAXLINELENGTH];
	
}

static int getLine()
{
	extern char line[];
}

int getWord(char word[])
{
	extern int i;
	extern char line[];

	for(; line[i] != '\n'; i++) {
		
	}
	word[i] = '\0';
	--i;
	return i;
}
