#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
int main() {
	long long s; 
	cin >> s;
	long long A[s];
	for(long long i = 0; i < s; i++) {
		cin >> A[i];	
	}
	long long x;
	cin >> x;
	long long flag = 0;
	for(long long i = 0; i < s; i++) {
		if(A[i] == x) {
			cout << i << endl;
			flag == 1;	
			break;
		}
	}
	return 0;
}

