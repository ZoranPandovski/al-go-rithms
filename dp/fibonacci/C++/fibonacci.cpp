#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void){
	int n;
	cin >> n;
	long long int fib[n+1];
	fib[0] = (long long int)0;
	fib[1] = (long long int)1;

	for(int i = 2; i <= n; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}

	cout << fib[n] << endl;

	return 0;
}