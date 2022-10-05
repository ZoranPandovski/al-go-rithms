// Problem : A substring of a string is a subsequence in which all the characters are consecutive.Given two strings,
// we need to find the longest common substring.

// Approach :

// We are creating a 2d dp array corresponding to the dimensions of the array. Now if the characters for a pair of
// i, j are not equal, that show that they can be included in the final answer and hence they are discarded.
// Else, we take a look at dp[i-1][j-1] if the continuity is maintained the we can find a continous equal substring
// or not.

#include <bits/stdc++.h>
using namespace std;

int lcs(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                // looking if just previous characters are also equal or not
                int val = 1 + dp[i - 1][j - 1];
                dp[i][j] = val;
                ans = max(ans, val);
            }
            else
            {
                // not a part of equal substring, hence 0
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    cout << "The Length of Longest Common Substring is " << lcs(s1, s2);
}

// Sample Inputs

// abcjklp
// acjkp

// Corresponding Outputs

// 3