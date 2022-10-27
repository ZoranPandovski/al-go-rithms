 //2063. Vowels of All Substrings
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

long long countVowels(string word) 
{
    int n = word.size();
    long long cnt=0;
    vector<long> v(n,0);
    if(string("aeiou").find(word[0]) != string::npos) v[0]=1;
    for(int i=1;i<n;i++) {
        if(string("aeiou").find(word[i]) != string::npos)
            v[i]=v[i-1]+i+1;
        else
            v[i] = v[i-1];
    }
    for(auto i:v) cnt+=i;
    return cnt;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin>>s;
  cout<<countVowels(s);
  return 0;
}