#include<stdio.h>

long long fact(long long x)
{
	if(x > 1)
		return x*fact(x-1);
	else return 1;
}

int main(void)
{
	int n, t, s=0, r;
	printf("Enter the number: ");
	scanf("%d", &n);
	printf("\nFactorial of the number is: %lld",fact(n));
	return 0;
}