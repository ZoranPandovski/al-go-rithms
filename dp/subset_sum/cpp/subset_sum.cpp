#include <iostream>

using namespace std;

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int s)
{
    // The value of subset[i][j] will be true if there is a 
    // subset of set[0..j-1] with s equal to i
	bool subset[n+1][s+1];
	
    // If s is 0, then answer is true
	for (int i = 0; i <= n; i++)
		subset[i][0] = true;
	
    // If s is not 0 and set is empty, then answer is false
	for (int i = 1; i <= s; i++)
		subset[0][i] = false;
	
     // Fill the subset table in botton up manner
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= s; j++)
		{
			if(j<set[i-1])
				subset[i][j] = subset[i-1][j];
			if (j >= set[i-1])
				subset[i][j] = subset[i-1][j] || 
			subset[i - 1][j-set[i-1]];
		}
	}
	
     /*   // uncomment this code to print table
     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= s; j++)
          printf ("%4d", subset[i][j]);
       printf("n");
     }*/
	
	return subset[n][s];
}

// Driver program to test above function
int main()
{
	int set[] = {3,2,7,1};
	int s = 6;
	int n = sizeof(set)/sizeof(set[0]);
	if (isSubsetSum(set, n, s) == true)
		cout << "Found a subset with given sum!" << endl;
	else
		cout << "No subset with given sum!" << endl;
	return 0;
}