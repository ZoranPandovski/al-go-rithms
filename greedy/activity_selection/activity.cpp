#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define inf_ll 2000000000000000000LL
#define inf 1000000000
#define eps 1e-8
#define mod 1000000007
#define ff first
#define ss second
#define N 3456789
using namespace std;
typedef long long int ll;
typedef pair <ll, ll> PII;
PII ar[N];

int main () {
	ll n, i, res = 1, j = 0;
	cin >> n;
	for (i = 0; i < n; i++) cin >> ar[i].ss >> ar[i].ff;
	sort(ar, ar + n);	// Sort according to the finish times
	for (i = 1; i < n; i++) {
		if (ar[i].ss >= ar[j].ff) {			// If an activity does not conflict add it to res
			res++;
			j = i;
		}
	}
	cout << res << "\n";
	return 0;
}