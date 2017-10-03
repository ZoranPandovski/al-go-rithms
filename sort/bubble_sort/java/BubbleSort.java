/**
 * @author Tino097
 *
 */
public class BubbleSort {

	protected static void bubbleSort(int[] list) {
		int temp = 0;
		for (int i = 0; i < list.length; i++) {
			for (int j = 1; j < list.length - i; j++) {
				if (list[j - 1] > list[j]) {
					temp = list[j - 1];
					list[j - 1] = list[j];
					list[j] = temp;
				}

			}

		}
	}
	
