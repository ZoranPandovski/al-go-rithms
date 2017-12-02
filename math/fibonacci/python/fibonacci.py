def fib(n):  # return Fibonacci series up to n from: https://docs.python.org/2/tutorial/controlflow.html
    """Return a list containing the Fibonacci series up to n."""
    result = []
    a, b = 0, 1
    while a < n:
        result.append(a)
        a, b = b, a+b
    return result

def fibonacci(n):
	fib = [0, 1]
	
	for i in range(n+1):
		fib.append(fib[-1] + fib[-2])

	return fib[n]


for i in range(0,10):
	print(fibonacci(i))
