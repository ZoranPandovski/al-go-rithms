#include <stdio.h>
#include <conio.h>

//main
void main()
{
    //declaration
    int n,i,j;

    //prompt for input of total number of values
    printf("enter number of values you want to enter");
    scanf("%d",&n);

    //declaration of array in which values are stored
    int a[n];

    //prompt for input of values in the array using for loop
    for(i=0;i<n;i++)
    {
        printf("\nenter %dth value",i);
        scanf("%d",&a[i]);
    }

    //printing the input values
    printf("\nentered values are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }

    //sorting in ascending order
    for (i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                //swaping two numbers
                a[j]=a[j]+a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]=a[j]-a[j+1];

            }
        }
    }

    //printing the sorted values or array
    printf("\nSorted Value In Ascending Order\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

