#include <iostream>
#include <set>
#include <stdio.h>
#include <chrono>

using namespace std;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int **memo;

set<string> GetLCS(char *a, char *b, int i, int j)
{
  set<string> s;
  if (i == 0 || j == 0)
  {
    s.insert("");
    return s;
  }
  if (a[i - 1] == b[j - 1])
  {
    set<string> tmp = GetLCS(a, b, i - 1, j - 1);
    set<string>::iterator it;
    for (it = tmp.begin(); it != tmp.end(); it++)
    {
      string tmp = *it;
      s.insert(tmp + a[i - 1]);
    }
  }
  else
  {
    if (memo[i - 1][j] >= memo[i][j - 1])
    {
      s = GetLCS(a, b, i - 1, j);
    }
    if (memo[i][j - 1] >= memo[i - 1][j])
    {
      set<string> tmp = GetLCS(a, b, i, j - 1);
      set<string>::iterator it;
      for (it = tmp.begin(); it != tmp.end(); it++)
      {
        string t = *it;
        s.insert(t);
      }
    }
  }
  return s;
}

int CountLCS(const int n, char *a, char *b, set<string> &lcs)
{
  auto s = std::chrono::high_resolution_clock::now();

  memo = new int *[n + 1];
  for (int i = 0; i < n + 1; ++i)
    memo[i] = new int[n + 1];
  int i, j;
  for (i = 0; i <= n; i++)
  {
    for (j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
        memo[i][j] = 0;
      else if (a[i - 1] == b[j - 1])
        memo[i][j] = 1 + memo[i - 1][j - 1];
      else
        memo[i][j] = MAX(memo[i][j - 1], memo[i - 1][j]);
    }
  }

  auto f0 = std::chrono::high_resolution_clock::now();
  auto m0 = std::chrono::duration_cast<std::chrono::microseconds>(f0 - s);
  cout << "GetLCS fill memo get Count: " << m0.count() << "µs\n";

  lcs = GetLCS(a, b, n, n);

  auto f = std::chrono::high_resolution_clock::now();
  auto m = std::chrono::duration_cast<std::chrono::microseconds>(f - s);
  cout << "GetLCS: " << m.count() << "µs\n";

  return memo[n][n];
}
