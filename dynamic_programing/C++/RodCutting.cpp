//to tell the maximum price we can get from this rod
//BOTTOM UP
#include <iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin>>m;

    while(m--)
    {
        int n;//total length of rod
        cin>>n;
        int p[n];//price of each length of rod
        for(int i=0;i<n;++i)
        {
            cin>>p[i];
        }
        int dp[n+1];
        dp[0]=0;
        for(int i=1;i<=n;++i)
        {
            int q=-1;
            for(int j=1;j<=i;++j)
            {
                q=max(q,p[j-1]+dp[i-j]);
            }
            dp[i]=q;
        }
        cout<<dp[n]<<endl;

    }
    return 0;
}

//UP-DOWN
#include <iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

int rodCutMaxProfit(int n,int p[],int dp[])
{
    if(dp[n]>=0) return dp[n];
    if(n==0)
    {
        dp[n]=0;
        return n;
    }
    else
    {
        int q=-1;
        for(int i=1;i<=n;++i)
        {
            q=max(q,p[i-1]+rodCutMaxProfit(n-i,p,dp));
        }
        dp[n]=q;
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin>>m;

    while(m--)
    {
        int n;//total length of rod
        cin>>n;
        int p[n];//price of each length of rod
        for(int i=0;i<n;++i)
        {
            cin>>p[i];
        }
        int dp[n+1];
        for(int i=0;i<n+1;++i) dp[i]=-1;
        long long ans=rodCutMaxProfit(n,p,dp);
        cout<<ans<<endl;

    }
    return 0;
}
