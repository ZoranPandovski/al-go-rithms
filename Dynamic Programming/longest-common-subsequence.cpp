#include <bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2){
    int n1=s1.size(), n2=s2.size();
    int dp[n1+1][n2+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}
int main(){
    string s1, s2;
    cout<<"\nEnter the 1st string: ";
    cin>>s1;
    cout<<"\nEnter the 2nd string: ";
    cin>>s2;
    int length = lcs(s1, s2);
    cout<<"\nLength of longest common subsequence between \""<<s1<<"\" and \""<<s2<<"\" is: "<<length<<endl; 
    return 0;
}
