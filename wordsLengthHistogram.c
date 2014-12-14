#include <stdio.h>

typedef enum {false = 0, true = 1} BOOL;

#define MAXWORDL 26 //max word length that fit in default console buffer

BOOL isSeparator(int var);
void printHorizontalHistogram(int values[], int start, int end, int maxVal);
void printVerticalHistogram(int values[], int start, int end);
void printArray(int array[], int start, int end);

int main() {
	//Scanning loop
	int ch;
	BOOL in = false;
	int wordL = 0;
	int wordsL[MAXWORDL] = { 0 }; //wordsL[0] is reserved to hold the value of the biggest word length
	int biggestFrequency = 0;
	while((ch = getchar()) != EOF)
	{
		if(isSeparator(ch) == true)
		{
			if(in == true)
			{
				if(wordL <= MAXWORDL) //To prevent index out of bound exception
				{
					wordsL[wordL]++;
					if (wordsL[wordL] > biggestFrequency)
					{
						biggestFrequency = wordsL[wordL];
					}
					if(wordL > wordsL[0])
					{
						wordsL[0] = wordL;
					}
				}
				wordL = 0;
				in = false;
			}
		}
		else
		{
			if(in == false)
			{
				in = true;
			}
			wordL++;
		}
	}

	//Print histogram
	//printVerticalHistogram(wordsL, 1, wordsL[0]);
	printHorizontalHistogram(wordsL, 1, wordsL[0], biggestFrequency);
}

BOOL isSeparator(int character) {
	switch(character) {
		case ' ':
		case ',':
		case '.':
		case ':':
		case ';':
		case '(':
		case ')':
		case '\t':
		case '\n':
		case '\0':
			return true;
		default:
			return false;
	}
}

void printHorizontalHistogram (int array[], int start, int end, int maxVal) {
	int i, j;
	//Print histogram
	for(i = maxVal + 1, j = start; i > 0; i--, j = start)
	{
		for(; j <= end; j++)
		{
			if(array[j] > 0 && i - array[j] - 1 == 0)
			{
				printf("%2d ", array[j]);
			}
			else if(i - array[j] <= 0)
			{
				printf("__ ");
			}
			else
			{
				printf("   ");
			}
		}
		printf("\n");
	}
	//Print number row
	for(j = start; j <= end; j++)
	{
		printf("%2d ", j);
	}
	printf("\n");
}

void printVerticalHistogram (int array[], int start, int end) {
	int i, j;
	for (i = start, j = array[i]; i <= end;i++, j = array[i])
	{
		printf("%2d ", i);
		for (; j > 0; j--)
		{
			printf("|");
		}
		if (array[i] > 0) {
			printf(" %d", array[i]);
		}
		printf("\n");
	}

}

void printArray(int array[], int start, int end) {
	int i;
	char separator[] = ", ";
	for (i = start; i <= end; i++)
	{
		if(i == end) 
		{
			*separator = *"\n";
		}
		printf("%d%s", array[i], separator);
	}
}
