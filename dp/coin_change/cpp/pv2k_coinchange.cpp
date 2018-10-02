#include <bits/stdc++.h>
using namespace std;

int change(int c[],int n, int m)
{
    int ttl[n+1],i,j;
    for(i=0;i<=n;i++)
        ttl[i] = 0;
    ttl[0]=1;
    for(i=0;i<m;i++)
    {
        for(j=c[i];j<=n;j++)
        {
            ttl[j] += ttl[j-c[i]];
        }
    }
    return ttl[n];
}

int main() {
    int T,i,j,m,n;
    cin >> T;
    while(T--)
    {
        cin >> m;
        int c[m];
        for(i=0;i<m;i++)
        {
            cin >> c[i];
        }
        cin >> n;
        int res = change(c,n,m);
        cout << res << endl;
    }
	return 0;
}