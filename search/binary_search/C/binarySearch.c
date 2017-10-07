#include <stdio.h>

int binarySearch(int arr[], int start, int end, int x) {
	if (start <= end) {

		int mid = start + (end - start) / 2;

		if (arr[mid] == x)

			return mid;

		if (arr[mid] > x)
			return binarySearch(arr, start, mid - 1, x);

		return binarySearch(arr, mid + 1, end, x);
	}
	return -1;
}

int main()
{
	int arr[] = { 2, 3, 7, 8, 78, 99, 102, 5555 };
	int x = 9;
	int result = binarySearch(arr, 0, sizeof(arr) / sizeof(arr[0]), x);

	if (result == -1) {
		printf("Element not present");
	}
	else {
		printf("Element found at index %d", result);
	}
}
