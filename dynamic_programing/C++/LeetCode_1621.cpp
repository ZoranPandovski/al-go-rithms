 //1621. Number of Sets of K Non-Overlapping Line Segments
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"


int memo[1001][1000];
const int MOD = pow(10, 9)+7;
int dfs(int n, int k, int pos)
{
    if(pos >= n) return 0;
    if(memo[pos][k] != -1) return memo[pos][k];
    if(!k) return 1;
    int ans = dfs(n, k, pos+1);
    for(int i = pos+1; i+k-1 < n; i++)
    {
        ans += dfs(n, k-1, i);
        ans %= MOD;
    }
    return memo[pos][k] = ans;
}
int numberOfSets(int n, int k) 
{
    memset(memo, -1, sizeof memo);
    return dfs(n, k, 0);
}


int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin>>n>>k;
  cout<<numberOfSets(n, k);
  return 0;
}