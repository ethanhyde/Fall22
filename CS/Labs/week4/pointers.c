#include <stdio.h>
#include <stdlib.h>

int main()
{
	char x = 'A';
	char y = &A;
	
	printf("%c", x);
	free(y);
	printf("%p", y);

	x = 'B';






return 0;
}
