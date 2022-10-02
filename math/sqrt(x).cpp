
#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) 
{
        
    if(x==1)
        return x;
        
    int res=0;
    for(int i=1;i<=x;i++)
    {
        if(pow(i,2)>x)
        {
            res=i-1;
            break;
        }
    }
    return res;
}

int main()
{
    int num;
    cin>>num;
    cout<<mySqrt(num);

    return 0;
}

/*
Example 1:

Input: x = 4
Output: 2

Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

*/
