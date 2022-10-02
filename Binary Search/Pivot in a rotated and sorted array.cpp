// STATEMENT
Given a sorted array that is being rotated.
The required point is the minimum point there.

// Example
Input:- arr==>[7,9,1,2,3]
Output:- the pivot element is 1.  

// Graph

        .(9)
    .(7)
                    .(3)
                .(2)
            .(1)=====> This is the pivot element.


int findpivot(int *arr,int n){
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}