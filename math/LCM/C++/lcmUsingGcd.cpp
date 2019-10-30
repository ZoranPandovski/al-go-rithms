/* Author: Codiyapa
   finding lcm of a given pair
*/

#include<bits/stdc++.h>
using namespace std;

int lcm(int a , int b){
    int gcd = __gcd(a, b);
    return (a*b)/gcd;
}

int main(){
    int a, b;
    cin>>a>>b;
    cout<<lcm(a, b);
    return 0;
}

