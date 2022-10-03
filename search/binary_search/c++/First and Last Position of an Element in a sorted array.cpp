// STATEMENT
Given array of size n. You are also given an integer k.
Find its first and last occurence in the array.

// Example:
Input: arr==>[0,5,5,6,6,6] and k=3
Output: -1 -1

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k){
    int s=0,e=n-1,firstindex=-1,lastindex=-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]<k){
			s=mid+1;
		}
		else if(arr[mid]>k){
			e=mid-1;
		}
		else{
			firstindex=mid;
			e=mid-1;
		}
	}
	s=0;e=n-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]<k){
			s=mid+1;
		}
		else if(arr[mid]>k){
			e=mid-1;
		}
		else{
			lastindex=mid;
			s=mid+1;
		}
	}
	
	pair<int, int> res;
	res.first=firstindex;
	res.second=lastindex;
	return res;
}


// Variations
1. Find total number of occurences a given number in a sorted array.
   ===>We find the first and last index of the element using above approach.
   ===>Lastindex-FirstIndex+1 is the total number of the occureneces.
