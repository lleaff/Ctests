#include "calc.h"
#include "getOp.h"
#include "valStack.h"
#include <stdio.h>
#include <math.h>

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum { FALSE, TRUE } BOOL;
#endif /* BOOL_TYPE */

double add(double val1, double val2)
{
	return val1 + val2;
}

double calc(char input[], BOOL *shouldPrintResult)
{
	char type;
	int i;
	int oC, oCCurr; //Number of operations
#define MAXOPERANDSC 50
	double operandBuffer[MAXOPERANDSC];
	double operand2;
	BOOL value = FALSE; //Whether the input modified or added a value in the stack
	BOOL assignment = FALSE; //Whether the variable to follow is used in an assignment
	for (i = 0, type = getOp(input[i]); type != EOF; i++, type = getOp(input[i])) {
		switch(type) {
			case NUMBER:
				value = TRUE;
			case COMMAND:
			case SKIP:
				break;
			case '+':
				oC = pullOC();
				for (oCCurr = oC; oCCurr > 0; oCCurr--) {
					operandBuffer[oCCurr] = pull();
				}
				for (oCCurr = 1; oCCurr < oC; oCCurr++) {
					operandBuffer[oCCurr + 1] = add(operandBuffer[oCCurr], operandBuffer[oCCurr + 1]);
				}
				push(operandBuffer[oCCurr]);
				setOC(pullOC() + 1);
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
				break;
			case SIN:
				push(sin(pull()));
				break;
			case EXP:
				push(exp(pull()));
				break;
			case POW:
				operand2 = pull();
				push(pow(pull(), operand2));
				break;
			case ASSIGNMENT:
				assignment = TRUE;
				break;
			case VARIABLE:
				if (assignment) {
					value = FALSE;
					pushVar(pull());
				} else {
					if (isVarInit()) {
						value = TRUE;
						push(readVar());
					} else {
						fprintf(stderr, "ERROR: Variable unnassigned\n");
					}
				}
				break;
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
