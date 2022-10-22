// { Driver Code Starts
#include <bits.h/stdc++.h>
#include<iostream>
using namespace std;
// } Driver Code Ends

class Solution
{
public:
    int swapBitGame(long long N)
    {
        // Code here
        int count = 0;
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                count++;
            }
            N /= 2;
        }
        return (count % 2 == 0) ? 2 : 1;
    }
};

// { Driver Code Starts
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.swapBitGame(N) << endl;
    }
    return 0;
}
// } Driver Code Ends