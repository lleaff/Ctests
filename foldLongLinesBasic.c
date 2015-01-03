//Basic version, doesn't handle special cases and string literals

#include <stdio.h>

#define MAXLINESIZE 1000
#define TRUE 1
#define FALSE 0

int getLine(char line[]);
void insertChar(char line[], int position, char character);
int containsChar(char charArr[], char val);

int main()
{
	printf("Fold lines longer than...\n");
	int maxLineL = 20;
	//scanf("%d", &lines);

	char line[MAXLINESIZE];
	int i, iCurr;
	int lineLength;

	char openingBraces[] = "({[<";

	for (lineLength = getLine(line); lineLength != -1; lineLength = getLine(line)) {
		for (i = maxLineL, iCurr = lineLength; iCurr > maxLineL && i >= 0; i--) {
			if (containsChar(openingBraces, line[i]) || (line[i] == ' ' || line[i] == '\t')) {
				insertChar(line, i++, '\n');
				iCurr = lineLength - i;
				i += maxLineL;
			}
		}
		printf("%s\n", line);
	}

	return 0;
}

int getLine(char line[]) 
{
	int length = 0;
	int ch = getchar();
	if (ch == EOF) {
		return -1; //ERROR: EOF
	}
	while(ch != '\n' && ch != EOF) {
		line[length] = ch;
		ch = getchar();
		length++;
	} 
	line[length] = '\0';
	return length;
}

//Pushes values to the right of the inserted value
//Requires that the char array be long enough to accomodate the additional value
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

int containsChar(char charArr[], char val)
{
	int i;
	for (i = 0; charArr[i] != '\0'; i++) {
		if (charArr[i] == val) {
			return 1; //TRUE
		}
	}
	return 0; //FALSE
}
