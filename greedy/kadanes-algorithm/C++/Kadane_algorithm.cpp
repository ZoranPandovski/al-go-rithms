// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n)
{
    int msum = INT_MIN;
    int csum = 0;

    for (int i = 0; i < n; i++)
    {
        csum = csum + arr[i];
        if (msum < csum)
            msum = csum;
        if (csum < 0)
        {
            csum = 0;
        }
    }

    return msum;
    // Your code here
}

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}