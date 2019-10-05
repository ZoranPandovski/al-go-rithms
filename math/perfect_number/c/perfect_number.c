#include <stdio.h>
#include <stdbool.h>

#define ll long long 

bool is_perfect(ll num) {
    ll sumDivisors = 1;

    // Find the divisors in pairs
    for(ll i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            sumDivisors += i;
            if(i * i != num)
                sumDivisors += num / i;
        }   
    } 

    return sumDivisors == num;
}

int main() {

    ll num;
    
    printf("Perfect Numbers\n\n");
    printf("Enter a number: ");
    scanf("%lld", &num);
    
    if(is_perfect(num))
        printf("%lld is a perfect number!\n", num);
    else
        printf("%lld is not a perfect number!\n", num);

    return 0;
}