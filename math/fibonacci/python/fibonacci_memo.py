from __future__ import print_function

# Fibonacci with memoization
# Get the number by running fibonacci(n)

def fib(n, memo):
	if n == 0:
		return 0
	if n == 1 or n == 2:
		return 1
	if (n in memo):
		return memo[n]

	memo[n] = fib(n-1, memo) + fib(n-2, memo);
	return memo[n];


def fibonacci(n):
	memo = {0:1, 1:1}
	return fib(n, memo)


# fibonacci(10) = 55
print(fibonacci(10))

# fibonacci(43) = 433494437 
print(fibonacci(43))