#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

map<long long, long long> h;

long long f(long long n)
{
  if (h.count(n))
  {
    return h[n];
  }
  else
  {
    h[n] = f(n / 2) + f(n / 3) + f(n / 4);
    return h[n];
  }
}

int main()
{

  long long n, ans;
  int i;
  for (i = 0; i <= 11; i++)
  {
    h[i] = i;
  }
  while (scanf("%lld", &n) != EOF)
  {
    ans = f(n);
    printf("%lld\n", ans);
  }
  return 0;
}