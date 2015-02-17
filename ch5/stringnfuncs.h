#ifndef STRINGNFUNCS_H
#define STRINGNFUNCS_H
#include <string.h>

int String__strncat(void *str1, void *str2, int n);
#define strncat(str1, str2, n)	String__strncat(&(str1), &(str2), n)

#endif /* STRINGNFUNCS_H */
