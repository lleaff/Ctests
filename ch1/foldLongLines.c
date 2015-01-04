//Advanced multiple pass version for C programs
//Not finished, will come back to it later when I have more knowledge of C

#include <stdio.h>

#define MAXLINESIZE 1000
#define TRUE 1
#define FALSE 0

int getLine(char line[]);
void insertChar(char line[], int position, char character);
int containsChar(char charArr[], char val);
int isSurroundedBy(char charArr[], int position, char surroundingChar);


int main()
{
	printf("Fold lines longer than...\n");
	int maxLineL = 20;
	//scanf("%d", &lines);

	char line[MAXLINESIZE];
	int i, iCurr;
	int lineLength;

	char openingBraces[] = "({[<";
	char closingBraces[] = ")}]>";

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

int isSurroundedBy(char charArr[], int position, char surroundingChar)
{
	int inside = FALSE, containsPosition = FALSE, escaped = FALSE;
	int i;
	for (i = 0; charArr[i] != EOF && charArr[i] != '\0'; i++) {
		if (!inside) {
			if (i == position) {
				return FALSE;
			} else if (charArr[i] == surroundingChar && !escaped) {
				inside = TRUE;
			}
		} else {
			if (i == position) {
				containsPosition = TRUE;
			} else if (charArr[i] == surroundingChar && !escaped) {
				if (containsPosition) {
					return TRUE;
				}
				inside = FALSE;
			}
		}
		if (charArr[i] == '\\') {
			escaped = TRUE;
		} else {
			escaped = FALSE;
		}
	}
	return FALSE;
}
