/**
 * Generator function which iterates through prime numbers less than or equal to the provided max value
 * @param max The max value of the primes being returned
 * @returns {IterableIterator<number>} Iterator over the prime numbers
 */
function* generatePrimes(max = Infinity) {
    const markedNotPrime = { };
    let valueToCheck = 2;
    while (valueToCheck <= max) {
        if (!(valueToCheck in markedNotPrime)) {
            yield valueToCheck;
            markedNotPrime[valueToCheck ** 2] = [ valueToCheck ];
        } else {
            let primes = markedNotPrime[valueToCheck];
            primes.forEach(function(prime) {
                let nextMultipleOfPrime = prime + valueToCheck;
                if (nextMultipleOfPrime in markedNotPrime) {
                    markedNotPrime[nextMultipleOfPrime].push(prime);
                } else {
                    markedNotPrime[nextMultipleOfPrime] = [ prime ];
                }
            });
            delete markedNotPrime[valueToCheck];
        }
        valueToCheck++;
    }
}

// Examples:
console.log(Array.from(generatePrimes(1000))); // Print an array containing primes less than or equal to 1,000
console.log(Array.from(generatePrimes(5000))); // Print an array containing primes less than or equal to 5,000