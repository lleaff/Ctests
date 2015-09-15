#include <stdio.h>
#include <limits.h>

int main() {
	int i = 0;
	const int maxInt = INT_MAX;

	for (i = 0; i <= maxInt; ++i) {
		printf("%d\n", i);
		if (i == maxInt) {
			i = 0;
		}
	}

	return 0;
}
