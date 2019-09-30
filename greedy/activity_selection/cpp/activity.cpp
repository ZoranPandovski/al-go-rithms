#include<stdio.h>
#include<cstdio>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<utility>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
#define lli long long int
#define mp make_pair
#define f first
#define s second
#define sc(n) scanf("%d",&n);
#define scl(n) scanf("%lld",&n);
#define pr(n) printf("%d",n);
#define prl(n) printf("%lld",n);
#define nl printf("\n");
#define all(c) (c).begin(), (c).end()
#define sz(a) int((a).size())
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
void optimizeIO()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
}
bool sortinasc(const pair<int,int> &a, const pair<int,int> &b)
{
	return (a.s < b.s);
}

vector<pair<int, int> >arr;
int main()
{
	int n;
	cin >> n;
	int  t=n;
	while(t--)
	{
		int u,v;
		cin >> u >> v;
		arr.push_back(mp(u,v));
	}

	sort(arr.begin(),arr.end(),sortinasc);
//	tr(arr,it)
//		cout << it->first << " " << it->second << endl;
	int cnt = 1;
	int j=0;
	for(int i=1;i<n;i++)
		if(arr[i].f >=  arr[j].s)
		{
			cnt ++;
			j = i;
		}

	cout << cnt;
	nl;
}
