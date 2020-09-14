#include <stdio.h>

int i = 12345;
char *formato = "i=%d\n";

int main()
{
	printf(formato, i);
	return 0;
}
