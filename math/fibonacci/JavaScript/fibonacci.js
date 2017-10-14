(function() {
    "use strict"

    /**
     * Finds the series of n numbers in which each
     * number is the sum of the two preceding numbers.
     * @param {integer} n The number of iterations of Fibonacci
     */
    function fibonacci(n) {
        if (n == 1) {
            return [ 1 ];
        }

        // Define base cases
        var fib = [ 1, 1 ];
        
        // Iterate through using the sum of the last two values
        for (var i = 2; i < n; i++) {
            fib.push(fib[ i - 1 ] + fib[ i - 2 ]);
        }

        return fib;
    }

    // Tests
    // n = 1
    var expected = [ 1 ].toString();
    var actual = fibonacci(1).toString();
    console.assert(actual === expected);

    // n = 2
    expected = [ 1, 1 ].toString();
    actual = fibonacci(2).toString();
    console.assert(actual === expected);

    // n = 5
    expected = [ 1, 1, 2, 3, 5 ].toString();
    actual = fibonacci(5).toString();
    console.assert(actual === expected);

    // n = 8
    expected = [ 1, 1, 2, 3, 5, 8, 13, 21 ].toString();
    actual = fibonacci(8).toString();
    console.assert(actual === expected);
})();