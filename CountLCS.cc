#include <iostream>
#include <set>
#include <stdio.h>
#include <vector>

using namespace std;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

class Backtrack
{
public:
  int i;
  int j;
  set<string> h;

  Backtrack() : h()
  {
    i = -1;
    j = -1;
  };

  void setV(int _i, int _j, set<string> _h)
  {
    i = _i;
    j = _j;
    h = _h;
  }

  int getXKey()
  {
    return i;
  }

  int getYKey()
  {
    return j;
  }

  set<string> getH()
  {
    return h;
  }
};

int **memo;
Backtrack **bc;

void InitializeBacktrack(char *a, char *b, const int n, const int m)
{
  bc = new Backtrack *[n + 1];
  for (int i = 0; i < n + 1; i++)
  {
    bc[i] = new Backtrack[m + 1];
  }
}

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
    set<string> tmp;
    if (bc[i - 1][j - 1].getXKey() == -1 || bc[i - 1][j - 1].getYKey() == -1)
    {
      tmp = GetLCS(a, b, i - 1, j - 1);
      bc[i - 1][j - 1].setV(i - 1, j - 1, tmp);
    }
    else
      tmp = bc[i - 1][j - 1].getH();

    set<string>::iterator it;
    for (it = tmp.begin(); it != tmp.end(); it++)
    {
      string t = *it;
      s.insert(t + a[i - 1]);
    }
  }
  else
  {
    if (memo[i - 1][j] >= memo[i][j - 1])
    {
      if (bc[i - 1][j].getXKey() == -1 || bc[i - 1][j].getYKey() == -1)
      {
        s = GetLCS(a, b, i - 1, j);
        bc[i - 1][j].setV(i - 1, j, s);
      }
      else
        s = bc[i - 1][j].getH();
    }
    if (memo[i][j - 1] >= memo[i - 1][j])
    {
      set<string> tmp;
      if (bc[i][j - 1].getXKey() == -1 || bc[i][j - 1].getYKey() == -1)
      {
        tmp = GetLCS(a, b, i, j - 1);
        bc[i][j - 1].setV(i, j - 1, tmp);
      }
      else
        tmp = bc[i][j - 1].getH();
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

  // auto f0 = std::chrono::high_resolution_clock::now();
  // auto m0 = std::chrono::duration_cast<std::chrono::microseconds>(f0 - s);
  // cout << "GetLCS fill memo get Count: " << m0.count() << "µs\n";

  InitializeBacktrack(a, b, n, n);
  lcs = GetLCS(a, b, n, n);

  // auto f = std::chrono::high_resolution_clock::now();
  // auto m = std::chrono::duration_cast<std::chrono::microseconds>(f - s);
  // cout << "GetLCS: " << m.count() << "µs\n";

  return memo[n][n];
}
