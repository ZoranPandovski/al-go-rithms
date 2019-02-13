public class HybridSort {

    private static final int number = 154; // use insertion sort if size < number

    public static void hybridSort(int[] arr, int start, int end) {
        if ( end - start < number) {
            insertionSort(arr, start, end);
        } else {
            if (start < end) {
                int part = QuickSort.partition(arr, start, end);
                hybridSort(arr, start, part - 1);
                hybridSort(arr, part + 1, end);
            }
        }
    }

    private static void insertionSort(int[] arr, int start, int end) {
        for (int i = start; i <= end; i++) {
            int tmp = arr[i];
            for (int j = i - 1; j >= 0 && tmp < arr[j] ; j-- ) {
                arr[j+1] = arr[j];
                arr[j] = tmp ;
            }
        }
    }
}
