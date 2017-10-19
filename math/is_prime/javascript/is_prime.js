(function(){
"use strict"

/**
 * isPrime in Javascript
 * @param {int} n Integer to test for primality
 * @return {Boolean} True if prime number
 *
 * Uses the simple algorithm to test for primality described on this Wikipedia page:
 * https://en.wikipedia.org/wiki/Primality_test#Pseudocode
 * Is not efficient for very large prime numbers
 */

const isPrime = (n) => {
    if (n <= 1) return false;
    else if (n <= 3) return true;
    else if (n % 2 === 0 || n % 3 === 0) return false

    let i = 5
    while (i * i <= n) {
      if (n % i === 0 || n % (i + 2) === 0) {
        return false;
      }
      i = i + 6;
    }
    return true;
}

module.exports = isPrime;
})();
