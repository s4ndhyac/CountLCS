#include <stdio.h>
#include <stdlib.h>
#include "CountLCS.c"
#include <math.h>

int main()
{
  int n;
  printf("Enter the value of n in range [3:20] ");
  scanf("%d", &n);
  if (n < 3 || n > 20)
  {
    printf("Entered number is not in range\n");
    exit(0);
  }

  int max = pow(2, n) - 1;

  int x;
  printf("Enter value of x in range [0:%d]: ", max);
  scanf("%d", &x);
  if (x < 0 || x > max)
  {
    printf("Entered number is not in range\n");
    exit(0);
  }

  int y;
  printf("Enter value of y in range [0:%d]: ", max);
  scanf("%d", &y);
  if (y < 0 || y > max)
  {
    printf("Entered number is not in range\n");
    exit(0);
  }

  fflush(stdout);
}