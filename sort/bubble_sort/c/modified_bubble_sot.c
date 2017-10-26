#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubblesort(int a[],int n)
{
	bool flip=true;
	for(int i=0;i<n-1 && flip==true;i++)
	{
		flip=false;

		for(int j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				flip=true;
				int key=a[j];
				a[j]=a[j+1];
				a[j+1]=key;
			}
	}
}

int main()
{
	int n;
	printf("Enter the no. of elements in the array.\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements of the array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	bubblesort(a,n);

	printf("\n\nArray after bubblesort is.\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n\n\n");
}
