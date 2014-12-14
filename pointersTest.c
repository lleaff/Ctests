#include <stdio.h>

int main() {
	char monkey = 'b';
	char *monk = NULL;

	monk = &monkey;

	printf("Yolo molo %08x it's %c\n", monk, *monk );

	return 0;
}
