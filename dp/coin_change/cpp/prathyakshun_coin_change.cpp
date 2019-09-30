#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define MOD 1000000007

int dp[150010][310],arr[310];
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0);	cout.tie(0);
	int n,m,i,j;
	cin>>n>>m;
	for (i=1;i<=n;i++)	{cin>>arr[i];	dp[0][i]=1;}
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (i-arr[j]>=0)	dp[i][j] = (dp[i][j] + dp[i-arr[j]][j])%MOD;
			if (j>=2)	dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
		}
	}
	cout<<dp[m][n]<<endl;
	return 0;
}