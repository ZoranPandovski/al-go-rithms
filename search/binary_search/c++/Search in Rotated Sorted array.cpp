// STATEMENT
Given a sorted array that is being rotated. You are also given an integer k.
Tell if the element is present or not.

// Example:
Input: arr==>[8,9,4,5] and k=3
Output: -1

Input: arr==>[2,4,5,6,8,9,1] and k=2
Output: 0

/*
    Time Complexity : O(log(N))
    Space Complexity : O(1)

    where N is the length of array.
*/


int binarySearch(vector<int>& arr, int si, int ei, int k){
    while(si <= ei){
        int mid = si + (ei - si) / 2;

        if(arr[mid] == k){
            return mid;
        }

        if(arr[mid] > k){
            ei = mid - 1;
        }
        else{
            si = mid + 1;
        }
    }
    return -1;
}

int findPosition(vector<int>& arr, int n, int k){
    int si = 0, ei = n - 1;
    int pivot = 0, index;
    while(si <= ei){
        int mid = si + (ei - si) / 2;
        if(arr[mid] < arr[0]){
            pivot = mid;
            ei = mid - 1;
        }
        else{
            si = mid + 1;
        }
    }

    if(pivot == 0 || (k <= arr[n - 1] && k >= arr[pivot])){
        index = binarySearch(arr, pivot, n - 1, k);
    }
    else{
        index = binarySearch(arr, 0, pivot - 1, k);
    }
    return index;
}


// Tried but didn't worked.
// int findpivot(vector<int>& arr,int n){
//     int s=0,e=n-1;
//     int mid=s+(e-s)/2;
//     while(s<e){
//         if(arr[mid]>arr[0]){
//             s=mid+1;
//         }
//         else if(arr[mid]<=arr[0]){
//             e=mid;
//         }
//         mid=s+(e-s)/2;
//     }
//     return s;
// }

// int findPosition(vector<int>& arr, int n, int k){
//     // Write your code here.
//     // Return the position of K in ARR else return -1.
//     int t=findpivot(arr,n);
//     int s=0,e=n-1;
//     int mid=s+(e-s)/2;
//     if(k>=arr[0]){
//         e=t-1;
//     }
//     else{
//         s=t;
//     }
//     while(s<=e){
//         if(arr[mid]==k){
//             return mid;
//         }
//         if(arr[mid]>k){
//             s=mid+1;
//         }
//         else{
//             e=mid-1;
//         }
//         mid=s+(e-s)/2;
//     }
//     return -1;
// }

