//Ugly Number
# include<bits/stdc++.h>

using namespace std;
 
int Nth_Ugly_Number(int n)
{
    int ugly[n]; // To store ugly numbers
    int c2 = 0, c3 = 0, c5 = 0;
    int next_multiple_of_2 = 2;
    int next_multiple_of_3 = 3;
    int next_multiple_of_5 = 5;
    int next_ugly_no = 1;
 
    ugly[0] = 1;
    for (int i=1; i<n; i++)
    {
       next_ugly_no = min(next_multiple_of_2,min(next_multiple_of_3, next_multiple_of_5));
       ugly[i] = next_ugly_no;
       if (next_ugly_no == next_multiple_of_2)
       {
           c2 = c2+1;
           next_multiple_of_2 = ugly[c2]*2;
       }
       if (next_ugly_no == next_multiple_of_3)
       {
           c3 = c3+1;
           next_multiple_of_3 = ugly[c3]*3;
       }
       if (next_ugly_no == next_multiple_of_5)
       {
           c5 = c5+1;
           next_multiple_of_5 = ugly[c5]*5;
       }
    } 
    return next_ugly_no;
}
 
int main()
{
    int n = 150;
    cout << Nth_Ugly_Number(n);
    return 0;
}
