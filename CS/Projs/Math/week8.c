#include <stdio.h>
#include <string.h>

int main ()
{
    int num = 1;

    for(int i = 1; i < 10; ++i)
    {

        if(num % 2 == 0)
        {
            num = num / 2;
        }

        else
        {
            num = (3 * num) + 1;
        }

        printf("N = %d\t Num of steps is %d\n", i, num);
        
    }








    return 0; 
}