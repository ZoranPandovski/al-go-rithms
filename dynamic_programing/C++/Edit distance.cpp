#include<iostream>
#include<algorithm>
#include<string>
int diff(int, int);
using namespace std;
string X, Y;
int main()
{ 
	ios::sync_with_stdio(0);
	cin >> X;
	cin >> Y;
	int m = X.length();
	int n = Y.length();
	int **E = new int*[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		E[i] = new int[n + 1];
	}
	for (int i = 0; i < m + 1; i++)
	{
		E[i][0] = i;
	}
	for (int j = 0; j < n + 1; j++)
	{
		E[0][j] = j;
	}
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			E[i][j] = min({ 1 + E[i - 1][j], 1 + E[i][j - 1], diff(i, j) + E[i - 1][j - 1] });
		}
	}
	cout << E[m][n];
}
int diff(int i, int j)
{
	if (X[i-1] == Y[j-1])
		return 0;
	else
		return 1;
}
