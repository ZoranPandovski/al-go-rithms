#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll min(ll a,ll b)               // min function
{
if(a>=b) return b;
else return a;
}


int main()
{
	ll n,p;
	cin >> n >>p;

	ll a[n];

	for(ll i=0;i<n;i++)   // creating a array for price of lengths
	{
		cin >> a[i];
	}

	ll dp[n+1][p+1];

	for(int i=0;i<n+1;i++)   // intiliase dp as value of 0
	{
    		for(int j=0;j<p+1;j++)
    		{
    			dp[i][j]=0;
    		}
	}

	for(int i=1;i<n+1;i++)
	{
		for(int j=0;j<p+1;j++)
		{
			if(j==0 || dp[i][j]!=0)   
			{
				if(j+a[i-1]<=p+1 && dp[i][j]+i<=n)  //checking whether at that time index is <=given price and value is <=total length 
                          	{
					if(dp[i][j+a[i-1]]!=0)
					dp[i][j+a[i-1]]=min(dp[i][j]+i,dp[i-1][j+a[i-1]]);
					
					else
					dp[i][j+a[i-1]]=dp[i][j]+i;
				}
			}

        		if(i!=n)
			dp[i+1][j]=dp[i][j];
    		}
	}	

	vector<ll> v;
	ll j=p;

	for(ll i=n;i>=1;i--)
	{
		if(dp[i][j]!=dp[i-1][j] && i>=0) // if element is not match with above element of column then length at that time is stored in vector
		{
			v.push_back(i);
			ll temp=dp[i][j]-i;  // temp get rest length value at that time

    			while(temp!=dp[i][j] && j>=0) j--;

    			i++;
		}
	}

	if(v.size())
	{
		cout<<"By cutting in "<<v.size()<<" pieces of lengths : ";

		for(ll i=0;i<v.size();i++)  // showing length of rod to get given price
		cout<<v[i]<<" ";
	}

	else cout<<"NOT POSSIBLE!";
	
	cout<<endl;

	return 0;

}
