/*This idea is like the selection sort. 
We repeatedly place the max element at end 
reduce the size of the array.
*/

#include<bits/stdc++.h>
using namespace std;
 
void swap(int arr[], int i)
{
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int Max(int arr[], int n)
{
int m, i;
for (m = 0, i = 0; i < n; ++i)
    if (arr[i] > arr[m])
            m = i;
return m;
}

void pancakeSort(int *arr, int n)
{
    for (int curr = n; curr > 1;
                               --curr)
    {
        int mi = Max(arr, curr);
 
        if (mi != curr-1)
        {
         
            swap(arr, mi);
 
            swap(arr, curr-1);
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout<< arr[i]<<" ";
}

int main()
{ 
    cout << "Enter the total number of elements in the array \n";
    int n; 
    cin >>n ;
    cout << "Enter the elements of the array \n";
    int arr[n];
    
     for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   
    pancakeSort(arr, n);
 
    cout<<"Sorted Array "<<endl;
    printArray(arr, n);
 
}

/*Enter the total number of elements in the array 
7
Enter the elements of the array 
12 2 34 65 4 90 54
Sorted Array 
2 4 12 34 54 65 90 
*/