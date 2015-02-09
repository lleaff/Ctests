#include "main.h"
#include "calc.h"
#include <stdio.h>
#include <string.h>

#define MAXSTRINGSIZE 1000

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

BOOL getUserInput(char *input);
BOOL exitcmd(char input[]);

//Simply forwards raw input to calc.c
int main(int argc, char **argv)
{
	if (argc == 1) {
		// Interactive mode
		printf("=========-Polish Calculator-=========\n\
Input operations in \"Polish notation\"\n\
   (eg. 4 6 + => 10, 8 2 / 3 * => 12)\n\
You can assign one-letter variables\n\
   (eg. 6 1 + > x, x 2 * => 14)\n\
=====================================\n");
		char input[MAXSTRINGSIZE];
		double result;
		BOOL isThereInput = TRUE;
		BOOL shouldPrintResult = FALSE;
		for (printf("  "), isThereInput = getUserInput(input); !exitcmd(input) && isThereInput; printf("  ")) {
			result = calc(input, &shouldPrintResult);
			if (shouldPrintResult) {
				printf("> %g\n", result);
			}
			isThereInput = getUserInput(input);
		}
	} else {
		// Argument processing mode
		int i;
		for (i = 1; i < argc; i++) {
			printf("%g%s", calc(argv[i], NULL), (i == argc - 1) ? "" : "\n");
		}
	}
	return 0;
}

BOOL getUserInput(char *input)
{
	if (fgets(input, MAXSTRINGSIZE, stdin) == NULL) {
		return FALSE;
	}
	//Remove trailing newline
	if (input[strlen(input) - 1] == '\n') {
		input[strlen(input) - 1] = '\0';
	}
	return TRUE;
}

BOOL exitcmd(char input[])
{
	return !(strcmp(input, "q") && strcmp(input, "quit") && strcmp(input, "exit")) 
		|| (input[0] == EOF);
}
