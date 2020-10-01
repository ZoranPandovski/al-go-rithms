//Question : Given a number, swap the adjacent bits in the binary representation of the number, 
//and print the new number formed after swapping.

//Input: 
//4
//10
//7
//43
//100

//Output:
//5
//11
//23
//152


#include<bits/stdc++.h>
using namespace std;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long

//Just A Gentle Reminder about MOD
const int mod = 1e9 + 7;


int swapbits2(int n){
    for(int i=0;i<32;i+=2){
        int x=i,y=i+1;
        int temp1=(n>>x)&1;
        int temp2=(n>>y)&1;
        if((temp1^temp2)!=0){
            n=n^((1<<x)|(1<<y));
        } 
    }
    return n;
}


int swapbits1(int n){
    //0xAAAAAAAA even pos set bits mask
    //0x55555555 odd pos set bits mask
    return (((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1));
}


int main(){
    fast;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans=swapbits2(n);
        cout<<ans<<endl;   
    }
    return 0;
}