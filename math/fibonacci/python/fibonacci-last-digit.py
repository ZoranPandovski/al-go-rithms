# The fibonacci series grows very fast by each successive term.
# This program can calculate the last digit of very large terms of the fibonacci series by using the property of pisano periods.

# We use the following definition for fibonacci: 0th term - 0, 1st term - 1, 2nd term - 1, 3rd term - 2, and so on

# create a global list to store the fibonacci series
f = [0, 1]

def pisano_period(m):
    if m < 2:
        return 1
    mods = [0 % m, 1 % m]
    i = 1
    while True:
        f.append(f[i-1] + f[i])
        i += 1
        mods.append(f[i] % m)
        if mods[-1] == 1 and mods[-2] == 0:
            return (len(mods) - 2)

def fib_fast(n):
    i = len(f)-1
    while i < n:
        f.append(f[i-1] + f[i])
        i+=1
    return f[n]

# the function that actually returns the last digit of the required term
def fib_last(n):
    n %= pisano_period(10)
    return (fib_fast(n) % 10)

if __name__ == '__main__':
    n = int(input())    # we will calculate the last digit of the nth term
    print(fib_last(n))
