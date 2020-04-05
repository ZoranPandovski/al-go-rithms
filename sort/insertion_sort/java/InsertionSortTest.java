import org.junit.Test;
import java.util.Arrays;

public class InsertionSortTest {

    @Test
    public void test() {
        int list[] = { -5, 8, 0, 12, 55, 1, -66, 35, 3 };
        InsertionSort insertionSort = new InsertionSort();
        insertionSort.sort(list);
        for (int i = 0; i < list.length - 1; i++) {
            assert (list[i] <= list[i + 1]);
        }
    }

    @Test
    public void nullList(){
        int list[] = {};
        int expectedList[] = {};
        InsertionSort insertionSort = new InsertionSort();
        insertionSort.sort(list);
        assert (Arrays.equals(list, expectedList));
    }
}
