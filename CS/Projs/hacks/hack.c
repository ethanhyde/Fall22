#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//main function
int main(int argc, char *argv[])
{
	FILE *fin;
	int i, j, n;

	//open the input file
	fin = fopen(argv[1], "r");

//check if file not exist
	if(fin==NULL)
	{
		printf("File not open");
		return 1;
	}

	//dynamic memory allocation
	char *word = (char*)malloc(20);
	int *count = (int*)malloc(sizeof(int)*(argc-2));

	//initialization of count
	for(i=0; i<argc-2; i++)
		count[i] = 0;

	j = 0;
	while(fin)
	{
		//read a word from file
		fscanf(fin, "%s", word);

		//check of end of file
		if(feof(fin)) break;
		//increase the number of words
		j++;

		//length of string
		n = strlen(word);

		//remove comma, period or newline
		if(word[n-1]==',') word[n-1] = '\0';
		else if(word[n-1]=='.') word[n-1] = '\0';
		else if(word[n-1]=='\n') word[n-1] = '\0';

		//compare with the set of words
		for(i=0; i<argc-2;i++)
		{
		if(!strcmp(word, argv[i+2]))
			count[i]++;
		}
	}

	//print the number of words
	printf("Total number of words: %d\n", j);

	//print the frequency of number of words
	for(i=0; i<argc-2; i++)
	{
		printf("%s\t%d\n", argv[i+2], count[i]);
	}

//close the file
fclose(fin);

return 0;
}
