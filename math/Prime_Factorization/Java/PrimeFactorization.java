import java.util.ArrayList;
import java.util.Scanner;

/**
 * prime factorization
 * @author Magro28
 */
public class PrimeFactorization {

  public static ArrayList<Long> primefactorize(long n){
    ArrayList<Long> primes = new ArrayList<>();

    if (n == 1l) {
      return primes;
    }
    long tmp = 2;
    while (tmp <= n) {
      //check if tmp is primefactor
      if (n % tmp == 0) {
        primes.add(tmp);
        n=n/tmp;
        tmp = 1;
      }
      tmp++;
    }

    return primes;
  }

  public static void main(String[] args)
  {
    Scanner sc=new Scanner(System.in);
    long x=sc.nextLong();
    ArrayList<Long> primes = primefactorize(x);
    for (Long prime : primes){
      System.out.println(prime + " ");
    }
  }
}