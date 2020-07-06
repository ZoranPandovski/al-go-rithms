// C++ program to do range minimum query in O(1) time with O(n*n) 
// extra space and O(n*n) preprocessing time. 
#include <bits/stdc++.h> 
using namespace std;
#define MAX 500 

// lookup[i][j] is going to store index of minimum value in 
// arr[i..j] 
int lookup[MAX][MAX];

// Structure to represent a query range 
struct Query
{
	int L, R;
};

// Fills lookup array lookup[n][n] for all possible values of 
// query ranges 
void preprocess(int arr[], int n)
{
	// Initialize lookup[][] for the intervals with length 1 
	for (int i = 0; i < n; i++)
		lookup[i][i] = i;

	// Fill rest of the entries in bottom up manner 
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)

			// To find minimum of [0,4], we compare minimum of 
			// arr[lookup[0][3]] with arr[4]. 
			if (arr[lookup[i][j - 1]] < arr[j])
				lookup[i][j] = lookup[i][j - 1];
			else
				lookup[i][j] = j;
	}
}

// Prints minimum of given m query ranges in arr[0..n-1] 
void RMQ(int arr[], int n, Query q[], int m)
{
	// Fill lookup table for all possible input queries 
	preprocess(arr, n);

	// One by one compute sum of all queries 
	for (int i = 0; i < m; i++)
	{
		// Left and right boundaries of current range 
		int L = q[i].L, R = q[i].R;

		// Print sum of current query range 
		cout << "Minimum of [" << L << ", "
			<< R << "] is " << arr[lookup[L][R]] << endl;
	}
}

// Driver program 
int main()
{
	int a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
	int n = sizeof(a) / sizeof(a[0]);
	Query q[] = { {0, 4}, {4, 7}, {7, 8} };
	int m = sizeof(q) / sizeof(q[0]);
	RMQ(a, n, q, m);
	return 0;
}
