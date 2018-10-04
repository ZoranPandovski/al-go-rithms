#include<stdio.h>
#include<math.h>

int main(void)
{
	int n,r,a=0,t,c=0,z;
	printf("Enter a number: ");
	scanf("%d",&n);
	t=n; z=n;
	while(z>0)
    {
       z=z/10;
       c++;
    }
	while(n>0)
    {
        r=n%10;
        a=a+pow(r,c);
        n=n/10;
    }
    if(a==t)
        printf("\nThe number is armstrong\n");
    else printf("\nThe number is not armstrong\n");
    return 0;
}
