#include "calc.h"
#include "getOp.h"
#include "valStack.h"
#include <stdio.h>
#include <math.h>

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

double calc(char input[], BOOL *shouldPrintResult)
{
	char type;
	int i;
	double operand2;
	BOOL value = FALSE; //Whether the input modified or added a value in the stack
	for (i = 0, type = getOp(input[i]); type != EOF; i++, type = getOp(input[i])) {
		switch(type) {
			case NUMBER:
				value = TRUE;
			case COMMAND:
			case SKIP:
				break;
			case '+':
				push(pull() + pull());
				break;
			case '-':
				operand2 = pull();
				push(pull() - operand2);
				break;
			case '*':
				push(pull() * pull());
				break;
			case '/':
				operand2 = pull();
				push(pull() / operand2);
				break;
			case '%':
				operand2 = pull();
				push((int)pull() % (int)operand2);
			default:
				fprintf(stderr, "ERROR: No meaning assigned to: %c\n", type);
				break;
		}
	}
	
	if (shouldPrintResult != NULL) {
		*shouldPrintResult = value;
		if (!value) {
			return 0;
		}
	}

	return (readTopValue());
}
