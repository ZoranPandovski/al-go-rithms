/*
COIN CHANGE MAKING PROBLEM  [ Bottom up SOLUTION ]
Time comp. --> O( amount * size of coin array)

Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?

Examples:

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents
*/


#include<bits/stdc++.h>
using namespace std;

int minCoins(vector<int> coins, int m, int amount){

	vector<int> table(amount+1);
	for(int i = 0; i <=amount; i++){ // asign with bigger value
		table[i] = amount + 1;
	}
	table[0] = 0;

	for(int i = 1; i <= amount; i++){
		for(int j = 0; j < m; j++){
			if(coins[j] <= i){
				table[i] = min(table[i-coins[j]] + 1, table[i]);
			}
		}
	}

	
	return table[amount];


}

int main(){
	int m;
	cin>>m;
	vector<int> coins(m);
	for(int i = 0; i < m; i++){
		cin>>coins[i];
	}
	int amount;
	cin>>amount;
	cout<<minCoins(coins,m,amount);
}