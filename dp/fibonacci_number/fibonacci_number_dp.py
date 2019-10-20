# computes the n_th number of the fibonacci sequence
# with the help of dynamic programming to avoid recursive recomputations
def dyn_fib(n, memo):
    if n < 1:
        return 0
    if n == 1:
        return 1
    if n in memo:
        return memo[n]
    memo[n] = dyn_fib(n-1, memo) + dyn_fib(n-2, memo)
    return memo[n]

def test():
    num = 500
    assert dyn_fib(num, {}) == 139423224561697880139724382870407283950070256587697307264108962948325571622863290691557658876222521294125

if __name__ == "__main__":
    test()
