#include <stdio.h>
typedef long long ll;

ll fast_expo(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b % 2) 
			ans *= a;
		a *= a;
		b /= 2;
	}
	return ans;
}

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", fast_expo(a, b));
}
