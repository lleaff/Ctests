#include "outputHeaderFile.h"
#include "boolType.h"
#include "ch3/stringCompare.h"
#include <stdio.h>

char wordDelimiters[] = "\"'|()[]{}<>=+-/*;";
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
			} else if (isValidIdentifierChar(ch) && !(wordLength == 0 && (ch >= '0' && ch <= '9'))) {
				//is identifier
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

//Return string length (not including terminator)
int stringAppend(char base[], int position, char appended[])
{
	int i;
	for (i = 0; appended[i] != '\0' && base[i] != '\0'; i++) {
		base[position + i] = appended[i];
	}
	return --i;
}

int getStatement(char statement[], int wordsStart[])
{
	char charBuffer = '\0';
	char word[MAXWORDLENGTH];
	int wordCount = 0; //Different "word" meaning as words counted in wordsStart[], doesn't count syntax chars/words
	int i;
	for (i = 0; !stringCompare(word, ";"); ) {
		i += wordsStart[i] = getWord(word, charBuffer);
		stringAppend(statement, i, word);
		if (!stringContainsChar(word[0], " \t") && !stringContainsChar(word[0], wordDelimiters)) {
			wordCount++;
		}
	}
	return wordCount;
}

int main()
{
	char statement[MAXSTATEMENTLENGTH] = { 'X' }; //X to DEBUG, change to \0 otherwise
	int wordsStart[MAXSTATEMENTLENGTH] = { 0 }; // n > 0 value indicates that a word of length n is starting at this position
}
