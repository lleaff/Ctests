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
	return ((myChar >= 'A' && myChar <= 'Z') || (myChar >= 'a' && myChar <= 'z')\
			|| (myChar >= '0' && myChar <= '9') || myChar == '_');
}

int getWord(char word[], char* charBuffer)
{
	int wordLength = 0;
	BOOL WORDFOUND = FALSE;
	char ch;
	//Check past getWord buffer to see if it stopped at a singleCharWordDelimiter
	if (stringContainsChar(*charBuffer, wordDelimiters)) {
		//sprintf(word, "%c", *charBuffer); //<= why did I use that instead of just "word[0] = charBuffer" ?
		word[0] = *charBuffer;
		*charBuffer = '\0';
		wordLength = 1;
		WORDFOUND = TRUE;
	}
	BOOL escaped = (*charBuffer == '\\') ? TRUE : FALSE;
	//Loop through the next characters 
	ch = (*charBuffer == '\0') ? getchar() : *charBuffer;
	for (; !WORDFOUND && ch != EOF; ch = getchar(), wordLength++) {
		printf("\t\t\tDEBUG: ch=%c\n", ch);//DEBUG
		if (!escaped) {
			if (stringContainsChar(ch, wordDelimiters)) {
				printf("DEBUG: *charBuffer_%c_ = %c\n", *charBuffer, ch);//DEBUG
				WORDFOUND = TRUE;
			} else if (ch == ' ' || ch == '\t' || (ch > 0 && ch == '\0')) {
				WORDFOUND = TRUE;
			} else if (isValidIdentifierChar(ch) && (wordLength == 0 && (ch >= '0' && ch <= '9'))) {
				//is identifier
			} else if (ch == '\\') {
				escaped = TRUE;
			}
		}
		word[wordLength] = ch;
	}
	*charBuffer = ch;
	wordLength--;
	word[wordLength] = '\0'; //Close the string
	return wordLength;
}

//Return string length (not including terminator)
int stringAppend(char base[], int position, char appended[])
{
	int i;
	//find end of string if position > stringLength
	if (base[position] == '\0') {
		for (; base[position] == '\0'; position--);
	}
	position++;
	for (i = 0; appended[i] != '\0'; i++) {
		base[position + i] = appended[i];
	}
	return --i;
}

int stringToUppercase(char inputString[], char outputString[])
{
	int i;
	for (i = 0; inputString[i] != '\0'; i++) {
			outputString[i] = (inputString[i] >= 'a' && inputString[i] <= 'z') ? inputString[i] - 'a' + 'A' : inputString[i];
	}
	return i;
}

int symbolsToUnderscore(char inputString[], char outputString[])
{
	int i;
	for (i = 0; inputString[i] != '\0'; i++) {
		if ((inputString[i] >= 'a' && inputString[i] <= 'z') || \
					(inputString[i] >= 'A' && inputString[i] <= 'Z')) {
			outputString[i] = inputString[i];
		} else {
			outputString[i] = '_';
		}
	}
	return i;
}

int getStatement(char statement[], int wordsStart[])
{
	char charBuffer = '\0';
	char word[MAXWORDLENGTH];
	int wordCount = 0; 
	//^ Different "word" meaning as words counted in wordsStart[], doesn't count syntax chars/words
	int i;
	for (i = 0; stringCompare(word, ";"); ) {
		wordsStart[i] = getWord(word, &charBuffer);
		printf("word=%s\n", word);//DEBUG
		stringAppend(statement, i, word);
		if (!stringContainsChar(word[0], " \t") && !stringContainsChar(word[0], wordDelimiters)) {
			wordCount++;
		}
		i += wordsStart[i];
	}
	statement[i + 1] = '\0';
	return wordCount;
}

int main()
{
	char programName[MAXWORDLENGTH] = "testProgram"; //TODO parse name from arguments
	char headerName[MAXWORDLENGTH];
	stringAppend(headerName, stringToUppercase(programName, headerName), "_H");
	//symbolsToUnderscore(headerName, headerName);
	

	char statement[MAXSTATEMENTLENGTH] /*= { 'X' }*/; //X to DEBUG, change to \0 otherwise
	int wordsStart[MAXSTATEMENTLENGTH] = { 0 }; 
	//^ A n > 0 value indicates that a word of length n is starting at this position
	
	printf("#ifndef %s\n#define %s\n", headerName, headerName); //Keep at top

	//DEBUG Tests begin
	int x;
	char chBuffer = '\0';
	char word[MAXWORDLENGTH];
	for (x = 0; x < 25; x++) {
		getWord(word, &chBuffer);
		printf("%02d. \"%s\",\n  charBuffer: \"%s%c\"\n", x, word, (charBuffer == '\0') ? "\\0" : "", charBuffer);
	}
	//DEBUG Tests end

	printf("#endif /* %s $/\n", headerName); //Keep at bottom
	return 0;
}
