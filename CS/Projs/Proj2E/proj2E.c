#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv [])
{
	int counter = 0;
	//Opens file and ensures it exists
	FILE *h = fopen(argv[1], "r");
	if(!fopen)
		{
			printf("File does not exist\n");
			return 1;
		}
	
	//Searches file and copies contents 
	fseek(h, 0, SEEK_END);
	long max = ftell(h);
	char *contents = (char *) malloc(sizeof(char) * max);
	rewind(h);
	fread(contents, sizeof (char), max, h);
	fclose(h);

	for (int i = 0; i < max; ++i)
	{
		printf("%c", contents[i]);
	}

	int *count = (int *) malloc(sizeof (int) * argc);

	int result;
	for(int i = 2; i < argc; ++i)
		{
			
		}


	free(contents);
	return 0;
}
