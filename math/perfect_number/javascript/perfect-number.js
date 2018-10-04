/**
 * Checks whether the given number is perfect
 * @param {Number} n The number to test
 * @return true if the number is perfect, else false
 */
function isPerfect (n) {
  if (n % 2 === 1) return false // Odd perfect numbers don't exist (probably!)
  let result = 1 // 1 is always a divisor, so start with it already added
  let i = 2 // Start from i = 2 (as 1 is always true)
  // Loop until i <= sqrt of n
  while (i * i <= n) {
    if (n % i === 0) result += i + n / i
    i++
  }
  // If a pefect square, then sqroot of n was added an extra time, so remove
  if (i * i === n) result -= i
  return result === n
}

module.exports = isPerfect;
