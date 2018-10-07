// To Get Maximum Profit by selling wines Either From right or left side from given array 

//of prices of Wine  one by one

// Included Three Solutions

//1.Recursive Approach

//2.TopDown Approach

//3.BottomUp Approach
public class WineProblem {

	public static void main(String[] args) {
		int[] wine = { 2, 3, 5, 1, 4 };
		System.out.println(Wine(wine, 0, wine.length - 1, 1));
		System.out.println(WineTD(wine, 0, wine.length - 1, new int[wine.length][wine.length]));
		System.out.println(WineBU(wine));
	}

	// Approach no1
	public static int Wine(int[] arr, int si, int ei, int yr) {

		if (si > ei) {
			return 0;
		}

		int left = Wine(arr, si + 1, ei, yr + 1) + arr[si] * yr;
		int right = Wine(arr, si, ei - 1, yr + 1) + arr[ei] * yr;

		return Math.max(left, right);

	}

	// Approach no2
	public static int WineTD(int[] arr, int si, int ei, int[][] strg) {

		int yr = arr.length - (ei - si);

		if (si > ei) {
			return 0;
		}

		if (strg[si][ei] != 0) {
			return strg[si][ei];
		}

		int left = WineTD(arr, si + 1, ei, strg) + arr[si] * yr;
		int right = WineTD(arr, si, ei - 1, strg) + arr[ei] * yr;

		int max = Math.max(left, right);

		strg[si][ei] = max;
		return max;

	}

	// Approach no3
	public static int WineBU(int[] arr) {

		int n = arr.length;
		int[][] strg = new int[n][n];
		for (int slide = 0; slide < n; slide++) {

			for (int si = 0; si <= n - slide - 1; si++) {

				int ei = si + slide;
				int yr = n - (ei - si);
				if (si == ei) {
					strg[si][ei] = yr * arr[si];
				} else {
					int sc = strg[si][ei - 1] + arr[ei] * yr;
					int ec = strg[si + 1][ei] + arr[si] * yr;

					strg[si][ei] = Math.max(sc, ec);

				}

			}
		}
		return strg[0][n - 1];
	}

}