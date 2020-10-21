//C++ program to move all negative elements in an array to one side without sorting.
//order does not matter here.

#include<bits/stdc++.h>
using namespace std;
int main() {

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
  
  //we can use any one of the approaches below.
  
  //two-pointer approach
	int l = 0, r = n - 1;
	while (l <= r) {
  
    // if both are negative
		if (arr[l] < 0 && arr[r] < 0) {
			l++;
		}
    
    //if right side element is negative and left side element is positive swap them.
    else if (arr[l] > 0 && arr[r] < 0) {
			int temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++;
			r--;
		}
    
    //if both are positive
    else if (arr[l] > 0 && arr[r] > 0) {
			r--;
		} else {
			l++;
			r--;
		}
	}

	//quick-sort approach
	int j = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (i != j) {
				swap(arr[i], arr[j]);
			}
			j++;
		}
	}

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
