#include<bits/stdc++.h>

using namespace std;

//kadane's algorithm
//find the maximum sum of a subarray

int maxSubSum(int arr[]){
    int currSum=0;
    int maxSum=0;
    for(int i=0;i<5;i++){
        currSum+=arr[i];
        if(currSum>maxSum){
            maxSum=currSum;
        }
        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
}

int main(){
    int n=5;
    int arr[n] ={5,-4,2,-3,1};
    int ans=maxSubSum(arr);
    cout<<ans;
    return 0;
}