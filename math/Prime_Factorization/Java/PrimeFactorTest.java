import java.util.ArrayList;
import org.junit.Test;


/**
 * Testing prime factorization
 * @author Magro28
 */
public class PrimeFactorTest {

  @Test
  public void test() {

    ArrayList<Long> primefactorize = PrimeFactorization.primefactorize(91);
    assert(primefactorize.contains(7l));
    assert(primefactorize.contains(13l));
  }
}
