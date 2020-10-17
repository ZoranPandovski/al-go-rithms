#include <iostream>
#include<vector>
using namespace std;

int zeroOneKnapsack(vector<int>& value,vector<int>& weight,int capacity) 
{
    vector<vector<int>> dp(weight.size()+1,vector<int>(capacity+1,0));
        
    for(int i=1 ; i<weight.size()+1 ; i++)
    {
        for(int j=1 ; j<capacity+1 ; j++)
        {
            dp[i][j] = dp[i-1][j];
            
            if(j >= weight[i-1])
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i-1]]+value[i-1]);
            }
        }
    }
    return dp[weight.size()][capacity];  
}


int main()
{
    int n;
    cin>>n;
    vector<int> value(n);
    vector<int> weight(n);
    
    for(int i=0 ; i<n ; i++)
    {
        cin>>value[i];
    }
    
    for(int i=0 ; i<n ; i++)
    {
        cin>>weight[i];
    }
    
    int capacity;
    cin>>capacity;
    cout<<zeroOneKnapsack(value,weight,capacity);

    return 0;
}
