#include <iostream>
#include <stdio.h>
#include <memory>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

using namespace std;

int **dp;
int **memo;

void LCSLength(const int n, shared_ptr<char> a, shared_ptr<char> b)
{
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
      else if (*(a.get() + (i - 1)) == b.get()[j - 1])
        memo[i][j] = 1 + memo[i - 1][j - 1];
      else
        memo[i][j] = MAX(memo[i][j - 1], memo[i - 1][j]);
    }
  }
}

int GetCommomSubsequencesCount(shared_ptr<char> s1, shared_ptr<char> s2, const int N1, const int N2)
{
  LCSLength(N1, s1, s2);
  dp = new int *[N1 + 1];
  for (int i = 0; i < N1 + 1; ++i)
    dp[i] = new int[N2 + 1];

  for (int b = 0; b <= N2; b++)
  {
    for (int a = 0; a <= N1; a++)
    {
      if (a == 0 || b == 0)
        dp[a][b] = 1;
      else
      {
        dp[a][b] = 0;
        if (s1.get()[a] == s2.get()[b])
          dp[a][b] = dp[a - 1][b - 1];
        else
        {
          if (memo[a - 1][b] == memo[a][b])
            dp[a][b] = dp[a][b] + dp[a - 1][b];

          if (memo[a][b - 1] == memo[a][b])
            dp[a][b] = dp[a][b] + dp[a][b - 1];

          if (memo[a - 1][b - 1] == memo[a][b])
            dp[a][b] = dp[a][b] - dp[a - 1][b - 1];
        }
      }
    }
  }

  int max = dp[N1][N2];

  for (int i = 0; i < N1 + 1; ++i)
    delete[] dp[i];
  delete[] dp;

  for (int i = 0; i < N1 + 1; ++i)
    delete[] memo[i];
  delete[] memo;

  return max;
}