

import java.util.Arrays;

public class StartAndEndOfInteger {

	public static void main(String[] args) {

		int[] arr = { 1, 3, 5, 7, 7, 7, 8, 9 };
		System.out.println(Arrays.toString(startAndEndOfInteger(arr, 7)));

	}

	static int[] startAndEndOfInteger(int[] arr, int target) {

		int start = OccuranceOfTarget(arr, target, true);
		int end = OccuranceOfTarget(arr, target, false);

		return new int[] { start, end };
	}

	static int OccuranceOfTarget(int[] arr, int target, boolean isStart) {
		// TODO Auto-generated method stub

		int start = 0, end = arr.length - 1;
		int mid = 0;
		int ans = -1;
		while (start <= end) {

			mid = start + (end - start) / 2;

			if (target > arr[mid])
				start = mid + 1;
			else if (target < arr[mid])
				end = mid - 1;

			else {
				ans = mid;
				if (isStart) {
					end = mid - 1;

				} else {
					start = mid + 1;
				}
			}
		}
		return ans;

		
	}

}
