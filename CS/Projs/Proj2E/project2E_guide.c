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
			printf("File does not exist\n");
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
	/*for (int i = 0; i < max; ++i)
	{
		printf("%c", contents[i]);
	}*/
	
	//Dynamically allocates argc count
	int *count = (int *) malloc(sizeof (int) * argc);

	for(int z = 0; z < max; ++z)
	{
		if(contents[z] == ' ' || contents[z] == ',' ||
		contents[z] == '.' ||contents[z] == '\n')
		{
			contents[z] = '\0'; //was contents[z] == '\0';
		}
	}
	
	/*//For testing, prints contents of file
	for (int i = 0; i < max; ++i)
	{
		printf("%c", contents[i]);
	}
	printf("\n");*/

	//Searches for matches between argv and contents
	for(int i = 2; i < argc; ++i)
	{		
		count[i] = 0;
		wordSize = strlen(argv[i]); //you forgot this
		
		//you need to store the previous k so you can get the next word
		int k_previous = 0;
		
		//Search for input word
		for(int k = 0; k < max; ++k)
		{
			if(contents[k] == '\0')
			{	
		//		printf("%s\n",&(contents[k_previous]));	
				//result = strncmp(argv[i], &(contents[k_previous]), wordSize);
				result = strcmp(argv[i], &(contents[k_previous]));
				//printf("%s %d\n",argv[i], result);	
				if(result == 0)
				{
					count[i] += 1;
//					printf("+1 here\n");	
				}
				k_previous = k + 1;	//+1to get to the start of next word 
			}
		}
		printf("The word \"%s\" occurs %d times.\n", argv[i], count[i]); //should be outside if otherwise only count once (like what you got before)
	}


	return 0;
}

