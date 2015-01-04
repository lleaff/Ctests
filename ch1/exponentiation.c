#include <stdio.h>

int power(int var, int exponent);

int main() {
	int x, y;
	printf("x?\n>");
	scanf("%d", &x);
	printf("y?\n>");
	scanf("%d", &y);
	if (y < 0)
	{
		printf("ERROR: y can only be a positive integer");
		return 1;
	}
	printf("%d", power(x, y));
	return 0;
}

int power(int myVar, int exponent) {
	int result = myVar;
	for (; exponent > 1; exponent--) {
		result *= myVar;
	}
	return result;
}
