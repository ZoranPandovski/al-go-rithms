#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair<int,int> >
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define MOD 1000000000

using namespace std;

void simpleSieve(int maxi, vector<int> &prime)
{
    bool vis[maxi+1];
    memset(vis, true, sizeof(vis));

    for (int p=2; p*p<maxi; p++)
    {
        if (vis[p] == true)
        {
            for (int i=p*2; i<maxi; i+=p)
                vis[i] = false;
        }
    }

    for (int p=2; p<maxi; p++)
    {
        if (vis[p] == true)
        {
            prime.push_back(p);
            cout << p << "  ";
        }
    }
}

void segmentedSieve(int n)
{
    int maxi = floor(sqrt(n))+1;
    vector<int> prime;
    simpleSieve(maxi, prime);

    int l = maxi,r = 2*maxi;

    while (l < n)
    {
        bool vis[maxi+1];
        memset(vis, true, sizeof(vis));

        for (int i = 0; i < prime.size(); i++)
        {
            int ll = floor(l/prime[i]) * prime[i];
            if (ll < l)
                ll += prime[i];

            for (int j=ll; j<r; j+=prime[i])
                vis[j-l] = false;
        }

        for (int i = l; i<r; i++)
            if (vis[i - l] == true)
                cout << i << "  ";

        l = l + maxi;
        r = r + maxi;
        if (r >= n) r = n;
    }
}

int main()
{
    int n = 73;
    cout << "Primes smaller than " << n << ":\n";
    segmentedSieve(n);
    return 0;
}

