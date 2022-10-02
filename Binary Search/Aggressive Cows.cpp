/*                Statement
Given an array of length 'N', where each element denotes the position of a stall. 
Now you have 'N' stalls and an integer 'K' which denotes the number of cows that are aggressive. 
To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the 
minimum distance between any two of them is as large as possible. 

Return the largest minimum distance.
Input:- k=4 and arr=[0,3,4,7,10,9]
Output:- 3

In the first test case, the largest minimum distance will be 3 when 4 cows are placed at 
positions {0, 3, 7, 10}.
*/

#include<limits.h>
bool isPossibleSolution(vector<int> &stalls, int k,int mid){
    int count=1,diff,lastpos=0;
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-stalls[lastpos]>=mid){
            count++;
            lastpos=i;
            if(count==k){
                return true;
            }
        }
        if(count>=k){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(),stalls.end());
    int maxi=0,mini=INT_MAX;
    for(int i=0;i<stalls.size();i++){
        maxi=max(maxi,stalls[i]);
        mini=min(mini,stalls[i]);
    }
    int s=0,e=maxi-mini,ans=0;
    int mid=s+(e-s)/2;
    while(s<=e){
        mid=s+(e-s)/2;
        if(isPossibleSolution(stalls,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
