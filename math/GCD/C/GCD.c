#include <stdio.h>

#define ll long long

ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b); 
}

int main() {
    ll a, b;

    printf("GCD – Greatest Common Divisor\n\n");
    printf("Enter the first number: ");
    scanf("%lld", &a);
    printf("Enter the second number: ");
    scanf("%lld", &b);
    printf("\nThe GCD of %lld and %lld is: %lld.\n", a, b, gcd(a, b));

    return 0;
}