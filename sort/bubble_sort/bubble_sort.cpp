//PROGRAM TO SORT AN ARRAY USING BUBBLE SORT METHOD

#include<iostream>   // INCLUDING LIBRARIES
using namespace std;

//FUNCTION TO SORT ARRAY
void bubble_sort(int arr[], int sz)
{
    for(int i=0;i<sz-1;i++)
    {
        for(int j=0;j<sz-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

// MAIN FUNCION
int main()
{
    int sz;
    cout<<"Enter the size of Array : ";
    cin>>sz;

    // TAKING INPUT FROM USER
    int arr[sz];
    cout<<"\nEnter Elements : ";
    for(int i=0; i<sz;i++)
        cin>>arr[i];
    bubble_sort(arr,sz);        // FUNCTION CALLING
    cout<<"\nSorted Array : ";  // DISPLAY SORTED ARRAY
    for(int i=0;i<sz;i++)
        cout<<" "<<arr[i];
    return 0;
}
