#include <stdio.h>
#include <stdlib.h>
#include "CountLCS.c"
#include <math.h>

int main()
{
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

  fflush(stdout);
}