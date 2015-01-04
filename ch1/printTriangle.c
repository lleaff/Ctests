#include <stdio.h>

#define BRICK ':'

int main() {
	int height, width;
	printf("Triangle base length?\n>");
	scanf("%d", &width);
	height = (width / 2);
	if(width % 2 != 0)
		height++;

	int x, y;
	printf("\n");
	for (y = height - 1, x = 1; y >= 0; y--, x = 1)
	{
		for (; x <= width; x++)
		{
			if (y == 0 || x == y + 1 || x == width - y)
				printf("%c", BRICK);
			else 
				printf(" ");
		}
		printf("\n");
	}
}
