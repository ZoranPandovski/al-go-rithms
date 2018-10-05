#include <stdio.h>

const int N = 1e5;

int lis(int a[], int n) {
	int i, j;
	int dp[N];

	for(i = 0; i < n; ++i)
		dp[i] = 1;

	for(i = 0; i < n; ++i)
		for(j = 0; j < i; ++j)
			if(a[j] < a[i])
				if(dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;

	int mx = 0;
	for(i = 0; i < n; ++i)
		if(mx < dp[i])
			mx = dp[i];

	return mx;
}

int main() {
	int n;
	scanf("%d", &n);

	int a[N];
	int i;
	for(i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	printf("%d\n", lis(a, n));
}