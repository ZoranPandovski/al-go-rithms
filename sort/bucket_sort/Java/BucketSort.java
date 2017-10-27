import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.IntStream;

public class BucketSort {
    public static void main(String[] args) {
        int[] elements = init();
        sort(elements);
        System.out.println(Arrays.toString(elements));
    }

    public static void sort(int[] elements) {
        int[] code = hash(elements);
        List<Integer>[] buckets = new List[code[1]];

        IntStream.range(0, buckets.length).forEach(i -> buckets[i] = new ArrayList());

        Arrays.stream(elements).forEach(i -> buckets[hash(i, code)].add(i));
        Arrays.stream(buckets).forEach(bucket -> Collections.sort(bucket));

        final AtomicInteger idx = new AtomicInteger(0);
        Arrays.stream(buckets).forEach(bucket -> {
            for(int el : bucket) {
                elements[idx.getAndIncrement()] = el;
            }
        });
    }

    private static int[] hash(int[] elements) {
        int max = Arrays.stream(elements).reduce(Integer.MIN_VALUE, (result, current) -> Math.max(result, current));
        return new int[] { max, (int) Math.sqrt(elements.length) };
    }

    private static int hash(int i, int[] code) {
        return (int)((double) i / code[0] * (code[1] - 1));
    }

    private static int[] init() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements: ");
        int n = sc.nextInt();
        int[] elements = new int[n];
        System.out.println("Enter elements: ");
        for(int i = 0; i < n; i++)
            elements[i] = sc.nextInt();
        return elements;
    }
}
