#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair

using namespace std;

typedef pair <ll, pair <ll, ll> >  p_type;
priority_queue <p_type, vector <p_type> > q;
vector<ll> value(5000010), arr(5000010), siz(5000010);

bool find(pair <ll, ll> arg)
{
	int root1 = root(arg.first), root2 = root(arg.second);
	if(arr[root1] == arr[root2])
		return true;
	return false;   
}

ll root(ll i)
{
    while(arr[i] != i)
    {
        arr[i] = arr[arr[i]]; 
		i = arr[i];
    }
	return i;
}

void UNION(pair <ll, ll> arg)
{
	ll a = arg.first, b = arg.second;
	ll root_a = root(a), root_b = root(b);
    if(siz[root_a] < siz[root_b])
    {
		arr[root_a] = arr[root_b];
		siz[root_b] += siz[root_a];
	}
    else
    {
		arr[root_b] = arr[root_a];
		siz[root_a] += siz[root_b];
	}
}