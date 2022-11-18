#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct person
{
    char *name;
    char *answer1;
    char *answer2;
    void (*favorite1)(char*);
    void(*favorite2)(char*);

};

//Prototypes
void favoriteFood(char *A)
{
   printf("Hello my favorite food is %s\n", A);
}
//void favoriteMovie(char*);
//void favoriteSong(char*);
void favoriteSport(char *A)
{
    printf("Hello, my favorite sport is %s\n", A);
}

void intro(struct person *A)
{
    printf("Hello, my name is %s\n", A->name);
    A->favorite1(A->answer1);
    A->favorite2(A->answer2);
}

int main()
{

    //Struct variable
    struct person *e = (struct person *)malloc(sizeof(struct person));
    struct person *d = (struct person *)malloc(sizeof(struct person));
    

    e->name = strdup("Ethan");
    d->name = strdup("Daniel");

    e->answer1 = strdup("pizza");
    d->answer1 = strdup("banana");

    e->answer2 = strdup("Soccer");
    d->answer2 = strdup("basketball");

    e->favorite1 = favoriteFood;
    d->favorite1 = favoriteFood;

    e->favorite2 = favoriteSport;
    d->favorite2 = favoriteSport;
    
    intro(d);
    intro(e);






    return 0;
}