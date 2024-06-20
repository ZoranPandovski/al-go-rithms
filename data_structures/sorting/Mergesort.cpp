#include<iostream>
using namespace std;
void swapping(int &a, int &b) {     
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void mergeSort(int a[], int start, int end) {
    if (end - start == 1) {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid, end);
    int temp[end - start];
    int i = start, j = mid, k = 0;
    while (k < end - start) {
        if (j == end ||  (i < mid && a[i] < a[j])) {
            //Add from 1st half
            temp[k] = a[i];
            ++k;
            ++i;
        } else {
            //Add from 2nd half
            temp[k] = a[j];
            ++k;
            ++j;
        }
    }
    for (int l = 0; l < end - start; ++l) {
        a[start + l] = temp[l];
    }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   mergeSort(arr, 0, n);   
   cout << "Array after Sorting: ";
   display(arr, n);
}
