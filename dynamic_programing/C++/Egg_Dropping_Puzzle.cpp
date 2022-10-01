#include<bits/stdc++.h>
using namespace std;

int attempt(int n,int k)
{
    int dp[n+1][k+1];
    int i,j,x;
    for(i=0;i<=n;i++)
    {
        dp[i][1]=1;
        dp[i][0]=0;
    }
    for(i=0;i<=k;i++)
    {
        dp[1][i]=i;
    }
    
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k;j++)
        {
            dp[i][j]=INT_MAX;
            for(x=1;x<=j;x++)
            {
                int res= 1+max(dp[i-1][x-1],dp[i][j-x]);
                if(res<dp[i][j])
                    dp[i][j]=res;
            }
        }
    }
    
    return dp[n][k];
}

int main() {
	
    int n,k;
    cout<<"Enter number of eggs: ";
    cin>>n;

    cout<<"Enter number of floors: ";
    cin>>k;
    
    int a= attempt(n,k);

    cout<<"Minimum no. of attempts to find critical floor: "<<a<<endl;
	    
	return 0;
}