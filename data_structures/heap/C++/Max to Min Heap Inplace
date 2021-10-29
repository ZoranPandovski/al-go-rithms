#include<bits/stdc++.h> 
using namespace std; 
 
void MaxHeapify(int a[], int i, int n) 
{ 
    int l = 2*i+1; 
    int r = 2*i+2; 
    int largest = i; 
    if (l<n && a[l]<a[i]) // > convet to min to max
        largest = l; 
    if (r<n && a[r]<a[largest]) // > convet to min to max
        largest = r; 
    if (largest != i) 
    { 
        swap(a[i], a[largest]); 
        MaxHeapify(a, largest, n); 
    } 
}

void convertMaxHeap(int a[], int n)
{ 
    for (int i = (n-2)/2;i >= 0; i--)
        MaxHeapify(a, i, n); 
} 

int main() 
{ 
    int a[] = {9,4,7,1,-2,6,5};
    int n = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n; ++i)
    cout<<a[i]<<" ";
    cout<<"\n";
    convertMaxHeap(a, n);
    for (int i = 0; i < n; i++)
    cout<<a[i]<<" "; 
    return 0; 
} 
