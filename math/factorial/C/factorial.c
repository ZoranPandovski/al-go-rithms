#include<stdio.h>

unsigned long long fact(unsigned long long x)
{
	if(x > 1)
		return x*fact(x-1);
	else return 1;
}

int main(void)
{
	unsigned int n, t, s=0, r;
	printf("Enter the number: ");
	scanf("%u", &n);
	printf("\nFactorial of the number is: %llu",fact(n));
	return 0;
}
