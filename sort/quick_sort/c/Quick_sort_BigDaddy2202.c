#include<stdio.h>
int partition(int arr[],int start,int end)
{
  int pivot=arr[end];
  int i,j=start;
  for (i = start; i<end; i++) {
    if(arr[i]<=pivot)
    {
      int temp=arr[j];
       arr[j]=arr[i];
      arr[i]=temp;
      j++;

    }
    int temp=arr[j];
   arr[j]=arr[end];
    arr[end]=temp;
    return j;
}
}
void quicksort(int arr[],int start,int end) {

      if(start<end)
      {
          int mid=partition(arr,start,end);
          quicksort(arr,start,mid-1);
          quicksort(arr,mid+1,end);
      }

  }

int main()
{
  int n,i;
  scanf("%d",&n);
  int arr[n];
  for (i = 0; i < n; i++) {
    scanf("%d",&arr[i]);
  }
  quicksort(arr,0,n-1);
  for (i = 0; i < n; i++) {
    printf("%d ",arr[i]);
  }
  return 0;
}
