#include <stdio.h>
#include <stdbool.h>

#define ll long long

ll digit_sum(ll n) {
    ll count = 0;

    while(n != 0 && n != 1) {
        count += n % 2;
        n = n / 2;
    }

    count += n;  

    return count; 
}

bool is_prime(ll n) {
    if(n < 2)
        return false;

    if(n == 2)
        return true;

    if(n % 2 == 0)
        return false;

    for(ll i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;

    return true;
}

int main() {

    ll num;

    printf("Pernicious number\n\n");
    printf("Enter a number: ");
    scanf("%lld", &num);

    if(is_prime(digit_sum(num)))
        printf("%lld is a pernicious number!\n", num);
    else
        printf("%lld is not a pernicious number!\n", num);

    return 0;
}