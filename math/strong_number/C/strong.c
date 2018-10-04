#include<stdio.h>

int fact(int x)
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
	t=n;
	while(t>0)
	{
		r = t % 10;
		t = t / 10;
		s = s + fact(r);
	}
	(s == n) ? printf("\nThis is a strong number") : printf("\nThis is not a strong number");
}