// duplicates in the given array
#include <bits/stdc++.h>
using namespace std;
 
// function to find and print duplicates
void printDuplicates(int arr[], int n)
{
    // unordered_map to store frequencies
    unordered_map<int, int> freq;
    for (int i=0; i<n; i++)
        freq[arr[i]]++;
 
    bool dup = false;
    unordered_map<int, int>:: iterator itr;
    for (itr=freq.begin(); itr!=freq.end(); itr++)
    {
        // if frequency is more than 1
        // print the element
        if (itr->second > 1)
        {
            cout << itr->first << " ";
            dup = true;
        }
    }
 
    // no duplicates present
    if (dup == false)
        cout << "No duplicates present";
}
int main()
{int n=0;
    cout <<"Enter the number of element  ";
    cin >>n;
    int arr[n];
    cout <<"Enter the elements  ";
    for(int i=0;i<n;i++)cin>>arr[i];
    printDuplicates(arr, n);
    return 0;
}