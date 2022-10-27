 //1960 : Maximum Product of the Length of Two Palindromic Substrings
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"


 int longestPalindrom(string s) 
 {
    int n = s.length();
    vector<int> p(n,1);
    
    int lp = 0;   // the index of the center position of previous longer palindrom, used as mirror
	int ans = 1;
    for(int i=1;i<n-1;i++) {
        int l = 1;
        if(lp + p[lp]/2 >= i) {                                   // check if a mirrored version exists.
            int j = lp - (i - lp);                                // this is the mirror of the current number
            l = 2 * (j - max(lp - p[lp] / 2, j - p[j] / 2)) + 1;  // using the portion contained within the longer palindrom
        }
        if(lp + p[lp]/2 <= i + l/2) {                              // try to extend the new palindrom over the longer palindrom
            while(i+l/2+1<n && i-l/2-1>=0 && s[i+l/2+1]==s[i-l/2-1]){
                l+=2;
            }
            lp = i; 
        }
        p[i] = l;
		ans = max(l, ans);
    }
    return ans;
}


int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin>>s;
  cout<<longestPalindrom(s);
  return 0;
}