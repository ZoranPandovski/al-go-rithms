//Minimum coins required to change the given  amount of money
#include<bits/stdc++.h>
using namespace std;
int minCoinChange(int coin[],int n,int change)
{
    int dp[n+1][change+1];

    //Base conditions
    for(int i=0;i<change+1;i++)
    dp[0][i]=INT_MAX-1;

    for(int j=1;j<n+1;j++)
    dp[j][0]=0;
    
    
    for(int j=1;j<change+1;j++)
    {
        if(j%coin[0]==0)
        dp[1][j]=j/coin[0];
        else
        dp[1][j]=INT_MAX-1;
    }

    for(int i=2;i<n+1;i++)
    {
        for(int j=1;j<change+1;j++)
        {
            if(coin[i-1]<=j)
            dp[i][j]=min(dp[i][j-coin[i-1]]+1,dp[i-1][j]);
            if(coin[i-1]>j)
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
    int coin[n];
    for(int i=0;i<n;i++)
    cin>>coin[i];
    cout<<minCoinChange(coin,n,change);
}
        