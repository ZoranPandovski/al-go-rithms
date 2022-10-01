//Maximum number of ways to change a given amount of money
#include<bits/stdc++.h>
using namespace std;
int coinChange(int change,int coin[],int n)
{
    int dp[n+1][change+1];

    //Base conditions
    for(int i=0;i<n+1;i++)
    dp[i][0]=0;

    for(int j=1;j<change+1;j++)
    dp[0][j]=1;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<change+1;j++)
        {
            if(coin[i-1]<=change)
            dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
            if(coin[i-1]>change)
            dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][change];
}
int main()
{
    int change;
    cin>>change;
    int n;
    cin>>n;
    int coin[n];
    for(int i=0;i<n;i++)
    cin>>coin[i];
    cout<<coinChange(change,coin,n);   
}