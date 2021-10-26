#include <iostream>
using namespace std;

void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}

void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}

int main()
{
    int arr[10];
    cout<<"Program for Merge Sort"<<endl<<endl;
    cout<<"Enter 10 elements in the array"<<endl;
    for (int i=0; i < 10; i++)
        cin>>arr[i];
    merge_sort(arr, 0, 9);
    cout<<"Sorted array: \n";
    for (int i=0; i <10; i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
    return 0;
}
