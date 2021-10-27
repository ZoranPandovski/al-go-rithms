#include<bits/stdc++.h>
using namespace std;
int main(){
	int A[]={};
	
}
vector<vector<int> > threeSum(vector<int> &A) {
    int n=A.size();
    sort(A.begin(),A.end());
    vector<vector<int>>v;
    for(int i=0;i<n-2;i++){
        int j=i+1;
        int k=n-1;
        while(k>j){
            int sum=A[i]+A[j]+A[k];
            if(sum==0){
                vector<int>p={};
                p.push_back(A[i]);
                p.push_back(A[j]);
                p.push_back(A[k]);
                v.push_back(p);
                
            }
            else if(sum>0) k--;
            else j++; 
        }
    }
    return v;
}
