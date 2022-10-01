//Nikita Gautam github: @nikitaghps
//C++ program to find the sum of maximum amount of gold that can be collected from a goldmine if we are allowed to move 1 cell right-up, 1 cell right or 1 cell right-down.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int dp[n+2][m+2];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    memset(dp,0,sizeof(dp));

    for(int i=1,j=m-1;i<=n;i++)
        dp[i][j]=a[i-1][j];
    

    for(int j=m-2;j>=0;j--){
        for(int i=1;i<=n;i++){
            dp[i][j]=a[i-1][j] + max( dp[i-1][j+1] , max( dp[i+1][j+1] , dp[i][j+1] ) );
        }
    }

    int ma=INT_MIN;

    for(int i=1;i<=n;i++){
        if(dp[i][0]>ma)
            ma=dp[i][0];
    }
    cout<<ma;
    return 0;
}