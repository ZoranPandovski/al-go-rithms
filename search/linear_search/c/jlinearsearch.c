#include<stdio.h>
void main()
{
    int i,element,n,c=0;
	
	printf("Enter no. of Elements in array: ");
	scanf("%d",&n); 
    int array[n];
	printf("\nEnter array elements \n");
    for(i=0; i<n; i++)
        scanf("%d",&array[i]);

	printf("Enter element to search: ");
	scanf("%d",&element);
    for(i=0; i<n; i++)
    {
        if(array[i]==element)
        {
            c=1;
            break;
        }
    }
    if(i<n)
        printf("Element %d found at index %d",element,i+1); 
    else
        printf("Element not found");
}
