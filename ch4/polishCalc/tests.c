#include <stdio.h>
#include "buffer.c"
#include <math.h>

int main()
{
	printf("doubleIsNAN(NAN)=%s\ndoubleIsNAN(%g)=%s\n",
			doubleIsNAN(NAN) ? "TRUE" : "FALSE",
			32.0, doubleIsNAN(32.0) ? "TRUE" : "FALSE");
}
