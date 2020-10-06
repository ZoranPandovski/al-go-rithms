/*
A program to find transpose of a square matrix mat[][] of size N*N. 
Transpose of a matrix is obtained by changing rows to columns and columns to rows.

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case contains an integer N, denoting the size of the square matrix. Then in the next line are N*N space separated values of the matrix.

Output:
For each test case output will be the space separated values of the transpose of the matrix

Constraints:
1 <= T <= 15
1 <= N <= 20
-103 <= mat[i][j] <= 103

Input:
2
4
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4
2
1 2 -9 -2

Output:
1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4
1 -9 2 -2

Explanation:
Testcase 1: The matrix after rotation will be: 1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4.
*/


#include <iostream>
using namespace std;

int main() {
	int t=0;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int a=0;
	    cin>>a;
	    int arr[20][20];
	    for(int i=0;i<a;i++)
	    {
	        for(int j=0;j<a;j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	     for(int i=0;i<a;i++)
	    {
	        for(int j=i;j<a;j++)
	        {
	            int b=0;
	          b= arr[i][j];
	            arr[i][j]=arr[j][i];
	            arr[j][i]=b;
	        }
	    }
	    for(int i=0;i<a;i++)
	    {
	        for(int j=0;j<a;j++)
	        {
	            cout<<arr[i][j]<<" ";
	        }
	       
	    }
	    cout<<endl;
	}   
	return 0;
}
