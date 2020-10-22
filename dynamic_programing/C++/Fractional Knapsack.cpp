#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> iPair;
bool comp(iPair a, iPair b)
{
	int x = a.first / a.second;
	int y = b.first / b.second;
	return x > y;
}
int main()
{
	int N,w;
	cin >> N>>w;
	iPair *W = new iPair[N];
	for (int i = 0; i < N; i++)
	{
		cin >> W[i].first >> W[i].second;
	}
	sort(W, W + N, comp);
	int curw = 0;
	double curv = 0.0;
	for (int i = 0; i < N; i++)
	{
		if (curw + W[i].second <= w)
		{
			curw += W[i].second;
			curv += W[i].first;
		}
		else
		{
			int remain = w - curw;
			curv += W[i].first*((double)remain / W[i].second);
			break;
		}
	}
	cout << curv << endl;
}




