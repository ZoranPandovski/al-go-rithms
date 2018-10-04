import org.junit.Test;

public class BubbleSortTest {

	@Test
	public void test() {
		int list[] = { 21, 8, 9, 2, 5, 11, 6, 35, 1 };
		BubbleSort.bubbleSort(list);
		for (int i = 0; i < list.length - 1; i++) {
			assert (list[i] <= list[i + 1]);
		}
	}
}
