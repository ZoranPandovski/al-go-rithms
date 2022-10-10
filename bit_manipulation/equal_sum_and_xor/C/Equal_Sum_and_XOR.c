#include<stdio.h>

long long int Equal_Sum_and_XOR(int n){
    int count=0;
    while(n>0){
        if(n%2==0)
            count++;
        n/=2;
    }
    return 1LL<<count;
}

int main(){
    int n;
    scanf("%d",&n);
    long long int ans=Equal_Sum_and_XOR(n);
    printf("%lld\n",ans);
    return 0;
}

// Time complexity O(lg(n))
// Space Complexity O(1)

/*
    Description:
    * Using the identity n+x = n^x + 2*(n&x), we see that n+x = n^x holds iff n&x=0.
    * Hence, in order to obtain n&x=0, for every set bit of n, the corresponding bit of x should be unset.
    * For every unset bit of n, the bit of x has 2 possibilities, 1 or 0.
    * Hence the required ans is pow(2,no of unset bits)*pow(1,no of set bits) = pow(2,no of unset bits)
    * Also for faster implementation, we use 1LL<<k instead of pow(2,k)
*/