class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();  //no of elements in vector
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid =(s+e)/2;
            if(nums[mid]==target)
                return mid;
            //check if left half is sorted
            if(nums[s]<=nums[mid]){
                //left half sorted
                //check if value lie in left half range
                if(target>=nums[s] && nums[mid]>=target){
                    //move in left half
                    e=mid-1;
                }
                else{
                    //move to right half
                    s=mid+1;
                }
            }
            else{
                //right half is sorted
                //check if value lie in right half range
                if(target>=nums[mid] && nums[e]>=target){
                    //move in right half
                    s=mid+1;
                }
                else{
                    //move to left half
                    e=mid-1;
                }

            }
        }

        //if i am at then value doesn't exist
        return -1;



    }
};
