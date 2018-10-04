import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Valar Dohaeris on 10/29/17.
 */
public class LIS {

    /**
     * Returns the length of the longest increasing subsequence.
     * For example {10, 9, 2, 5, 3, 7, 101, 18} the LIS would be {2, 3, 7, 101}
     * and the function returns 4.
     * **/
    public static int getLongestIncreasingSubsequence(int[] nums) {

        List<Integer> res = new ArrayList<>();

        for(int n: nums)
            res = update(res, n);

        return res.size();
    }

    /**
     * Helper function, which for every input number checks if it can be added to current sequence, else
     * finds a appropriate place in the current sequence where it can be inserted.
     * **/
    private static List<Integer> update(List<Integer> res, int n)
    {
        if(res.size()==0 || res.get(res.size()-1) < n)
            res.add(n);
        else
        {
            int pos = binarySearch(res, n);
            res.set(pos, n);
        }

        return res;
    }

    /**
     * Binary search to find an appropriate position to insert the number in the increasing sequence.
     * */
    private static int binarySearch(List<Integer> res, int x)
    {
        int low = 0;
        int high = res.size()-1;

        while(low < high)
        {
            int mid = low + ((high-low)/2);

            if(res.get(mid) < x)
                low = mid+1;
            else
                high = mid;
        }

        return low;
    }

    public static void main(String[] args) throws Exception {
        int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
        System.out.println(getLongestIncreasingSubsequence(nums));
    }

}
