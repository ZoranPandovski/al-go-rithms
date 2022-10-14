#include<stdio.h>
void main()
{
    int a[100],n,i,j,flag,num;
    printf("How many elements \n");
    scanf("%d",&n);
    printf("Enter the elements \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the number to be searched \n");
    scanf("%d",&num);
    for(i=0;i<n;i++)
    {
        if(a[i]==num)
        {
            flag=1;
            j=i+1;
        }
    }
    if(flag==1)
        printf("The element %d is found at the position %d",num,j);
    else
        printf("Not found in the given array");
}
