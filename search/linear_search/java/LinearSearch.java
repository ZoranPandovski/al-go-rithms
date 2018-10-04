
public class LinearSearch {
	
	// Search through array linearly, returns index if found, -1 if not found
	public static int search(int[] array, int key) {
		int index = -1;
		
		for (int i = 0; i < array.length; i++) {
			if(array[i] == key) return i;
		}
		
		return index;
	}
	
	public static void main(String[] args) {
		int[] array = {1,2,3,4,5};
		int ans = LinearSearch.search(array, 6);
		System.out.println(ans);
	}
}
