package ARRAYS;


//When we dont know wether the sorting is in ascending or descending order....
public class AgnosticBinarySearch {
	public static void main(String[] args) {
		int[] arr = {-35, -23, -8, 0, 3, 27, 34, 45, 65, 78, 99};
		int target = 45;
		int[] arr2 = {345, 321, 254, 76, 65, 43, 27, 10, 5, 0, -23, -29};
		int target2 = -29;
		int ans = agnosticBS(arr, target);
		int ans2 = agnosticBS(arr2, target2);
		System.out.println(ans);
		System.out.println(ans2);
	}

	static int agnosticBS(int[] arr, int target) {

		boolean asc = isAsc(arr);

		int start = 0;

		int end = arr.length - 1;

//		int mid= (start+end)/2; --> not a better way as start + end can exceed the range of int


		while (start <= end) {

			int mid = start + (end - start) / 2;

			if (target == arr[mid]) {
				return mid;
			}

			if (asc) {
				if (target > arr[mid]) {
					start = mid + 1;

				} else if (target < arr[mid]) {
					end = mid - 1;

				}
			} else {
				if (target < arr[mid]) {
					start = mid + 1;

				} else if (target > arr[mid]) {
					end = mid - 1;

				}
			}
		}
		return -1;
	}

	static boolean isAsc(int[] arr) {
		return arr[0] < arr[arr.length - 1];
	}
}
