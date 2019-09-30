#include<iostream>
using namespace std;
void swaps(int *x, int *y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}
void quickSort(int arr[], int l, int r)
{
    int i = l, j = r;
    int pivot = arr[(l+r)/2];
    while(i <= j)
    {
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <= j)
        {
            swaps(&arr[i],&arr[j]);
            i++;
            j--;
        }
    }
    if(l < j)
        quickSort(arr, l, j);
    if(i < r)
        quickSort(arr, i, r);
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int l = 0, r = n-1;
    quickSort(arr, l, r);
    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;;
    }
    return 0;
}
