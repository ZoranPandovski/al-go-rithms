#include <iostream>

using namespace std;

// Inputs taken by the function:

// Values (stored in array v)
// Weights (stored in array w)
// Number of distinct items (n)
// Knapsack capacity (W)

int fill_knapsack(int v[], int w[], int n, int W)
{
	// T[i][j] stores the maximum value of knapsack having weight less than equal to j with only first i items considered.
    int T[n+1][W+1];
 
	for (int j = 0; j <= W; j++)
		T[0][j] = 0;                           //Since no. of items is zero so value of knapsack will be zero (Base Case)
	
	for (int i = 1; i <= n; i++)
	{
		// We consider all weights from 0 to maximum capacity W
		for (int j = 0; j <= W; j++)
		{
			// We don't include ith element if j-w[i-1] is negative
			if (w[i-1] > j)
				T[i][j] = T[i-1][j];
			else
			// We find maximum value we get by excluding or including the ith item
				T[i][j] = max(T[i-1][j],                         //Excluding the item
							T[i-1][j-w[i-1]] + v[i-1]);          //Including the item
		}
	}
	
	// We return the maximum value
    return T[n][W];
}
 
int main()
{
	// Input: set of items each with a weight and a value
	int v[] = { 20, 5, 10, 40, 15, 25};
	int w[] = {  1, 2,  3,  8,  7, 4};
	
	// Knapsack capacity
	int W = 10;

	// Number of items
	int n = sizeof(v) / sizeof(v[0]);

	cout << "The value of the knapsack is " << fill_knapsack(v, w, n, W) << endl;

    return 0;
}