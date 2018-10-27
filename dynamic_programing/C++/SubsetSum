/* **** Complexity = O(subsetSum*n) where subsetSum is sum of the subset to be searched for *** */

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> Arr;
    int n,temp,subsetSum;
    cout<<"\nEnter number of the elements in the set : ";
    cin>>n;
    cout<<"\nEnter elements of the set : \n";
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        if(temp<0)
        {
            cout<<"\nEnter Non Negative Integers Only!!";
            i--;
        }
        else
        {
            Arr.push_back(temp);
        }
    }
    cout<<"\nEnter sum of subset to be searched for : ";
    cin>>subsetSum;
    bool subsetTable[n+1][subsetSum+1];
    for (int i = 0; i <= n; i++)
    {
        subsetTable[i][0] = true;
    }
    for (int i = 1; i <= subsetSum; i++)
    {
        subsetTable[0][i] = false;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=subsetSum;j++)
        {
            if(j<Arr[i-1])
            {
                subsetTable[i][j]=subsetTable[i-1][j];
            }
            if(j>=Arr[i-1])
            {
                subsetTable[i][j] = (subsetTable[i-1][j]) || (subsetTable[i - 1][j-Arr[i-1]]);
            }
        }
    }
    if(subsetTable[n][subsetSum])
    {
        cout<<"\nYes, there exists a subset whose sum is "<<subsetSum<<"\n";
    }
    else
    {
        cout<<"\nNo, there doesn't exist any subset whose sum is "<<subsetSum<<" !\n";
    }
    return 0;
}
