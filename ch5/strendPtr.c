#include <stdio.h>
#include "stringType.h"
#include <string.h>

//#define DEBUG
#include "../debug.h"

#undef strcmp
#define strcmp(...) strcmp_custom(__VA_ARGS__)
int strcmp_custom(char *str1, char *str2)
{
	int i;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
		DEBUGS(PUTCHARLIT(str1[i]); printf("\t"); PUTCHARLIT(str2[i]); printf("\n");)
		if (str1[i] != str2[i]) {
			return 1;
		}
	}
	if (str1[i] != str2[i]) {
		return 1;
	} else {
		return 0;
	}
}

int strendPtr(void *str1, void *str2)
{
	char *cstr1 = isStringType(str1) ? (char *)(((String *)str1)->Chars) : (char *)str1;
	char *cstr2 = isStringType(str2) ? (char *)(((String *)str2)->Chars) : (char *)str2;
	DEBUGP("%d %d\n", strlen(cstr1), strlen(str1));
	DEBUGS(char *ptr = (cstr1 + strlen(cstr1) /*- strlen(cstr2)*/));
	DEBUGP("[%c]>>>>%s<<<<\n", ptr[0], ptr);
	DEBUGP("[%c]>>%s<<\n", cstr2[0], cstr2);
	if (!strcmp((cstr1 + strlen(cstr1) - strlen(cstr2)), cstr2)) {
		return 1;
	} else {
		return 0;
	}
}

int main()
{
	String testStr1 = newString(50, "Beginning ... theEnd");
	printf("str1:\n%s\n", testStr1.Chars);
	String testStr2 = newString(-1, "theEnd");
	printf("str2:\n%s\n", testStr2.Chars);
	String testStr3 = newString(-1, "something else");
	printf("str3:\n%s\n", testStr3.Chars);
	printf("\n");

	printf("str2 at the end of str1? %s\n", (strendPtr(&testStr1, &testStr2)) ? "TRUE" : "FALSE");
	printf("str3 at the end of str1? %s\n", (strendPtr(&testStr1, &testStr3)) ? "TRUE" : "FALSE");

	return 0;
}
