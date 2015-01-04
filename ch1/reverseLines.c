#include <stdio.h>
#define MAXLINELENGTH 1000

int getLine(char line[], int lim);
int getStringLength(char arr[]);
void reverseLine(char orig[], char reversed[]);

int main()
{
  char line[MAXLINELENGTH], lineRev[MAXLINELENGTH];
  while(getLine(line, MAXLINELENGTH) >= 0) {
	reverseLine(line, lineRev);
	printf("%s\n", lineRev);
  }
}

int getLine(char *line, int lim)
{
  int length, ch;
  for (length = 0; length < lim; length++ ) {
	ch = getchar();
	if (!length && ch == EOF) {
	  return -1; //ERROR: EOF reached
	}
	switch(ch) {
	  case '\n':
	  case '\0':
	  case EOF:
		line[length] = '\0';
		return length;
	  default:
		line[length] = ch;
		break;
	}
  }
  line[length] = '\0';
  return -2; //ERROR: line too long
}

void reverseLine(char orig[], char reversed[]) 
{
  int length = getStringLength(orig);
  int ch, i;
  for (i = 0, ch = orig[i]; i <= length; i++) {
	reversed[i] = orig[length - i];
  }
  reversed[length + 1] = '\0';
  return;
}

int getStringLength(char arr[])
{
  int length, ch;
  for (length = 0, ch = arr[length]; ch != '\0' && ch != EOF; length++, ch = arr[length]) {
  }
  return length - 1;
}
