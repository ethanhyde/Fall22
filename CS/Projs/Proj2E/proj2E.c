#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SearchForWord(char word)
{
	int counter = 0; //Value to be returned

	//Opens file and ensures it exists
	FILE *h = fopen("file.txt", "r");
	if(!fopen)
		{
			printf("File does not exist\n");
		}
	
	

	return count; 
}	

int main(int argc, char argv [])
{
	int count;
	
	for(int i = 0; i < argc; ++i)
		{
			//Sends each argc string into the function
			//Returns the count of how many times it occurred in file
			count = SearchForWord(argv[i]);
		}
	


return 0;
}
