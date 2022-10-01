// This algorithm calculates all possible sum from subsets in O(n) time. 
// MAX_SIZE is the maximum possible value of subset sum.
#include<bits/stdc++.h>
#include<algorithm>

#define MAX_SUM 100000

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    bitset<MAX_SUM> sum;
    sum[0] = 1; // trivial case: empty subset
    for(int i=0;i<n;i++)
    {
        sum |= (sum<<arr[i]);
    }
    // wherever sum[i] = 1, means i is a possible subset sum
    cout<<"The list of all possible subset sums are: "<<endl;
    for(int i=0;i<MAX_SUM;i++)
    {
        if(sum[i])
            cout<<i<<" ";
    }
    return 0;
}