// Java program to sort an array of 0, 1 and 2

/* 
Follow the steps below to solve the given problem:

1.) Keep three indices low = 1, mid = 1, and high = N and there are four ranges, 1 to low (the range containing 0), low to mid (the range containing 1), mid to high (the range containing unknown elements) and high to N (the range containing 2).
2.) Traverse the array from start to end and mid is less than high. (Loop counter is i)
3.) If the element is 0 then swap the element with the element at index low and update low = low + 1 and mid = mid + 1
4.) If the element is 1 then update mid = mid + 1
5.) If the element is 2 then swap the element with the element at index high and update high = high – 1 and update i = i – 1. As the swapped element is not processed
6.) Print the array.
*/

import java.util.Scanner;

public class Dutch_National_Flag {
	static void sort012(int a[], int arr_size)
	{
		int low = 0;
		int high = arr_size - 1;
		int mid = 0, temp = 0;

		while (mid <= high) {
			switch (a[mid]) {
				// If the element is 0
			case 0: {
				temp = a[low];
				a[low] = a[mid];
				a[mid] = temp;
				low++;
				mid++;
				break;
			}
				// If the element is 1
			case 1:
				mid++;
				break;
				// If the element is 2
			case 2: {
				temp = a[mid];
				a[mid] = a[high];
				a[high] = temp;
				high--;
				break;
			}
			}
		}
	}

	/* function to print array arr[] */
	static void printArray(int arr[], int arr_size)
	{
		int i;
		for (i = 0; i < arr_size; i++)
			System.out.print(arr[i] + " ");
		System.out.println("");
	}

	public static void main(String[] args)
	{
	    Scanner sc = new Scanner(System.in);
	    int n;
	    System.out.println("Enter the size of the Array");
	    n = sc.nextInt();
		int arr[];
		System.out.println("Enter the Array values");
		arr = new int[n];
	    for (int i = 0; i < n; i++)
        {
            arr[i] = sc.nextInt();
        }
        System.out.println("Sorted Array : ");
		sort012(arr, n);
		printArray(arr, n);
	}
}
