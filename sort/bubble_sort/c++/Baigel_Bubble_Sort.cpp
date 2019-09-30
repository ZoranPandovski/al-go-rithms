// INCLUDE LIBRARIES
#include<iostream>

// FUNCTIONS
void bubble_sort (int*a, int n) {  // Sorts the array using the bubble sort algorithm
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}


int main()
{
    // Recieve User Inputs
    int n;
    std::cout << "Enter array size: " << std::endl;
    std::cin >> n;
    int arr[n];
    std::cout << "Enter elements in array: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // Sort the array
    bubble_sort(arr,n);
    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }
}
