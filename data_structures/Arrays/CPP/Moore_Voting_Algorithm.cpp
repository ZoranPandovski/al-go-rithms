#include<bits/stdc++.h>
using namespace std;

int moore_voting(int [], int);

int main()
{
    int n, ar[50];
    cout << "Enter the size of the array: ";
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cout << "ar[" << i << "] = ";
        cin >> ar[i];
    }
    cout << "The majority element in the array is: ";
    cout << moore_voting(ar, n);
}

int moore_voting(int arr[], int size)
{
    //Phase 1: - Finds a suitable candidate for the majority element
    int res = 0, count = 1;     //
    for(int i = 1; i<size; i++)    //Traversing the array
    {
        if(arr[res] == arr[i])   //Checking if first element is same as ith element
            count++;     //If yes then incrementing the count by 1
        else
            count--;     //Decrementing the count if ith element is not equal to first element
        if(count==0)     //If at any point the count becomes 0 while decrementing
        {
            res = i;     //Updating the ith element as result since it's not a suitable 
            count = 1;   //candidate for majority. Also resetting the count of majority element
        }
    }

    //Phase 2: - Checks if the candidate selected is actually in majority or not
    count = 0;
    for(int i = 0; i<size; i++)
    {
        if(arr[res] == arr[i])
        
            count++;              //Line 36-44: - Checks if the candidate
    }                             //element is a majority element or not
    if(count <= size/2)
        res = -1;
    return res;
}