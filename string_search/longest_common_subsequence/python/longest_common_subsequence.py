def calculate_lcs_length(a,b):
    a_len = len(a)
    b_len = len(b)
    dp = [[0] * (1 + len(b)) for i in range(1 + len(a))]
    for i in range(1, a_len + 1):
        for j in range(1, b_len + 1):
            if a[i - 1] == b[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j - 1])
    max_length = dp[a_len][b_len]
    return dp, max_length

def recursive_back_track(a, b, dp, i, j):
    if i == 0 or j == 0:
        return ""
    if a[i-1] == b[j-1]:
        return recursive_back_track(a, b, dp, i-1, j-1) + a[i-1]
    else:
        if dp[i-1][j] > dp[i][j-1]:
            return recursive_back_track(a, b, dp, i-1, j)
        else:
            return recursive_back_track(a, b, dp, i, j-1)

def iterative_back_track(a, b, dp, i, j):
    seq = ""
    while(i != 0 and j != 0):
        if a[i-1] == b[j-1]:
            i-=1
            j-=1
            seq += a[i]
        else:
            if dp[i-1][j] > dp[i][j-1]:
                i-=1
            else:
                j-=1
    return seq[::-1]

if __name__ == "__main__":
    a = "anaa"
    b = "banana"
    dp, max_length = calculate_lcs_length(a,b)
    lcs_str = iterative_back_track(a, b, dp, len(a), len(b))
    for i in range(len(a) + 1):
        for j in range(len(b) + 1):
            print(dp[i][j], end=' ')
        print('\n')
    print(lcs_str)
