

/* C++ code for linearly search x in arr[].  If x
 is present  then return its  location,  otherwise
 return -1 */
#include<iostream>
using namespace std;
int search(int arr[], int n, int x)                    // function which performs the search
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
         return i;                                    // returns the location of the key if it is present in the array
    return -1;                                        // returns -1 in case the key is not present in the array
}
int main()
{
    cout<<"enter size of array ";
    int n,k;
    cin>>n;                                            // n=size of the array in which the number is to be searched
    int * arr= new int [n];                            // providing size from heap array to the pointer dynamically 
    cout<<"enter elements of array ";
    for(int i=0;i<n;i++)
    cin>>arr[i];                                        // adding elements to the array
    cout<<"enter the element to be searched";
    cin>>k;                                             // number to be searched or the key
    if(search(arr,n,k)==-1)                             // calling function search(arr,n,k)
    cout<<"element not found";
    else
    cout<<"element is present at "<<search(arr,n,k)<<" index";
    return 0;
}


