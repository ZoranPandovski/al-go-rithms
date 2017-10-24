import org.junit.Test;

/**
 * Valar Dohaeris on 10/23/17.
 */
public class KnapsackTest {
    @Test
    public void test() {
        int value[] = {10, 40, 30, 50};
        int weight[] = {5, 4, 6, 3};
        int W = 10;
        assert (Knapsack.knapsack(value, weight, W) == 90);
    }

    @Test
    public void testNull() {
        int value[] = {};
        int weight[] = {};
        int W = 10;
        assert (Knapsack.knapsack(value, weight, W) == 0);
    }

    @Test
    public void testZero() {
        int value[] = {10, 40, 30, 50};
        int weight[] = {5, 4, 6, 3};
        int W = 0;
        assert (Knapsack.knapsack(value, weight, W) == 0);
    }
}
