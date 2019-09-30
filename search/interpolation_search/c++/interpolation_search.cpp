#include <iostream>

// C++ implementation of interpolation search
// Pass a sorted integer array, length of the array, and value of the target
// Returns index of the target if it is found, otherwise returns -1
int interpolationSearch(int* arr, int length, int target)
{
	// Find indices of first and last elements
	int low = 0, high = length - 1;

	// Loop until the target is found or it is determined that the target cannot exist in the array
	while (low <= high && target >= arr[low] && target <= arr[high])
	{
		// Interpolate a position
		int pos = low + ( (target-arr[low]) * (high-low) / (arr[high]-arr[low]) );

		// Check if position of target is found yet
		if (arr[pos] == target)
			return pos;

		// Otherwise, determine if target is above or below the interpolated position and adjust indices accordingly
		if (arr[pos] > target)
			high = pos - 1;
		else
			low = pos + 1;
	}
	return -1;
}


// Driver, searching for 35 as an example
int main()
{
	int arr[14] = {1, 3, 7, 12, 14, 19, 23, 26, 30, 34, 35, 39, 46, 53};
	int length = sizeof(arr)/sizeof(int);
	int target = 35; // Feel free to change this value

	std::cout << interpolationSearch(arr, length, target);
	return 0;
}


