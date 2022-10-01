// code to implement merge sort
// the algorithm uses a divide and conquer technique 
// it divides the array in hand into 2 parts, sorts them first by recursivley calling the same sort function and then merges(thats whr the algo got its name) the 2 sorted array
// Time complexity: O(nlogn)

#include<bits/stdc++.h>
using namespace std;
int c[100001];
int arr[100001];

// this function merges 2 sorted array provided
void merge_(int a[], int l, int mid, int r)
{
   int i=l; int j=mid+1; int k=0;

   // merging the 2 arrays in ascending order
   while(i<=mid && j<= r)
   {
       if(a[i]<a[j])
            c[k++]=a[i++];
       else
            c[k++]=a[j++];
   }

   // if some elements are left in first array, they need to be copied directly
   while(i<=mid)
   {
       c[k++]=a[i++];
   }

   // if some elements are left in second array, they need to be copied directly
   while(j<=r)
   {
       c[k++]=a[j++];
   }

   // copying back the sorted array to the original array
   for(i=0;i<k;i++)
   {
       a[l+i]=c[i];
   }
}

// this function sorts the given array by using merge sort
void merge_sort(int a[],int l,int r)
{

   // if l>r, meaning an invalid partition is encountered, return
   if(l>=r)
        return;

  // divide the array into 2 halves and sort both of them
  int mid= (l+r)/2;
  merge_sort(a, l, mid);
  merge_sort(a, mid+1, r);

  // then merge them using the merge function to get the combined sorted array
  merge_(a,l,mid,r);
}

int main()
{
    int n,i;
    cin>>n;

    // input the array to be sorted
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    // call merge sort on it
   merge_sort(arr, 0, n-1);

   // print the sorted array
   for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

/*
test cases
 TC 1:
 n= 5, arr= [4, 3, 1, 5, 2]
 output = [1, 2, 3, 4, 5]
 */
