/*Given a standard 6-sided dice, find the number of ways to get a sum of N.*/
/*Sample Input 0
5
3
11
7
5
500

Sample Output 
4
976
63
16
765996555*/


#include<bits/stdc++.h>
using namespace std;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define readvector(a) for(int &i:a){cin>>i;}

long double pi = 3.14159265358979323;
const int mod = 1e9 + 7;


int main(){
    fast;
    int n=100001;
    vector<ll> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<=6;j++){
            if(j>i){
                break;
            }
            dp[i]=((dp[i]%mod)+(dp[i-j]%mod))%mod;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        printf("%lld\n",dp[x]);
    }
    return 0;
}


