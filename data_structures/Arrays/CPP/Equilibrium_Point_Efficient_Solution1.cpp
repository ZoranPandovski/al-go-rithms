#include<bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY: - O(n)
//SPACE COMLEXITY: - 0(n)

int equilibrium_point(int [], int);

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
    cout << "The equilibrium point in the array is: ";
    if(equilibrium_point(ar, n) >= 0)
        cout << equilibrium_point(ar, n);
    else
        cout << "Not Found";
}

int equilibrium_point(int arr[], int size)
{
    int prefix_sum[size], suffix_sum[size];
    prefix_sum[0] = arr[0];
    suffix_sum[size-1] = arr[size-1];
    for(int i = 1; i<size; i++)
    {
        prefix_sum[i] = arr[i] + prefix_sum[i-1];
    }
    for(int i = size-2; i>=0; i--)
    {
        suffix_sum[i] = arr[i] + suffix_sum[i+1];
    }
    for(int i = 0; i<size; i++)
    {
        if(prefix_sum[i-1] == suffix_sum[i+1])
            return i;
    }
    return -1;
}