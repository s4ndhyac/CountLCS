#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory>
#include "MaxLCS.cc"
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

  int x = 0;
  int y = 0;
  int max = pow(2, n) - 1;
  int maxCount = 0;
  for (x = 0; x <= max; x++)
  {
    for (y = 0; y <= max; y++)
    {
      std::shared_ptr<char> a(new char[n + 1], std::default_delete<char[]>());
      std::shared_ptr<char> b(new char[n + 1], std::default_delete<char[]>());
      a = Binstring(n, x);
      b = Binstring(n, y);
      int count = GetCommomSubsequencesCount(a, b, n, n);
      if (count > maxCount)
      {
        maxCount = count;
        cout << "x: " << x << " y: " << y << " s: " << maxCount << endl;
      }
    }
  }
}