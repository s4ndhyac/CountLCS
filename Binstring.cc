#include <stdio.h>
#include <stdlib.h>
#include <memory>

using namespace std;

shared_ptr<char> Binstring(int n, int x)
{
  std::shared_ptr<char> r(new char[n + 1], std::default_delete<char[]>());
  long i, tmp;
  long c = 0;
  for (i = n - 1; i >= 0; i--)
  {
    tmp = x >> i;
    if (tmp & 1)
      *(r.get() + c) = 1 + '0';
    else
      *(r.get() + c) = 0 + '0';

    c++;
  }

  *(r.get() + c) = '\0';
  return r;
}