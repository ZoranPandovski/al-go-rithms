// Subfactorial

// This logs the number of permutations that can be made from our number to the console.

const number = 4

const factorial = n => n === 1 ? 1 : n * factorial(n - 1)

const subfactorial = Math.round(factorial(number) / Math.E)

console.log(subfactorial)
