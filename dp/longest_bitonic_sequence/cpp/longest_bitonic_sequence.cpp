#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int cases;
  cin>>cases;
  while(cases--){
    cin>>n;
    vector<int> v(n+1);
    for(int i = 0; i < n; i++){
      cin>>v[i];
    }
    vector<int> dp(n+1);
    for(int i = 0; i <n; i++){
      dp[i] =1;
    }
    for(int i = 1 ;i < v.size(); i++){
      for(int j = 0; j < i; j++){
        if(v[i] > v[j]){
          dp[i] = max(dp[i],dp[j]+1);
        }
      }
    }
    vector<int> dp1(n+1);
    for(int i = 0; i < n; i++){
      dp1[i] = 1;
    }
    for(int i = n-2; i >=0 ; i--){
      for(int j = n-1; j > i; j--){
        if(v[i] > v[j]){
          dp1[i] = max(dp1[i],dp1[j]+1);
        }
      }
    }
    vector<int> ans(n+1);
    for(int i = 0; i < n; i++){
      ans[i] = dp[i] + dp1[i] - 1;
    }
    auto res = *max_element(ans.begin(),ans.end());
    cout<<res<<"\n";
  }
  return 0;
}

