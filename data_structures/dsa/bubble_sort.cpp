#include<iostream>
using namespace std;

void bubble(int n, int *arr){
    
    for(int i=0;i<n;i++)//i=2 arr[2]=4
    {s
        for (int j=i+1;j<n;j++)//j=3, arr[3]=2
        {
            if(arr[i]>arr[j])//
            {
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
            
        }
        
    }
    for(int i=0;i<n;i++)
        cout<<arr[i];
}

int main()
{
    int arr[]={1,4,6,2,9,5,8,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubble(n,arr);
}
