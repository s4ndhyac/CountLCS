#include <stdio.h>
#include <stdlib.h>
#include "CountLCS.c"
#include <math.h>
#define MAX_LENGTH 20
#define MAX_NUMBER 100 //Update after observing output

int main()
{
  //Read input n
  int n;
  char term;
  printf("Enter the value of n in range [3:20] ");
  if (scanf("%d%c", &n, &term) != 2 || term != '\n')
  {
    printf("Valid integer not entered\n");
    exit(0);
  }
  if (n < 3 || n > 20)
  {
    printf("Entered number is not in range\n");
    exit(0);
  }

  int max = pow(2, n) - 1;

  //Read input x
  int x;
  printf("Enter value of x in range [0:%d]: ", max);
  if (scanf("%d%c", &x, &term) != 2 || term != '\n')
  {
    printf("Valid integer not entered\n");
    exit(0);
  }
  if (x < 0 || x > max)
  {
    printf("Entered number is not in range\n");
    exit(0);
  }

  //Read input y
  int y;
  printf("Enter value of y in range [0:%d]: ", max);
  if (scanf("%d%c", &y, &term) != 2 || term != '\n')
  {
    printf("Valid integer not entered\n");
    exit(0);
  }
  if (y < 0 || y > max)
  {
    printf("Entered number is not in range\n");
    exit(0);
  }

  //Get binstring from n and x
  char *a = Binstring(n, x);

  //Get binstring from n and x
  char *b = Binstring(n, y);

  //Get LCS
  int i = 0;
  char **lcs = malloc(sizeof(char *) * MAX_NUMBER);
  if (!lcs)
  {
    printf("Error in allocating memory for LCS\n");
    exit(0);
  }
  for (i = 0; i < MAX_NUMBER; i++)
  {
    lcs[i] = malloc(MAX_LENGTH + 1);
    if (!lcs[i])
    {
      free(lcs);
      printf("Error in allocating memory for LCS\n");
      exit(0);
    }
  }

  int len = 0;
  int count = CountLCS(a, b, lcs, len);

  //output the results
  printf("STRINGLEN: %d\n", n);
  printf("X (%d) = %s\n", x, a);
  printf("Y (%d) = %s\n", y, b);
  printf("Length of LCS: %d\n", len);
  printf("No. of LCS: %d\n", count);

  int j = 0;
  for (j = 0; j < count; j++)
  {
    printf("LCS %d: %s\n", j, lcs[j]);
  }

  free(lcs);
  fflush(stdout);
}