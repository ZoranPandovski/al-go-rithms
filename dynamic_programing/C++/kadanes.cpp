/**
 * Our task is to take length of array and then the whole array as input from
 * the user and then calculate the maximum contiguous subarray sum for the
 * input array, using the kadane's algorithm.
 *
 * There can be a case that all the elements in the input array are negative.
 * In that case, the least value among all elements is the maximum sum with
 * subarray length = 1.
 */

#include <climits>  // for INT_MIN value
#include <iostream> // for IO operations
using namespace std;

/**
 * max_suarray_sum function calculates the maximum contiguous sum for the given array.
 */
int max_subarray_sum(int arr[], int length)
{
    int current_max = INT_MIN, current_sum = 0;
    for (int i = 0; i < length; i++)
    {
        current_sum = current_sum + arr[i];
        if (current_max < current_sum)
        {
            current_max = current_sum;
        }

        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }
    return current_max;
}

/**
* example test cases
* {
*    arr = {1, 2, 3, 4}
*    maximum contiguos subarray sum = 1 + 2 + 3 + 4 = 10
*    arr1 = {-1, -2, -4, -6, 7}
*    maximum contiguos subarray sum = 7
*    arr1 = {-1, -2, -4, -6, -7}
*    maximum contiguos subarray sum = -1
* }
*/

// main function
int main()
{
    // code for accepting array from user starts

    int n; // variable for length of input array
    cout << "Enter length of the array: ";
    cin >> n;
    int arr[n]; // array to store the input array

    for (int i = 0; i < n; i++) //taking elements of the array
    {

        {
            cin >> arr[i];
        }
    }
    // code for accepting array from user ends
    int max_sum = max_subarray_sum(arr, n); // max_sum stores the maximum contiguous subarray sum
    cout << "Maximum contiguous sum for this array is : " << max_sum << endl;

    return 0;
}
