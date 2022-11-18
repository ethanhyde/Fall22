/* CS 212 Lab Leader Demonstration
 * File I/O
 *
 * Author: S. Isaac Geronimo Anderson (Fall 2022)
*/

#include <stdio.h>   /* fscanf fgets getline */
#include <stdlib.h>  /* malloc EXIT_SUCCESS EXIT_FAILURE */
#include <string.h>  /* strtok */

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    fprintf(stderr, "usage: %s inputFile\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *f = fopen(argv[1], "r");
  if (f == NULL)
  {
    fprintf(stderr, "%s: %s: cannot open file\n", argv[0], argv[1]);
    return EXIT_FAILURE;
  }


  /* Use fscanf to read, parse, and print the values from each line
     in parse-me.txt. */
  printf("File contents, using fscanf:\n");
  rewind(f);
  int matches = 0;
  float kdr = 0.0;
  char *name = malloc(80 * sizeof *name);

  int count;
  count = fscanf(f, "%d:%f:%s\n", &matches, &kdr, name);
  while (count == 3)
  {
    printf("matches: %d, kdr: %f, name: %s\n", matches, kdr, name);
    count = fscanf(f, "%d:%f:%s\n", &matches, &kdr, name);
  }


  /* Use fgets to read each line into a buffer, and print the
     buffer. */
  printf("File contents, using fgets:\n");
  rewind(f);
  char *line = malloc(80 * sizeof *line);
  line = fgets(line, 80, f);
  while (line != NULL)
  {
    printf("line: %s", line);
    line = fgets(line, 80, f);
  }


  /* Use getline to read each line into a buffer, and print the
     buffer. */
  printf("File contents, using getline:\n");
  rewind(f);
  size_t n = 80;
  while (getline(&line, &n, f) > -1)
  {
    printf("line: %s", line);
  }


  /* Use your getline loop from above, and add strtok to read and
     print each token from each line. */
  printf("File contents, using strtok:\n");
  rewind(f);
  while (getline(&line, &n, f) > -1)
  {
    char *token = strtok(line, ":");
    while (token != NULL)
    {
      printf("token: %s\n", token);
      token = strtok(NULL, ":");
    }
  }


  /* Clean up. */

  return EXIT_SUCCESS;
}
