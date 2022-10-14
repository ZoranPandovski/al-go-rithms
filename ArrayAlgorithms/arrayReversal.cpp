#include <bits/stdc++.h>
using namespace std;


//basically we are just swapping the elements from both the ends of the array
//for eg:
/*
 1 2 3 4 5
 -> after first iteration
 5 2 3 4 1
 -> after second iteration
 5 4 3 2 1

//loop ended

*/

void reverse (int arr[],int n)
{
    if(n==0) return;
    for(int i=0;i<=(n-1)/2;i++)
    {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
} //0(n) actually n/2

//another implementation
/*
void reverse (int arr[],int n)
{
  int  low = 0, high = n-1;
  while(low<high)
  {
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
    low++;
    high--;
  }
}
*/

int main()
{
   int arr[] = {};
   reverse(arr,0);
   for(auto it : arr)
   {
    cout<<it<<" ";
   }
   return 0;
}
