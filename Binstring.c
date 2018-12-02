#include <stdio.h>

char *Binstring(int n, int x)
{
  char *r = (char *)malloc(n + 1);

  int i, tmp;
  int c = 0;
  for (i = n - 1; i >= 0; i--)
  {
    tmp = x >> i;
    if (tmp & 1)
      *(r + c) = 1 + '0';
    else
      *(r + c) = 0 + '0';

    c++;
  }

  *(r + c) = '\0';
  return r;
}