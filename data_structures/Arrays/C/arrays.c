#include <stdio.h>
#include <stdlib.h>

void mainchoices()
{
	printf("\n\nAvailable choices are.\n\n");
	printf("1: \tTo change the value of the array.\n");
	printf("2: \tTo delete an element from the array.\n");
	printf("3: \tTo search for an element in the array\n");
	printf("4: \tTo print the array.\n");
	printf("5: \tTo print the size of the array\n");
	printf("-1: \tTo quit.\n\n");
}

void printfun(int *a,int n)
{
	printf("\n\nThe array is\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int search(int *a,int v,int n)
{
	int i=0;
	while(i<n)
	{
		if(a[i]==v) break;
		else i++;
	}

	return i;
}


void changechoices()
{
	printf("\n\nYou have following choices.\n\n");
	printf("1: \tTo change the value by index.\n" );
	printf("2: \tTo replace a value with a new value.\n\n");
}

void deletechoices()
{
	printf("\n\nYou have following choices\n\n\n");
	printf("1: \tTo delete any index no.\n");
	printf("2: \tTo delete any particular element.\n\n");
}

void updateByIndex(int *a,int index,int val)
{
	a[index]=val;
}

int deleteindex(int *a,int in,int n)
{
	for(int i=in;i<n-1;i++)
	{
		a[in]=a[in+1];
	}
	n--;
	return n;
}

int main()
{
	int n;
	printf("Enter the total no. of elements in the array.\n");
	scanf("%d",&n);
	int *a = (int *)malloc(sizeof(int) * n);
	printf("Enter the elements of the array.\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	mainchoices();

	int ch;
	scanf("%d",&ch);
	while(ch!=-1)
	{
		if(ch==1)
		{
			changechoices();
			int chch;
			scanf("%d",&chch);
			if(chch==1)
			{
				printf("\nEnter the index no. Remember that indexing starts from 0 in the array.\n\n");
				int ind,value;
				scanf("%d",&ind);
				if(ind<n && ind>=0)
				{
					printf("\nEnter the new value.\n");
					scanf("%d",&value);
					updateByIndex(a,ind,value);
					printf("Updated the value of index no %d to %d\n",ind,value);
				}
				else
				{
					printf("This index does not exist. Please choose an index between 0 to %d both inclusive.\n",n-1);
					mainchoices();
				}
			}

			else if(chch==2)
			{
				printf("\nEnter the old value followed by the new value.\n\n");
				int oldv,newv;
				scanf("%d%d",&oldv,&newv);
				int in=search(a,oldv,n);
				if(in<n)
				{
					a[n]=newv;
					printf("Updated value at the ind no. %d to %d.\n",in,newv);
				}
				else
				{
					printf("This value is not present in the array.\n");
					mainchoices();
				}
			}

			else
			{
				printf("\nYour choice doesn't match any of the available options\n");
				mainchoices();
			}
		}

		else if(ch==2)
		{
			deletechoices();
			int chdel;
			scanf("%d",&chdel);
			if(chdel==1)
			{
				int ind;
				printf("\nEnter the index to be deleted.Remember that indexing starts from 0.\n");
				scanf("%d",&ind);
				if(ind<n)
				{
					n=deleteindex(a,ind,n);
					printf("\n\nDeleted index no %d. New size of the array is %d\n",ind,n);
				}
				else
				{
					printf("\n%d index is out of the array size.\n",ind);
					mainchoices();
				}
			}

			else if(chdel==2)
			{
				printf("Enter the element value to be deleted.\n");
				int del;
				scanf("%d",&del);
				int ind=search(a,del,n);
				if(ind<n)
				{
					n=deleteindex(a,ind,n);
					printf("\nDeleted element %d. New size of the array is %d\n",del,n);
				}
				else
				{
					printf("\n%d is not present in the array, hence can't be deleted.\n",del);
				}
			}

		}

		else if(ch==3)
		{
			printf("Enter the value of the elem] to be searched in the array.\n");
			int val;
			scanf("%d",&val);
			int fo=search(a,val,n);
			if(fo<n)
			{
				printf("%d is present at the index %d.\n",val,fo);
			}
			else
			{
				printf("%d is not present in the array\n",val);
			}
		}

		else if(ch==4)
		{
			printfun(a,n);
		}

		else if(ch==5)
		{
			printf("size of the array is %d\n",n);
		}

		else
		{
			printf("None of the choices you eneterd matches the given choices.\n");
			mainchoices();
		}
		mainchoices();
		scanf("%d",&ch);
	}

}
