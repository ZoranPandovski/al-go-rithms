#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll phi(ll n) {
    ll count = 1;

    for(ll i = 2; i < n; i++)
        if(gcd(i, n) == 1)
            count++;
    
    return count;
}

int main() {
    ll num;

    cout << "Euler's Totient Function\n\n";
    cout << "Enter a number: ";
    cin >> num;
    cout << "phi(" << num << ") = " << phi(num) << endl;

    return 0;
}