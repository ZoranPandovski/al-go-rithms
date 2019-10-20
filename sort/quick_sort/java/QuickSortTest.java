import org.junit.Test;
import java.util.Arrays;

public class QuickSortTest {

    @Test
    public void test() {
        int list[] = { -5, 8, 0, 12, 55, 1, -66, 35, 3 };
        int listLength = list.length;
        QuickSort quickSort = new QuickSort();
        quickSort.sort(list, 0, listLength-1);
        for (int i = 0; i < list.length - 1; i++) {
            assert (list[i] <= list[i + 1]);
        }
    }

    @Test
    public void nullList(){
        int list[] = {};
        int expectedList[] = {};
        QuickSort quickSort = new QuickSort();
        quickSort.sort(list, 0, 0);
        assert (Arrays.equals(list, expectedList));
    }
}
