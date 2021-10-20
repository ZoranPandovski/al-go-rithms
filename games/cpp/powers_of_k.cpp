// In the Annual Quiz Competition Finals, Nobita and Dekisugi are the only ones competing. Dekisugi had reached there 
// using his wit and Nobita had reached there by seeking help from his friend Doraemon. Unfortunately, Doraemon has a
// business to attend and thus cannot help Nobita. However, Nobita has to win this competition to impress the most 
// beautiful girl in the town, Shizuka.

// Doraemon wants you to help Nobita out. The question is as follows:

// You are given two numbers N, K. You have to represent the number N as sum or difference of powers of K. Also, it is 
// necessary to use all the powers of K less than N,atleast once. You must report the minimum count of numbers used to
// form the number N.

// INPUT:
// First line represents the number of test cases T, followed by T lines.
// Each line contains two integer N and K.

// OUTPUT:
// Return the count of minimum numbers used to form N.

// SAMPLE TEST-CASES:
// 1)	2
//     145 12
//     12 10
// 1)	4 
//     3
//         Explanation:
//         a)	(1 + 12 + 144) - (12) = 145
//         b)  (1 + 1 + 10) = 12
// 2)	5
//     1124 15
//     268 3
//     37 2
//     51 5
//     201 4
// 2)	32
//     10

#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
using namespace std;

ll minCount(vector<ll> powers, ll cnt1, ll diff){
    vector<vector<ll>>dp(cnt1 + 1,vector<ll>(diff + 1,0));
    for (ll i = 1; i <= diff; i++) {
        dp[0][i] = INT_MAX - 1;
    }
    for (ll i = 1; i <= cnt1; i++){ 
        for (ll j = 1; j <= diff; j++){
                if (powers[i - 1] > j){
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j]= min(dp[i - 1][j],dp[i][j - powers[i - 1]] + 1);
            }
        }
    }
    return dp[cnt1][diff];     
}

void solve(ll n,ll k){
    vector<ll> powers;
    ll i=1;
    powers.pb(i);
    while(i<n){
        i*=k;
        if(i<n) powers.pb(i);
    }
    // for(auto x:powers){
    //     cout << x << " ";
    // }
    ll sum1=accumulate(powers.begin(),powers.end(),0);
    ll cnt1=powers.size();
    ll diff=0,cnt2=0;
    if(sum1==n){
        cout << cnt1 << endl;
    }
    else{
        diff=abs(sum1-n);
        cnt2=minCount(powers,cnt1,diff);
        cout << (cnt1+cnt2) << endl;
    }
}

int main(){
    ll t;cin >> t;
    while(t--){
        ll k,n;cin >> n >> k;
        solve(n,k);
    }
    return 0;
}


