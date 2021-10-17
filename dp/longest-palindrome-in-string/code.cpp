//Problem Link: https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

#include <bits/stdc++.h>
using namespace std;

void solve(string s){
    int n = s.size();
    bool dp[n+1][n+1];
    memset(dp,false,sizeof(dp));
    
    //single character count
    for(int i=0;i<n;i++){
        dp[i][i] = true;
    }
    
    //2 character length count
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = true;
        }
    }
    
    //more than 2 character length
    
    for(int k=2;k<n;k++){
        int i = 0, j = k;
        
        while(j<n){
            
            if(s[i] == s[j] && dp[i+1][j-1]){
                dp[i][j] = true;
            }else{
                dp[i][j] = false;
            }
            
            i++; j++;
        }
    }
    
    string ans;
    int s_l = 0;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(dp[i][j]){
                string s2 = s.substr(i,j-i+1);
                if(s2.size() > s_l){
                    ans = s2;  
                    s_l = s2.size();
                }
            }
        }
    }
    
    cout << ans << endl;
    
}

int main() {
	//code
	int t;
	cin >> t;
	
	while(t--){
	    string s;
	    cin >> s;
	    solve(s);
	}
	return 0;
}
