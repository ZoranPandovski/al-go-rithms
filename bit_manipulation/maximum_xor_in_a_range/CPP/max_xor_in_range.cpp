#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int maximumXOR(int L, int R)
{
    int LXR = L^R;
    int highestSetBit = log2(LXR)+1;
    int maxXOR = (1 << highestSetBit) - 1;
    return maxXOR;

    /*  
        EXPLANATION:
        Suppose L = 110010 and R = 101011 in binary.
        L^R = (110010)^(101011) = 011001
        Now since the highest set bit is 5th bit, the highest Xor possible for a 
        pair of numbers in this range will be of the form 1XXXX.
        So we can choose such a number that all the X's are replaced by 1.
        For ex: 110011 and 101100.
        Hence the answer is 11111.
    */
}

int main()
{
    int L,R;
    cin>>L>>R;
    cout<<maximumXOR(L,R)<<endl;
    return 0;
}