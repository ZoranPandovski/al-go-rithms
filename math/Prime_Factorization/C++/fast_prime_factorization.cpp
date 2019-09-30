#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000000;
int lp[MAXN+1]; // lp[i] -> lowest prime factor of i
int pr[MAXN+1]; // pr[i] -> i-th prime number
int pr_size;

/*
    This sieve allows to factorize numbers up to 10^8 in O(log n) time [linear in factorization size].
    Samples:
        5 = 5^1
        10 = 2^1 x 5^1
        99999999 = 3^2 x 11^1 x 73^1 x 101^1 x 137^1
*/

void sieve() // O(n log log n)
{
    memset(lp, 0, sizeof(lp));
    pr_size = 0;
    for (int i = 2; i <= MAXN; ++i) {
        if (lp[i] == 0) { // i is prime
            lp[i] = i;
            pr[pr_size++] = i;
        }
        for (int j = 0; j < pr_size and pr[j] <= lp[i] and i*pr[j] <= MAXN; ++j) {
            lp[i*pr[j]] = pr[j];
        }
    }   
}

vector<pair<int,int>> factorize(int n) // O(log n)
{
    vector<pair<int,int>> factors;
    while (n > 1) {
        pair<int,int> factor = make_pair(lp[n], 0); // { factor, power }
        while (lp[n] == factor.first) {
            ++factor.second;
            n /= lp[n];
        }
        factors.push_back(factor);
    }
    return factors;
}

int main()
{
    sieve();
    int n;
    while (cin >> n) {
        vector<pair<int,int>> factors = factorize(n);
        cout << n << " = ";
        for (int i = 0; i < factors.size(); ++i) {
            if (i != 0) cout << " x ";
            cout << factors[i].first << "^" << factors[i].second;
        }
        cout << endl;
    }
}