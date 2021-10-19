#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll shortest(ll n,ll *dp)
{
    if(n==0) return 0;
    else if(n<0) return 1000000000;
    else if(dp[n]!=0) return dp[n];
    else
    {
        if(n%3==0)
        {
            dp[n]= min(1+shortest(n-1,dp),1+shortest(n/3,dp));
        }
        else
        {
            dp[n]= 1+shortest(n-1,dp);
        }
        return dp[n];
    }
}

int main()
 {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n;
        cin>>n;
        ll dp[n+1]{};
        ll ans=shortest(n,dp)-1;
        cout<<ans<<endl;
    }
    
	return 0;
}