// shortest path for all source vertex



#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<vector<int> > g(n);
	vector<vector<int> > dp(n);
	for(int i = 0 ; i < n; i++){
		vector<int> tmp;
		for(int j=0;j < n; j++){
			int x; cin>>x;
			tmp.push_back(x);
		}
		g[i] = tmp;
		dp[i]  = tmp;
	}

	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(d[i][j] > (dp[i][k]+dp[k][j])){
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(dp[i][j] == 10000000){
				cout<<INF<<" ";
			}
			else{
				cout<<dp[i][j]<<" ";
			}
		}
		cout<<endl;
	}

	

}