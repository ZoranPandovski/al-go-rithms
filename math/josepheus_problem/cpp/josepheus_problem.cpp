#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// Josepheus Problem Algorithm - Returns 'the survivor'.
// Considering the initial position as 0, and the direction left-right.
int f(int n, int k){
	if(n==1) return 1;

	return (((f(n-1, k) + k - 1) % n) + 1);
}

int main(){
	// n -> number of pernsons
	// k -> skipp
	int n, k;
	
	cin >> n >> k;
	cout << "Survivor: " << f(n, k) << endl;
}
