import java.util.Scanner;

/**
 * @author avcbcoder last modified @29-Oct-2018 @2:28:45 PM Code Library - TODO
 */

/**
 * <============================== Upper/Lower Bound BinarySearch =================================>
 * 
 * DESCRIPTION of all the methods ------------------------------------------------------------------
 * lowerBound(array,length,searchKey) =>returns index of biggest integer smaller/equal to searchKey-
 * upperBound(array,length,searchKey) =>returns index of smallest integer bigger/equal to searchKey-
 */

/** 
 */
public class LowerUpperBound {
	public static void main(String[] args) throws Exception {
		int[] arr = { 1, 2, 4, 5, 6, 8, 9, 13, 45, 54, 97, 99, 130 };
		while (true) {
			int x = sc.nextInt();
			System.out.println("lower bound :" + lowerBound(arr, arr.length, x));
			System.out.println("upper bound :" + upperBound(arr, arr.length, x));
		}
	}

	// x => returns biggest integer smaller/equal to x
	public static int lowerBound(int[] a, int n, int key) {
		int s = 0, e = n - 1;
		int ans = Integer.MIN_VALUE;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (a[mid] <= key) {
				ans = mid;
				s = mid + 1;
			} else
				e = mid - 1;
		}
		return ans;
	}

	// x => returns smallest integer strictly greater/equal to x
	public static int upperBound(int[] array, int length, int value) {
		int low = 0;
		int high = length;
		while (low < high) {
			final int mid = (low + high) / 2;
			if (value >= array[mid]) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		return low;
	}

	public static Scanner sc = new Scanner(System.in);
}
