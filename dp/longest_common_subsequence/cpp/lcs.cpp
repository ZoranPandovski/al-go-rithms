#include <iostream>
#include <string.h>
#include <algorithm>

void LCS(char A[], char B[])
{
	int m = strlen(A);
	int n = strlen(B);
	int D[m + 1][n + 1];

	/* Following steps build D[m+1][n+1] in bottom up fashion. Note 
      that D[i][j] contains length of LCS of A[0..i-1] and B[0..j-1] */
	for (int i = 0; i <= m; ++ i)
		for (int j = 0; j <= n; ++ j)
			if (i == 0 || j == 0)
				D[i][j] = 0;
			else
				if (A[i - 1] == B[j - 1])
					D[i][j] = 1 + D[i - 1][j - 1];
				else
					D[i][j] = std::max(D[i - 1][j], D[i][j - 1]);

	std::cout << "Length of longest common subsequence is " << D[m][n] << "\n";

	// writing the LCS
	int bst = D[m][n];
	// Create a character array to store the LCS string
	char str[bst];

	str[bst --] = 0; // set the terminating character

	for (int i = m - 1, j = n - 1; i >= 0; )
		// If current character in A and B are same, then
        // current character is part of LCS
		if (A[i] == B[j]) {
			str[bst --] = A[i];
			-- i;
			-- j;
		}
		// If not same, then find the larger of two and
        // go in the direction of larger value
		else
			if (D[i][j + 1] < D[i + 1][j])
				-- j;
			else
				-- i;

	std::cout << str << "\n";
}

int main()
{
	char A[] = "ABCDEFGHI";
	char B[] = "BEGIN";

	LCS(A, B);

	return 0;
}