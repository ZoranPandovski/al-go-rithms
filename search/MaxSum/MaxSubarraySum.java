import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class MaxSubarraySum {
   Scanner in;
   MaxSubarraySum (Scanner in) {
       this.in = in;
   }
   
   void start() {
        int tests = in.nextInt();
        for (int i = 0; i < tests; i++) {
            doTest();
        }
   }
    
   void doTest() {
        int n = in.nextInt();
        long m = in.nextLong();
        System.out.println(solve(n, m));
   }

   public long solve(int n, long m) {
       SortedMap<Long,SortedSet<Integer>> rems = new TreeMap<>();
       long prefix_sum = 0;
       long max = 0;
       for(int i = 0; i < n; i++) {
           long val = in.nextLong() % m;
           prefix_sum = (prefix_sum + val) % m;
           if (prefix_sum > max) {
               max = prefix_sum;
           } else if (val > max) {
               max = val;
           }
           if (!rems.containsKey(prefix_sum)) {
               rems.put(prefix_sum, new TreeSet<Integer>());
           }
           SortedSet<Integer> z = rems.get(prefix_sum);
           z.add(i);
       }
       SortedMap<Long,SortedSet<Integer>> tail = rems;
       long diff = m - max;
       while (!tail.isEmpty() && diff > 1) {
           long first = tail.firstKey();
           tail = tail.tailMap(first+1);
           long newMax = newMax(first, tail, diff, m, rems);
           if (newMax > max) {
               max = newMax;
               diff = m - newMax;
           }
       }
       return max;
   }
    
   public long newMax(long first, SortedMap<Long,SortedSet<Integer>> tail, long diff, long m, SortedMap<Long,SortedSet<Integer>> rems) {
       while (!tail.isEmpty() && Math.abs(first - tail.firstKey()) < diff) {
           long second = tail.firstKey();
           SortedSet<Integer> secIdx = rems.get(second);
           SortedSet<Integer> firstIdx = rems.get(first);
           if (firstIdx.last() > secIdx.first()) {
               return (first - second + m) % m;
           }
           tail = tail.tailMap(second+1);
       }
       return -1;
   }
    
   public static void main(String[] args) {
        new MaxSubarraySum(new Scanner(System.in)).start();
   }
}