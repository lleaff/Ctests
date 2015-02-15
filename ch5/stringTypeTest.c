#include "stringType.h"
#include <stdio.h>

int main()
{
	String testStr = newString(50, "YOYOYO");
	char cStyleStr[] = "Yolo";
	printf("String:\n%s\n", testStr.Chars);
	printf("len1=%d, .LengthLimit=%d\n", strlen(testStr), testStr.LengthLimit);
	printf("\nC-style:\n%s\n", cStyleStr);
	printf("len2=%d\n", strlen(cStyleStr));
}
