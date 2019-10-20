#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll max(ll a,ll b)		// max function
{
if(a>=b) return a;
else return b;
}


int main()
{
	ll n;
	cin >> n;
	ll a[n];		// creating a array for price of lengths

	for(ll i=0;i<n;i++)
	{	
		cin >> a[i];

	}

	ll dp[n+1][n+1];   

	for(int i=0;i<n+1;i++) 		// intiliase dp as value of 0
	{
    		for(int j=0;j<n+1;j++)
    		{
    			dp[i][j]=0;
    		}

	}

	for(int i=1;i<n+1;i++)			
	{
		for(int j=1;j<n+1;j++)
		{
			if(i<=j) //if i<=j then we take max value from either above element of column or previous element of raw 
			{
				dp[i][j]=max(dp[i-1][j],a[i-1]+dp[i][j-i]); 
			}
			else  // else we take value from above element of column
			{
			dp[i][j]=dp[i-1][j];
			}
		}
	}



	cout<<"Maximum Price = "<<dp[n][n]<<endl;  //thus max value stored at dp[n][n] 

	vector<ll> v;

	ll j=n;

	for(ll i=n;i>=1;i--)
	{
		if(dp[i][j]!=dp[i-1][j] && i>=0)   // if element is not match with above element of column then length at that time is stored in vector
		{
			v.push_back(i);
		     	ll temp=dp[i][j]-a[i-1];  // temp get rest price value at that time

    			while(temp!=dp[i][j] && j>=0) j--;  

    			i++;
		}
	}

	cout<<"By cutting in "<<v.size()<<" pieces of lengths : ";

	for(ll i=0;i<v.size();i++)  	// showing length of rod to get maximum price
	cout<<v[i]<<" ";

	cout<<endl;

	return 0;

}
