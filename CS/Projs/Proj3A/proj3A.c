
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20000

typedef struct
{
    char **keys;
    int currIndex;
    float *values;
    
} ArrayDictionary;

void Initialize(ArrayDictionary *ad)
{
   ad->values = malloc(MAX_SIZE * sizeof(float));
   ad->keys = malloc(MAX_SIZE * sizeof(char *));
   ad->currIndex = 0;

}

void Store(ArrayDictionary *ad, char *key, float value)
{
    if(ad->currIndex >= MAX_SIZE)
    {
        exit(EXIT_FAILURE);
    }
   ad->keys[ad->currIndex] = key;
   ad->values[ad->currIndex] = value;
   ad->currIndex++;
}

float Fetch(ArrayDictionary *ad, char *key)
{
    for(int i = 0; i < ad->currIndex; ++i)
    {
        if(strcmp(ad->keys[i], key) == 0)
        {
            return ad->values[i];
        }
    }
   return 0.;
}


int main()
{
    FILE *f = fopen("DJIA", "r");
    if (f == NULL)
    {
         fprintf(stderr, "Unable to open file \"DJIA\" ... did you copy it to the current directory?\n");
         exit(EXIT_FAILURE);
    }
    ArrayDictionary ad;
    Initialize(&ad);

    size_t size = 1024;
    char *buffer = malloc(size*sizeof(char));
    char *date = malloc(80);

    while (getline(&buffer, &size, f) > 0)
    {
        printf("The line is \"%s\"\n", buffer);
        char *str;
        float closePrice;
        float other1;
        float other2;
        float other3;

        sscanf(buffer, "%s %f %f %f %f", date, &other1, &other2, &other3, &closePrice);
 
        str = strdup(date);
       
         
        Store(&ad, str, closePrice);
    }

    char dates[91][10] = {
                 "02/19/21", "02/19/20", "12/19/19", "12/12/19", "12/02/19", "11/22/19", "11/12/19", "10/22/19", "10/02/19", 
                 "09/12/19", "08/22/19", "08/12/19", "08/02/19", "07/22/19", "07/12/19", "07/02/19", "06/12/19", "05/22/19", 
                 "05/02/19", "04/22/19", "04/12/19", "04/02/19", "03/22/19", "03/12/19", "02/22/19", "02/19/19", "02/12/19", 
                 "01/22/19", "01/02/19", "12/19/18", "12/19/17", "12/19/16", "02/19/16", "02/19/15", "12/19/14", "02/19/14", 
                 "12/19/13", "02/19/13", "12/19/12", "12/19/11", "02/19/10", "02/19/09", "12/19/08", "02/19/08", "12/19/07", 
                 "12/19/06", "12/19/05", "02/19/04", "12/19/03", "02/19/03", "12/19/02", "02/19/02", "12/19/01", "12/19/00", 
                 "02/19/99", "02/19/98", "12/19/97", "02/19/97", "12/19/96", "12/19/95", "12/19/94", "02/19/93", "02/19/92", 
                 "12/19/91", "02/19/91", "12/19/90", "12/19/89", "12/19/88", "02/19/88", "02/19/87", "12/19/86", "02/19/86", 
                 "12/19/85", "02/19/85", "12/19/84", "12/19/83", "02/19/82", "02/19/81", "12/19/80", "02/19/80", "12/19/79", 
                 "12/19/78", "12/19/77", "02/19/76", "12/19/75", "02/19/75", "12/19/74", "02/19/74", "12/19/73", "12/19/72", 
                 "02/19/71"
           };

    float sum = 0; //Sum for final answer 
    
    for (int i = 0 ; i < 91 ; i++)
    {
        // You will need to repeat the code from the last while loop to get the data as a "char *"
  
        float val = Fetch(&ad, dates[i]);
        if (val == 0.)
        {
            printf("Bad fetch!\n");
            exit(EXIT_FAILURE);
        }
        sum = sum + val;
    }
        
    // Uncomment this.  Not it assumes you called your sum variable "sum"
    printf("Over the 91 days, the average value was %d\n", (int)(sum/91.0));
    // It should print:
    //    Over the 91 days, the average value was 13209
}
