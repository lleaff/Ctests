#include "getOp.h"
#include "buffer.h"
#include "valStack.h"
#include "commands.h"
#include <ctype.h>
#include <stdio.h>

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

int charToDigit(char input)
{
	return input - '0';
}

#define EMPTY -2


char getOp(char input)
{
	enum waitingType { Nothing, Command };
	static enum waitingType wait = Nothing;
	static char chBuffer = EMPTY;
	char execCmdReturn;

	char ch;
	if (chBuffer == EMPTY || chBuffer == NUMBER) {
		ch = input;
	} else {
		ch = chBuffer;
	}

	/*--- A-Z or a-z ---*/
	if (isalpha(ch)) {
		if (!wait == Command) {
			resetCommand();
			wait = Command;
		}
		storeCommand(ch);
		return COMMAND;
	} else {
		if (wait == Command) {
			execCmdReturn = execCommand(compareCommand());
			wait = Nothing;
			//If the command is a "calc command"
			if (execCmdReturn != REGCMD) {
				return execCmdReturn;
			}
		}
		/*--- 0-9 ---*/
		if (isdigit(ch) && wait == Nothing) {
			storeNum(ch);
			chBuffer = NUMBER;
			return NUMBER;
		} else {
			if (chBuffer == NUMBER) {
				push(pullNum());
				chBuffer = EMPTY;
			}
		}
	}

	switch (ch) {
		//is whitespace
		case ' ':
		case '\t':
			return SKIP;
		//End of statement
		case EOF:
		case '\0':
		case ',':
			return EOF;
		default:
			return ch;
	}
}
