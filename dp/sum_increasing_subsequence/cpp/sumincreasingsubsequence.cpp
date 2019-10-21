#include<iostream>
using namespace std;

// First find increasing subsequence
// find the maximum possible sum
int maxSumIS(int a[], int n){
	int i, j, max = 0;
	int msis[n];

	for(i = 0; i<n; i++){
		msis[i] = a[i];
	}

	for(int i = 1; i<n; i++){
		for(int j = 0; j<i; j++){
			if(a[i] > a[j] && msis[i] < msis[j] + a[i]){
				msis[i] = msis[j] + a[i];
			}
		}
	}

	for(int i = 0; i<n; i++){
		if(max < msis[i])
			max = msis[i];
	}

	return max;
}

int main(){
	int a[] = {1, 101, 2, 3, 100, 4, 5};
	cout<<maxSumIS(a, 7)<<endl;
	return 0;
}