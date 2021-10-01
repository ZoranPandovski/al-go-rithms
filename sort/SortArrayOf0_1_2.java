Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
  
  import java.io.*;
import java.util.*;
class Solution
{
    public static void sort012(int a[], int n)
    {
        // code here 
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high)
        {
            if(a[mid]==0)
            {
                swap(a,low,mid);
                low++;
                mid++;
            }
            else if(a[mid]==1)
            mid++;
            else
            {
                swap(a,high,mid);
                high--;
            }
        }
        
    }
    
    private static void swap(int arr[],int x,int y)
    {
        int temp=arr[x];
        arr[x]=arr[y];
        arr[y]=temp;
    }
}
