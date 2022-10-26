#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv [])
{
	int counter = 0;
	char firstChar; //Holds first character of argv

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
	
	//For testing, prints contents of file
	for (int i = 0; i < max; ++i)
	{
		printf("%c", contents[i]);
	}
	
	//Dynamically allocates argc count
	int *count = (int *) malloc(sizeof (int) * argc);
	int wordSize = 0; //Strlen of the word from cmd line
	int result;      //Returned value of strcmp
	//Searches for matches between argv and contents
	for(int i = 2; i < argc; ++i)
	{					
		firstChar = argv[i][0];
		wordSize = strlen(argv[i]);
		
		printf("the first char is %c\n", firstChar);
		
		for(int j = 0; j < max; ++j)
		{
			result = strcmp(argv[i][0], contents[j], wordSize);	

			if(result == 0);
			{
				printf("MATCH\n");
			}
		}
	}



	free(contents);
	return 0;
}
