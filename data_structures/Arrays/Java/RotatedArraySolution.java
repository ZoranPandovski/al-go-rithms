/*Given an array nums[], rotate the array to the right by k steps, where k is non-negative.*/

class Solution 
{
    public void rotate(int[] nums, int k)
    {
       //if k > length of array for that case
    k = k % nums.length;

    //reverse 1st part
    reverse(nums, 0, nums.length-k-1);

    //reverse 2nd part
    reverse(nums, nums.length-k, nums.length-1);

    //now reverse the full arrary
    reverse(nums, 0, nums.length-1);
    }
  
    public static void reverse(int[] nums, int s, int e)
   {

    int i = s;
    int j = e;

    while(i < j)
    {
        int t = nums[i];
        nums[i] = nums[j];
      nums[j] = t;

        i++;
        j--;
    } 
   }
}


/*
TEST CASE

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

*/
