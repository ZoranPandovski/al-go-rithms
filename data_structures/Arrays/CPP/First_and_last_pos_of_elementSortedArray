#include <bits/stdc++.h>
using namespace std;
 
// A binary search function.
 void searchArray(int nums[],int n, int target) {
        int low = 0;
        int high = n-1;
        int ans[] = {-1,-1};
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target){
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
            	//first position of target element found
                ans[0] = mid;
                high = mid - 1;
            }
        }
        low = 0;
        high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > target){
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
            	//last position of target element found
                ans[1] = mid;
                low = mid + 1;
            }
        }

        cout<<target<<" is found at position " << ans[0] <<" and "<<ans[1];
    }
int main()
{
int n;
cout<<"Enter number of elements :";
cin>>n;
int nums[n];
for(int i=0;i<n;i++)
{
  cin>>nums[i];
}
   
    int x ;
    cout<<"Enter element want to find position :";
    cin>>x;
   searchArray(nums,n,x);
	    return 0;
}
