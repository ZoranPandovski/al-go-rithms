// STATEMENT
An array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that 
arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// Example:
Input: arr = [0,1,0]
Output: 1

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0,e=arr.size()-1,ans=0;
        int mid=s+(e-s)/2;
        
        while(s<=e){
            if((arr[mid-1]<arr[mid]) && (arr[mid]>arr[mid+1])){
                ans=mid;
                break;
            }
            else if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else if(arr[mid]>arr[mid+1]){
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};
