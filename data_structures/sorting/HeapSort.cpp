#include <iostream>
using namespace std;


void heapify(int arr[], int N, int i)
{

	int count = i;

	int l = 2 * i + 1;

	int r = 2 * i + 2;

	if (l < N && arr[l] > arr[count])
		count = l;


	if (r < N && arr[r] > arr[count])
		count = r;

	if (count != i) {
		swap(arr[i], arr[count]);

	
		heapify(arr, N, count);
	}
}

void heapSort(int arr[], int N)
{

	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);


	for (int i = N - 1; i > 0; i--) {

		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int N)
{
	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, N);

	cout << "Sorted array is \n";
	printArray(arr, N);
}
