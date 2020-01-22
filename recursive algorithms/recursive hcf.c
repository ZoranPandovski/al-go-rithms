#include <stdio.h>
int hcf(int a,int b,int i)
{
    if(i>b)
    return 0;
    if(a%i==0 && b%i==0)
    return (hcf(a,b,i+1));
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int i=a;
    printf("%d",hcf(a,b,i));
}
