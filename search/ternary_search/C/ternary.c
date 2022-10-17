#include <stdio.h>
 
// Ternary search algorithm to return the position of
// target `x` in a given array `A` of size `n`
int TernarySearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
 
    while (low <= high)
    {
        int left_mid = low + (high - low) / 3;
        int right_mid = high - (high - low) / 3;
 
        if (arr[left_mid] == x) {
            return left_mid;
        }
        else if (arr[right_mid] == x) {
            return right_mid;
        }
        else if (arr[left_mid] > x) {
            high = left_mid - 1;
        }
        else if (arr[right_mid] < x) {
            low = right_mid + 1;
        }
        else {
            low = left_mid + 1, high = right_mid - 1;
        }
    }
 
    return -1;
}
 
int main(void)
{
    int A[] = { 2, 5, 6, 8, 9, 10 };
    int target = 6;
 
    int n = sizeof(A) / sizeof(A[0]);
    int index = TernarySearch(A, n, target);
 
    if (index != -1) {
        printf("Element found at index %d", index);
    }
    else {
        printf("Element not found in the array");
    }
 
    return 0;
}
