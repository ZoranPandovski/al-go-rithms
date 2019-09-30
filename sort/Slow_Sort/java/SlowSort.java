import java.util.Arrays;

/**
 * created by AlexxRuzza on 7/10/18
 */
public class SlowSort {

    public static void main(String[] args) {
        int[] arrayToBeSorted = new int[]{6, 14, 144, 7, -24, 9, 12, 23, 7, 331, -6, 13, 12, -1};

	slowSort(arrayToBeSorted, 0, arrayToBeSorted.length);
	system.out.println(arrayToBeSorted);
    }

    private static void slowSort(int[] arr,int i, int j) {
	    if(i>=j)
		    return;
	    int m=i+(j-i)/2;
	    int temp;
	    slowSort(arr, i, m);
	    slowSort(arr, m+1, j);
	    if(arr[j]<arr[m])
	    {
		    temp=arr[j];
		    a[j]=a[m];
		    a[m]=temp;
	    }
	    slowSort(arr, i, j-1);
    }

 }

