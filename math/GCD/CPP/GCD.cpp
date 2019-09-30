#include <bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a, int b){
    if (a == 0 || b == 0) 
       return 0;
    if (a == b) 
        return a;
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 

int main(){
	ll a,b;
	cout<<"Enter two numbers you want to find GCD of: \n";
	cin>>a>>b;
	cout<<"The GCD is : ";
	cout<<gcd(a,b)<<endl;
}