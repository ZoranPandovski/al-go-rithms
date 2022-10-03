// Statement
Given an Integer N find the square root of N.

// Example
Input: N=25
Output: 5

Input: N=40
Output: 6.324

// Logic
// We calculate the integer value similarly as described in Square root.cpp


int Integer_sqrtN(long long int N){
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

double moreprecision(int N,int integer,int precision){
    double factor=1,ans=integer;
    for(int i=0;i<precision;i++){
        factor=factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}

int integer=Integer_sqrtN(N);
double finalanswer=moreprecision(N,integer,5);
