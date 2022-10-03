// STATEMENT
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the 
sum of all the numbers strictly to the index right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. 
This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

// Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,lsum=0,rsum=0,e=nums.size()-1,i=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        lsum=0;
        while(i<=e){
            rsum=sum-nums[i]-lsum;
            if(lsum==rsum){
                return i;
            }
            lsum+=nums[i];
            i++;
        }
        return -1;
    }
};


// This is one more code i tried but it didn't worked.
// int s=0,e=nums.size()-1,s1=0,s2=0,ans=-1;
//         int mid=s+(e-s)/2;
//         while(s<=e && mid<e){
//             s1=0;
//             s2=0;
//             for(int i=0;i<mid;i++){
//                 s1=s1+nums[i];
//             }
//             for(int i=mid+1;i<nums.size();i++){
//                 s2+=nums[i];
//             }
//             if(s1==s2){
//                 ans=mid;
//                 return ans;
//             }
//             else if(s1>s2){
//                 e=mid;
//             }
//             else{
//                 s=mid+1;
//             }
//             mid=s+(e-s)/2;
//         }
//         return ans;
