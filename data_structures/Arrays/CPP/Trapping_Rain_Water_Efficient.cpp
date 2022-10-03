#include<bits/stdc++.h>
using namespace std;

int getWater(int [], int);

int main()
{
    int n, ar[50];
    cout << "Enter the size of the bars: ";
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cout << "bar[" << i << "] = ";
        cin >> ar[i];
    }
    cout << "The maximum water that can be trapped is: " << getWater(ar, n);
}

int getWater(int arr[], int size)
{
    int res = 0;
    int lmax[size];  //Creating an array of biggest bars at the left side of ith bar
    int rmax[size];  //Creating an array of biggest bars at the right side of ith bar
    lmax[0] = arr[0];     //Because extreme left supports the water
    for(int i = 1; i<size; i++)
    {
        lmax[i] = max(arr[i], lmax[i-1]);  //Need to compare ith bar with min(lmax & rmax)
    }
    rmax[size-1] = arr[size-1];  //Because extreme right supports the water
    for(int i = size-2; i>=0; i--)
    {
        rmax[i] = max(arr[i], rmax[i+1]);  //Need to compare ith bar with min(lmax % rmax) 
    }
    for(int i = 1; i<size-1; i++)  //Because water would be contained between left & right bars
    {
        res += (min(lmax[i], rmax[i]) - arr[i]);  //Amount of water obtained will be difference
    }                                    //of ith bar and the minimum of leftmost & rightmost bar 
    return res;
}