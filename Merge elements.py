# Python3 program for the above approach
import sys

# Function to find the total minimum
# cost of merging two consecutive numbers
def mergeTwoNumbers(numbers):

	# Find the size of numbers[]
	n = len(numbers)

	# If array is empty, return 0
	if (len(numbers) == 0):
		return 0
	
	# To store the prefix Sum of
	# numbers array numbers[]
	prefixSum = [0] * (n + 1)

	# Traverse numbers[] to find the
	# prefix sum
	for i in range(1, n + 1):
		prefixSum[i] = (prefixSum[i - 1] +
						numbers[i - 1])
	
	# dp table to memoised the value
	dp = [[0 for i in range(n + 1)]
			for j in range(n + 1)]

	# For single numbers cost is zero
	for i in range(1, n + 1):
		dp[i][i] = 0
	
	# Iterate for length >= 1
	for p in range(2, n + 1):
		for i in range(1, n - p + 2):
			j = i + p - 1

			# Find sum in range [i..j]
			sum = prefixSum[j] - prefixSum[i - 1]

			# Initialise dp[i][j] to _MAX
			dp[i][j] = sys.maxsize

			# Iterate for all possible
			# K to find the minimum cost
			for k in range(i, j):

				# Update the minimum sum
				dp[i][j] = min(dp[i][j],
							(dp[i][k] +
							dp[k + 1][j] + sum))
			
	# Return the final minimum cost
	return dp[1][n]

# Driver Code

# Given set of numbers
a=int(input("Number of elements in the array:-"))
arr1=list(map(int, input("elements of array:-").strip().split()))

# Function call
print(mergeTwoNumbers(arr1))

# This code is contributed by saanthosh24
