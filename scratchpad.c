#include <stdio.h>

typedef enum { YES, NO, ERROR } ReturnCode;

typedef int integer;

int main()
{
	ReturnCode returnC = ERROR;

	integer uselessType = 10;

	char myString[] = "";

	printf("%d\n%d\n", uselessType, printf("%s", myString));

	return returnC;
}
