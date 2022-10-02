#include <climits>  
#include <iostream> 
using namespace std;

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
int main()
{
    int n; 
    cout << "Enter length of the array: ";
    cin >> n;
    int arr[n]; 

    for (int i = 0; i < n; i++) 
    {
            cin >> arr[i];
    }
    int max_sum = max_subarray_sum(arr, n); 
    cout << "Maximum contiguous sum for this array is : " << max_sum << endl;

    return 0;
}
