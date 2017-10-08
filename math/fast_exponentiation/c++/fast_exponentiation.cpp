#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

ll fast_exp(int base, int exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res;
}


int main(){
	ll base=4;
	ll power=10;
	cout<<fast_exp(4,10)<<endl;
}
