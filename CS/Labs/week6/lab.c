#include <stdio.h.>
#include <stdlib.h>
#include <string.h>

struct cat
{
  int age;
  char *name;
};

struct cat CreateCat(char name [], int age)
{
  struct cat *x;
  x = (struct cat *) malloc(sizeof (struct cat));

  x->name = name;
  x->age = age;

  printf("The name is %s\n", x->name);
  printf("The age is %d\n", x->age);


  return *x;

}

int main ()
{

  //Declairing struct variable
  struct cat t;

  t.age = 13;
  t.name = "Tiramisu";
  printf("%d\n", t.age);
  printf("%s\n", t.name);

  struct cat *k;

  k = (struct cat *) malloc(sizeof (struct cat));
  k->age = 12;
  k->name = (char*) malloc(strlen("Kita")+1);
  strcpy (k->name, "Kita");

  /* Print the student information. */
 
  printf("%s\n", k->name);
  printf("%d\n", k->age);

  //Cat creator function
  *k = CreateCat("Hannah", 3);
    

    return 0;
}

