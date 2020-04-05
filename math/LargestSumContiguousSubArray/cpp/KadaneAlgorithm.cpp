#include <bits/stdc++.h>
using namespace std;

int kadanes(int arr[],int size)
{
    int max_current=arr[0];
    int max_global=arr[0];

    for(int i=1;i<size;i++)
    {
        if(arr[i]>max_current+arr[i])
        {
          max_current=arr[i];
        }
        else
        {
          max_current=(max_current+arr[i]);
        }

        if(max_current>max_global)
        {
           max_global=max_current;
        }
    }

    return max_global;
}

int main() 
{

	    int size;
	    cin>>size;

	    int arr[size];

	    for(int i=0;i<size;i++)
      {
	      cin>>arr[i]; 
      }  

	    cout<<kadanes(arr,size)<<endl;

	return 0;
}
