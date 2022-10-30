#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char *s)

{	int count;
		
	for(int i = 0; s[i] != '\0'; ++i)
	{
		count = i;

	}

	return count;
}

void str_reverse(char *str)
{
    int length; 
    length = my_strlen(str);
    int k  = length;	
    int i = 0;
    char temp;
    while(i < k)
       {
	    temp = str[i];
	    str[i] = str[k];
	    str[k] = temp;

	    i++;
	    k--;

    }

}

int main()
{
    int len;
    
    char *str = malloc(strlen("hello world")+1);
    strcpy(str, "hello world");
    str_reverse(str);
    if (strcmp(str, "dlrow olleh") == 0)
    {
        printf("Congrats!  You have successfully reversed \"hello world\" to \"%s\"\n", str);
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Project does not work yet.  You reversed \"hello world\" to \"%s\"\n", str);
        exit(EXIT_FAILURE);
    }
}
