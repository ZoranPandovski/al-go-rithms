#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cout<<"Enter the number of elements of set: ";
	cin >> n;
	int arr[n];
	cout<<"Enter the elements of the set: ";
	for(int i = 0; i<n; i++) cin >> arr[i];
	
	cout<<"\nSubsets of the given set are \n";
	for(int i = 0; i<(1<<n); i++) {
		cout<<"Subset #"<<i+1<<" -> ";
		for(int j = 0; j<n; j++) {
			if(i & (1<<j)) {
				cout<<arr[j]<<' ';
			}
		}
		cout<<'\n';
	}
}
