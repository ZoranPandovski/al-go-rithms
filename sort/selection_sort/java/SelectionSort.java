
import java.util.Arrays;

public class SelectionSort {

    /**
     * Uses the Selection Sort algorithm to sort the provided array of integers
     * in place.
     *
     * @param a The array of integers to sort
     */
    public static void sort(int[] a) {
        int n = a.length;

        for (int j = 0; j < n - 1; j++) {
            // keep track of the index of the smallest value
            int min = j;

            // compare the smallest value to the other values until a smaller value is found.
            for (int i = j + 1; i < n; i++) {
                // if this value is smaller than the value at min, it is now the smallest.
                if (a[i] < a[min]) {
                    min = i;
                }
            }

            // swap a new smallest value with an old smallest value.
            if (min != j) {
                int temp = a[j];
                a[j] = a[min];
                a[min] = temp;
            }

        }

    }

    public static void main(String[] args) {
        int[] testArray = {4, 2, 5, 1, 2, 17, 7, -1, -199, 500, 1245, -5};
        sort(testArray);
        System.out.println(Arrays.toString(testArray));

    }
}
