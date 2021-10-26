// Username - dhanjay8968
// Binary Search :
// Time Complexity - O(log(n))->Each time we are dividing the search space in half.
// Space Complexity - O(1)->We are not using any extra space.

#include <bits/stdc++.h>
using namespace std;

int binary_search(int array[], int size_of_array, int target)
{
    int low = 0;                  // beginning of the search space
    int high = size_of_array - 1; // end of the search space
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // this is used instead of (low+high)/2 to handle overflow.
        if (array[mid] == target)
        {
            // if the middle element is our target then we return it.
            return mid;
        }
        else if (array[mid] > target)
        {
            // if middle element is greater than target then all the elements after middle would be greater than target as the array is sorted.
            // hence we reject the half after mid.
            high = mid - 1;
        }
        else
        {
            // if middle element is smaller than target then all the elements before middle would be smaller than target as the array is sorted.
            // hence we reject the half before mid.
            low = mid + 1;
        }
    }
    // if target is not found we return -1
    return -1;
}

int main()
{

    int size_of_array = 5;
    int array[size_of_array] = {3, 4, 7, 8, 10};
    cout << binary_search(array, size_of_array, 7) << "\n"; //prints 2
    cout << binary_search(array, size_of_array, 6) "\n";    //prints -1
}