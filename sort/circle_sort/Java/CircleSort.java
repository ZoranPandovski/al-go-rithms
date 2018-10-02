import java.util.Arrays;

/**
 * Created by aubdira on 10/30/17. CircleSort
 */
public class CircleSort {

    public static void main(String[] args) {
        int[] arrayToBeSorted = new int[]{6, 14, 144, 7, -24, 9, 12, 23, 7, 331, -6, 13, 12, -1};
        circleSort(arrayToBeSorted);
    }

    /**
     * Keep Calling circleSortRec while there is a swap
     */
    private static void circleSort(int[] arr) {
        if (arr.length > 0) {
            do {
                System.out.println(Arrays.toString(arr));
            } while (circleSortRec(arr, 0, arr.length - 1));
        }
    }

    /**
     * This method  perform a circular swaps recursively it returns true if there was a swap
     */
    private static boolean circleSortRec(int[] arr, int lo, int hi) {
        boolean swapped = false;

        if (lo == hi) {
            return false;
        }

        int high = hi;
        int low = lo;
        int mid = (hi - lo) / 2;

        while (lo < hi) {
            if (arr[lo] > arr[hi]) {
                swap(arr, lo, hi);
                swapped = true;
            }
            lo++;
            hi--;
        }

        // special case arises with odd size lists
        if (lo == hi && arr[lo] > arr[hi + 1]) {
            swap(arr, lo, hi + 1);
            swapped = true;
        }

        boolean firstHalf = circleSortRec(arr, low, low + mid);
        boolean secondHalf = circleSortRec(arr, low + mid + 1, high);

        return swapped || firstHalf || secondHalf;
    }

    private static void swap(int[] arr, int idx1, int idx2) {
        int tmp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = tmp;
    }
}

