import java.util.*;

class SumSubset
{
	/*
	 * w[] is the set
	 * x[] is the solution vector
	 * v stores the number of solutions
	 * m is the sum limit
	 */
	private static int w[], x[], v, m;

	public static void main(String args[])
	{
		int arraySize = 5, sumLimit = 10, sum=0;
		w = new int[]{1, 2, 9, 8, 5};
		x = new int[]{0, 0, 0, 0, 0};
		m = sumLimit;

		// Sort the given array
		Arrays.sort(w);

		// Calculate max sum of array
		for(int i=0; i<arraySize; i++)
			sum += w[i];

		SumSubset subs = new SumSubset();
		if(sum < m)
			System.out.println("No solution exist");
		else
			subs.sub(0, 0, sum);

		System.out.println(v + " Solutions found.");//return should be given
	}

	/*
	 * Find all the subsets of w[0: n-1] that sum to m.
	 * The value of x[i] is 1 or 0 depending on whether the
	 * weight w[i] is included in thw solution or not.
	 * s is sum of the elements included till that node.
	 * k is the index
	 * r is sum of all the elements that can be included in
	 * the solution.
	 */
	public void sub(int s, int k, int r){
		x[k] = 1;
		if(s + w[k] == m){
			v = v + 1;
			System.out.print("Subset is: ");
			for(int i=0; i<=k; i++){
				if(x[i] == 1)
					System.out.print(w[i] + "  ");
			}
			System.out.println("\n");
		}
		else if(s + w[k] + w[k+1] <= m)
			sub(s + w[k], k + 1, r - w[k]);
		if( (s + r - w[k] >= m) && (s + w[k+1] <= m)){
			x[k] = 0;
			sub(s, k + 1, r - w[k]);
		}
	}
}


/* Test Cases:
 * input-
 * 5
 * 1 2 5 6 8
 * 9
 * output-
 * 1 2 6
 * 1 8
 *
 * input-
 * 5
 * 1 2 5 6 8
 * 100
 * output-
 * No solution exist
 */

/* Reference:
 * Computer Algorithm
 * by Horowitz, Sahni and Rajasekaran
 */
