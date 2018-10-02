import java.util.Arrays;

/**
 * Created by aubdira on 10/30/17. CycleSort
 */
public class CycleSort {

    public static void main(String[] args) {
        int[] arr = {233, 51, 63, 7, 18, 30, 66, -5, 128, 65, 49, 4};

        System.out.println(Arrays.toString(arr));

        cycleSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    private static void cycleSort(int[] a) {

        for (int cycleStart = 0; cycleStart < a.length - 1; cycleStart++) {
            int val = a[cycleStart];

            // count the number of values that are smaller than val
            // since cycleStart
            int pos = cycleStart;
            for (int i = cycleStart + 1; i < a.length; i++) {
                if (a[i] < val) {
                    pos++;
                }
            }

            // if there aren't any
            if (pos == cycleStart) {
                continue;
            }

            // skip duplicates
            while (val == a[pos]) {
                pos++;
            }

            // put val into final position
            int tmp = a[pos];
            a[pos] = val;
            val = tmp;

            // repeat as long as we can find values to swap
            // otherwise start new cycle
            while (pos != cycleStart) {
                pos = cycleStart;
                for (int i = cycleStart + 1; i < a.length; i++) {
                    if (a[i] < val) {
                        pos++;
                    }
                }

                while (val == a[pos]) {
                    pos++;
                }

                tmp = a[pos];
                a[pos] = val;
                val = tmp;
            }
        }
    }
}
