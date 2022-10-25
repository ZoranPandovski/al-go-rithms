#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n)
{
    if(n==0)
    return ;

    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
    }

    bubble_sort(arr,n-1);
    
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    bubble_sort(arr,n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
    
    
}