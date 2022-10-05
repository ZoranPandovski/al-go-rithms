// Problem : Given an array of ‘N’ positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

#include <bits/stdc++.h>
using namespace std;

// Recursive Approach starts

int maximumNonAdjacentSum(int ind, vector<int> &arr, vector<int> &dp)
{
    if (ind == 0)
    {
        return arr[0];
    }
    else if (ind == 1)
    {
        return max(arr[0], arr[1]);
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    // there can be two cases for an element, either we keep it, so we discard the element adjacent to it, or else we discard the current element so that we can move ahead and make decision for the adjacent element and then return the maximum of both of these choices
    int pick = arr[ind] + maximumNonAdjacentSum(ind - 2, arr, dp);
    int nonPick = maximumNonAdjacentSum(ind - 1, arr, dp);
    return dp[ind] = max(pick, nonPick);
}

int solve(int n, vector<int> &arr)
{
    vector<int> dp(n, -1);
    return maximumNonAdjacentSum(n - 1, arr, dp);
}

// Recursive Approach ends

// Tabulation Approach starts

// int maximumNonAdjacentSum(vector<int> &nums)
// {
//     int n = nums.size();
//     if (n == 1)
//     {
//         return nums[0];
//     }
//     vector<int> v(n, 0);
//     v[0] = nums[0];
//     v[1] = max(nums[0], nums[1]);
//     for (int i = 2; i < n; i++)
//     {
//         v[i] = max(nums[i] + v[i - 2], v[i - 1]);
//     }
//     return v[n - 1];
// }

// Tabulation approach ends

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(n, arr);
}

// Sample Inputs

// 4 2 1 4 9
// 3 1 2 4
// 9 1 2 3 1 3 5 8 1 9

// Corresponding Outputs

// 11
// 5
// 24