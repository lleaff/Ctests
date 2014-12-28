#include <stdio.h>
#include <stdlib.h>

#define MAXARRSIZE	1000

void reverseString (char *input, char *output);
void printString (char arr[]);
int getStringLength (char arr[]);

int main()
{
	int ch, length = 0, loop = 1;
	char *arr = malloc(sizeof(*arr) * MAXARRSIZE);
	while(loop) {
		ch = getchar();
		switch(ch) {
			case '\n':
			case '\0':
			case EOF:
				loop = 0;
				break;
			default:
				*(arr + length++) = ch;
				break;
		}
	}
	*(arr + length) = '\0';


	printString(arr);
	char *arrRev = malloc(sizeof(*arr) * length);
	reverseString(arr, arrRev);
	printString(arrRev);
}

void reverseString (char *input, char *output)
{
	int arrL = getStringLength(input);
	int i;
	for (i = 0; i < arrL; i++) {
		output[arrL - 1 - i] = input[i];
	}
	output[arrL] = '\0';
}

void printString (char arr[]) {
	int arrL = getStringLength(arr);
	int i;
	for (i = 0; i < arrL; i++) {
		printf("%c",arr[i]);
	}
	printf("\n");
}

int getStringLength (char arr[]) {
	int length = 0;
	while(1) {
		switch(arr[length]) {
			case EOF:
			case '\0':
				return length;
			default:
				length++;
				break;
		}
	}
}
