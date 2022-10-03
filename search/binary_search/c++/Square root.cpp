// Statement
Given an Integer N find the square root of N.
If the number doesnt have a perfect square root return the floor value.

// Example
Input: N=25
Output: 5

Input: N=27
Output: 5

// Logic
// We consider the search space from 0 to N completely and handle the corner cases seperately.

int sqrtN(long long int N){
    long long int s=0,e=N;
    int ans=0;
    long long int mid=s+(e-s)/2;
    
    // Corner Case
    if(N<2){
        return N;
    }
    
    while(s<=e){
        mid=s+(e-s)/2;
        if(mid>N/mid){
            e=mid-1;
        }
        else if(mid<N/mid){
            ans=mid;
            s=mid+1;
        }
        else if(mid==N/mid){
            return mid;
        }
    }
    return ans;
}
