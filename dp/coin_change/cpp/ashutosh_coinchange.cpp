/*Problem link (Leetcode) : https://leetcode.com/problems/coin-change/ */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    
    vector<int> dp(amount+1, INT8_MAX);
    dp[0] = 0;
    
    for(int i =1; i <= amount; i++){
        for (int j = 0; j < n; j++){
            if (coins[j] <= i){
                if (dp[i-coins[j]] != INT8_MAX){
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main(void){
    int amount = 100;
    vector<int> coins = {1, 2, 5, 10};

    cout << coinChange(coins, amount) << endl;

    return 0;
}