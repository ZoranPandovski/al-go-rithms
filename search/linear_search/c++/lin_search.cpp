

/* C++ code for linearly search x in arr[].  If x
 is present  then return its  location,  otherwise
 return -1 */
#include<iostream>
using namespace std;
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
         return i;
    return -1;
}
int main()
{
    cout<<"enter size of array ";
    int n,k;
    cin>>n;
    int * arr= new int [n];
    cout<<"enter elements of array ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"enter the element to be searched";
    cin>>k;
    if(search(arr,n,k)==-1)
    cout<<"element not found";
    else
    cout<<"element is present at "<<search(arr,n,k)<<" index";
    return 0;
}


