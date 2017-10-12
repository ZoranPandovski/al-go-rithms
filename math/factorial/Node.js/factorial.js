/**
 * Factorials in Node.js
 *
 * Usage: node factorial [n]
 *
 * Constraints: n must be a positive integer greater than zero
 *
 * Example input: node factorial 5
 * Example output: 120
 */

/**
 * A recursive approach. If n is 1, return n, otherwise multiply n by the factorial of n - 1.
 *
 * factorial(5) would look like this:
 * 0. factorial(5) => 5 is not 1, return 5 * factorial(4)
 * 1. factorial(4) => 4 is not 1, return 4 * factorial(3)
 * 2. factorial(3) => 3 is not 1, return 3 * factorial(2)
 * 3. factorial(2) => 2 is not 1, return 2 * factorial(1)
 * 4. factorial(1) => 1 is 1, return 1
 *
 * This leads to the following calculation:
 * factorial(5) => 5 * 4 * 3 * 2 * 1
 */
const factorial = n => n === 1 ? 1 : n * factorial(n - 1);

console.log(factorial(parseInt(process.argv[2])))
