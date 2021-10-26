#include <bits/stdc++.h>
using namespace std;

int max_elem(vector<int>& arr, int n){
    int low = 0, high = n-1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(mid == 0 and arr[mid] > arr[mid + 1]) return mid; 
        else if(mid == n-1 and arr[mid] > arr[mid - 1]) return mid; 
        else if(mid - 1 >= 0 and mid + 1 < n and arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]){
            return mid;
        }
        else if(mid - 1 >= 0 and arr[mid-1] > arr[mid]) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

int search(vector<int>& arr, int ele, bool reverse, int low, int high){
    while(low <= high) {
        int mid = low + (high - low)/2;

        if(arr[mid] == ele) return mid;

        if(reverse){
            if(arr[mid] < ele) high = mid - 1;
            else low = mid + 1;
        }else{
            if(arr[mid] < ele) low = mid + 1;
            else high = mid - 1;  
        }
    }

    return -1;
}

int bitonic_search(vector<int> &arr, int ele) {

    int n = arr.size();

    int max_elem_idx = max_elem(arr, n);

    int l = search(arr, ele, false, 0, max_elem_idx);
    int r = search(arr, ele, true, max_elem_idx+1, n-1);

    return max(l, r);
}
