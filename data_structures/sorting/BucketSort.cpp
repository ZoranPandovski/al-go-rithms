/*We use bucket sort if the input values are 
distributed uniformly over a given range. 
Mostly, the bucket sort is used to sort floating-point 
numbers in the range [0,1].*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(float arr[], int n)
{
    vector<float> b[n];
 
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; 
        b[bi].push_back(arr[i]);
    }
 
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
 
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
 
int main()
{
    cout << "Enter the total number of elements in the array \n";
    int n; 
    cin >>n ;
    cout << "Enter the elements of the array \n";
    float arr[];
    
     for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bucketSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

}

/*
Input :

Enter the number of elements in the array 
5  
Enter the elements of the array 
12 34 54 2 3

Output :

Array before sorting: 
12 34 54 2 3 
Array after sorting: 
2 3 12 34 54 

*/