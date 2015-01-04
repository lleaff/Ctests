#include <stdio.h>

int main()
{
	int lineC = 0;
	int ch;
	while ((ch = getchar()) != EOF)
	{
		if(ch == '\n')
		{
			lineC++;
		}
	}
	printf("%d\n", lineC);
}
