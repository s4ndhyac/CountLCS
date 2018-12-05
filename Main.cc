#include <iostream>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>
#include "CountLCS.cc"
#include "Binstring.cc"

using namespace std;

int main()
{
  //Read input n
  // int n;
  // char term;
  // printf("Enter the value of n in range [3:20] ");
  // if (scanf("%d%c", &n, &term) != 2 || term != '\n')
  // {
  //   printf("Valid integer not entered\n");
  //   exit(0);
  // }
  // if (n < 3 || n > 20)
  // {
  //   printf("Entered number is not in range\n");
  //   exit(0);
  // }

  // int max = pow(2, n) - 1;

  //Read input x
  // int x;
  // printf("Enter value of x in range [0:%d]: ", max);
  // if (scanf("%d%c", &x, &term) != 2 || term != '\n')
  // {
  //   printf("Valid integer not entered\n");
  //   exit(0);
  // }
  // if (x < 0 || x > max)
  // {
  //   printf("Entered number is not in range\n");
  //   exit(0);
  // }

  // //Read input y
  // int y;
  // printf("Enter value of y in range [0:%d]: ", max);
  // if (scanf("%d%c", &y, &term) != 2 || term != '\n')
  // {
  //   printf("Valid integer not entered\n");
  //   exit(0);
  // }
  // if (y < 0 || y > max)
  // {
  //   printf("Entered number is not in range\n");
  //   exit(0);
  // }

  //freopen("output.txt", "w", stdout);
  int n = 14;
  const int max = pow(2, 14) - 1;
  int **cache;
  int i = 0;
  int j = 0;
  for (i = 0; i <= max; i++)
  {
    cache = new int *[max + 1];
    for (j = 0; j <= max; j++)
    {
      cache[i] = new int[max + 1];
      cache[i][j] = -1;
    }
  }
  int x = 0;
  int y = 0;
  int maxCount = 46;

  for (x = 793; x <= max; x++)
  {
    for (y = 0; y <= max; y++)
    {
      if (cache[x][y] == -1)
      {
        auto start = std::chrono::high_resolution_clock::now();
        char *a = Binstring(n, x);
        char *b = Binstring(n, y);
        set<string> lcs;
        int lcsLen = CountLCS(n, a, b, lcs);
        int count = lcs.size();
        auto finish = std::chrono::high_resolution_clock::now();
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
        if (count > maxCount)
        {
          maxCount = count;
          cout << "x: " << x << " y: " << y << " s: " << maxCount << " t: " << microseconds.count() << endl;
        }
      }
    }
  }

  // //Program execution starts
  // auto start = std::chrono::high_resolution_clock::now();

  // //Get binstring from n and x
  // char *a = Binstring(n, x);

  // auto f1 = std::chrono::high_resolution_clock::now();
  // auto m1 = std::chrono::duration_cast<std::chrono::microseconds>(f1 - start);
  // cout << "X: " << m1.count() << "µs\n";

  // //Get binstring from n and x
  // char *b = Binstring(n, y);

  // auto f2 = std::chrono::high_resolution_clock::now();
  // auto m2 = std::chrono::duration_cast<std::chrono::microseconds>(f2 - start);
  // cout << "Y: " << m2.count() << "µs\n";

  // //Get LCS
  // set<string> lcs;
  // int lcsLen = CountLCS(n, a, b, lcs);

  // auto f3 = std::chrono::high_resolution_clock::now();
  // auto m3 = std::chrono::duration_cast<std::chrono::microseconds>(f3 - start);
  // cout << "CountLCS Total: " << m3.count() << "µs\n";

  // int count = lcs.size();

  // //output the results
  // printf("STRINGLEN: %d\n", n);
  // printf("X (%d) = %s\n", x, a);
  // printf("Y (%d) = %s\n", y, b);
  // printf("Length of LCS: %d\n", lcsLen);
  // printf("No. of LCS: %d\n", count);

  // int i = 1;
  // set<string>::iterator it;
  // for (it = lcs.begin(); it != lcs.end(); it++)
  // {
  //   cout << "LCS " << i++ << ": " << *it << endl;
  // }

  // //Program ends
  // auto finish = std::chrono::high_resolution_clock::now();
  // auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
  // cout << "Total: " << microseconds.count() << "µs\n";

  fflush(stdout);
}