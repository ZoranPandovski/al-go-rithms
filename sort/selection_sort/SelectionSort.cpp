#include <bits/stdc++.h>
using namespace std;

//Swap function
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void SelectionSort(int arr[], int n)
{
	int i, j, minIdx;

	for (i = 0; i < n-1; i++)
	{
		minIdx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[minIdx])
			minIdx = j;

		// Swap the minimum element with the first element
		if(minIdx!=i)
			swap(&arr[minIdx], &arr[i]);
	}
}

void display(int arr[], int size)
{
	for (int i=0; i < size; i++)
		cout << arr[i] << " ";
}


int main()
{
	int n;
    cout<<"Enter number of elements :";
    cin>>n;
    int arr[n];
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
  SelectionSort(arr, n);
	cout << "Sorted array:  ";
	display(arr, n);
	return 0;
}
