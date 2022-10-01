//This function returns true if num is prime, else returns false.
const isPrime = (num) => {
    if (num === 1) {
        return false;
    } else {
       for (let i = 2; i <= Math.sqrt(num); i++) {
           if (isPrime(i)) {
                if (num % i === 0) {
                    return false;
                }
           }
       }
       return true;
    }
}

console.log('5 is a prime number: ', isPrime(5));       //5 is prime
console.log('6 is a prime number: ', isPrime(6));       //6 is not prime