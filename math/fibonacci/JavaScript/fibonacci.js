/**
 * Finds the series of n numbers in which each
 * number is the sum of the two preceding numbers.
 * @param {integer} n The number of iterations of Fibonacci
 */
function fibonacci(n) {
    // Define base case
	var fib = [1, 1];
    
    // Iterate through using the sum of the last two values
	for (i = 2; i < n; i++) {
        fib.push(fib[i - 1] + fib[i - 2]);
    }

	return fib;
}

for (i = 1; i < 10; i++) {
    console.log(fibonacci(i));
}