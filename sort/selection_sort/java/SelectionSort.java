public class SelectionSort {

	//selection sort algorithm
	public static int[] selection(int[] arr) {
		//minimum index variable
		int min = 0;
		//each pass will have 1 element sorted
		for (int i = 0; i < arr.length; i++) {
			//each pass will find the lowest unsorted element and bring it to the bottom
			for (int j = 0; j < arr.length; j++) {
				//if the element is greater than the minimum, switch their values
				if(arr[j]>arr[min]){
					int temp = arr[min];
					arr[min] = arr[j];
					arr[j] = temp;
				}
			}
			//the minimum index increases after each minimum value of the unsorted section is selected
			min++;
		}
		//giving the sorted array
		return arr;
	}

	//running selection sort on an array of integers
	public static void main(String[] args) {
		int[] arr = { 6, 3, 9, 1, 4, 0, 8, 2, 7, 5};
		System.out.println("Before sorting");
		for (int x : arr) {
			System.out.print(x + " ");
		}
		System.out.println("\nAfter sorting");
		for (int x : selection(arr)) {
			System.out.print(x + " ");
		}
	}

}
