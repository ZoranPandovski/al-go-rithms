#include <stdio.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)//  Function to implement bubble sort
{
	int i, j;
	for (i = 0; i < n-1; i++)//For number of passes
	{
		for (j = 0; j < n-i-1; j++)// For number of elements
		{
			if (arr[j] > arr[j+1])//For comparing two elements
			{
				swap(&arr[j], &arr[j+1]);//Swapping takes place
			}
		}
	}
}

void printArray(int arr[], int size)//For printing the elements
{
	int i;
	for (i=0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
