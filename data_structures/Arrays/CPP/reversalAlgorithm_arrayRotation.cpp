#include <bits/stdc++.h> 
using namespace std; 
void rvereseArray(int arr[], int start, int end) 
{ 
    while (start < end) 
    { 
        int temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    } 
}
void Rotate(int arr[], int d, int n) 
{ 
    rvereseArray(arr, 0, d-1); 
    rvereseArray(arr, d, n-1); 
    rvereseArray(arr, 0, n-1); 
}
int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int d = 2;
    Rotate(arr, d, n); 
    for (int i = 0; i < n; i++) 
    cout << arr[i] << " ";  
      
    return 0; 
} 
