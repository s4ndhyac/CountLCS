#include <iostream>
#include <set>
#include <stdio.h>

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
  memo = new int *[n + 1];
  for (int i = 0; i < n + 1; ++i)
    memo[i] = new int[n + 1];
  int i, j;
  for (i = n; i >= 0; i--)
  {
    for (j = n; j >= 0; j--)
    {
      if (a[i] == '\0' || b[j] == '\0')
        memo[i][j] = 0;
      else if (a[i] == b[j])
        memo[i][j] = 1 + memo[i + 1][j + 1];
      else
        memo[i][j] = MAX(memo[i + 1][j], memo[i][j + 1]);
    }
  }

  lcs = GetLCS(a, b, n, n);
  return memo[0][0];
}
