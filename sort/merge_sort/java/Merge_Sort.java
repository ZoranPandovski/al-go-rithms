import java.util.Scanner;

/**
 * 
 * @author Tarannum Ara
 *
 */

public class MergeSort {

	void merge(int a[], int beg, int mid, int end)    
	{    
	    int i, j, k;  
	    int n1 = mid - beg + 1;    
	    int n2 = end - mid;    

	    int LeftArray[] = new int[n1];
	    int RightArray[] = new int[n2];

	    for (i = 0; i < n1; i++)    
	    LeftArray[i] = a[beg + i];    
	    for (j = 0; j < n2; j++)    
	    RightArray[j] = a[mid + 1 + j];     

	    i = 0; /* index of first sub-array */  
	    j = 0; /* index of second sub-array */   
	    k = beg;  /* index of merged sub-array */  

	    while (i < n1 && j < n2)    
	    {    
	        if(LeftArray[i] <= RightArray[j])    
	        {    
	            a[k] = LeftArray[i];    
	            i++;    
	        }    
	        else    
	        {    
	            a[k] = RightArray[j];    
	            j++;    
	        }    
	        k++;    
	    }    
	    while (i<n1)    
	    {    
	        a[k] = LeftArray[i];    
	        i++;    
	        k++;    
	    }    

	    while (j<n2)    
	    {    
	        a[k] = RightArray[j];    
	        j++;    
	        k++;    
	    }    
	}

	void sort(int arr[], int l, int r)
    {
        if (l < r) {
            // Find the mid point
            int m =l+ (r-l)/2;

            // Sort first and second halves
            sort(arr, l, m);
            sort(arr, m + 1, r);

            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    }

	void printArray(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

	public static void main(String[] args) {
		    Scanner sc = new Scanner(System.in);
		    System.out.println("number of array elements: ");
		    int n = sc.nextInt();
		    int []arr = new int[n];
		    for(int i=0; i<n; i++) {
		    	arr[i]=sc.nextInt();
		    }

		    MergeSort Obj = new MergeSort();
		    Obj.sort(arr,0,n-1);
		    Obj.printArray(arr);
		    sc.close();
	}
}
