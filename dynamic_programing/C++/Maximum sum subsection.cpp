#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int*W = new int[N + 1];
	int*cbest = new int[N + 1];
	int*nbest = new int[N + 1];
	for (int i = 1; i < N + 1; i++)
	{
		cin >> W[i];
	}
	cbest[0] = 0;
	for (int i = 1; i < N + 1; i++)
	{
		cbest[i] = max(W[i] + cbest[i - 1], W[i]);
	}
	nbest[0] = 0;
	for (int i = 1; i < N + 1; i++)
	{
		nbest[i] = max(W[i] + nbest[i - 1], nbest[i - 1]);
	}
	if (nbest[N] != 0)
		cout << *max_element(cbest + 1, cbest + N + 1) << "  " << nbest[N] << endl;
	else
		cout << *max_element(cbest + 1, cbest + N + 1) << "  " << *max_element(W + 1, W + N + 1) << endl;
}