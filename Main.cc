#include <iostream>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "CountLCS.cc"
#include "Binstring.cc"

using namespace std;

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
  set<string> lcs;
  int lcsLen = CountLCS(n, a, b, lcs);
  int count = lcs.size();

  //output the results
  printf("STRINGLEN: %d\n", n);
  printf("X (%d) = %s\n", x, a);
  printf("Y (%d) = %s\n", y, b);
  printf("Length of LCS: %d\n", lcsLen);
  printf("No. of LCS: %d\n", count);

  int i = 1;
  set<string>::iterator it;
  for (it = lcs.begin(); it != lcs.end(); it++)
  {
    cout << "LCS " << i++ << ": " << *it << endl;
  }

  fflush(stdout);
}