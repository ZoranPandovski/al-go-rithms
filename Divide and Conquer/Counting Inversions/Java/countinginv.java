import java.io.*;
import java.util.*;

class countinginv 
{
    static int arr[];
    static long count = 0;

    // Merge sort function 
    public static void split(int[] arr,int l,int r)
    {
        if(l < r)
        {
            int mid = (l+r)/2;

            split(arr,l,mid);
            split(arr,mid+1,r);
            count_splitinv(arr,l,mid,r);
        }
    }

    // Function to count the number of inversions 
    // during the merge process 
    public static void count_splitinv(int[] arr,int l,int mid,int r)
    {
        int n1 = (mid - l) + 1;
        int n2 = (r - (mid + 1)) + 1;

        int b[] = new int[n1];
        int c[] = new int[n2];

        int i = 0;
        while(i != n1)
        {
            b[i] = arr[l + i];
            i++;
        }

        i = 0;
        while(i != n2)
        {
            c[i] = arr[mid + i + 1];
            i++;
        }

        i = 0;
        int j = 0;
        int k = l;

        while(i != n1 && j != n2)
        {
            if(b[i] < c[j])
            {
                arr[k] = b[i];
                i++;  
            }
            else
            {
                count += (n1 - i);
                arr[k] = c[j];
                j++;
            }
            k++;
        }
    }

    //Driver Program
    public static void main(String[] args) throws Exception
    {
        int n = 5;
        int arr[] = {2,3,5,4,1};

        split(arr,0,n-1);

        System.out.println(count);
    }
}