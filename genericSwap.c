#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *vpt1, void *vpt2, int size)
{
	void *tmp = malloc(size);
	memcpy(tmp, vpt1, size);
	memcpy(vpt1, vpt2, size);
	memcpy(vpt2, tmp, size);
}

int main()
{
	printf("\n\
Generic swap function\n\
---------------------\n");

	char x = 'x';
	char y = 'y';
	printf("x: %-3c y: %-3c\n", x, y);
	swap(&y, &x, sizeof(char));
	printf("...swap...\n");
	printf("x: %-3c y: %-3c\n", x, y);
	if(x == 'y' && y == 'x') {
		return 0; //SUCCESS
	} else {
		return 1;
	}
}
