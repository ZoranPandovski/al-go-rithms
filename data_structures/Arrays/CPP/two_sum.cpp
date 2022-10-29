#include <bits/stdc++.h>

using namespace std;
void twoSum(int nums[],int n, int target) {
       int ans[10];
       int cnt =0;
        int s = 0;
        //int n = nums.size();
        int e = n-1;
        int copy[n];
        for(int i=0;i<n;i++){
            copy[i]=nums[i];
        }
        sort(copy,copy+n);
        while(s < e){
            int sum = copy[s] + copy[e];
            if(sum == target)
                break;
            else if(sum < target){
                s++;
            }
            else{
                e--;
            }
        }
        for(int i = 0 ; i<n;i++){
            if(nums[i] == copy[s]){
                ans[cnt++]=i;
            }
            else if(nums[i] == copy[e]){
                ans[cnt++]=i;
            }
        }
        for(int i=0;i<cnt;i++){
            cout<<"\t"<<ans[i];
        }
}
int main()
{
    int n;
    cout<<"Enter number of elements :";
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cout<<"Enter target :";
    cin>>target;
     twoSum(nums,n,target);
        return 0;
}
