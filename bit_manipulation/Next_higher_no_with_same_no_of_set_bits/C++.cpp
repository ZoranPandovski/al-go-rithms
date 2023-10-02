// Next higher number with same number of set bits 
#include <bits/stdc++.h>
using namespace std; 
#define ll long long 

ll fun(ll n){
    ll ans=0,r1,r,next;
    if(n){
        r1=n&(-n);
        next=n+r1;
        r=(n^next)/r1;
        r>>=2;
        ans=next|r;
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;
    cout<<fun(n)<<endl;
    return 0;
}
