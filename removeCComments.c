#include <stdio.h>

#define MAXLINESIZE 1000
#define MAXINDENTSIZE 50
#define TRUE 1
#define FALSE 0

int getLine(char line[]);
int nextXChars(char line[], int index, int x, char chars[]);

int main()
{
	char line[MAXLINESIZE];
	int lineLength;

	int slashCommentOpened = FALSE;	// // comment
	int starCommentOpened  = FALSE;	// /* comment 
	int commentedOutLine   = FALSE; // Skip printing the line
	int blankLine          = TRUE; // Only whitespace line, safe to skip printing

	// Store the whitespace before printing it in case the line is commented out
	char whiteSpaceBuffer[MAXINDENTSIZE]; 

	int i;
	// Read the input line by line
	// Reset // comment on each new line
	for (lineLength = getLine(line); lineLength != -1; lineLength = getLine(line)) {
		// Read the line char by char
		for (i = 0; i < lineLength; i++) {
			if (slashCommentOpened) {
				break;
			} else if (!starCommentOpened && nextXChars(line, i, 2, "//") && (i == 0 || line[i - 1] != '*')) {
				// Third condition checks against "*//" special case where "*/" has precedence
				if (blankLine) {
					commentedOutLine = TRUE;
				}
				slashCommentOpened = TRUE;
			} else if (nextXChars(line, i, 2, "/*")) { 
				starCommentOpened = TRUE;
			} else if (nextXChars(line, i, 2, "*/")) {
				starCommentOpened = FALSE;
			} else if (!starCommentOpened && (i == 0 || !nextXChars(line, i - 1, 2, "*/"))) {
				if (blankLine && (line[i] == ' ' || line[i] == '\t')) {
					whiteSpaceBuffer[i] = line[i];
					whiteSpaceBuffer[i + 1] = '\0';
				} else {
				if (blankLine) {
					printf("%s", whiteSpaceBuffer);
					blankLine = FALSE;
				}
				printf("%c", line[i]);
				}
			}
		} 
		if (!commentedOutLine && !starCommentOpened) {
			printf("\n");
		}
		//Reset line-dependent variables
		slashCommentOpened = FALSE;
		commentedOutLine = FALSE;
		blankLine = TRUE;
		whiteSpaceBuffer[0] = '\0';
	}
}


int getLine(char line[])
{
	int length;
	int ch = getchar();
	if (ch == EOF) {
		return -1; //ERROR EOF
	}
	for (length = 0; ch != '\n' && ch != EOF; length++) {
		line[length] = ch;
		ch = getchar();
	}
	line[length] = '\0';
	return length;
}

int nextXChars(char line[], int index, int x, char chars[]) {
	int i;
	int equal = FALSE;
	for (i = x - 1; i >= 0; i--) {
		if (line[index + i] == chars[i]) {
			equal = TRUE;
		} else {
			equal = FALSE;
			break;
		}
	}
	return equal;
}
