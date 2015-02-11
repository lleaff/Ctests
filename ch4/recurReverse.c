#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Generic swap function
void swap(void *ptr1, int size1, void *ptr2, int size2)
{
	int smallerSize = size1 > size2 ? size2 : size1;
	void *tmp = malloc(smallerSize);
	memcpy(tmp, ptr2, smallerSize);
	memcpy(ptr2, ptr1, smallerSize);
	memcpy(ptr1, tmp, smallerSize);
	free(tmp);
	return;
}

//Not really recursive but whatever, truely recursive solutions suck
void reverseString(char myString[])
{
	char *start = myString;
	char *end = &myString[(strlen(myString) - 1)];
	while (start < end) {
		swap(start, sizeof(char), end, sizeof(char));
		start++, end--;
	}
}

int main(int argc, char *argv[])
{
#define MAXSTRINGSIZE 1000
	char input[MAXSTRINGSIZE];

	if (argc == 1) {
		while (fgets(input, MAXSTRINGSIZE, stdin) != NULL) {
			if (input[strlen(input) - 1] == '\n') { //Remove trailing newline
				input[strlen(input) - 1] = '\0';
			}
			reverseString(input);
			printf("%s\n", input);
		}
	} else {
		int i;
		for (i = 0; i < argc; i++) {
			reverseString(argv[i]);
			printf("%s\n", argv[i]);
		}
	}
	return 0;
}
