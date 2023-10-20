def mergeElements(arr):
    n = len(arr)
    dp = [[0 for _ in range(n)] for _ in range(n)]

    # Fill in the dp table diagonally
    for gap in range(1, n):
        for l in range(n - gap):
            r = l + gap
            total = sum(arr[l:r+1])
            dp[l][r] = float('inf')
            for mid in range(l, r):
                dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid+1][r] + total)

    return dp[0][n-1]

try:
    arr = [int(x) for x in input().split()]
except:
    print("enter a valid list")
    arr = [int(x) for x in input().split()]

print(mergeElements(arr))
   
   