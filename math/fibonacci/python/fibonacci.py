def fibonacci(n):
	fib = [0, 1]
	
	for i in range(n+1):
		fib.append(fib[-1] + fib[-2])

	return fib[n]


for i in range(0,10):
	print(fibonacci(i))
