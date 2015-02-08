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

static int operandsC;

char getOp(char input)
{
	enum waitingType { Nothing, Command, Variable };
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
		if (wait == Variable) {
			setVar(ch);
			wait = Nothing;
			return VARIABLE;
		} else {
			if (!wait == Command) {
				resetCommand();
				wait = Command;
			}
			storeCommand(ch);
			return COMMAND;
		}
	} else {
		if (wait == Command) {
			execCmdReturn = execCommand(compareCommand());
			wait = Nothing;
			//If the command is a "calc command"
			if (execCmdReturn != REGCMD) {
				if (execCmdReturn == VARIABLE) {
					operandsC++;
					setVar(readCharInCommand(0));
				}
				return execCmdReturn;
			}
		}
		/*--- 0-9 ---*/
		if ((isdigit(ch) || ch == '.') && wait == Nothing) {
			storeNum(ch);
			chBuffer = NUMBER;
			return NUMBER;
		} else {
			if (chBuffer == NUMBER) { //Number complete, push it and increase operands counter
				operandsC++;
				push(pullNum());
				chBuffer = EMPTY;
			}
		}
	}

	if (ch == '>') {
		wait = Variable;
		return ASSIGNMENT;
	}

	switch (ch) {
		//Whitespace
		case ' ':
		case '\t':
			return SKIP;
		//End of statement
		case EOF:
		case '\0':
		case ',':
			operandsC = 0; //Reset all operand counters
			return EOF;
		//Should be an operator
		default: 
			return ch;
	}
}

int pullOC(void)
{
	int tmp = operandsC;
	operandsC = 0;
	return tmp;
}

void setOC(int num)
{
	operandsC = num;
}
