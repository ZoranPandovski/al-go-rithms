import java.util.*;

public class CedricEratosthenesSieve {


  /**
  * Find all primes from 1 to n 
  * Eg. if n = 10, primes = [3,5,7]
  * Uses the Sieve of Eratosthenes
  */
  public static List<Integer> findPrimes(int n) {
     List<Integer> primes = new ArrayList<>();
     if(n < 2) {
       return primes;
     }

     NavigableSet<Integer> primeCandidates = new TreeSet<Integer>();
     for(int i = 2; i<=n; i ++) {
       primeCandidates.add(i);
     }

     //Start from 2, the first prime number
     Integer p = 2;
     while(p != null) {
       int multiplier = 2;
       int multiple = p * multiplier;
       //remove all multiples from the candidate
       while (multiple<=n) {
        primeCandidates.remove(multiple);
         multiple = p * ++multiplier;
       }
       //Check other prime candidates. Stop when the last prime number found is the last item in the candidates 
       p = primeCandidates.higher(p); 
     }  

     return new ArrayList<Integer>(primeCandidates);
  }

}
