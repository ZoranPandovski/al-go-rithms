#include <stdio.h> 
int binarySearch(int arr[], int l, int r, int x) 
{ 
	if (r >= l) 
	{ 
		int mid = l + (r - l) / 2; 
		if (arr[mid] == x) 
			return mid; 
		if (arr[mid] > x) 
			return binarySearch(arr, l, mid - 1, x); 
		return binarySearch(arr, mid + 1, r, x); 
	} 
	return -1; 
} 

int main(void) 
{ 
	int n;
	printf("\n Enter the size");
	scanf("%d", &n);
	int arr[n];
	printf("\n enter the array elements");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);	
	} 
	int x;
	printf("\n enter the value to be searched");
	scanf("%d",&x);
	int result = binarySearch(arr, 0, n - 1, x); 
	if(result == -1) 
	{
		printf("Element is not present in array");
	}
	else
	{
		printf("Element is present at index %d",result);
	}
	return 0; 
} 

