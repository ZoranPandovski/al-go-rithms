#include<bits/stdc++.h>
using namespace std;

void RemoveDuplicate(int nums[], int n) 
{
        int j=0;
        if(n==0 || n==1)
            j=n;
        else
        {
            for(int i=0;i<n-1;i++)
            {
                if(nums[i]!=nums[i+1])
                    nums[j++]=nums[i];
            }
            nums[j++]=nums[n-1];
        }
        
        for(int i=0;i<j;i++)
            cout<<nums[i]<<" ";
            
}
                    

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int nums[n];
    cout<<"Enter elements"<<"\n";
    for(int i=0;i<n;i++)
        cin>>nums[i];
    RemoveDuplicate(nums,n);
    return 0;
}
