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
  
  q->name[q->back] = n;
  printf("Name is %s\n", q->name[q->back]);

  q->population++;
  q->back++;
  //printf("Front is %d, back is %d\n", q->front, q->back);
  

}

char *dequeue(char *n, Queue *q)
{
  char *rv = q->name[0];

  for (int i = 0; i < q->population-1; i++)
  {
    q->front = q->front + 1;
    q->population--;
  }
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

/*
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
      printf("%s\n", q->strings[index]);
    }
  }
}
*/


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

  for(int i = 0; i < 4; ++i)
  {
    //Initializes donors
    donors[i] = malloc(sizeof(Queue));
    initializeQueue(donors[i]);

    //Initializes recipients
    recipients[i] = malloc(sizeof(Queue));
    initializeQueue(recipients[i]);

    initializeQueue(surgeons);

  }

  while(getline(&buffer, &size, f) > 0)
  {
    printf("Buffer 0 is %c\n", buffer[0]);
    if(buffer[0] == 'S')
    {
      //type = 'S';
      name = strdup(buffer+2);
      //Looks for donors and matching recipient before enququeing suregon
      for(int i = 0; i < BLOOD_TYPES; i++)
      {
        if(donors[i]->population > 0 && recipients[i]->population > 0)
        {
          printf("ENQUEUE SUREGON\n");
          enqueue(name, surgeons);
          break;
          
        }
      }

    }

    else
    {
      sscanf(buffer, "%[^:]:%[^:]:%[^\n]\n", &type, blood, name);
    
      //Recipients
      if(type == 'R')
      {
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
        
        //If there are surgeons, look for match
        else
        {
          if(donors[0]->population > 0)
          {
             printf("MATCH: %s donates to %s via Dr. %s\n",*donors[0]->name,*recipients[0]->name,*surgeons->name);
            // dequeue(name, );
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
      }
      else
      {
        if(recipients[0]->population > 0)
        {
          //dequeue();
        }
      }

  
  }
    
      //printf("TYPE IS %c, BLOOD IS %s, NAME IS %s\n", type, blood, name);
      //printf("recipients are %s", recipients[0]->name);
    



  
  /***
    STEP #3: After your queue code works and after you can read the
             file, implement the prompt.
             Note: Here is the print statement to use for a match:

  printf(
      "MATCH: %s donates to %s via Dr. %s\n",
      donor,
      recipient,
      surgeon);

    You will need four queues for recipients, and four queus for
    donors, so using arrays seems sensible. Suggested declarations
    for these arrays are included below this comment.

  ***/

  /* Here is a suggested helper array for facilitating matching as
    described in the prompt. The blood types are listed from most
    rare to least rare. */
  /*
  char *types[BLOOD_TYPES] = {"AB", "B", "A", "O"};

  struct queue *donors[BLOOD_TYPES];
  struct queue *recipients[BLOOD_TYPES];
  struct queue *surgeons = malloc(sizeof *surgeons);
  */  


  /***
    STEP #4: After your matching code is done, add prettyPrintQueue
             calls for each of your recipient queues, your donor
             queues, and your surgeon queue. If you used the
             suggested "recipients" and "donors" arrays, and the
             "types" array, then you can use these print statements:

  for (int r = 0; r < BLOOD_TYPES; r++)
    prettyPrintQueue(recipients[r], "recipients", types[r]);
  for (int d = 0; d < BLOOD_TYPES; d++)
    prettyPrintQueue(donors[d], "donors", types[d]);
  prettyPrintQueue(surgeons, "surgeons", "type-agnostic");

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
 // free(surgeons);

  return EXIT_SUCCESS;
}


/* End. */
