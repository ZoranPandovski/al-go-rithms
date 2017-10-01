import java.util.Arrays;

/**
 * Created on 9/30/17.
 */
public class MergeSort {

    public static int[] mergeSort(int[] nums, int start, int end)
    {
        if(start<end)
        {
            //Break the array from starting index to ending index into 2 parts.
            int mid= start + ((end-start)/2);

            //Get the array which has the first part sorted
            nums = mergeSort(nums, start, mid);

            //We will reuse the same array to get the second part sorted.
            // Other way would be to use two separate arrays and then have them merged into a new array.
            nums = mergeSort(nums, mid+1, end);

            int i=start;
            int j=mid+1;

            // Iterate while comparing the positions from the first array and second array,
            // If the position of the first array is lesser, we do nothing as it is already in the right place.
            // If the position of the second array is lesser, we move all elements of the first array one position
            // to the right and put element in the position of the first array. We do this iteratively either till
            // the second array reaches its end or the first array crosses the pointer of second array.
            while(i<=j && j<=end)
            {

                if(nums[i] > nums[j])
                {
                    int k = j;
                    int temp = nums[j];
                    // Swap all elements in between i and j one position to the right.
                    while (k>i)
                    {
                        nums[k] = nums[k-1];
                        k--;
                    }
                    nums[i] = temp;
                    // Increment indices of the first and second part of the array
                    i++;
                    j++;
                }else {
                    // Increment just the front part of the array.
                    i++;
                }
            }
        }

        return nums;
    }

    public static int[] sort(int[] array)
    {
        return mergeSort(array, 0, array.length-1);
    }

    public static void main(String[] args)
    {
        int[] list = {5, 7, 231, 606, 1, 1, 1, 6, 2, 1, 7, 3};
        System.out.print(Arrays.toString(sort(list)));
    }
}
