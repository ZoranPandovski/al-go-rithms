#include<stdio.h>
int main()
{
    int i,j,n;
     printf("size of array - ");
    scanf("%d",&n);

    int a[n];
    int c=0;

    printf("enter array elements \n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    printf("element to search - ");
    scanf("%d",&j);
    for(i=0; i<n; i++)
    {
        if(a[i]==j)
        {
            c=1;
            break;
        }
    }
    if(i<n)
        printf("element found at index %d",i);
    else
        printf("element not found");
}
