#include<stdio.h>
void main()
{
    int n,i,p,s,temp:
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {scanf("%d",&a[i]);}
    for(p=0;p<n-1;p++)
    {
        for(s=0;s<n-p-1;s++)
        {
            if(a[s]>a[s+1])
            {
                temp=a[s];
                a[s]=a[s+1];
                a[s+1]=temp;
            }
        }
    }
    printf("Sorted array is\n");
    for(i=0;i<n;i++)
    {printf("%d",a[i]);}
}
