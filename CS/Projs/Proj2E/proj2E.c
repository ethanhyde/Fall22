#include <stdio.h>
#include <stdlib.h>


int SearchForWord(char *txt, int remaining, char *searchWord)
{
	FILE *h = fopen("file.txt", "r");
	if(!fopen)
		{
			printf("File does not exist\n");
		}
	char * contents = malloc(sizeof(int)* h);

}	

int main(int argc, char argv [])
{

	//Counts the number of argc, dynamically allocated
	int *argumentNum = malloc(sizeof(int) * argc);
	int num;	
	
	for(int count = 1; count < argc; ++count)
		{
			argumentNum[count] = count;
			num = count;
		}	

	SearchForWord(*argumentNum, num, *word);


return 0;
}
