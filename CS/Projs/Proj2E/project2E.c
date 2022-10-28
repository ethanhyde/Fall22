#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int counter = 0;
	char firstChar; //Holds first character of argv
	int wordSize = 0; //Strlen of the word from cmd line
	int result;      //Returned value of strcmp
	int move;        //For comparing file
	int occurs = 0;   //Returned from function

	//Opens file and ensures it exists
	FILE *h = fopen(argv[1], "r");
	if(!fopen)
		{
			printf("%s is not a valid file name\n", argv[1]);
			return 1;
		}
	
	//Searches file and copies contents 
	fseek(h, 0, SEEK_END);
	long max = ftell(h);
	char *contents = (char *) malloc(sizeof(char) * max);
	rewind(h);
	fread(contents, sizeof (char), max, h);
	contents[max - 1] = '\0';
	fclose(h);
	
	//For testing, prints contents of file
	for (int i = 0; i < max; ++i)
	{
		printf("%c", contents[i]);
	}
	
	//Dynamically allocates argc count
	int *count = (int *) malloc(sizeof (int) * argc);

	for(int z = 0; z < max; ++z)
	{
		if(contents[z-1] == ' ' || contents[z-1] == ',' ||
		contents[z-1] == '.' ||contents[z-1] == '\n')
		{
			contents[z-1] == '\0';
		}
	}
	
	//Searches for matches between argv and contents
	for(int i = 2; i < argc; ++i)
	{		
		count[i] = 0;
	
		//Search for input word
		for(int k = 0; k < max; ++k)
		{
			if(contents[k] == '\0')
			{
				//result = strcmp(argv[i], &(contents[k]));
					
				if(strcmp(&(contents[k]), argv[i]))
				{
					count[i]++;
				}

				printf("there are %d matches for %s\n", count[i], argv[i]);

			}	//	break;

		}

	}
		










/*
			if(contents[k] == argv[i][0])
			{
				count[i] += 1;
			}

			printf("counted %d\n", count[i]);
		}

	}

*/

	free(contents);
	return 0;
}








