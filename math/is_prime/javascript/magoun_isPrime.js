/*
    This prime number checker implements the Sieve of Eratosthenes to find all primes below a target value. The function inside isPrime called findPrimes is the implementation of the sieve. The return call of isPrime checks the input against the sieve to determine primality.
    
    Wiki: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    
    It is not efficient for very large numbers.
*/

function isPrime(num) {
    // Makes negative inputs positive... just in case.
  if (num < 0) {num *= -1;}
  
    // Implement the sieve.
  function findPrimes(max) {
    var boolArray = Array(max + 1).fill(true);
    var primeArray = [];
    
    for (let i=2;i<=Math.sqrt(max);i++) {
      if (boolArray[i] === true) {
        for (let j=Math.pow(i,2);j<=max + 1;j+=i) {
          boolArray[j] = false;
        }
      }
    }
    
    for (let i=2;i<=max;i++) {
      if (boolArray[i] === true) {
        primeArray.push(i);
      }
    }
    return primeArray;
  } // findPrimes
  
    // Run the sieve and check the input for primality.
  return findPrimes(num).indexOf(num) != -1;
}