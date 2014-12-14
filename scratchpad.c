#include <stdio.h>

typedef enum {out, in} inout;

int main() {
	inout location = out;
	printf("%d char: %c\n", location, location);
	inout locc = in;
	printf("%d char: %c\n", locc, locc);
}
