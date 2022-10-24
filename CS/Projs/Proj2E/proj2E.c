#include <stdio.h>
#include <stdlib.h>

void openFile(int argSize)
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
	//char *name = malloc(2*sizeof(char));	
	//*name

//Counts the number of argc, dynamically allocated
	int *argumentNum = malloc(sizeof(int) * argc);
	int num;	
	
	for(int count = 1; count < argc; ++count)
		{
			argumentNum[count] = count;
		//printf("%d\n", i);
			num = count;
		}	
	//Calling function to open and read file
	openFile(num);




return 0;
}
