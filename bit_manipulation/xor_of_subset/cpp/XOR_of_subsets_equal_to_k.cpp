#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define pb push_back
#define mod 1000000007
int subsetXOR(int arr[],int n,int k)
{
    int max_ele=*max_element(arr,arr+n);
    int m=(1<<(int)log2(max_ele)+1)-1;

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            dp[i][j]=0;
    }

    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j^arr[i-1]];
    }
    return dp[n][k];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    cout<<subsetXOR(arr,n,k);
    return 0;
}
