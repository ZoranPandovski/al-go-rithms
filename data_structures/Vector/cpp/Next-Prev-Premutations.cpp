// C++ program to demonstrate working of next_permutation() and prev_permutation() in vectors.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	
	// Initializing vector with array values
	
	int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> vect(arr, arr+n);

	
	cout << "Given Vector is:\n";
	for (int i=0; i<n; i++)
		cout << vect[i] << " ";

	
	// modifies vector to its next permutation order
	
	next_permutation(vect.begin(), vect.end());
	cout << "\nVector after performing
				next permutation:\n";
	for (int i=0; i<n; i++)
		cout << vect[i] << " ";

	
	prev_permutation(vect.begin(), vect.end());
	cout << "\nVector after performing prev
							permutation:\n";
	for (int i=0; i<n; i++)
		cout << vect[i] << " ";

	return 0;
}
