 //926. Flip String to Monotone Increasing
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

 int minFlipsMonoIncr(string s) 
 {
  int one =0;
  for (int i=0;i<s.size();i++)
    if(s[i]=='0')
      one++;  // total flips to make the whole string of 1
  int zero = one;
  int ans = INT_MAX;
  for(int i=0;i<s.size();i++)
  {
    if (s[i]=='0')zero--;   // making each place 0 one by one
    else zero++;
    ans=min(ans,zero); // storing mnimum result for each possible sequence 
  }
  ans=min(ans,one);
  return ans;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin>>s;
  cout<<minFlipsMonoIncr(s);
  return 0;
}