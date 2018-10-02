
import java.io.*;
import java.util.*;

class LRS 
{
	// Function to find the longest repeating subsequence
	static int findLongestRepeatingSubSeq(String str)
	{
		int n = str.length();

		// Create and initialize DP table
		int[][] dp = new int[n+1][n+1];

		// Fill dp table (similar to LCS loops)
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				// If characters match and indexes are not same
				if (str.charAt(i-1) == str.charAt(j-1) && i!=j)
					dp[i][j] = 1 + dp[i-1][j-1];		 
					
				// If characters do not match
				else
					dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j]);
			}
		}
		return dp[n][n];
	}
	
	// driver program to check above function
	public static void main (String[] args) 
	{
		String str = "aabb";
		System.out.println("The length of the largest subsequence that"
			+" repeats itself is : "+findLongestRepeatingSubSeq(str));
	}
}


