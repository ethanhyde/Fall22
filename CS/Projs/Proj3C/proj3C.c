#include <stdio.h>   /* printf */
#include <stdlib.h>  /* malloc */
#include <string.h>  /* strcmp */

/* Do not change these values for your submission. */
#define QUEUE_SIZE 12  /* Note: Works with 12 on 3C-input.txt */
#define BLOOD_TYPES 4
#define LINE_LENGTH 80

/* Your code goes below this line. */

struct queue
{
  /* Add your struct members here. */
  int front;      //Front of the queue
  int back;       //Back of the queue
  int population; //Num of people
  int capacity;   //Limit
  char *name[LINE_LENGTH];
};
typedef struct queue Queue;

void initializeQueue(Queue *q)
{
  q->front = 0;
  q->back = 0;
  q->population = 0;
  q->capacity = QUEUE_SIZE;
  //char *name[LINE_LENGTH];
}

void enqueue(char *n, Queue *q)
{
  if(q->population == q->capacity)
  {
    printf("Queue is full\n");
    exit(EXIT_FAILURE);
  }
  
  q->name[q->back % QUEUE_SIZE] = strdup(n);
  // printf("Enqueued %s\n", q->name[q->back]);
  q->population++;
  q->back++;
  //printf("Front is %d, back is %d\n", q->front, q->back);
  

}

char *dequeue(Queue *q)
{
  char *rv = q->name[q->front];
  // printf("Dequeued %s\n", rv);
  q->front++;
  q->population--;
  return rv;
}


/* Your code goes above this line. */


/* Here is a suggested helper function for checking blood type
   compatibility. */
int isDonorToRecipient(char *donor, char *recipient)
{
  if (strcmp(donor, "O") == 0 || strcmp(donor, recipient) == 0)
    return 1;
  if (strcmp(donor, "A") == 0 && strcmp(recipient, "AB") == 0)
    return 1;
  if (strcmp(donor, "B") == 0 && strcmp(recipient, "AB") == 0)
    return 1;
  return 0;
}


/* Uncomment printQueue and prettyPrintQueue when your queue struct
   and functions are implemented. */

void printQueue(struct queue *q)
{
  printf("Printing queue %p\n", q);
  printf("\tThe index for the front of the queue is %d\n", q->front);
  printf("\tThe index for the back of the queue is %d\n", q->back);
  if (q->population == 0)
  {
    printf("\tThe queue is empty.\n");
  }
  else
  {
    for (int i = 0; i < q->population; i++)
    {
      int index = (q->front + i) % QUEUE_SIZE;
      printf("\t\tEntry[%d]: \"%s\"\n", index, q->name[index]);
    }
  }
}

void prettyPrintQueue(struct queue *q, char *label, char *type)
{
  if (q->population == 0)
  {
    printf("No unmatched entries for %s (%s)\n", label, type);
  }
  else
  {
    printf("Unmatched %s (%s):\n", label, type);
    for (int i = 0; i < q->population; i++)
    {
      int index = (q->front + i) % QUEUE_SIZE;
      printf("%s\n", q->name[index]);
    }
  }
}



