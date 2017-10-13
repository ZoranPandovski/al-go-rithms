function fibonacci(n) {
	var fib = [1, 1];
	
	for (i = 2; i < n; i++) {
        fib.push(fib[i - 1] + fib[i - 2]);
    }

	return fib;
}

for (i = 1; i < 10; i++) {
    console.log(fibonacci(i));
}