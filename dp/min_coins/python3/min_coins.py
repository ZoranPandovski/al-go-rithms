def coinChange(coins, amount):
    if amount == 0:
        return 0
    if min(coins) > amount:
        return -1
    dp = [-1 for i in range(0, amount + 1)]
    for i in coins:
        if i > len(dp) - 1:
            continue
        dp[i] = 1
        for j in range(i + 1, amount + 1):
            if dp[j - i] == -1:
                continue
            elif dp[j] == -1:
                dp[j] = dp[j - i] + 1
            else:
                dp[j] = min(dp[j], dp[j - i] + 1)
    return dp[amount]


print(coinChange([1, 5, 10, 25, 50], 199))
