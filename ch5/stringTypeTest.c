#include "stringType.h"
#include <stdio.h>

int main()
{
	String testStr = newString(50, NULL);
	char cStyleStr[] = "Yolo";
	printf("%d\n", strlen(testStr));
	printf("%d\n", strlen(cStyleStr));
}
