

// Importing required libraries
#include <bits/stdc++.h>
 
using namespace std;
 
// Two pointer based solution to find
// if there is a pair in A[0..N-1] with the given sum.
int PairSum(int A[], int N, int X)
{
    // first pointer
    int i = 0;
 
    // second pointer
    int j = N - 1;
 
    while (i < j) {
 
        if (A[i] + A[j] == X)
            return 1;
 
        // If sum of elements at current
        // pointers is less, we move towards
        // higher values by increasing i by one unit
        else if (A[i] + A[j] < X)
            i++;
 
        // If sum of elements at current
        // pointers is more, we move towards
        // lower values by decreasing j by one unit 
        else
            j--;
    }
    return 0;
}
 
// Driver code
int main()
{
    // array declaration
    int arr[] = { 2, 4, 7, 8, 9, 12, 14 };
     
    // value to search
    int val = 17;
     
    // detecting the size of array using pointers 
    int arrSize = *(&arr + 1) - arr;
     
      // two pointer can only be applied if the array is sorted 
      sort(arr, arr+7);
    // calling the function 
    cout << (bool)PairSum(arr, arrSize, val);
 
    return 0;
}

// time complexity of the algorithm is of order n*log(n)
// in naive approach it takes n-squared time to search for the pair
