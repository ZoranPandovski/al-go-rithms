def longest_common_subsequence(x, y):
    n = len(x)
    m = len(y)

    c = [[0 for x in range(m + 1)] for y in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if x[i - 1] == y[j - 1]:
                c[i][j] = c[i-1][j-1] + 1
            else:
                c[i][j] = max(c[i-1][j], c[i][j-1])
    return c


def print_longest_common_subsequence(c, X, Y, i, j):
    if i == 0 or j == 0:
        return
    if X[i - 1] == Y[j - 1]:
        print_longest_common_subsequence(c, X, Y, i-1, j-1)
        print(X[i - 1], end='')
    elif c[i - 1][j] > c[i][j-1]:
        print_longest_common_subsequence(c, X, Y, i-1, j)
    else:
        print_longest_common_subsequence(c, X, Y, i, j-1)



X = "FABCDGH"
Y = "AVBDC"

c = longest_common_subsequence(X, Y)
print('Length:', c[len(string1)][len(string2)])
print_longest_common_subsequence(c, X, Y, len(X), len(Y))
