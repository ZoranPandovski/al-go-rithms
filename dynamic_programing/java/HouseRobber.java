/*
  Problem statement: You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint         stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

                     Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

  Test cases:
  
  1.
  Input: nums = [1,2,3,1]
  Output: 4
  Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
  Total amount you can rob = 1 + 3 = 4.
  
  
  2.
  Input: nums = [2,7,9,3,1]
  Output: 12
  Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
  Total amount you can rob = 2 + 9 + 1 = 12.

*/

class Solution {
    int[][] dp;
    int solve(int[] a,int n, int chosen){
        if(n>=a.length) return 0;
        if(dp[n][chosen]!=-1) return dp[n][chosen];
        int ans = 0;
        if(chosen==0){
            ans = Math.max(a[n]+solve(a,n+1,1),solve(a,n+1,0));
        }else{
            ans = solve(a,n+1,0);
        }
        
        
        return dp[n][chosen] = ans;
    }
    public int rob(int[] nums) {
        int n = nums.length;
        dp = new int[n][2];
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j] = -1;
            }
        }
        return Math.max(solve(nums,0,0),solve(nums,0,1));
    }
}
