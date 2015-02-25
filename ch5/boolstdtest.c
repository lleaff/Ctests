#include <stdio.h>
#include <stdbool.h>

#define BOOLTOSTR(myBool)	((myBool) ? "TRUE" : "FALSE")

typedef struct boolHouse {
	bool bool1:1; bool bool2:1; bool bool3:1;
} boolHouse;

typedef struct intHouse {
	int int1:1; int int2:1; int int3:1;
} intHouse;

int main()
{
	printf("sizeof(bool)=%d\n", (int)sizeof(bool));
	printf("sizeof(boolHouse)=%d\n", (int)sizeof(struct boolHouse));

	printf("\n==========================\n\n");

	boolHouse cabin = { .bool1 = true, .bool2 = false, .bool3 = 1 };
	printf("sizeof(cabin)=%d\n", (int)sizeof(cabin));
	printf("%s %s %s\n", BOOLTOSTR(cabin.bool1), BOOLTOSTR(cabin.bool2), BOOLTOSTR(cabin.bool3));

	printf("\n==========================\n\n");

	intHouse hut = { .int1 = true, .int2 = false, .int3 = 1 };
	printf("sizeof(hut)=%d\n", (int)sizeof(hut));
	printf("%s %s %s\n", BOOLTOSTR(hut.int1), BOOLTOSTR(hut.int2), BOOLTOSTR(hut.int3));

}
