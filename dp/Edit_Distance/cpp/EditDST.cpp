#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	string s1,s2;
	cout<<"Enter the two strings: \n";
	cin>>s1>>s2;
	ll m=s1.length();
	ll n=s2.length();
	ll dp[m+1][n+1];
	memset(dp,0,sizeof(dp));
	for(ll i=0;i<=m;i++)
	{
		for(ll j=0;j<=n;j++)
		{
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if(s1[i]==s2[j])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else 
			{
				dp[i][j]=min(1+dp[i-1][j-1],min(1+dp[i-1][j],1+dp[i][j-1]));
			}
		}	
	}
	cout<<"The number of operations required : ";
	cout<<dp[m][n];
}