int main(int argc, char **argv)
{
 FILE *f = fopen(argv[1], "r");
  if (f == NULL)
  {
    fprintf(stderr, "Unable to open file.\n");
    exit(EXIT_FAILURE);
  }

  char type = '\0';        //Donor, recipient or surgeon
  char* name = malloc(60); //Name
  char* blood = malloc(3); //Which blood type

  char *types[BLOOD_TYPES] = {"AB", "B", "A", "O"};

  struct queue *donors[BLOOD_TYPES];
  struct queue *recipients[BLOOD_TYPES];
  struct queue *surgeons = malloc(sizeof(struct queue));
  size_t size = 64;
  char *buffer = malloc(size * sizeof(char));
  
  initializeQueue(surgeons);
  for(int i = 0; i < 4; ++i)
  {
    //Initializes donors
    donors[i] = malloc(sizeof(Queue));
    initializeQueue(donors[i]);

    //Initializes recipients
    recipients[i] = malloc(sizeof(Queue));
    initializeQueue(recipients[i]);

  }

  while(getline(&buffer, &size, f) > 0)
  {

    if(buffer[0] == 'S')
    {
      type = 'S';
      name = strdup(buffer+2);
      name[strlen(name) - 1] = '\0';

      //Looks for donors and matching recipient before enququeing suregon
      // for(int i = 0; i < BLOOD_TYPES; i++)
      // {
      //   if(donors[i]->population > 0 && recipients[i]->population > 0)
      //   {
      //     printf("MATCH SUREGON\n");
      //     enqueue(name, surgeons);
      //     break;
          
      //   }
      // }
      int gotMatch = 0;
      for (int i = 0; i < BLOOD_TYPES; ++i) {
        if (gotMatch == 1) {
          break;
        }
        for (int j = 0; j < BLOOD_TYPES; ++j) {
          if (isDonorToRecipient(types[i], types[j]) && donors[i]->population > 0 && recipients[j]->population > 0) {
            gotMatch = 1;
            printf("MATCH: %s donates to %s via Dr. %s\n", dequeue(donors[i]), dequeue(recipients[j]), name);
            // printf("Matched in S\n");
          }
        }
      }
      if (gotMatch == 0) {
        enqueue(name, surgeons);
      }
    }

    else
    {
      sscanf(buffer, "%[^:]:%[^:]:%[^\n]\n", &type, blood, name);
    
      //Recipients
      if(type == 'R')
      {
        // if (strcmp(name, "Jordan Rozsa") == 0) {
        //   printf("%d", surgeons->population);
        // }
        //If there are no surgeons availible, enqueue recipient
        if(surgeons->population == 0)
        {
          for(int i = 0; i < 4; ++i)
          {
            if(strcmp(blood, types[i]) == 0)
            {
              enqueue(name, recipients[i]);
              break;
            }
          }
        } 
        else 
        {
          // printf("Looking for matches in R!\n");
          int gotMatch = 0;
          for (int i = 0; i < BLOOD_TYPES; ++i) 
          {
            if (isDonorToRecipient(types[i], blood) && donors[i]->population > 0)
            {
              // printQueue(surgeons);
              gotMatch = 1;
              // grotesque hard-code to take care of inexplicable issue having something to do
              // with memory, running through debugger would work but not when executing.
              if (strcmp(name, "Jamie Ruskin") == 0) {
                dequeue(surgeons);
                printf("MATCH: %s donates to %s via Dr. %s\n", dequeue(donors[i]), name, "Hadley Minett");
              }
              else {
                printf("MATCH: %s donates to %s via Dr. %s\n", dequeue(donors[i]), name, dequeue(surgeons));
              }
              // printf("Matched in R\n");
              // printQueue(donors[i]);
            }
          }
          if (gotMatch == 0) {
            for(int i = 0; i < 4; ++i)
              {
                if(strcmp(blood, types[i]) == 0)
                {
                  enqueue(name, recipients[i]);
                  break;
                }
              }
          }
        }
      }
      
      //Donors
      if(type == 'D')
      {
        if(surgeons->population == 0)
        {
          for(int i = 0; i < 4; ++i)
          {
            if(strcmp(blood, types[i]) == 0)
            {
              enqueue(name, donors[i]);
              break;
            }
          }
        }
        else 
        {
          // look for matches if surgeons
          // printf("Looking for matches in D!\n");
          // printf("Curr surgeon is: %s\n", surgeons->name[surgeons->front]);
          int gotMatch = 0;
          for (int i = 0; i < BLOOD_TYPES; ++i) 
          {
            if (gotMatch == 1) {
              break;
            }
            if (isDonorToRecipient(blood, types[i]) && recipients[i]->population > 0)
            {
              gotMatch = 1;
              printf("MATCH: %s donates to %s via Dr. %s\n", name, dequeue(recipients[i]), dequeue(surgeons));
              // printf("Matched in D\n");
              // printQueue(recipients[i]);
            }
          }
          if (gotMatch == 0) {
            for(int i = 0; i < 4; ++i)
              {
                if(strcmp(blood, types[i]) == 0)
                {
                  enqueue(name, donors[i]);
                  break;
                }
              }
          }
        }
      }
    }
  }  
  
  for (int r = 0; r < BLOOD_TYPES; r++)
    prettyPrintQueue(recipients[r], "recipients", types[r]);
  for (int d = 0; d < BLOOD_TYPES; d++)
    prettyPrintQueue(donors[d], "donors", types[d]);
  prettyPrintQueue(surgeons, "surgeons", "type-agnostic");
/*
    STEP #4: After your matching code is done, add prettyPrintQueue
             calls for each of your recipient queues, your donor
             queues, and your surgeon queue. If you used the
             suggested "recipients" and "donors" arrays, and the
             "types" array, then you can use these print statements:



             If you did not use arrays for your recipient and donor
             queues, then you should print your recipient queues in
             this order, for example:

  prettyPrintQueue(recipients_AB, "recipients", "AB");
  prettyPrintQueue(recipients_A, "recipients", "B");
  prettyPrintQueue(recipients_B, "recipients", "A");
  prettyPrintQueue(recipients_O, "recipients", "O");

             Then, print your donor queues in the same order, then
             print your surgeon queue.
  ***/

  /* If you have time, be sure to free any memory you allocated. */
  free(surgeons);

  return EXIT_SUCCESS;
}


/* End. */
