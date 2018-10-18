public class GnomeSort {

	public void sort(int[] array) {
		int index = 0;
	
		while (index < array.length) {
			if (index == 0)
				index++;
				
			if (array[index] >= array[index - 1])
				index++;
			else
				int temp = array[index];
				array[index] = array[index - 1];
				array[index - 1] = temp;
				
			return array;
		}
	}	
}
