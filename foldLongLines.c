#include <stdio.h>

#define MAXLINESIZE 1000
#define TRUE 1
#define FALSE 0

int getLine(char line[]);
void insertChar(char line[], int position, char character);

int main()
{
	printf("Fold lines longer than... ");
	int maxLineL = 20;
	//scanf("%d", &lines);

	char line[MAXLINESIZE];
	int lineL = getLine(line);
	int i;
	int folded;

	for (folded = FALSE; lineL != EOF; folded = FALSE) {
		for(i = 0; folded == FALSE && i <= 0; i--) {
			if(lineL > maxLineL + i) {
				switch(line[maxLineL + i]) {
					case ' ':
					case '\t':
						line[maxLineL + i] = '\n';
						folded = TRUE;
						break;
					case '(':
						insertChar(line, maxLineL + i, '\n');
						folded = TRUE;
						break;
					default:
						break;
				}
			}
		}
		printf("%s", line);
	}

	return 0;
}

int getLine(char line[]) 
{
	int length = 0;
	int ch = getchar();
	if (ch == EOF) {
		return EOF;
	}
	while(ch != '\n' || ch != EOF) {
		line[length] = ch;
		ch = getchar();
		length++;

	} 
	line[length] = '\0';
	return length;
}

//Pushes values to the right of the inserted value
//Requires that the char array be long enough to accomodate the inserted value
void insertChar(char line[], int position, char character)
{
	int i;
	char ch, chBuffer;
	for(i = position, ch = chBuffer = line[i]; ch != '\0' && i < MAXLINESIZE; i++) {
		chBuffer = line[i];
		line[i] = ch;
		ch = chBuffer;
	}
	line[i] = ch;
	line[position] = character;
	return;
}
