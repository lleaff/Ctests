#define DEBUG
#include "debug.h"

int main()
{
	int x = 5;
	char str[] = "Yo.";
	DEBUGP("%s %d\n", str, x);
	DEBUGPRINT("%d %s\n", x, str);
}
