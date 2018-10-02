
///Maximum Subarray Sum, AsifurRahman///

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long size,i;

    cin>>size;     ///size of the Array
    long long A[size];

    for(i=1; i<=size; i++)
        cin>>A[i];         /// value of Array

    long long p,s,k;

    p=s=0;

    for (k = 1; k <= size; k++)
    {
        s = max(A[k],s+A[k]); ///comparing the value from the start point to present point;
        //cout<<s<<endl;
        p = max(p,s);  /// updating the present max to the past max
    }
    cout << p << "\n";   /// returning the result
    return 0;
}
