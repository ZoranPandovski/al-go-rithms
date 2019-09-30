def lis(a):
	dp = [1] * len(a)
	for i in range(len(a)):
		for j in range(i):
			if a[j] < a[i]:
				dp[i] = max(dp[i], dp[j] + 1)
	return max(dp)

n = int(input("Enter number of elements: "))
a = input().split(' ')
for i in range(len(a)):
	a[i] = int(a[i])
print(lis(a))