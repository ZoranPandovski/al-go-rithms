public class BucketSortTest {

	public static void main(String[] args) {
		int items[] = { 65, 2, 5, 1, -3, 12, 34, 0, 13 };
		BucketSort.sort(items);
		for (int i = 0; i < items.length - 1; i++) {
			if (items[i] > items[i + 1]) {
			  System.out.println("Items are not sorted -> Test failed");
			  System.exit(1);
			}
		}
		
		System.out.println("Test was successful!");
	}
}