#include "stringType.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MIN(val1, val2)	((val1 < val2 ? val1 : val2))

#define STRINGTYPEID 16.5541e59
const double String__StringTypeID_ref = STRINGTYPEID;

String newEmptyString(void);

String newString(int length, char *cStyleString)
{
	String myString;
	if (cStyleString == NULL) {
		if (length < 0) {
			fprintf(stderr, "ERROR: stringType:newString, ");
			return newEmptyString();
		}
		myString.Chars = malloc((sizeof(char) * length) + 1);
		myString.Length = 0;
		myString.LengthLimit = length;
	} else {
		int i;
		for (i = 0; cStyleString[i] != '\0'; i++)
			;
		myString.Length = i < length ? i : length;
		myString.LengthLimit = length < 0 ? length : i;
		myString.Chars = malloc((sizeof(char) * myString.LengthLimit) + 1);
		CopyString(myString, cStyleString);
	}
	myString.stringTypeID = String__StringTypeID_ref;
	return myString;
}

String newEmptyString(void)
{
	String emptyString = {
		.stringTypeID = String__StringTypeID_ref, .Chars = NULL, .Length = -1, .LengthLimit = -1 
	};
	return emptyString;
}

int isStringType(void *ptr)
{
	return (*(double *)ptr == String__StringTypeID_ref);
}

int String__strlength(void *ptr)
{
	if (isStringType(ptr)) { //Is "String" type
		return ((String*)ptr)->Length;
	} else { //Is C-style string
		char *str = (char *)(void **)ptr;
		int i;
		for (i = 0; *(str + i) != '\0'; i++)
			;
		return i;
	}
}

//Returns 0 if both strings are String types, 1 if the origin string is C-type string
int CopyString(String destination, void *origin)
{
	if (isStringType(origin)) {
		memcpy(destination.Chars, (*(String *)origin).Chars, destination.Length * sizeof(char));
		return 0;
	} else {
		strcpy(destination.Chars, (char *)origin);
		return 1;
	}
}

//Returns 0 if the two Strings perfectly match,
// -1 if the string partially match but have different lengths properties,
// index of first non-matching characters otherwise.
int compareStrings(String str1, String str2)
{
	int minLength = MIN(str1.Length, str2.Length);
	int i;
	for (i = 0; i < minLength;i++) {
		if (str1.Chars[i] == '\0') {
			if (str2.Chars[i] == '\0') {
				return 0; //Perfect match
			} else {
				return i; //Don't match
			}
		} else if (str2.Chars[i] == '\0') {
			return i; //Don't match
		} else if (str1.Chars[i] != str2.Chars[i]) {
			return i; //Don't match
		}
	}
	return 0 - (str1.Length != str2.Length);
}
