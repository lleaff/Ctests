#include <stdio.h>

#define BRICK '#'
#define DOOR ':'

int main() {
	int height, width;
	printf("Pyramid base length?\n>");
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
			if (x >= y + 1 && x <= width - y)
			{
				if (((width >= 8) && (y <= 1)) && (x == width / 2 || x == width / 2 + 1))
					printf("%c", DOOR);
				else
					printf("%c", BRICK);
			}
			else 
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
