
#include <bits/stdc++.h>
using namespace std;

// Bubble sort
void BubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++){
		for (j = 0; j < n - i - 1; j++){
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

// print an array
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
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
	BubbleSort(arr, n);
	cout << "Sorted array:  ";
	printArray(arr, n);
	return 0;
}

