#include<bits/stdc++.h>
#define li long long int
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 100000007
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b){
        return (b[1]>a[1]);
}
int solve(vector<vector<int> > &A) {
    vector<int>dp(A.size(),1);
    int mx=1;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<i;j++){
            if(A[i][0]>A[j][1]) dp[i]=max(1+dp[j],dp[i]);
        }
        if(dp[i]>mx)mx=dp[i];
    }
    return mx;
}

int main(){
    fastio
    vector<vector<int>>A;
    // No of Values to be taken in array
    int t,a,b;
    cin>>t;
    while(t--){
        // Each element of array
        vector<int>arr;
        cin>>a>>b;
        arr.push_back(a),arr.push_back(b);
        A.push_back(arr);
    }
    cout<<solve(A);
    return 0;
}