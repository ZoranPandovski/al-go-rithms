#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// Josepheus Problem Algorithm - Returns 'the survivor'.
int f(int n, int k){
	if(n==1) return 1;

	return (((f(n-1, k) + k - 1) % n) + 1);
}

int main(){
	int n, k, res;

	cin >> n;
	k = 1;
	while(n){
		res = f(n-1, k);
		if(res == 12){
			cout << k << "\n";

			k = 1;
			cin >> n;
			continue;
		}
		k++;
	}
}
