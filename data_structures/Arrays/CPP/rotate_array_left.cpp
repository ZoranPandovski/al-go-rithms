//program to rotate the array left by d.


#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
	cin >> n >> d;
	int arr[n];
	
  for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

  //temporary array to store first d elements.
	int temp[d];
  
  //store first d elements in temp array.
	for (int i = 0; i < d; i++) {
		temp[i] = arr[i];
	}
  
  //shift rest of elements to the left by d.
	for (int i = d; i < n ; i++) {
		arr[i - d] = arr[i];
	}
  
  // shift elements from temp array to the given array
	for (int i = n - d, j = 0; i < n; i++, j++) {
		arr[i] = temp[j];
	}

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
