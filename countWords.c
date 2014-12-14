#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
	int wordsn = 0;
	int ch;
	int pos = OUT;
	while ((ch = getchar()) != EOF) {
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '.') {
			if (pos == IN) {
				wordsn++;
				pos = OUT;
			}
		}
		else {
			pos = IN;
		}
	}
	printf("%d", wordsn);
	return 0;
}
