#include <bits/stdc++.h>
using namespace std;

long long int arr[100001];
long long int LIS[100001];

int main() {
	
	int N;
	cin >> N;
	for (long long int i = 1; i <= N; i++)
		cin >> arr[i];
	
	LIS[1] = arr[1];
	long long int size = 1;
	
	long long int pos;
	for (long long int i = 2; i <= N; i++) {
		if (LIS[size] < arr[i]) {
			size++;
			LIS[size] = arr[i];
			continue;
		}

		pos = lower_bound(LIS + 1, LIS + size + 1, arr[i]) - LIS;  
		LIS[pos] = arr[i];
	}

	cout << size << endl;

	

	return 0;
}