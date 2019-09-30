#include<stdio.h>

void main()
{
    int a[]={1,2,3,4,5,6,7};
    int i,n,flag=0;

    printf("Enter a value for searching : ");
    scanf("%d",&n);

    for(i=0;i<7;i++)
    {
        if(n==i)
        {
            flag=1;
        }
    }

    if(flag==1)
    {
        printf("\nEntered number is found");
    }
    else
    {
        printf("\nEntered number is not found");
    }

}

