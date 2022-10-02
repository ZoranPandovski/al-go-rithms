/*QuickSort implementation using C++*/
#include <bits/stdc++.h>
using namespace std; 
  
// swap two elements 
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
/* This function takes last element as pivot, places the pivot element at its correct position in sorted array,
and places all smaller than pivot to left of pivot and all greater elements to right of pivot */
int partition (int arr[], int low, int high) 
{ 
    // pivot 
    int pivot = arr[high]; 
    // Index of smaller element and indicates the right position of pivot found
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            // increment index of smaller element
            i++;  
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
//low: Starting index 
//high: Ending index
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  
//print an array
void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
}
  
// main function
int main() 
{ 
    //obtain user inputs
    //number of inputs
    int noOfInputs = 0;
    cout << "Enter number of elements:\t";
    cin >> noOfInputs;

    //create the array and enter elements
    int arr [noOfInputs];
    int element;
    for(int i=0; i<noOfInputs; i++)
    {
        cout << "Enter element:\t";
        cin >> element;
        arr[i]=element;
    }

    //print array
    cout << "Unsorted array:\t";
    printArray(arr, noOfInputs - 1);
    
    quickSort(arr, 0, noOfInputs - 1); 
    cout << "Sorted array: \t"; 
    printArray(arr, noOfInputs - 1); 
    return 0; 
}