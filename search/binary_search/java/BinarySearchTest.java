import org.junit.Test;

public class BinarySearchTest {

	@Test
	public void test() {
	    int arr[] = {2, 3, 7, 8, 78, 99, 102, 5555};
	    int x = 102;
		assert(BinarySearch.search(arr, x) == 6);
	}
}
