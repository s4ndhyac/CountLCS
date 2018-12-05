#include <iostream>
#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int **dp;
int **memo;

void LCSLength(const int n, char *a, char *b)
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
      else if (a[i - 1] == b[j - 1])
        memo[i][j] = 1 + memo[i - 1][j - 1];
      else
        memo[i][j] = MAX(memo[i][j - 1], memo[i - 1][j]);
    }
  }
}

int GetCommomSubsequencesCount(char *s1, char *s2, const int N1, const int N2)
{
  LCSLength(N1, s1, s2);
  dp = new int *[N1 + 1];
  for (int i = 0; i < N1 + 1; ++i)
    dp[i] = new int[N2 + 1];

  // for (int i = 0; i <= N1; i++) //N1 is size of 1st string
  // {
  //   for (int j = 0; j <= N2; j++) //N2 is size of 2nd string
  //   {
  //     dp[i][j] = 0;
  //   }
  // }

  for (int b = 0; b <= N2; b++)
  {
    for (int a = 0; a <= N1; a++)
    {
      if (a == 0 || b == 0)
        dp[a][b] = 1;
      else
      {
        dp[a][b] = 0;
        if (s1[a] == s2[b])
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

  //   for j ← 0 to n do
  //     for i ← 0 to m do
  //         if i = 0 or j = 0 then
  //             D[i, j] ← 1
  //         else
  //             D[i, j] ← 0
  //             if ai  = bj  then
  //                 D[i, j] ← D[i − 1, j − 1]
  //             else if L[i − 1, j] = L[i, j] then
  //                 D[i, j] ← D[i, j] + D[i − 1, j]
  //             endif
  //             if L[i, j − 1] = L[i, j] then
  //                 D[i, j] ← D[i, j] + D[i, j − 1]
  //             endif
  //             if L[i − 1, j − 1] = L[i, j] then
  //                 D[i, j] ← D[i, j] − D[i − 1, j − 1]
  //             endif
  //         end if
  //     endfor
  // endfor

  // for (int i = 1; i <= N1; i++)
  // {
  //   for (int j = 1; j <= N2; j++)
  //   {
  //     if (s1[i - 1] == s2[j - 1])
  //     {
  //       dp[i][j] = 1 + dp[i][j - 1] + dp[i - 1][j];
  //     }
  //     else
  //     {
  //       dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
  //     }
  //   }
  // }

  int max = dp[N1][N2];
  delete dp;
  delete memo;
  return max;
}