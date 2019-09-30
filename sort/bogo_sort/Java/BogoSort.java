/**
 * Created by aubdira on 10/30/17.
 * BogoSort is an ineffective sorting algorithm. The algorithm
 * generates permutations of its input until it finds one that is sorted.
 */
public class BogoSort {

    public static void main(String[] args) {
        //Enter array to be sorted here
        int[] arr = {12, 43, 5, -5, 0, 13};

        BogoSort now = new BogoSort();
        System.out.print("Unsorted: ");
        now.printArray(arr);

        now.bogo(arr);

        System.out.print("Sorted: ");
        now.printArray(arr);
    }

    private void bogo(int[] arr) {
        while (!isSorted(arr)) {
            shuffle(arr);
        }
    }

    /**
     * Use  Fisher-Yates shuffle algorithm to shuffle the array
     *
     * @param arr input array
     */
    private void shuffle(int[] arr) {
        int i = arr.length - 1;
        while (i > 0) {
            swap(arr, i--, (int) (Math.random() * i));
        }
    }

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private boolean isSorted(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    private void printArray(int[] arr) {
        for (int anArr : arr) {
            System.out.print(anArr + " ");
        }
        System.out.println();
    }
}

