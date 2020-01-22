/**
 * @author Tino097
 *
 */
public class HeapSort {

	protected static void heapSort(int[] list) {
		int n = list.length;

		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(list, n, i);

		for (int i = n - 1; i >= 0; i--) {
			int temp = list[0];
			list[0] = list[i];
			list[i] = temp;

			heapify(list, i, 0);
		}

	}

	static void heapify(int list[], int n, int i) {
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;

		if (l < n && list[l] > list[largest])
			largest = l;

		if (r < n && list[r] > list[largest])
			largest = r;

		if (largest != i) {
			int swap = list[i];
			list[i] = list[largest];
			list[largest] = swap;

			heapify(list, n, largest);
		}
	}
}
