#include <bits/stdc++.h>
using namespace std;

long maxSum(vector<long> a, long m)
{
    long sum = 0, max = LONG_MIN, result = LONG_MAX;
    set<long> s;

    for (int i = 0; i < a.size(); i++)
    {
        sum = (sum + a[i]) % m;
        a[i] = sum;
        max = std::max(max, sum);
    }

    for (auto x : a)
    {
        auto p = s.insert(x);
        if (++p.first != s.end())
        {
            result = min(*p.first - x, result);
        }
    }

    return std::max(max, m - result);
}
int main()
{
    int t;
    int test_case;
    for (scanf("%lu", &test_case); test_case--;)
    {

        vector<long> g1;
        long n;
        long m;
        long a;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            g1.push_back(a);
        }
        cout << maxSum(g1, m) << endl;
    }
    return 0;
}