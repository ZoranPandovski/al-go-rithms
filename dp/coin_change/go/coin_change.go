package coins

// CountWays uses DP to count the number of ways a given quantity n can be
// exchanged into coins of the denominations specified by s
func CountWays(n int, s []int) int {
	dp := make([]int, n+1)
	dp[0] = 1

	for i := 0; i < len(s); i++ {
		for j := s[i]; j <= n; j++ {
			dp[j] += dp[j-s[i]]
		}
	}

	return dp[n]
}
