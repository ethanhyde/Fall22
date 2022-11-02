#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int arr [5];
	int num;
	int * p = arr;
	int count;
	for(int i = 0; i < 5; ++i)
	{
		printf("enter num: ");
		scanf("%d", p);
		++p;
	}

	p = arr;
	
	printf("You entered: ");
	for(int z = 0; z < 5; ++z)
	{
		printf("%d ", *p);
		++p;
		count = z;
	}

	//Dynamically allocate 
	int *size = (int *) malloc(sizeof(int) * count);

	printf("SIZE OF ARRAY is %d\n", &size);

return 0;
}





