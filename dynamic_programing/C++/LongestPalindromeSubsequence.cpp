#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int lps(char *str)
{
    int n = strlen(str);
    int dp[n][n]; // Create a table to store results of subproblems

    // Strings of length 1 are palindrome of length 1
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // Build the table. Note that the lower diagonal values of table are
    // useless and not filled in the process.
    for (int cl = 2; cl <= n; cl++)
    {
        for (int i = 0; i < n - cl + 1; i++)
        {
            int j = i + cl - 1;
            if (str[i] == str[j] && cl == 2)
                dp[i][j] = 2;
            else if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }
    return dp[0][n - 1];
}

int main()
{
    char seq[] = "BABCBAB";
    int n = strlen(seq);
    printf("The length of the LPS is %d", lps(seq));
    return 0;
}