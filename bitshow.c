#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 5000
#define BS (60 / 8)
#define PRINTCHARS 0

typedef int filedes;

/* ------------------------------------------------------------ */

void my_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void my_putnstr(char *str, int n)
{
	int i;

	i = 0;
	while (*str && i < n) {
		write(1, str++, 1);
		i++;
	}
}

void my_putnstr_escaped(char *str, int n)
{
	int i;
	int ni;
	char *si;

	i = 0;
	while (*str && i < n) {
		switch(*str) {
			case '\n':
				si = "\\n"; n = 2; break;
			case '\t':
				si = "\\t"; n = 2; break;
			case '\0':
				si = "\\0"; n = 2; break;
			default:
				si = str; n = 1; break;
		}
		write(1, si, n);
		str++;
		i++;
	}
}

void my_putchar(char c)
{
	write(1, &c, 1);
}

int simplegetint(char *str)
{
	int n;

	n = 0;
	while (*str)
		n = (n * 10) + *str++ - '0';
	return (n);
}

/* ------------------------------------------------------------ */

#define BITS 8

void putbits(char c)
{
	int n = BITS - 1;
	int b;
	while (n >= 0)
	{
		b = ((c >> n--) & 1);
		my_putchar(b + '0');
	}
}

void putbytes(void *buff, int bytes)
{
	int i = 0;
	while (i < bytes) {
		putbits(*(char*)buff);
		i++;
	}
}

#define USAGE "Usage: bitshow FILE\n"
#define PRINTFILENOTFOUND() { \
	my_putstr("File not found: \""); \
	my_putstr(filename); \
	my_putstr("\"\n"); \
}

int infer_bs()
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col / BITS);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		my_putstr(USAGE);
		return (1);
	}
	char *filename = *(argv + 1);
	char buff[BUFFSIZE];
	int bs = infer_bs();
	int readb;

	filedes f = open(filename, O_RDONLY);
	if (f == -1)
	{
		PRINTFILENOTFOUND();
		return (1);
	}
	while ((readb = read(f, buff, bs)))
	{

		putbytes(buff, readb);
		if (PRINTCHARS) {
			my_putstr("  |  ");
			my_putnstr_escaped(buff, readb);
		}
		my_putstr("\n");
	}

	putbits(15);

	return (0);
}
