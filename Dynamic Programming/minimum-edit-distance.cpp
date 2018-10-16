#include <bits/stdc++.h>
using namespace std;

int min_edit(string s1, string s2){
  int n1=s1.size(), n2=s2.size();
  int dp[n1+1][n2+1],k=0;
  for(int i=0; i<=n1;i++)
    dp[i][0]=k; k++;
  k=0;
  for(int j=0;j<=n2;j++)
    dp[0][j]=k; k++;

  for(int i=1; i<=n1; i++){
    for(int j=1; j<=n1; j++){
      if(s1[i-1]==s2[j-1])
        dp[i][j] = dp[i-1][j-1];
      else{
        dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
      }
    }
  }
  return dp[n1][n2];
}
int main(){
  string s1, s2;
  cout<<"\nEnter two strings: ";
  cin>>s1>>s2;
  int min_edit_distance = min_edit(s1, s2);
  cout<<"\nMinimum edit distance between these two strings is: "<<min_edit_distance<<endl;
  return 0;
}
