#include<iostream>
using namespace std;
void split(int arr[],int n,int k)
{
    int t=0,p=0,left[n],right[n];
    for(int i=0;i<k;i++)
    {
        left[i]=arr[i];
    }
    for(int j=k;j<n;j++)
    {
        right[t]=arr[j];
        t++;
    }
    for(int i=0;i<t;i++)
    {
        arr[i]=right[i];
    }

    for(int i=t;i<n;i++)
    {
        arr[i]=left[p];
        p++;

    }
    cout<<"\nRESULTED ARRAY\n";
    for(int j=0;j<n;j++)
    {
        cout<<arr[j]<<" ";
    }
}
int main()
{
    int arr[100];
    int n,k;
    cout<<"\nenter no. of elements\n";
    cin>>n;
    cout<<"\nEnter the array\t";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"\nenter the position";
    cin>>k;
    split(arr,n,k);
}
