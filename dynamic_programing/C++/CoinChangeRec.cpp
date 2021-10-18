#include <iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

long long change(long long c)
{
    if(c==0) return 0;
    long long minCoins=1000000000;
    
    long long a[]={1,6,10};
    
    for(int i=0;i<3;++i)
    {
        if(c-a[i]>=0)
        {
            long long curMinCoins=change(c-a[i]);
            if(curMinCoins<minCoins)
            {
                minCoins=curMinCoins;
            }
        }
    }
    return minCoins+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        long long ans=change(n);
        cout<<ans<<endl;
    }

    return 0;
}