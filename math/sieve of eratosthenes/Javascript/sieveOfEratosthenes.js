// In mathematics, the sieve of Eratosthenes is an ancient algorithm for
// finding all prime numbers up to any given limit.

// One of a number of prime number sieves, it is one of the most efficient
// ways to find all of the smaller primes. It may be used to find primes
// in arithmetic progressions.

// [from, from+1, from+2, from+3, .... to]
const range = (from, to) => {
  const x = [];
  while(from <= to) {
    x.push(from++);
  }
  return x;
}

const markMultiplesAsNull = ( prime, list ) => list.map(s => s % prime == 0 ? null : s);

const lowestRemainingCandidate = list => list.find(x => x != null);

const sieve = n => {
  if (n < 2) return [];

  let list = range(2, n);
  let result = [];
  let p = 2;

  while (p) {
    list = markMultiplesAsNull(p, list);
    result.push(p);
    p = lowestRemainingCandidate(list);
  }
  return result;
}

module.exports = sieve;
