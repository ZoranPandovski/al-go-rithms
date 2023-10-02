def fun(n):
    if n==0:
        return 0
    r1 = n & (-n)
    next = n + r1
    r = (n ^ next) / r1
    r >>= 2
    ans = next | r
    return ans