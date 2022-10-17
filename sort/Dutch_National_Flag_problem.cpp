// C++ program to sort an array
// with 0, 1 and 2 in a single pass

#include <bits/stdc++.h>
using namespace std;
 
// Function to sort the input array,
// the array is assumed
// to have values in {0, 1, 2}
void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;
 
    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        switch (a[mid]) {
 
        // If the element is 0
        case 0:
            swap(a[lo++], a[mid++]);
            break;
 
        // If the element is 1 .
        case 1:
            mid++;
            break;
 
        // If the element is 2
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}
 
// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
    // Iterate and print every element
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}
 
int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    sort012(arr, n);
 
    printArray(arr, n);
 
    return 0;
}

/*
    Time Complexity: O(n), Only one traversal of the array is needed.
    Space Complexity: O(1), No extra space is required.
*/

/* 
    Disclaimer: 
    * RoyCoding8 (Me) isn't the original author of this code. The original author is shivesh41kr.
    * I have just updated the decription to account for the simplification of the file name.

    Description: The problem sorts an array containing 0,1 and 2 in a single iteration. (The Dutch national flag problem).

*/