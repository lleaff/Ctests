#include "main.h"
#include "calc.h"
#include <stdio.h>
#include <string.h>

#define MAXSTRINGSIZE 1000

typedef enum { FALSE, TRUE } BOOL;

BOOL exitcmd(char input[]);

//Simply forwards raw input to calc.c
int main(int argc, char **argv)
{
	if (argc == 1) {
		char input[MAXSTRINGSIZE];
		for (scanf("%s", input); !exitcmd(input); scanf("%s", input)) {
			printf("DEBUG: input=\"%s\"\n", input);//DEBUG
			printf("%g\n", calc(input));;
		}
	} else {
		int i;
		for (i = 1; i < argc; i++) {
			printf("%g%s", calc(argv[i]), (i == argc - 1) ? "" : "\n");
		}
	}
	return 0;
}

BOOL exitcmd(char input[])
{
	return !(strcmp(input, "q") && strcmp(input, "quit") && strcmp(input, "exit"));
}
