#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j;
	cin >> n;
	int a[n],prod[n];
	for(i=0;i<n;i++)
		prod[i] = 1;
	int maxm = 1;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]>a[j] && prod[j]+1 > prod[i])
				prod[i] = prod[j]+1;
		}
		if(maxm<prod[i])
			maxm = prod[i];
	}
	cout << maxm << endl;
	return 0;
}