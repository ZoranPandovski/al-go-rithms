import java.math.BigInteger;
import java.util.Random;

/**
 * Generates even perfect numbers using the Euclid-Euler Theorem. Uses an implementation of the Miller–Rabin primality test
 * in attempt to speed up checking, but it never got past the 7th number after I let it heat up my CPU for a while.
 * Change the constant to generate perfect numbers based on the given number of primes.
 * 
 * Primality test implementation is not my own, credit to Manish Bhojasia. Taken from http://www.sanfoundry.com/java-program-miller-rabin-primality-test-algorithm/ on Oct 13, 2017
 * 
 * @author Abe Ramseyer
 */
public class PerfectNumbers {
	public static void main(String[] args) {
		
		final int PRIMES_TO_CHECK = 10000;
		
		for(int prime = 2; prime < PRIMES_TO_CHECK; prime = nextPrime(prime)) {	// loops through all prime numbers in order up to threshold
			long q = (long) (Math.pow(2, prime) - 1); 
			if(isPrime(q, 40))
				System.out.println(q*(q+1) / 2);
			
		}
		System.out.println("finished");
	}
	
    static boolean isPrime(long n, int iteration)
    {
        if (n == 0 || n == 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
 
        long s = n - 1;
        while (s % 2 == 0)
            s /= 2;
 
        Random rand = new Random();
        for (int i = 0; i < iteration; i++)
        {
            long r = Math.abs(rand.nextLong());            
            long a = r % (n - 1) + 1, temp = s;
            long mod = modPow(a, temp, n);
            while (temp != n - 1 && mod != 1 && mod != n - 1)
            {
                mod = mulMod(mod, mod, n);
                temp *= 2;
            }
            if (mod != n - 1 && temp % 2 == 0)
                return false;
        }
        return true;        
    }
    
    /* Function to calculate (a ^ b) % c */
    static long modPow(long a, long b, long c)
    {
        long res = 1;
        for (int i = 0; i < b; i++)
        {
            res *= a;
            res %= c; 
        }
        return res % c;
    }
    
    /* Function to calculate (a * b) % c */
    static long mulMod(long a, long b, long mod) 
    {
        return BigInteger.valueOf(a).multiply(BigInteger.valueOf(b)).mod(BigInteger.valueOf(mod)).longValue();
    }
	
	static int nextPrime(int start) {
		for(int i = start+1; true ;i++) {
			if(isPrime(i, 40)) return i;
		}
	}
}
