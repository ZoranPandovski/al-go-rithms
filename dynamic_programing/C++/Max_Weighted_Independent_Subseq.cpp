#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int *W, *A, N;
	cin >> N;
	W = new int[N + 1];
	A = new int[N + 1];
	for (int i = 1; i < N + 1; i++)
	{
		cin >> W[i];
	}
	A[0] = 0;
	A[1] = W[1];
	for (int i = 2; i < N + 1; i++)
	{
		A[i] = max(A[i - 1], A[i - 2] + W[i]);
	}
	cout << A[N]<<endl;
}