import org.junit.Test;

import java.util.Arrays;

public class MergeSortTest {

	@Test
	public void test() {
        int[] list = {5, 7, 231, 606, 1, 1, 1, 6, 2, 1, 7, 3};
        int[] expectedList = {1, 1, 1, 1, 2, 3, 5, 6, 7, 7, 231, 606};
		assert(Arrays.equals(MergeSort.sort(list), expectedList));
	}

	@Test
	public void testNull() {
		int[] list = {};
		int[] expectedList = {};
		assert(Arrays.equals(MergeSort.sort(list), expectedList));
	}
}
