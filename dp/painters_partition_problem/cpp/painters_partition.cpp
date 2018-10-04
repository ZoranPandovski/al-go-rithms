// CPP program for The painter's partition problem 

#include <climits> 
#include <iostream> 
using namespace std; 

int sum(int arr[], int from, int to) 
{ 
    int total = 0; 
    for (int i = from; i <= to; i++) 
        total += arr[i]; 
    return total; 
} 
  
// bottom up tabular dp 
int findMax(int arr[], int n, int k) 
{ 
    // initialize table 
    int dp[k + 1][n + 1] = { 0 }; 
  
    // base cases 
    // k=1 
    for (int i = 1; i <= n; i++) 
        dp[1][i] = sum(arr, 0, i - 1); 
  
    // n=1 
    for (int i = 1; i <= k; i++) 
        dp[i][1] = arr[0]; 
  
    // 2 to k partitions 
    for (int i = 2; i <= k; i++) { // 2 to n boards 
        for (int j = 2; j <= n; j++) { 
  
            // track minimum 
            int best = INT_MAX; 
  
            // i-1 th separator before position arr[p=1..j] 
            for (int p = 1; p <= j; p++)  
                best = min(best, max(dp[i - 1][p], 
                              sum(arr, p, j - 1)));        
  
            dp[i][j] = best; 
        } 
    } 
  
    // required time return
    return dp[k][n]; 
} 

int main() 
{ 
	int n;
	cout<<"Enter the size of the array and the no. of partitions - 
";
	int k;
  cin>>n>>k;
	cout<<"\n";
	int arr[n];
	cout<<"Enter the length of the boards - ";
	for(int i = 0; i < n; i++)
	{
	    cin>>arr[i];
	}
	cout<<endl;
  cout<<"The minimum time taken to paint the boards is - ";
	cout << findMax(arr, n, k) << endl; 

	return 0; 
} 

