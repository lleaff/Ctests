#include "outputHeaderFile.h"
#include "boolType.h"
#include <stdio.h>

char wordDelimiters[] = "\"'|()[]{}<>=+-/*";
char charBuffer;

BOOL stringContainsChar(char myChar, char myString[])
{
	int i;
	int ch;
	for (i = 0, ch = myString[i]; ch != '\0'; i++, ch = myString[i]) {
		if (ch == myChar) {
			return TRUE;
		}
	}
	return FALSE;
}

BOOL isValidIdentifierChar(char myChar)
{
	return ((myChar >= 'A' && myChar <= 'Z') || (myChar >= 'a' && myChar <= 'z') || (myChar >= '0' && myChar <= '9') || myChar == '_');
}

int getWord(char word[], char charBuffer)
{
	int wordLength = 0;
	BOOL WORDFOUND = FALSE;
	char ch;
	//Check past getWord buffer to see if it stopped at a singleCharWordDelimiter
	if (stringContainsChar(charBuffer, wordDelimiters)) {
		sprintf(word, "%c", charBuffer);
		charBuffer = '\0';
		wordLength = 1;
		WORDFOUND = TRUE;
	}
	BOOL escaped = (charBuffer == '\\') ? TRUE : FALSE;
	//Loop through the next characters 
	for (ch = charBuffer; !WORDFOUND && ch != EOF; ch = getchar(), wordLength++) {
		if (!escaped) {
			if (stringContainsChar(ch, wordDelimiters)) {
				charBuffer = ch;
				WORDFOUND = TRUE;
			} else if (ch == ' ' || ch == '\t' || ch == '\0') {
				charBuffer = '\0';
				WORDFOUND = TRUE;
			} else if (isValidIdentifierChar(ch) && !(wordLength == 0 && (ch >= '0' && ch <= '9'))) { // if is identifier
				
			} else if (ch == '\\') {
				escaped = TRUE;
			}
		}
		word[wordLength] = ch;
	}

	wordLength--;
	word[wordLength] = '\0'; //Close the string
	return wordLength;
}

int getStatement(char statement[])
{
	char charBuffer = '\0';
	char word[MAXWORDLENGTH];
	int wordCount = 0;

	return wordCount;
}

int main()
{


}
