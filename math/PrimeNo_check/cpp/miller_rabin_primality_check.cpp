#include <bits/stdc++.h>
using namespace std;

long long mul(long long a, long long b, long long mod)
{
    if(double(a)*b < 1e18) return a*b%mod;
    long long c = 0;
    while(b)
    {
        if(b&1) c=(c+a)%mod;
        b = (b/2);
        a = (a*2)%mod;
    }
    return c;
}

long long modexp(long long base, long long power, long long mod)
{
    long long res = 1;
    while (power)
    {
        if (power & 1)
            res = mul(res, base, mod);
        power >>= 1;
        base = mul(base, base, mod);
    }
    return res;
}

bool miller_rabin(long long num, int k)
{
    long long s = 0, d = num - 1, one = 1, temp;
    while (!(d & 1))
        d >>= 1, s++;

    bool flag = true;
    temp = modexp(k, d, num);
    if (temp == 1 || temp == num - 1)
        return 1;
    for (int i = 0; i < s; i++)
    {
        temp = mul(temp, temp, num);
        if (temp == 1)
            return 0;
        if (temp == num - 1)
            return 1;
    }
    return 0;
}

bool isPrime(long long num)
{
    vector<int> A{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
    for (auto x : A)
        if (x == num)
            return 1;
    if (!(num & 1))
        return 0;

    bool flag = true;
    for (auto x : A)
        flag &= miller_rabin(num, x);
    return flag;
}

int main()
{
    long long x;
    cin>>x;
    cout<<x<<" :: "<<isPrime(x)<<"\n";
}
