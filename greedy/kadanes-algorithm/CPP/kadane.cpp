#include<bits/stdc++.h>

using namespace std;

int n,arr[1000005],curSum,ans;

int main(){
	// Reading size of array and array.
	cin >> n;
	
	for(int i=1;i<=n;i++)
		cin >> arr[i];


	for(int i=1;i<=n;i++){

		// Add i'th value to current summary.
		curSum += arr[i];

		// When current summary becomes negative we should assign zero because adding to negative value isn't logical.
		if(curSum < 0){
			curSum = 0;
		}

		// Every for loops we should maximaze the answer.
		ans = max(ans, curSum);
	}

	cout << ans << endl;
}










