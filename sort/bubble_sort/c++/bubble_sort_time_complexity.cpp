/* Bubble Sort Algorithm */
/* Time Complexity
        Best Case- O(n)
        Worst Case- O(n^2)
        Avergae Case- O(n^2)
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

void bubblesort(int * , int );

int main()
{
  int n,a[100];
  cout<<"Enter number of elements: "<<endl;
  cin>>n;
  cout<<"Enter list elements: "<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }

  bubblesort(a,n);
  return 0;

}
 void bubblesort(int a[], int n)
 {
   int i,j,temp;
   for(i=0;i<n-1;i++)
    for(j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  cout<<"The sorted elements are: "<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
 }
