#include<bits/stdc++.h>
using namespace std;

int N = 1000000;
bool sieve[1000001];

void createSieve() {
	for (int i = 2; i < N; i++) {
		sieve[i] = true;
	}
	for (int i = 2; i * i <= N; i++) {
		if (sieve[i]) {
			for (int j = i * i; j <= N; j += i) {
				sieve[j] = false;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	createSieve();
	int n;
	cin >> n;

	if (sieve[n])
		cout << "Prime";
	else
		cout << "Not Prime";

	return 0;
}