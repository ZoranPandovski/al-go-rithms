import java.util.*;


public class Solution
{

    public static int findKthLargest(List<Integer> arr, int k)
    {
        if (arr == null || arr.size() < k) {
            return -1;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>(arr.subList(0, k));

        for (int i = k; i < arr.size(); i++)
        {
         
            if (arr.get(i) > pq.peek())
            {
                pq.poll();
                pq.add(arr.get(i));
            }
        }
        return pq.peek();
    }
 
 
    public static void main(String[] args)
    {
        List<Integer> arr = Arrays.asList(5,32,123,43,5,6);
        int k = 4;
 
        System.out.printf("%d'th largest array element is %d",k,findKthLargest(arr, k));
    }
}