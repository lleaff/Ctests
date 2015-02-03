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
		char input[MAXSTRINGSIZE];
		double result;
		BOOL shouldPrintResult = FALSE;
		for (getUserInput(input); !exitcmd(input); getUserInput(input)) {
			result = calc(input, &shouldPrintResult);
			if (shouldPrintResult) {
				printf("%g\n", result);
			}
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
