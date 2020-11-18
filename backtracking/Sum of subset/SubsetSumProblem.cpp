/*
By Priyanka Gupta
Using backtracking concepts
https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
*/

#include <bits/stdc++.h>
using namespace std;


bool back(int sum,int arr[],int n,int start){
    if(sum==0){
        return true;
    }
    if(sum<0)return false;
    
    for(int i=start;i<n;i++){
        bool val=back(sum-arr[i],arr,n,i+1);
        if(val)return true;
    }
    return false;
}

//equal partition function
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum%2!=0)return false;
        return back(sum/2,arr,N,0);
        
    }
};

// main function
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  
