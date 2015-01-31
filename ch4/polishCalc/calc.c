#include "calc.h"
#include "getOp.h"
#include "valStack.h"
#include <stdio.h>

double calc(char input[])
{
	char type;
	int i;
	double operand2;
	for (i = 0, type = getOp(input[i]); type != EOF; i++, getOp(input[i])) {
		switch(type) {
			case NUMBER:
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
			default:
				fprintf(stderr, "ERROR: No meaning assigned to: %c\n", type);
				break;
		}
		printf("DEBUG: calc() end-");//DEBUG
	}
	printf("DEBUG: pull()=%g", pull());//DEBUG
	return pull();
}