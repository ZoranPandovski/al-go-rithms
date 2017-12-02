import org.junit.Test;

/**
 * Valar Dohaeris on 10/29/17.
 */
public class LISTest {

    @Test
    public void test() {
        int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
        assert (LIS.getLongestIncreasingSubsequence(nums)== 4);
    }

    @Test
    public void testNull() {
        int nums[] = {};
        assert (LIS.getLongestIncreasingSubsequence(nums)== 0);
    }

    @Test
    public void testZero() {
        int nums[] = {10, 9, 8, 7, 4, 3};
        assert (LIS.getLongestIncreasingSubsequence(nums)== 1);
    }
}
