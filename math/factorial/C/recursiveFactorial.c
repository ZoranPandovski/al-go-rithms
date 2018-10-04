#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    if(n==0){
        return 1;
    } else {
        return n*factorial(n-1);
    }
}

int main ()
{
    int num;
    printf("input num : "); scanf("%d",&num);
    printf("Factorial : %d",factorial(num));
    return 0;
}

