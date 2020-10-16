/*

You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amouint of money you can win if you go first.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains N denoting the size of the array. The second line contains N elements of the array.

Output:
For each testcase, in a new line, print the maximum amout.

*/

#include <bits/stdc++.h>
using namespace std;

int dp[102][102];

int opt(int arr[],int start,int end)
{   if(start>end)
        return dp[start][end]=0;
    
    if(start==end)
        return dp[start][end]=arr[start];
        
    if(dp[start][end]!=-1)
        return dp[start][end];
        
    int a = arr[start]+min(opt(arr,start+2,end),opt(arr,start+1,end-1));
    int b = arr[end]+min(opt(arr,start+1,end-1),opt(arr,start,end-2));
    
    dp[start][end] = max(a,b);
    
    return dp[start][end];
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        int n,i;
        cin>>n;
        int arr[n];
        
        for(i=0;i<n;i++)
            cin>>arr[i];
            
        int ans = opt(arr,0,n-1);
        cout<<ans<<endl;
    }
	return 0;
}