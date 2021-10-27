#include <stdio.h>
int main()
{
    int n,i;
    long int a[10],sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%ld",&a[i]);
    for(i=0;i<n;i++)
    sum=sum+a[i];
    printf("%ld",sum);
    return 0;
}

/*
Sample Input

5
1000000001 1000000002 1000000003 1000000004 1000000005
Output

5000000015
*/
