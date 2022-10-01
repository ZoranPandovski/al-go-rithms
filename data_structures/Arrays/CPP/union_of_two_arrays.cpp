//union of two arrays
//In union elements of both arrays will be there, if there is a multiple occcurence of an element, only one occurence will be there.

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int arr1[n], arr2[m];

	//set is a data structure which stores unique elements
	set<int> st;

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
		st.insert(arr1[i]);
	}

	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
		st.insert(arr2[i]);
	}

	for (int x : st) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}
