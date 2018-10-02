
// binary trees of height h. 
#include <bits/stdc++.h> 
#define mod 1000000007 
using namespace std; 
   
long long int countBT(int h) { 
       
    long long int dp[h + 1]; 
    //base cases 
    dp[0] = dp[1] = 1; 
    for(int i = 2; i <= h; i++) { 
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod; 
    } 
    return dp[h]; 
} 
  
  
// Driver program 
int main() 
{ 
    int h = 3; 
    cout << "No. of balanced binary trees"
            " of height h is: "
         << countBT(h) << endl; 
} 