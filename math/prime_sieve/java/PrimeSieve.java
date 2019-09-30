public class PrimeSieve {
    public int getPrimes(int number) {

        // create a boolean array at the length of our input number,
        // so each number has a boolean associated with it
        boolean[] isPrime = new boolean[number + 1];

        // set all booleans in the array to true (except for 1/0)
        for(int i = 2; i <= number; i++) {
            isPrime[i] = true;
        }


        // now we're going to go through all the numbers and check for primes.
        // the logic behind this is that we start with 2, and all factors of 2 are marked as not prime
        // then we would go to the next 'true' (or prime number)-- that number is kept prime, and all it's factors are not
        // the next prime number is kept as prime, all it's factors are not, and we keep going through this cycle till we hit the end.
        for(int j = 2; j*j <= number; j++) {
            if(isPrime[j]) { // if the boolean is true (or if the number is marked as prime)
                for(int jFactors = j; jFactors * j <= number; jFactors++){
                    isPrime[jFactors * j] = false;
                }
            }
        }

        // now that all the numbers have been marked, we just have to count up the remaining primes (false) in the array
        int totalPrimes = 0;
        for(int countPrimeNumber = 2; countPrimeNumber <= number; countPrimeNumber++) {
            if(isPrime[countPrimeNumber]) {
                totalPrimes++;
            }
        }

        // return the total number of primes
        return totalPrimes;
    }
}
