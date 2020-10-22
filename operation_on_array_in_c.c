#include<stdio.h>
#include<stdlib.h>
main()
{
	printf("\t\t\tOPERATIONS ON ARRAY DATA STRUCTURE");
	printf("\n\n\t1) TRAVERSAL");
	int i,j,arr[30],a,b,c,d,arr2[30],t,x=0;
	printf("\n\nEnter 10 elements for the Array:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nTraversing:\nThe elements of the Array are:\t");
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n-----------------------------------------------------------------------------------------------------------");
	
	printf("\n\n\t2) INSERTION");
	printf("\n\nThe Array is:\t");
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\nEnter the Value to be added: ");
	scanf("%d",&a);
	printf("\nEnter the Position to which %d has to added: ",a);
	scanf("%d",&b);
	for(i=10;i>=b;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[b-1]=a;
	printf("\nInsertion\nThe updated elements are:\t");
	for(i=0;i<11;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n-----------------------------------------------------------------------------------------------------------");
	
	printf("\n\n\t3) DELETION");
	printf("\n\nThe Array is:\t");
	for(i=0;i<11;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\nEnter the Position of the Element to be deleted:");
	scanf("%d",&c);
	for(i=c-1;i<10;i++)
	{
		arr[i]=arr[i+1];
	}
	printf("\nDeletion\nThe updated elements are:\t");
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n-----------------------------------------------------------------------------------------------------------");
	
	printf("\n\n\t4) SEARCH");
	printf("\n\nThe Array is:\t");
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\nEnter the Element to be searched:");
	scanf("%d",&d);
	for(i=0;i<10;i++)
	{
		if(d==arr[i])
		{
			printf("The element %d is at location %d of the array.",d,i+1);
			x=1;
			break;
		}
	}
	if(x!=1)
		{
			printf("The value %d is not present in the array.",d);
		}
	printf("\n-----------------------------------------------------------------------------------------------------------");
	
	printf("\n\n\t5) SORT");
	printf("\n\nEnter 10 elements for the Array in Random Order:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr2[i]);
	}
	printf("\nThe Unsorted Array is:\t");
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr2[i]);
	}
	for (i=1;i<=9;i++)
    {
	    j=i;
		while ( j > 0 && arr2[j-1] > arr2[j])
		{	        
            t=arr2[j];
            arr2[j]=arr2[j-1];
            arr2[j-1]=t;
            j--;
        }
    }
    printf("\nThe Sorted Array is:\t");
	for(i=0;i<10;i++)
	{
		printf("%d\t",arr2[i]);
	}
	printf("\n-----------------------------------------------------------------------------------------------------------");
	
}