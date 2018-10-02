// C++ program to find the longest repeating
// subsequence
#include <iostream>
#include <string>
using namespace std;

// This function mainly returns LCS(str, str)
// with a condition that same characters at
// same index are not considered. 
int findLongestRepeatingSubSeq(string str)
{
	int n = str.length();

	// Create and initialize DP table
	int dp[n+1][n+1];
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			dp[i][j] = 0;

	// Fill dp table (similar to LCS loops)
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			// If characters match and indexes are 
			// not same
			if (str[i-1] == str[j-1] && i != j)
				dp[i][j] = 1 + dp[i-1][j-1];		 
					
			// If characters do not match
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[n][n];
}

// Driver Program
int main()
{
	string str = "aabb";
	cout << "The length of the largest subsequence that"
			" repeats itself is : "
		<< findLongestRepeatingSubSeq(str);
	return 0;
}

