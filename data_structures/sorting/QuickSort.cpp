#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition(int arr[], int l, int h)
{
	int pivot = arr[h]; 
	int i
		= (l- 1); 
	for (int j = l; j <= h - 1; j++) {
		if (arr[j] < pivot) {
			i++; 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}


void quickSort(int arr[], int l, int h)
{
	if (l < h) {
		
		int pi = partition(arr, l, h);

		
		quickSort(arr, l, pi - 1);
		quickSort(arr, pi + 1, h);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

