
public class LinearSearch {
	
	// Search through array linearly, returns index if found, -1 if not found
	public static int search(int[] array, int key) {
		int index = -1;
		
		for (int i = 0; i < array.length; i++) {
			if(array[i] == key) return i;
		}
		
		return index;
	}

	public static int searchWithRecursion(int [] array, int key, int index) {
		if(index == array.length) {
			return -1;
		}

		if(array[index] != key) {
			searchWithRecursion(array, key, index+1);
		} else {
			return index;
		}
	}
	
	public static void main(String[] args) {
		int[] array = {1,2,3,4,5};
		int ans = LinearSearch.search(array, 6);
		System.out.println(ans);

		int ansWithRecursion = LinearSearch.searchWithRecursion(array, 4, 0);
		System.out.println(ansWithRecursion);
	}
}
