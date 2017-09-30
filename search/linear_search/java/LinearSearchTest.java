import static org.junit.Assert.*;

import org.junit.Test;

public class LinearSearchTest {

	@Test
	public void test() {
		int[] array = {5,4,3,2,1};
		assert(LinearSearch.search(array,2) == 3);
		assert(LinearSearch.search(array,6) == -1);
	}

}
