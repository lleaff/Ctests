#include <stdio.h>

int power(int var, int exponent);

int main() {
	int x, y;
	printf("x?\n>");
	scanf("%d", &x);
	printf("y?\n>");
	scanf("%d", &y);
	printf("%d", power(x, y));
}

int power(int myVar, int exponent) {
	int result = myVar;
	for (; exponent > 1; exponent--) {
		result *= myVar;
	}
	return result;
}
