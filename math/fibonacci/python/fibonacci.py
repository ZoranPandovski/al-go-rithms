def fibonacci(n):
	fib = [1, 1]
	
	for i in range(2, n):
		fib.append(fib[i-1] + fib[i-2])

	return fib[-1]


for i in range(1,10):
	print(fibonacci(i))
