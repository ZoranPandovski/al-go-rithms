#include<stdio.h>
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

// Driver program to test above function
int main()
{
    int a = 10, b = 15;
    printf("GCD(%d, %d) = %dn", a, b, gcd(a, b));
    a = 35, b = 10;
    printf("GCD(%d, %d) = %dn", a, b, gcd(a, b));
    a = 31, b = 2;
    printf("GCD(%d, %d) = %dn", a, b, gcd(a, b));
    return 0;
}
