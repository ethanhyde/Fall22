#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char *s = "x=3=3.14";

    char item1;
    char item2;
    char item3;

    char *token = strtok(s, "=");

    while(token != NULL)
    {
        token = strtok(NULL, "=");
    }
  
    sscanf("%c %c %c", &item1, &item2, &item3);








    return 0;
}