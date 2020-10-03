//Rod cutting problem
//A variation of the unbounded knapsack
#include<bits/stdc++.h>
using namespace std;
int rodPieces(int price[],int length[],int n,int l)
{
    int dp[n+1][l+1];
    //Base conditions
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<l+1;j++)
        {
            dp[i][j]=0;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<l+1;j++)
        {
            if(length[i-1]<=j)
            dp[i][j]=max((dp[i-1][j]),(price[i-1]+dp[i][j-length[i-1]]));
            else
            dp[i][j]=dp[i-1][j];

        }
    }

    return dp[n][l];

}
int main()
{
    int n;
    cin>>n;
    int price[n],length[n];
    for(int i=0;i<n;i++)
    cin>>length[i]>>price[i];
    int l;
    cin>>l;
    cout<<rodPieces(price,length,n,l);
}