#include <stdio.h>
#include <stdarg.h>

void vaargfunc(int firstArg, ...)
{
	va_list ap;
	va_start(ap, firstArg);
	printf("*ap=%Lg\n", *(long double*)ap);
	printf("(%d)\n", *(long*)ap == 222);
	va_arg(ap, long double);
	printf("*ap=%Lg\n", *(long double*)ap);
	printf("(%d)\n", *(long*)ap == 123456);
	va_arg(ap, int);
	va_end(ap);
}

#define LASTARGID_LLD 2423197176542314001
static const long long LastArgId_LLD = LASTARGID_LLD;

int main()
{
	printf("%lld\n", LastArgId_LLD);
	vaargfunc(555, 222, 123456);
	return 0;
}
