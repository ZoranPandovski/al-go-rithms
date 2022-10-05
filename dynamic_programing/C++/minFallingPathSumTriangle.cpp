// Problem : Given a triangle array, return the minimum path sum from top to bottom. For each step, you may move to an
// adjacent number of the row below.More formally, if you are on index i on the current row, you may move to either
// index i or index i + 1 on the next row.

#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (i == 0 and j == 0)
            {
                // very first cell
                dp[i].push_back(triangle[i][j]);
            }
            else if (j == 0)
            {
                // we can jump to this cell by one way(⬇️)
                dp[i].push_back(dp[i - 1][j] + triangle[i][j]);
            }
            else if (j == (triangle[i].size() - 1))
            {
                // we can jump to this cell by one way(↘️)
                dp[i].push_back(dp[i - 1][j - 1] + triangle[i][j]);
            }
            else
            {
                // we can jump to this cell by two ways(⬇️ and ↘️)
                dp[i].push_back(min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j]);
            }
        }
    }
    // returning the minimum out of all calculated sums
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x;
            cin >> x;
            triangle[i].push_back(x);
        }
    }
    cout << minimumTotal(triangle);
}

// Sample Inputs

// Sample Inputs

// Sample Inputs

// 4
// 2
// 3 4
// 6 5 7
// 4 1 8 3

// 1
// -10

// Corresponding Outputs

// 11

// -10