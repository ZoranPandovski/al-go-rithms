/*Problem link : https://www.interviewbit.com/problems/longest-increasing-subsequence/ */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int lis(const vector<int> &A) {
    int n = A.size();
    if (n == 0) return 0;
    
    vector<int> dp(n,1);
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if (A[i] > A[j] && dp[i] < 1+dp[j])
                dp[i] = 1 + dp[j]; 
        }
    }
    
    return *max_element(dp.begin(),dp.end());
}

int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    cout << "Length of longest-increasing-subsequence : " << lis(v) << endl;

    return 0;
}