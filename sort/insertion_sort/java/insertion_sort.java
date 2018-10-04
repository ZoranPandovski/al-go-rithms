import java.util.*;

class InsertionSort
{
	void sort(int arr[])
	{
		int n = arr.length;
		for (int i=1; i<n; ++i)
		{
			int key = arr[i];
			int j = i-1;
			while (j>=0 && arr[j] > key)
			{
				arr[j+1] = arr[j];
				j = j-1;
			}
			arr[j+1] = key;
		}
	}

	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i=0; i<n; ++i)
		{
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	public static void main(String args[])
	{        
		Scanner S = new Scanner(System.in);
		System.out.println("Enter the size of your array: ");
		int n = S.nextInt();
		int arr[] = new int[n];
		System.out.println("Enter the elements of the array: ");
		for(int i=0;i<n;i++)
		{
			arr[i] = S.nextInt();
		}
		InsertionSort ob = new InsertionSort();        
		ob.sort(arr);
		System.out.println("The sorted array is:");
		printArray(arr);
	}
} 
