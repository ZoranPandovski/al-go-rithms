/**
 * Find the prime factorization of the provided number.
 * Adapted from https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
 * @param num Number to factor
 * @return {object} Object whose keys are the prime factors of num with values counting the number of times the key goes into num
 */
function primeFactors(num) {
    // Object to hold the prime factors (keys) and the number of times they divide into num (values)
    let pf = { };
    // Print the number of 2s that divide n
    while (num % 2 === 0) {
        pf[2] = pf[2] ? pf[2] + 1 : 1;
        num /= 2;
    }

    // num must be odd at this point.  So we can
    // skip one element (Note i = i + 2)
    for (let i = 3; i <= Math.sqrt(num); i += 2) {
        // While i divides num, count i and divide num
        while (num % i === 0) {
            pf[i] = pf[i] ? pf[i] + 1 : 1;
            num /= i;
        }
    }

    // This condition is to handle the case when
    // num is a prime number greater than 2
    if (num > 2) {
        pf[num] = 1;
    }

    return pf;
}

// Examples:
console.log(primeFactors(36)); // Prints { '2': 2, '3': 2 } (i.e. 36 = 2^2 * 3^2)
console.log(primeFactors(196745)); // Prints { '5': 1, '19': 2, '109': 1 } (i.e. 196745 = 5^1 * 19^2 * 109^1)
